#include <cmath>
#include <iostream>
#include <stdio.h>
#define PI 3.14
using namespace std;
int main()
{
    double h = 1.0, k = 0.6, v;
    double X = 20.0, T = 10.0, x;
    int a, b;
    int n = 3; // given in problem
    v = k / h;
    a = X / h + 1;
    b = T / k + 1;
    double u[a][b];
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            u[i][j] = 0;
    // Initial Condition
    for (int i = 0; i < a; i++) {
        x = h * i;
        u[i][0] = sin(2.0 * n * PI * (x / 10.0));
    }
    // Boundary Condition
    for (int i = 1; i < b; i++)
        u[0][i] = u[a - 1][i] = 0;
    for (int j = 0; j < b - 1; j++)
        for (int i = 1; i < a - 1; i++)
            u[i][j + 1] = (u[i + 1][j] + u[i - 1][j]) / 2.0
                          - v * (u[i + 1][j] - u[i - 1][j]) / 2.0;
    cout << ">---Time Varying--->--->--->\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%.2f  ", u[i][j]);
        }
        printf("\n\n");
    }
}
