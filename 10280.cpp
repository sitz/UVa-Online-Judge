#include <bits/stdc++.h>

using namespace std;

#define MAXD 4600
#define MAXL 450000
#define MAXN 110
#define MAXn 18000
#define INF 0x3f3f3f3f

int L, N, min_[MAXN], max_[MAXN], f[MAXL], vis[MAXD], v[MAXn];

void solve()
{
	int i, j, k, n, limit;
	scanf("%d%d", &L, &N);
	L *= 1000;
	limit = INF;
	for (i = 0; i < N; i++)
	{
		scanf("%d%d", &min_[i], &max_[i]);
		if (min_[i] * min_[i] / (max_[i] - min_[i]) < limit)
		{
			limit = min_[i] * min_[i] / (max_[i] - min_[i]);
		}
	}
	if (L > limit)
	{
		printf("0\n");
		return;
	}
	n = 0;
	memset(vis, 0, sizeof(vis));
	for (i = 0; i < N; i++)
		for (j = min_[i]; j <= max_[i]; j++)
			if (!vis[j])
			{
				vis[j] = 1;
				v[n++] = j;
			}
	memset(f, 0, sizeof(f));
	for (i = 0; i < n; i++)
		for (j = v[i]; j <= L; j++)
			if (f[j - v[i]] + v[i] > f[j])
			{
				f[j] = f[j - v[i]] + v[i];
			}
	printf("%d\n", L - f[L]);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
		if (t)
		{
			printf("\n");
		}
	}
	return 0;
}
