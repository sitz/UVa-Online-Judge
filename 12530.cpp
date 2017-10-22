#include <bits/stdc++.h>

using namespace std;

char s[55][55];
int id[55][55], head[3000], nxt[20005], v[20005], mat[3000], vis[3000], t, c;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void add(int x, int y)
{
	v[c] = y;
	nxt[c] = head[x];
	head[x] = c++;
}

int dfs(int u)
{
	int i;
	for (i = head[u]; i != -1; i = nxt[i])
		if (!vis[v[i]])
		{
			int x = v[i];
			vis[x] = 1;
			if (mat[x] == -1 || dfs(mat[x]))
			{
				mat[x] = u;
				mat[u] = x;
				return 1;
			}
		}
	return 0;
}

int main()
{
	int n, m, i, j;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		t = c = 0;
		memset(head, -1, sizeof(head));
		for (i = 0; i < n; i++)
		{
			scanf("%s", s[i]);
		}
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (s[i][j] == '.')
				{
					id[i][j] = ++t;
				}
		if (t & 1)
		{
			puts("1");
			continue;
		}
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (s[i][j] == '.')
				{
					int x = id[i][j];
					for (int d = 0; d < 4; d++)
					{
						int xx = i + dx[d];
						int yy = j + dy[d];
						if (xx >= 0 && xx < n && yy >= 0 && yy < m && s[xx][yy] == '.')
						{
							int y = id[xx][yy];
							add(x, y);
						}
					}
				}
		memset(mat, -1, sizeof(mat));
		int f = 1;
		for (i = 1; i <= t; i++)
		{
			if (mat[i] != -1)
			{
				continue;
			}
			memset(vis, 0, sizeof(vis));
			if (dfs(i) == 0)
			{
				f = 0;
				break;
			}
		}
		if (f)
		{
			puts("2");
		}
		else
		{
			puts("1");
		}
	}
	return 0;
}
