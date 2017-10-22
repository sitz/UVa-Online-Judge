#include <bits/stdc++.h>

using namespace std;

long long modulo(long long b, long long p, long long m)
{
	if (p == 0)
	{
		return 1 % m;
	}
	long long tmp = modulo(b, p / 2, m);
	if (p % 2 == 0)
	{
		return (tmp * tmp) % m;
	}
	if (p % 2 == 1)
	{
		return (tmp * tmp * (b % m)) % m;
	}
}

int main()
{
	long long b, p, m;
	while (cin >> b >> p >> m)
	{
		b %= m;
		cout << modulo(b, p, m) << endl;
	}
	return 0;
}
