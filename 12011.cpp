#include <bits/stdc++.h>

using namespace std;

#define M 18

int v[1 << M];
int has[M + 5], must[M + 5], f[M + 5];

int main()
{
	int t, cc = 0, n, i, j, all;
	f[0] = 1;
	for (i = 1; i <= M; i++)
	{
		f[i] = f[i - 1] << 1;
	}
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		all = f[M] - 1;
		for (i = 0; i < n; i++)
		{
			scanf("%d", v + i), all &= v[i];
		}
		int mx = 0;
		memset(has, 0, sizeof(has));
		for (i = 0; i < M; i++)
		{
			int tp = f[M] - 1;
			for (j = 0; j < n; j++)
				if (f[i] & v[j])
				{
					tp &= v[j], has[i] = 1;
				}
			must[i] = tp;
			if (has[i])
			{
				mx = i;
			}
		}
		int ret = 0;
		for (i = f[mx + 1]; i > 0; i--)
		{
			for (j = 0; j < M; j++)
				if (i & f[j])
				{
					if (!has[j])
					{
						break;
					}
					if ((i & must[j]) != must[j])
					{
						break;
					}
				}
			if (j >= M)
			{
				++ret;
			}
		}
		if (all == 0)
		{
			++ret;
		}
		printf("Case #%d: %d\n", ++cc, ret - n);
	}
	return 0;
}
