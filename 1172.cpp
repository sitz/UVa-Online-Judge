#include <bits/stdc++.h>

using namespace std;

#define SZ 1002

map<string, int> Map;
char col[SZ][SZ];
int dp[SZ][SZ];
int cnt[SZ][SZ];
int value1[SZ], value2[SZ];
int mark1[SZ], mark2[SZ];
int N, M;

void check(int a, int b, int c, int d, int e, int f, int g)
{
	if ((dp[a][b] + f + g > dp[c][d]) || (dp[a][b] + f + g == dp[c][d] && cnt[a][b] + e < cnt[c][d]))
	{
		dp[c][d] = dp[a][b] + f + g;
		cnt[c][d] = cnt[a][b] + e;
	}
}

void solve(int indx1, int indx2)
{
	if (indx1 == N || indx2 == M)
	{
		return;
	}
	if (col[indx1][indx2])
	{
		return;
	}
	col[indx1][indx2] = 1;
	solve(indx1 + 1, indx2);
	check(indx1 + 1, indx2, indx1, indx2, 0, 0, 0);
	solve(indx1, indx2 + 1);
	check(indx1, indx2 + 1, indx1, indx2, 0, 0, 0);
	if (mark1[indx1] == mark2[indx2])
	{
		solve(indx1 + 1, indx2 + 1);
		check(indx1 + 1, indx2 + 1, indx1, indx2, 1, value1[indx1], value2[indx2]);
	}
	return;
}

int main()
{
	char arr[20];
	int i, j, t;
	scanf("%d", &t);
	while (t--)
	{
		Map.clear();
		scanf("%d", &N);
		j = 0;
		for (i = 0; i < N; i++)
		{
			scanf("%s %s %d", arr, arr, &value1[i]);
			if (Map.find(arr) == Map.end())
			{
				Map[arr] = j++;
			}
			mark1[i] = Map[arr];
		}
		scanf("%d", &M);
		for (i = 0; i < M; i++)
		{
			scanf("%s %s %d", arr, arr, &value2[i]);
			if (Map.find(arr) == Map.end())
			{
				Map[arr] = j++;
			}
			mark2[i] = Map[arr];
		}
		for (i = 0; i <= N; i++)
			for (j = 0; j <= M; j++)
			{
				col[i][j] = 0, dp[i][j] = 0, cnt[i][j] = 0;
			}
		solve(0, 0);
		printf("%d %d\n", dp[0][0], cnt[0][0]);
	}
	return 0;
}
