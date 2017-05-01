#include<iostream>
using namespace std;

int gcd(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd1 = gcd(b%a, a, &x1, &y1);

    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd1;
}

int inv(int a, int m){
	int x, y;
	int gcd1 = gcd(a, m, &x, &y);
	if(gcd1!=1) return -1;
	else {
		int result = (x%m+m)%m;
		return result;
	}
}

int main(){
	int a, m;
	cout<<"Enter the value of a:";
	cin>>a;
	cout<<"Enter the value of m:";
	cin>>m;
	if(inv(a, m)!=-1)
	cout<<"Modulo inverse of a is : "<<inv(a,m);
	else cout<<"Inverse doesn't exist";
	return 0;
}
