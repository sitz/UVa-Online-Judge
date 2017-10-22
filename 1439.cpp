#include <bits/stdc++.h>

using namespace std;

#define MAXN 128
#define MAXM 15
#define INF 0x3f3f3f3f

// min vertex color O(3^n)
int main()
{
	char R1[MAXN][8], R2[MAXN][8];
	int N, M;
	while (scanf("%d", &N) == 1 && N)
	{
		map<char, int> R;
		for (int i = 0; i < N; i++)
		{
			scanf("%s %s", R1[i], R2[i]);
			R[R1[i][0]] = R[R2[i][0]] = 1;
		}
		M = 0;
		for (map<char, int>::iterator it = R.begin(); it != R.end(); it++)
		{
			it->second = M++;
		}
		int maskg[MAXM] = {}, self_edge[1 << MAXM];
		for (int i = 0; i < N; i++)
		{
			int x = R[R1[i][0]], y = R[R2[i][0]];
			maskg[x] |= 1 << y, maskg[y] |= 1 << x;
		}
		for (int i = 0; i < (1 << M); i++)
		{
			int ok = 1;
			for (int j = 0; j < M; j++)
			{
				if ((i >> j) & 1)
				{
					ok &= (i & maskg[j]) == 0;
				}
			}
			self_edge[i] = ok;
		}
		int dp[1 << MAXM] = {}, from[1 << MAXM];
		dp[0] = 0;
		for (int i = 1; i < (1 << M); i++)
		{
			dp[i] = INF;
			for (int j = i; j; j = (j - 1) & i)
			{
				if (self_edge[j])
				{
					if (dp[i - j] + 1 < dp[i])
					{
						dp[i] = dp[i - j] + 1;
						from[i] = i - j;
					}
				}
			}
		}
		int color[MAXM] = {};
		for (int c = 1, i = (1 << M) - 1; i; c++, i = from[i])
		{
			int lvl = i ^ (from[i]);
			for (int j = 0; j < M; j++)
			{
				if ((lvl >> j) & 1)
				{
					color[j] = c;
				}
			}
		}
		printf("%d\n", dp[(1 << M) - 1] - 2);
		for (int i = 0; i < N; i++)
		{
			int x = color[R[R1[i][0]]], y = color[R[R2[i][0]]];
			if (x > y)
			{
				printf("%s %s\n", R1[i], R2[i]);
			}
			else
			{
				printf("%s %s\n", R2[i], R1[i]);
			}
		}
	}
	return 0;
}
