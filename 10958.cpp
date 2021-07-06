#include <bits/stdc++.h>

using namespace std;

/*
10958
How Many Sol
*/
#define maxn 31630
//typedef __int64 ss;
typedef long long ss;
char sv[maxn + 2];
ss P[3403], tp;
void Prime()
{
	ss i, j;
	for (i = 2; i * i < maxn;)
	{
		for (j = i + i; j < maxn; j += i)
		{
			sv[j] = 1;
		}
		for (++i; sv[i]; i++)
			;
	}
	tp = 1;
	P[0] = 2;
	for (i = 3; i < maxn; i += 2)
	{
		if (sv[i] == 0)
		{
			P[tp++] = i;
		}
	}
}
ss Div(ss n)
{
	ss i, j, c = 1;
	if (n < 0)
	{
		n *= -1;
	}
	for (i = 0; i < tp && P[i] * P[i] <= n; i++)
	{
		if (n % P[i] == 0)
		{
			j = 0;
			while (n % P[i] == 0)
			{
				j++;
				n /= P[i];
			}
			j++;
			c *= j;
		}
	}
	if (n > 1)
	{
		c *= 2;
	}
	return c * 2 - 1;
}
int main()
{
	ss m, n, p, k = 1;
	Prime();
	while (scanf("%lld%lld%lld", &m, &n, &p) == 3)
	{
		if (!n && !m && !p)
		{
			break;
		}
		printf("Case %lld: %lld\n", k++, Div(n * m * p * p));
	}
	return 0;
}
