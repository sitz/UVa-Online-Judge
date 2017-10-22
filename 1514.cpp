#include <bits/stdc++.h>

using namespace std;

struct node
{
	int v, pre;
} edge[1000000];
int pos[300000], nEdge;
int W[600][600], B[600][600];
void connect(int u, int v)
{
	edge[nEdge].pre = pos[u];
	edge[nEdge].v = v;
	pos[u] = nEdge++;
}
int vis[300000];
int link1[300000];
char str[600][600];
int m, n;
int shuang;
inline bool find(int k)
{
	int i;
	for (int p = pos[k]; p != -1; p = edge[p].pre)
	{
		int v = edge[p].v;
		if (vis[v] == shuang)
			continue;
		vis[v] = shuang;
		if (link1[v] == -1 || find(link1[v]))
		{
			link1[v] = k;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		nEdge = 0;
		scanf("%d%d", &n, &m);
		int num = 0, flag = 0;
		for (int i = 0; i < n; i++)
			scanf("%s", str[i]);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (str[i][j] == 'B')
					B[i][j] = ++num;
				else if (str[i][j] == 'W')
					W[i][j] = ++flag;

		if (num * 2 != flag)
		{
			puts("NO");
			continue;
		}

		memset(link1, -1, sizeof(link1));
		memset(pos, -1, sizeof(pos));
		memset(vis, -1, sizeof(vis));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (str[i][j] == 'B')
				{
					if (str[i + 1][j] == 'W')
						connect(B[i][j], W[i + 1][j]);

					if (str[i - 1][j] == 'W')
						connect(B[i][j], W[i - 1][j]);

					if (str[i][j + 1] == 'W')
						connect(B[i][j] + num, W[i][j + 1]);

					if (str[i][j - 1] == 'W')
						connect(B[i][j] + num, W[i][j - 1]);
				}
		int ans = 0;
		shuang = 0;
		for (int i = 1; i <= num * 2; i++)
		{
			shuang++;
			if (find(i))
				ans++;
			else
				break;
		}
		if (ans == 2 * num)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
