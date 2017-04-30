#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	double h = 1.0, k = 0.0125, v, c = 4.0;
	double X = 8.0, T = 0.05, x;

	int a, b;
	v = (c * c * k) / (h * h);
	a = X / h + 1;
	b = T / k + 1;

	double u[a][b];
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			u[i][j] = 0;

	// Initial Condition
	for (int i = 0; i < a; i++) {
		x = h * i;
		u[i][0] = 4 * x - x * x / 2.0;
	}
	// Boundary Condition
	for (int i = 1; i < b; i++)
		u[0][i] = u[a - 1][i] = 0;
	for (int j = 0; j < b - 1; j++) {
		for (int i = 1; i < a - 1; i++) {
			u[i][j + 1]
				= v * u[i + 1][j] + (1.0 - 2 * v) * u[i][j] + v * u[i - 1][j];
		}
	}
	cout << ">---Time Varying--->--->--->\n";
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf("%.4f  ", u[i][j]);
		}
		printf("\n\n");
	}
}
