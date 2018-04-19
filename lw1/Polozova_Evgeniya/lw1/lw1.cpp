// lw1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;
namespace
{
	const int NUMBER_OF_ARGUMENTS = 3;
}

void getNumInCircle(int numberOfPoints, int & numOfPointsInCircle)
{
	double radius = 1.0;
	double x;
	double y;
	random_device rd; // access hardware RNG
	default_random_engine e(rd()); // seed the software PRNG
	uniform_real_distribution<> d(-1, 1); // range
	for (int i = 0; i < numberOfPoints; i++)
	{
		x = d(e);
		y = d(e);
		if ((x * x + y * y) <= radius * radius)
		{
			numOfPointsInCircle++;
		}
	}
}


int main(int argc, char *argv[])
{
	if (argc != NUMBER_OF_ARGUMENTS)
	{
		std::cout << "Incorrect input. The correct command line format:\nlw1.exe <numberOfPoints> <numberOfThreads>\n";
		return -1;
	}
	else
	{
		for (int i = 1; i < NUMBER_OF_ARGUMENTS; i++)
		{
			if (!isdigit(*argv[i]))
			{
				std::cout << "It's not a number: " << argv[i] << endl;
				return -1;
			}
		}

		int numAllPoints = atoi(argv[1]);
		int numThreads = atoi(argv[2]);
		int numOfPointsInCircle = 0;
		vector <thread> hTreads;
		int numPointsInThread = numAllPoints / numThreads;
		unsigned int startTime = clock();
		for (int i = 0; i != numThreads; i++)
		{
			if ((i + 1 == numThreads) && (numAllPoints % numThreads != 0))
			{
				numPointsInThread += numAllPoints % numThreads;
			}
			hTreads.push_back(thread(getNumInCircle, numPointsInThread, ref(numOfPointsInCircle)));
		}
		for (auto &it : hTreads)
		{
			it.join();
		}
		unsigned int endTime = clock();
		cout << "Calculated PI : " << numOfPointsInCircle * 4.0 / numAllPoints << endl;
		cout << "Time: " << endTime - startTime << endl;
		return 0;
	}
}

