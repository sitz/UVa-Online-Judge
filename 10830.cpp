#include <bits/stdc++.h>

using namespace std;

/*
10830
A new Fun
*/
typedef long long ss;
ss Summ(ss n, ss m, ss k)
{
	ss i, j;
	if (n > m)
	{
		return 0;
	}
	i = ((n + m) * (m - n + 1)) / 2;
	j = i + (m - n + 1) * k;
	return j;
}
ss Cal(ss n)
{
	ss i, total = 0;
	for (i = 2; i * i <= n; i++)
	{
		total += Summ(i + 1, n / i, i);
		total += i;
	}
	return total;
}
int main()
{
	ss n, ks = 1;
	while (scanf("%lld", &n) && n)
	{
		printf("Case %lld: %lld\n", ks++, Cal(n));
	}
	return 0;
}
