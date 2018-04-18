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

int main()
{
		unsigned int startTime = clock();
		double piMonteCarlo = getPiMonteCarlo(1000);
		unsigned int endTime = clock();
		cout << "Calculated PI : " << piMonteCarlo << endl;
		cout << "Time: " << endTime - startTime << endl;
		return 0;

}

