#include <bits/stdc++.h>

using namespace std;

int d[1002], p[1002], n[1002];
int N;
int DP[1001][201];

int main()
{
	int t, i, j, l;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &N);
		n[0] = 0;
		for (i = 1; i <= N; i++)
			scanf("%d %d %d", &p[i], &n[i], &d[i]);
		for (i = 0; i <= N; i++)
			for (j = 0; j < 201; j++)
				DP[i][j] = 10000000;
		DP[1][0] = d[1] * p[1];
		for (i = 1; i < N; i++)
			for (j = 0; j < 201 && j <= n[i]; j++)
				for (l = 0; l < 201 && l <= n[i - 1]; l++)
				{
					int ans = j * p[i] + max(0, d[i + 1] - j) * p[i + 1] + DP[i][l];
					if (j + max(0, d[i] - l) > n[i])
						continue;
					if (d[i + 1] - j > n[i + 1])
						continue;
					DP[i + 1][j] = min(DP[i + 1][j], ans);
				}
		int bs = 10000000;
		for (j = 0; j < 201 && j <= n[N - 1]; j++)
			bs = min(bs, DP[N][j]);
		printf("%d\n", bs);
	}
}
