#include<iostream>
#include<cmath>
using namespace std;
#define x_step 0.1
#define t_step 0.005
#define x0 0
#define xL 1
#define ALPHA 1.0
int main(){
	int x=(int)((xL-x0)/x_step);
	double u[x+1][2000];
	for(int i=0;i<=x;i++){
		u[i][0] = 100.0*sin(M_PI*(i*x_step));
	}
	for(int i=0;i<2000;i++){
		u[0][i] = 0.0;
		u[x][i] = 0.0;
	}
	double r = ALPHA*(t_step)/(pow(x_step, 2));
	for(int j=1;j<2000;j++){
	for(int i=1; i<x;i++){
		u[i][j] = u[i][j-1] + r*(u[i+1][j-1] - 2*u[i][j-1] + u[i-1][j-1]);
	}
	}

	for(int i=0;i<=x;i++){
		cout<<"Approximate values :"<<u[i][100]<<" Actiual Value: "<<100.0*exp(-1.0*pow(M_PI,2)*0.5)*sin(M_PI*(i*x_step))<<endl;
	}
	return 0;
}
