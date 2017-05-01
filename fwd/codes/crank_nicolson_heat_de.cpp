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
	double u[x+1][2000], a[x+1], b[x+1], c[x+1], d[x+1];
	double r = ALPHA*(t_step)/(2.0*pow(x_step, 2));

	// calculation of ci and bi
	for(int i=1;i<=x;i++){
		c[i] = a[i] = -1.0 * r;
		b[i] = 1.0 + 2.0*r;
	}

	// Boundary conditions
	for(int i=0;i<=x;i++){
		u[i][0] = 100.0*sin(M_PI*(i*x_step));
	}

	for(int i=0;i<2000;i++){
		u[0][i] = 0.0;
		u[x][i] = 0.0;
	}

	// ci' and di' calculation
	double c_dash[x+1], d_dash[x+1];
	c_dash[1] = c[1]/b[1];
	for(int i=2; i<=x; i++){
		c_dash[i] = c[i] / (b[i] - a[i]*c_dash[i-1]);
	}

	for(int j=1;j<=200; j++){
		d[1] = (1.0 - 2*r)*u[1][j-1] + r*u[0][j-1] + r*u[2][j-1] + r*u[0][j];
		for(int i=2; i<x; i++){
		d[i] = (1.0 - 2*r)*u[i][j-1] + r*u[i-1][j-1] + r*u[i+1][j-1];
	}
  d[x] = (1.0 - 2*r)*u[x][j-1] + r*u[x-1][j-1] + r*u[x+1][j-1] + r*u[x-1][j];


	d_dash[1] = d[1]/b[1];
	for(int i=2;i<=x; i++){
		d_dash[i] = (d[i] - a[i]*d_dash[i-1])/(b[i] - a[i]*c_dash[i-1]);
	}

	u[x][j+1] = d_dash[x];
	for(int i=x-1;i>=1; i--){
		u[i][j+1] = d_dash[i] - c_dash[i]*u[i+1][j+1];
	}
	if(j==100){
		for(int i=0;i<=x;i++){
		cout<<"Approximate values :"<<u[i][100]<<" Actiual Value: "<<100.0*exp(-1.0*pow(M_PI,2)*0.5)*sin(M_PI*(i*x_step))<<endl;
	}
	}

	}

	return 0;
}
