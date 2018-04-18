// lw1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;

double getPiMonteCarlo(int numberOfPoints)
{
	int numOfPointsInCircle = 0;
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
	return (numOfPointsInCircle * 4.0 / numberOfPoints);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Incorrect input. The correct command line format:\nlw1.exe <numberOfPoints>\n";
		return -1;
	}
	else
	{
		if (!isdigit(*argv[1]))
		{
			std::cout << "It's not a number: " << argv[1] << endl;
			return -1;
		}
		else
		{
			unsigned int startTime = clock();
			double piMonteCarlo = getPiMonteCarlo(atoi(argv[1]));
			unsigned int endTime = clock();
			cout << "Calculated PI : " << piMonteCarlo << endl;
			cout << "Time: " << endTime - startTime << endl;
			return 0;
		}
	}
}

