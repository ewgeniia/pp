// lw1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


using namespace std;
namespace
{
	const int NUMBER_OF_ARGUMENTS = 3;
	const int MAX_NUMBER_OF_THREADS = 64;
	const double RADIUS = 1.0;
}

struct paramsForCalc
{
	int numPointsInThread;
	int pointsInCircle = 0;
};

DWORD WINAPI GetNumInCircle(void *data)
{
	paramsForCalc *p = (paramsForCalc *)data;
	int numberOfPoints = p->numPointsInThread;
	double x;
	double y;
	random_device rd; // access hardware RNG
	default_random_engine e(rd()); // seed the software PRNG
	uniform_real_distribution<> d(-1, 1); // range
	for (int i = 0; i < numberOfPoints; i++)
	{
		x = d(e);
		y = d(e);
		if ((x * x + y * y) <= RADIUS * RADIUS)
		{
			p->pointsInCircle += 1;
		}
	}
	return 0;
}
double CalculatePiMonteCarlo(int numAllPoints, int numThreads)
{
	int numOfPointsInCircle = 0;
	vector <HANDLE> hTreads;
	paramsForCalc params[MAX_NUMBER_OF_THREADS];
	int numPointsInThread = numAllPoints / numThreads;
	for (int i = 0; i != numThreads; i++)
	{
		if ((i + 1 == numThreads) && (numAllPoints % numThreads != 0))
		{
			numPointsInThread += numAllPoints % numThreads;
		}
		params[i].numPointsInThread = numPointsInThread;
		hTreads.push_back(CreateThread(NULL, 0, &GetNumInCircle, &params[i], 0, NULL));
	}
	for (auto &it : hTreads)
	{
		WaitForSingleObject(it, INFINITE);
	}
	for (int i = 0; i != numThreads; i++)
	{
		numOfPointsInCircle += params[i].pointsInCircle;
	}
	return (numOfPointsInCircle * 4.0 / numAllPoints);
}

void PrintInfo(double piMC, unsigned int time)
{
	cout << "Calculated PI : " << piMC << endl;
	cout << "Time: " << time << endl;
}

bool isCorrectArgs(int argc, char *argv[])
{
	if (argc != NUMBER_OF_ARGUMENTS)
	{
		std::cout << "Incorrect input. The correct command line format:\nlw1.exe <numberOfPoints> <numberOfThreads>\n";
		return FALSE;
	}
	else
	{
		for (int i = 1; i < NUMBER_OF_ARGUMENTS; i++)
		{
			if (!isdigit(*argv[i]))
			{
				std::cout << "It's not a number: " << argv[i] << endl;
				return FALSE;
			}
		}
	}
	if (atoi(argv[2]) <= MAX_NUMBER_OF_THREADS && atoi(argv[2]) >= 1)
	{
		return TRUE;
	}
	else
	{
		cout << atoi(argv[2]) << " must be >= 1 and <= 64" << endl;
		return FALSE;
	}
}

int main(int argc, char *argv[])
{
	if (isCorrectArgs(argc, argv))
	{
		unsigned int startTime = clock();
		double piMonteCarlo = CalculatePiMonteCarlo(atoi(argv[1]), atoi(argv[2]));
		unsigned int endTime = clock();
		PrintInfo(piMonteCarlo, endTime - startTime);
	}
	else
	{
		return -1;
	}
		return 0;
}

