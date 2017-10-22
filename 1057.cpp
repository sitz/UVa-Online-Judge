#include <bits/stdc++.h>

using namespace std;

const int MaxN = 110;

int dis[MaxN][MaxN];
int dp[MaxN][MaxN];
int N, M;

int solve()
{
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 1;
	priority_queue<pair<int, int>> pQ;
	pQ.push(make_pair(-1, 0));
	while (!pQ.empty())
	{
		int d = -pQ.top().first;
		int a = pQ.top().second / N;
		int b = pQ.top().second % N;
		pQ.pop();
		if (d != dp[a][b])
		{
			continue;
		}
		if (a != b && dp[b][a] > dp[a][b] + dis[b][a] - 1)
		{
			dp[b][a] = dp[a][b] + dis[b][a] - 1;
			pQ.push(make_pair(-dp[b][a], b * N + a));
		}
		for (int i = 0; i < N; i++)
			if (dis[i][a] == 1 && dp[i][b] > dp[a][b] + (i != b))
			{
				dp[i][b] = dp[a][b] + (i != b);
				pQ.push(make_pair(-dp[i][b], i * N + b));
			}
		for (int i = 0; i < N; i++)
			if (dis[b][i] == 1 && dp[a][i] > dp[a][b] + (a != i))
			{
				dp[a][i] = dp[a][b] + (a != i);
				pQ.push(make_pair(-dp[a][i], a * N + i));
			}
	}
	return dp[1][1];
}

int main()
{
	int cas = 0;
	while (cin >> N >> M, N || M)
	{
		memset(dis, 0x3f, sizeof(dis));
		while (M--)
		{
			int a, b;
			cin >> a >> b;
			dis[--a][--b] = 1;
		}
		for (int k = 0; k < N; k++)
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
				{
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
		int ans = solve();
		printf("Network %d\n", ++cas);
		if (ans <= N)
		{
			printf("Minimum number of nodes = %d\n", ans);
		}
		else
		{
			puts("Impossible");
		}
		puts("");
	}
	return 0;
}
