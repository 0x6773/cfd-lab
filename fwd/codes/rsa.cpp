#include <bits/stdc++.h>
#define MAX 1000005
#define ll long long
using namespace std;
vector<int> prime;
bool b[MAX];

int phi(int n)
{
    for (int i = 0; i < prime.size() && prime[i] <= n; i++)
        if (n % prime[i] == 0)
            n -= n / prime[i];
    return n;
}

ll power(ll a, ll n, ll m)
{
    if (n == 0)
        return 1;
    else {
        ll v = power(a, n / 2, m);
        v = v * v % m;
        if (n & 1)
            v = v * a % m;
        return v;
    }
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    if (a == 0)
        return b;
    else
        return gcd(b, a % b);
}

void RSA(ll n, ll d)
{
    ll p = -1, q = 1;
    int i;
    for (i = 0; i < prime.size() && prime[i] <= n; i++) {
        if (n % prime[i] == 0) {
            p = prime[i];
            q = n / p;
            break;
        }
    }

    ll phin = (p - 1) * (q - 1);
    if (p == -1 || gcd(phin, d) != 1) {
        cout << "Error in input\n";
        return;
    } else {
        cout << "key is\t" << power(d, phi(phin) - 1, phin);
    }
}
int main()
{
    int i, j;
    memset(b, true, sizeof b);
    for (i = 2; i * i < MAX; i++) {
        if (b[i]) {
            prime.push_back(i);
            for (j = i * i; j < MAX; j += i)
                b[j] = false;
        }
    }
    for (i; i < MAX; i++)
        if (b[i])
            prime.push_back(i);
    ll n, d;
    cout << "Enter n and d\n";
    cin >> n >> d;
    RSA(n, d);
}
