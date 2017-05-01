#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int m = a, n = b;
    while (n > 0) {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}
int main()
{
    int a, b, gcd_result;
    cout << "Enter value of a:";
    cin >> a;
    cout << "Enter value of b:";
    cin >> b;
    gcd_result = gcd(a, b);
    cout << "GCD of " << a << "and " << b << " is " << gcd_result;
    return 0;
}
