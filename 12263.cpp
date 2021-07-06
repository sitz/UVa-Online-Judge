#include <bits/stdc++.h>

using namespace std;

int s[505][505], in[505], a[505], ans[505], use[505];

int main()
{
	int T, N, n, M, m, i, j, x, y;
	scanf(" %d", &T);
	while (T--)
	{
		scanf(" %d", &N);
		for (n = 0; n < N; n++)
			scanf(" %d", &a[n]);
		memset(s, 0, sizeof(s));
		memset(in, 0, sizeof(in));
		for (i = 0; i < N; i++)
			for (j = i + 1; j < N; j++)
				s[a[i]][a[j]] = 1;
		scanf(" %d", &M);
		for (m = 0; m < M; m++)
		{
			scanf(" %d %d", &i, &j);
			for (n = 0; n < N; n++)
			{
				if (a[n] == i)
					x = n;
				else if (a[n] == j)
					y = n;
			}
			if (x < y)
			{
				s[i][j] = 0;
				s[j][i] = 1;
			}
			else
			{
				s[j][i] = 0;
				s[i][j] = 1;
			}
		}
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				if (s[i][j] == 1)
					in[j]++;
		int c = 0;
		memset(use, 0, sizeof(use));
		while (c < N)
		{
			vector<int> v;
			v.clear();
			for (i = 1; i <= N; i++)
				if (in[i] == 0 && use[i] == 0)
				{
					v.push_back(i);
					use[i] = 1;
				}
			if (v.size() == 0)
				break;
			else if (v.size() == 1)
				ans[c++] = v[0];
			else
				for (i = 0; i < v.size(); i++)
					ans[c++] = -1;
			for (i = 0; i < v.size(); i++)
			{
				x = v[i];
				for (j = 1; j <= N; j++)
					if (s[x][j] == 1)
					{
						s[x][j] = 0;
						in[j]--;
					}
			}
		}
		if (c == N)
		{
			for (i = 0; i < N; i++)
			{
				if (i == 0)
				{
					if (ans[i] == -1)
						printf("?");
					else
						printf("%d", ans[i]);
				}
				else
				{
					if (ans[i] == -1)
						printf(" ?");
					else
						printf(" %d", ans[i]);
				}
			}
			printf("\n");
		}
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
