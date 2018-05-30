// lw3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;
namespace
{
	const int NUMBER_OF_ARGUMENTS = 3;
	const int MAX_NUMBER_OF_THREADS = 64;
	const double RADIUS = 1.0;
}

bool isCorrectArgs(int argc, char *argv[])
{
	if (argc != NUMBER_OF_ARGUMENTS)
	{
		cout << "Incorrect input. The correct command line format:\nlw3.exe <numberOfPoints> <numberOfThreads>\n";
		return false;
	}
	else
	{
		for (int i = 1; i < NUMBER_OF_ARGUMENTS; i++)
		{
			if (!isdigit(*argv[i]))
			{
				cout << "It's not a number: " << argv[i] << endl;
				return false;
			}
		}
	}
	if (atoi(argv[2]) <= MAX_NUMBER_OF_THREADS && atoi(argv[2]) >= 1)
	{
		return true;
	}
	else
	{
		cout << atoi(argv[2]) << " must be >= 1 and <= 64" << endl;
		return false;
	}
}

double CalculatePiMonteCarlo(int numberOfPoints, int numThreads)
{
	int numOfPointsInCircle = 0;
	double radius = 1.0;
	double x;
	double y;
	random_device rd; // access hardware RNG
	default_random_engine e(rd()); // seed the software PRNG
	uniform_real_distribution<> d(-1, 1); // range
	omp_set_num_threads(numThreads);
	#pragma omp parallel for
	for (int i = 0; i < numberOfPoints; i++)
		{
		x = d(e);
		y = d(e);
		if ((x * x + y * y) <= radius * radius)
			{
			numOfPointsInCircle++;
			}
		}
	return (numOfPointsInCircle * 4.0 / numberOfPoints);
}

void PrintInfo(double piMC, unsigned int time)
{
	cout << "Calculated PI : " << piMC << endl;
	cout << "Time: " << time << endl;
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
