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
struct eq
{
	ll a = 0, m = 0, M = 1, x = 0;
};
int main()
{
	ll n, M = 1;
	cin >> n;
	vector<eq> ar(n);
	for(auto& x : ar)
	{
		cin >> x.a >> x.m;
		M *= x.m;
	}
	ll X = 0;
	try
	{
		for(auto& x : ar)
		{
			x.M = M / x.m;
			x.x = mulinv(x.M, x.m);
			cout << x.a << "x = 1 mod "<< x.M << endl;
			X += x.x * x.a * x.M;
		}		
	}
	catch(...)
	{
		cout << "Error : All the m's must be pairwise coprime" << endl;
		return 1;
	}
	
	cout << "Answer : " << X << endl;


	return 0;
}
