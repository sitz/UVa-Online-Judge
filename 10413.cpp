#include <bits/stdc++.h>

using namespace std;

int t, n, m, c[15], p[15], l[15];
int EGCD(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		int d = EGCD(b, a % b, x, y), t = x;
		x = y;
		y = t - (a / b) * y;
		return d;
	}
}
int min(int a, int b)
{
	return (a < b) ? a : b;
}
int solve(int ci, int pi, int cj, int pj, int n)
{
	int a = pi - pj, b = cj - ci;
	if (a < 0)
	{
		a = -a;
		b = -b;
	}
	int x, y, base, period;
	int d = EGCD(a, n, x, y);
	if (b % d != 0)
	{
		return 99999999;
	}
	base = (x * (b / d)) % n;
	period = n / d;
	if (base < 0)
	{
		return base + (int)(ceil(-base / (double)period)) * period;
	}
	else
	{
		return base - (int)(floor(base / (double)period)) * period;
	}
}
int main()
{
	scanf("%d", &t);
	for (; t; t--)
	{
		bool flag = false;
		scanf("%d", &n);
		m = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d %d", &c[i], &p[i], &l[i]);
			if (c[i] > m)
			{
				m = c[i];
			}
		}
		for (; m <= 1000000; m++)
		{
			flag = true;
			for (int i = 0; i < n && flag; i++)
				for (int j = i + 1; j < n && flag; j++)
					if (solve(c[i], p[i], c[j], p[j], m) <= min(l[i], l[j]))
					{
						flag = false;
					}
			if (flag)
			{
				break;
			}
		}
		printf("%d\n", m);
	}
	return 0;
}
