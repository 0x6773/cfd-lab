#include <cmath>
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    double h = 0.1, k = 0.1, v, c = 10;
    double X = 1.0, T = 1.0, x; // taking any random value of T
    int a, b;
    v = k / (h * h);
    v /= c; // otherwise solution overflows
    cout << v << "\n";
    a = X / h + 1;
    b = T / k + 1;
    double u[a][b];
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            u[i][j] = 0;
    // Initial Condition
    for (int i = 0; i < a; i++)
        u[i][0] = 0;
    // Boundary Condition
    for (int i = 1; i < b; i++) {
        u[0][i] = 0;
        u[a - 1][i] = k * i;
    }
    for (int j = 0; j < b - 1; j++)
        for (int i = 1; i < a - 1; i++)
            u[i][j + 1] = (double)u[i][j]
                          + v * (u[i + 1][j] - 2.0 * u[i][j] + u[i - 1][j]);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%.2f  ", u[i][j]);
        }
        printf("\n\n");
    }
}
