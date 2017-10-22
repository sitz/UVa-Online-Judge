#include <bits/stdc++.h>

using namespace std;

int vv[1005], kk[1005], cc[1005], ll[1005], pp[1005], dp[1005];

int comp(const void *p, const void *q)
{
	int a, b;
	a = *(int *)p;
	b = *(int *)q;
	if (vv[a] == vv[b])
	{
		return cc[b] - cc[a];
	}
	return vv[a] - vv[b];
}

int main()
{
	int n, i, j, temp, res;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i = 0; i < n; i++)
		{
			scanf("%d%d%d%d", &vv[i], &kk[i], &cc[i], &ll[i]);
			pp[i] = i;
		}
		qsort(pp, n, sizeof(int), comp);
		for (i = 0; i < n; i++)
		{
			dp[i] = 2147483647;
			for (j = i, temp = ll[pp[j]]; j >= 0; j--)
			{
				res = kk[pp[i]] + temp * cc[pp[i]];
				if (j)
				{
					res += dp[j - 1];
					temp += ll[pp[j - 1]];
				}
				if (res < dp[i])
				{
					dp[i] = res;
				}
			}
		}
		printf("%d\n", dp[n - 1]);
	}
	return 0;
}
