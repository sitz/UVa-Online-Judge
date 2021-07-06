#include <bits/stdc++.h>

using namespace std;

const int N = 220;
const int oo = 0x7fffffff;
int w[N][N], x[N], y[N], px[N], py[N], sy[N], slack[N], par[N];
int n[2];
vector<int> edge[2][N];
int stamp, vis[N][N], f[N][N];
void adjust(int v)
{
	sy[v] = py[v];
	if (px[sy[v]] != -2)
	{
		adjust(px[sy[v]]);
	}
}
bool find(int v, int n)
{
	int i;
	for (int i = 0; i < n; ++i)
	{
		if (py[i] == -1)
		{
			if (slack[i] > x[v] + y[i] - w[v][i])
			{
				slack[i] = x[v] + y[i] - w[v][i];
				par[i] = v;
			}
			if (x[v] + y[i] == w[v][i])
			{
				py[i] = v;
				if (sy[i] == -1)
				{
					adjust(i);
					return 1;
				}
				if (px[sy[i]] != -1)
				{
					continue;
				}
				px[sy[i]] = i;
				if (find(sy[i], n))
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
int km(int n0, int m0)
{
	int i, j, n, m;
	n = max(n0, m0);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i >= n0 || j >= m0)
			{
				w[i][j] = 0;
			}
		}
	}
	/*
	printf("\n");
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				printf("%d ", w[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	*/
	for (i = 0; i < n; ++i)
	{
		sy[i] = -1, y[i] = 0;
	}
	for (i = 0; i < n; ++i)
	{
		x[i] = 0;
		for (j = 0; j < n; ++j)
		{
			x[i] = max(x[i], w[i][j]);
		}
	}
	bool flag;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			px[j] = py[j] = -1, slack[j] = oo;
		}
		px[i] = -2;
		if (find(i, n))
		{
			continue;
		}
		flag = false;
		for (; !flag;)
		{
			m = oo;
			for (j = 0; j < n; ++j)
				if (py[j] == -1)
				{
					m = min(m, slack[j]);
				}
			for (j = 0; j < n; ++j)
			{
				if (px[j] != -1)
				{
					x[j] -= m;
				}
				if (py[j] != -1)
				{
					y[j] += m;
				}
				else
				{
					slack[j] -= m;
				}
			}
			for (j = 0; j < n; ++j)
			{
				if (py[j] == -1 && !slack[j])
				{
					py[j] = par[j];
					if (sy[j] == -1)
					{
						adjust(j);
						flag = true;
						break;
					}
					px[sy[j]] = j;
					if (find(sy[j], n))
					{
						flag = true;
						break;
					}
				}
			}
		}
	}
	int ans = 0;
	for (i = 0; i < n; ++i)
	{
		ans += w[sy[i]][i];
	}
	return ans;
}
int cal(int u, int v)
{
	//printf("%d %d\n",u,v);
	if (vis[u][v] == stamp)
	{
		return f[u][v];
	}
	vis[u][v] = stamp;
	if (min(edge[0][u].size(), edge[1][v].size()) == 0)
	{
		f[u][v] = 1;
	}
	else
	{
		for (int i = 0; i < edge[0][u].size(); ++i)
		{
			int a = edge[0][u][i];
			for (int j = 0; j < edge[1][v].size(); ++j)
			{
				int b = edge[1][v][j];
				cal(a, b);
			}
		}
		for (int i = 0; i < edge[0][u].size(); ++i)
		{
			int a = edge[0][u][i];
			for (int j = 0; j < edge[1][v].size(); ++j)
			{
				int b = edge[1][v][j];
				w[i][j] = cal(a, b);
			}
		}
		f[u][v] = km(edge[0][u].size(), edge[1][v].size()) + 1;
	}
	return f[u][v];
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		for (int i = 0; i < 2; ++i)
		{
			scanf("%d", &n[i]);
			n[i]++;
			for (int j = 0; j < n[i]; ++j)
			{
				edge[i][j].clear();
			}
			for (int j = 1; j < n[i]; ++j)
			{
				int fa;
				scanf("%d", &fa);
				edge[i][fa].push_back(j);
			}
		}
		++stamp;
		static int id = 0;
		printf("Case %d: %d\n", ++id, (n[0] + n[1]) - 2 * cal(0, 0));
	}
	return 0;
}
