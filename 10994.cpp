#include <bits/stdc++.h>

using namespace std;

long long solve(long long p, long long q)
{
	if (p > q)
	{
		return 0;
	}
	if (p / 10 == 0 && q / 10 == 0)
	{
		long long sum = 0;
		for (long long i = p; i <= q; i++)
		{
			sum += i;
		}
		return sum;
	}
	if (p / 10 == 0 && q / 10 != 0)
	{
		long long pp = 10, qq, i;
		long long sum = 0;
		for (i = p; i < pp; i++)
		{
			sum += i % 10;
		}
		qq = q / 10 * 10;
		for (i = qq; i <= q; i++)
		{
			sum += i % 10;
		}
		return sum + solve(pp, qq);
	}
	if (p % 10 == 0 && q % 10 == 0)
	{
		long long sum = (q - p) / 10 * 45;
		return sum + solve(p / 10, q / 10);
	}
	long long pp, qq, i;
	pp = (long long)ceil(p * 1.0 / 10) * 10;
	qq = q / 10 * 10;
	long long sum = 0;
	for (i = p; i <= pp; i++)
	{
		sum += i % 10;
	}
	for (i = qq; i <= q; i++)
	{
		sum += i % 10;
	}
	return sum + solve(pp, qq);
}

int main()
{
	long long p, q;
	while (cin >> p >> q && p >= 0 && q >= 0)
	{
		cout << solve(p, q) << endl;
	}
	return 0;
}
