#include <iostream>
#include <cmath>
#include <tuple>
#include <stdexcept>
using namespace std;
using ll = long long;
	template<typename Type>
tuple<Type, Type, Type> egcd(Type a, Type b)
{
	if(a == 0)
		return {b, 0, 1};
	Type g, x, y;
	tie(g, x, y) = egcd(b % a, a);
	return {g, y - (b / a) * x, x};
}
	template<typename Type>
Type mulinv(Type b, Type n)
{
	Type g, x, _;
	tie(g, x, _) = egcd(b, n);
	if(g == 1)
		return (x + n) % n;
	throw logic_error("No inverse found!");
}
int main()
{
	ll b, n;
	cin >> b >> n;
	try
	{
		cout << "Multiplicative inverse of " << b << " mod " 
			<< n << " : " << mulinv(b, n) << endl;
	}
	catch(...)
	{
		cout << "No multiplicative found for " << b << " mod " 
			<< n << endl;
	}

	return 0;
}
