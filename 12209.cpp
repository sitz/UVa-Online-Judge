#include <bits/stdc++.h>

using namespace std;

int dp[505][505], c[105], dpp[505], in[505];
vector<int> v[505];

int main()
{
	int T, t, i, j, k, K, N, n, W, w, S, s, x, y;
	scanf(" %d", &T);
	for (t = 0; t < T; t++)
	{
		scanf(" %d %d %d", &N, &S, &W);
		for (i = 0; i <= N; i++)
			for (j = 0; j <= N; j++)
			{
				dp[i][j] = 1e9;
			}
		for (i = 0; i <= N; i++)
		{
			v[i].clear();
		}
		for (w = 0; w < W; w++)
		{
			scanf(" %d", &K);
			for (k = 0; k < K; k++)
			{
				scanf(" %d", &i);
				v[i].push_back(w);
			}
		}
		for (i = 1; i <= N; i++)
		{
			memset(c, 0, sizeof(c));
			int all = 0;
			for (j = i; j <= i + S && j <= N; j++)
			{
				for (k = 0; k < v[j].size(); k++)
				{
					if (c[v[j][k]] == 0)
					{
						c[v[j][k]] = 1;
						all++;
					}
				}
				if (j - i + 1 + all <= S)
				{
					dp[i][j] = all;
				}
				else
				{
					break;
				}
			}
		}
		for (i = 0; i <= N; i++)
		{
			dpp[i] = 1e9;
		}
		dpp[0] = 0;
		queue<int> q;
		q.push(0);
		memset(in, 0, sizeof(in));
		while (!q.empty())
		{
			x = q.front();
			q.pop();
			in[x] = 0;
			if (x == N)
			{
				continue;
			}
			for (i = x + 1; i <= x + S && i <= N; i++)
			{
				if ((dpp[x] + dp[x + 1][i] < dpp[i]) && (i - x + dp[x + 1][i] <= S))
				{
					dpp[i] = dpp[x] + dp[x + 1][i];
					if (in[i] == 0)
					{
						in[i] = 1;
						q.push(i);
					}
				}
			}
		}
		if (dpp[N] == 1e9)
		{
			printf("Case %d: -1\n", t + 1);
		}
		else
		{
			printf("Case %d: %d\n", t + 1, dpp[N]);
		}
	}
	return 0;
}
