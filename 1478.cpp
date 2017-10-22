#include <bits/stdc++.h>

using namespace std;

#define N 100001
#define M 25
#define Mod 100000000
#define INF 2000000007

int n, m;

struct _int
{
	long long d[10001];
	int len;
	_int()
	{
		len = 1;
		memset(d, 0, sizeof(d));
	}
	void multiply(long long x)
	{
		for (int i = 1; i <= len; ++i)
		{
			d[i] *= x;
		}
		for (int i = 1; i <= len; ++i)
		{
			d[i + 1] += d[i] / Mod, d[i] %= Mod;
		}
		while (d[len + 1])
		{
			++len;
		}
	}
	void divid(long long x)
	{
		for (int i = len; i >= 1; --i)
		{
			d[i - 1] += (d[i] % x) * Mod;
			d[i] /= x;
		}
		while (len > 1 && d[len] == 0)
		{
			--len;
		}
	}
	void add(_int x)
	{
		if (x.len > len)
		{
			len = x.len;
		}
		if (len > 14)
		{
			len = 14;
		}
		for (int i = 1; i <= len; ++i)
		{
			d[i] += x.d[i];
		}
		for (int i = 1; i <= len; ++i)
		{
			d[i + 1] += d[i] / Mod, d[i] %= Mod;
		}
		if (d[len + 1])
		{
			++len;
		}
	}
	void print()
	{
		len = 13;
		d[len] %= 10000;
		while (len > 1 && d[len] == 0)
		{
			--len;
		}
		printf("%lld", d[len]);
		for (int i = len - 1; i >= 1; --i)
		{
			if (d[i] < 10000000)
			{
				printf("0");
			}
			if (d[i] < 1000000)
			{
				printf("0");
			}
			if (d[i] < 100000)
			{
				printf("0");
			}
			if (d[i] < 10000)
			{
				printf("0");
			}
			if (d[i] < 1000)
			{
				printf("0");
			}
			if (d[i] < 100)
			{
				printf("0");
			}
			if (d[i] < 10)
			{
				printf("0");
			}
			printf("%lld", d[i]);
		}
		printf("\n");
	}
};

void Solve()
{
	int i, j, k;
	_int ans, x;
	x.d[1] = 1;
	ans.add(x);
	for (i = 1; i <= n / 2; ++i)
	{
		x.multiply(1ll * (n - 2 * i + 1) * (n - 2 * i + 2));
		x.divid(1ll * (i + 1) * i);
		ans.add(x);
	}
	ans.print();
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		Solve();
	}
	return 0;
}
