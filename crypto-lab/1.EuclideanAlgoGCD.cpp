#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
	template<typename Type>
Type egcd(Type a, Type b)
{
	if(a == 0)
		return b;
	return egcd(b % a, a);
}
int main()
{
	ll x, y;
	cin >> x >> y;
	cout << "GCD of " << x << " and " 
		<< y << " : " << egcd(x, y) << endl;

	return 0;
}
