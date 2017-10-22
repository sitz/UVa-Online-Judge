#include <bits/stdc++.h>

using namespace std;

/*
11083
*/
#define maxn 317
#define MIN(a, b) (a > b ? b : a)
typedef long long SS;
char sv[maxn + 2];
int P[70], ip;
SS N, B;
void Table()
{
	int i, j;
	for (i = 2; i * i < maxn;)
	{
		for (j = i + i; j < maxn; j += i)
		{
			sv[j] = 1;
		}
		for (++i; sv[i]; i++)
			;
	}
	P[0] = 2;
	ip = 1;
	for (i = 3; i < maxn; i += 2)
	{
		if (!sv[i])
		{
			P[ip++] = i;
		}
	}
}
SS Zero(SS n)
{
	SS rem, r, c = 0;
	r = N / n;
	if (r == 1)
	{
		return N - n + 1;
	}
	rem = N % n + 1;
	c += rem * r;
	r--;
	rem = r + 1;
	if (r % 2)
	{
		return ((rem / 2) * r) * n + c;
	}
	return (rem * (r / 2)) * n + c;
}
SS Count(int p)
{
	SS i, c = 0;
	if (p > N)
	{
		return 0;
	}
	for (i = p; i <= N; i *= p)
	{
		c += Zero(i);
	}
	return c;
}
void Cal()
{
	SS n = B, i, min, c, z, f = 0;
	for (i = 0; i < ip && P[i] * P[i] <= n; i++)
	{
		if (n % P[i] == 0)
		{
			z = Count(P[i]);
			c = 0;
			while (n % P[i] == 0)
			{
				c++;
				n /= P[i];
			}
			if (f == 0)
			{
				f = 1;
				min = z / c;
			}
			else
			{
				min = MIN(min, z / c);
			}
			if (!min)
			{
				printf("0\n");
				return;
			}
		}
	}
	if (n > 1)
	{
		z = Count(n);
		if (f == 0)
		{
			min = z;
		}
		else
		{
			min = MIN(min, z);
		}
	}
	printf("%lld\n", min);
}
int main()
{
	Table();
	while (scanf("%lld%lld", &N, &B) == 2)
	{
		if (!N && !B)
		{
			break;
		}
		Cal();
	}
	return 0;
}
