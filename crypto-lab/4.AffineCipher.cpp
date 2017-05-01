#include <iostream>
#include <cmath>
#include <tuple>
#include <stdexcept>
#include <vector>
#include <cctype>
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
size_t toint(char v)
{
	return v - 'a';
}
char tochar(size_t i)
{
	return i + 'a';
}
int main()
{
	ll a, b;
	string p, c;
	cin >> a >> b >> p;
	vector<size_t> pt, ct;
	for(auto x : p)
		pt.push_back(toint(x));

	ll ai = 0;
	try
	{
		ai = mulinv(a, 26LL);
	}
	catch(...)
	{
		cout << "gcd(a, 26) must be 1" << endl;
		return 0;
	}

	for(auto x : pt)
	{
		size_t cx = (a * x + b) % 26;
		ct.push_back(cx);
	}

	cout << "Encrypted Text : " << endl;
	for(auto cx : ct)
	{
		cout << static_cast<char>(tochar(cx));
	}
	
	


	return 0;
}
