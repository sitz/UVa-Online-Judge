#include <bits/stdc++.h>

using namespace std;

long long GCD(long long a, long long b)
{
	return (b == 0) ? a : GCD(b, a % b);
}
long long a[10], b[10], ans;
int n, depth;
void DFS(int d, int start, long s)
{
	if (d == depth)
	{
		if (d % 2)
		{
			ans += s;
		}
		else
		{
			ans -= s;
		}
	}
	else
	{
		for (int i = start; i < n; i++)
		{
			DFS(d + 1, i + 1, (d == 0) ? a[i] : GCD(s, a[i]));
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int caseno = 1; caseno <= t; caseno++)
	{
		scanf("%d", &n);
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", a + i);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", b + i);
		}
		for (int i = 0; i < n; i++)
		{
			a[i] -= b[i];
			if (a[i] == 0)
			{
				ans = -1;
			}
			if (a[i] < 0)
			{
				a[i] = -a[i];
			}
		}
		printf("Case %d: ", caseno);
		if (ans == -1)
		{
			puts("0");
			continue;
		}
		for (depth = 1; depth <= n; depth++)
		{
			DFS(0, 0, 0);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
