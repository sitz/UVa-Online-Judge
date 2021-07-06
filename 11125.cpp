#include <bits/stdc++.h>

using namespace std;

#define MAXD 1100000
int f[MAXD], a[5], b[5];
int dp(int state)
{
	int i, j, k, t, st = state, ans = 0, fc, fn, pc, pn;
	if (f[state] != -1)
	{
		return f[state];
	}
	fc = st % 4, st /= 4;
	fn = st % 4, st /= 4;
	pc = st % 4, st /= 4;
	pn = st % 4, st /= 4;
	k = 0;
	for (i = 0; i < 4; i++)
	{
		b[i] = st % 8, st /= 8;
		k += b[i];
	}
	if (k == 0)
	{
		if (pc == fc && pn == fn)
		{
			return f[state] = 1;
		}
		else
		{
			return f[state] = 0;
		}
	}
	for (i = 0; i < 4; i++)
	{
		if (i == pc)
		{
			continue;
		}
		for (j = 1; j <= 3 && j <= b[i]; j++)
		{
			if (j == pn)
			{
				continue;
			}
			b[i] -= j;
			for (k = 3, t = 0; k >= 0; k--)
			{
				t = t * 8 + b[k];
			}
			t = (((t * 4 + j) * 4 + i) * 4 + fn) * 4 + fc;
			ans += dp(t);
			b[i] += j;
		}
	}
	return f[state] = ans;
}
void solve()
{
	int i, j, k, n, res, t;
	memset(a, 0, sizeof(a));
	scanf("%d", &n);
	k = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		k += a[i];
	}
	if (!k)
	{
		printf("1\n");
		return;
	}
	for (i = 3, k = 0; i >= 0; i--)
	{
		k = k * 8 + a[i];
	}
	res = 0;
	for (i = 0; i < n; i++)
		for (j = 1; j <= 3 && j <= a[i]; j++)
		{
			t = (((k * 4 + j) * 4 + i) * 4 + j) * 4 + i;
			res += dp(t);
		}
	printf("%d\n", res);
}
int main()
{
	int t;
	memset(f, -1, sizeof(f));
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
	return 0;
}
