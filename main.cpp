include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int n;
double f(double, double);

double f(double x, double y)
{
	return (1 + 0.2*y*sin(x) - y*y);
}

int main()
{
	double *y1, xi, x0, a, b, yi;
	n = 10;
	a = 0;
	b = 1;
	y1 = new double[n];
	double h = (b - a) / n;
	x0 = a;
	for (int k = 0; k < n; k++) {
		y1[k] = 0.;
	}

	y1[0] = 0;

	for (int i = 0; i<n; i++)
	{
		xi = x0 + i*h;
		yi = h*f(xi, y1[i]);
		y1[i + 1] = y1[i] + yi;
	}

	for (int i = 0; i<n; i++)
	{
		cout << "y=" << y1[i] << endl;
	}
	double eps = 0.01;
	double *y2 = new double[n];
	for(int k = 0; k <= n; k++) {
		y2[k] = 0.;
	}
	do {
		for (int i = 0; i < n; i++) {
			xi = x0 + i*h/2;
			yi = h/2*f(xi, y2[i]);
			y2[i + 1] = y2[i] + yi;
		}
	} while (fabs(y1[n] - y2[n])<eps);
	cout << endl;
	for (int i = 0; i<n; i++)
	{
		cout << "y2=" << y2[i] << endl;
	}

	system("pause");
	return 0;
}
