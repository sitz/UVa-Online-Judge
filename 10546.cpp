#include <bits/stdc++.h>

using namespace std;

char name[100][25];
int g[202][202], f[202][202], v[100], d[100], w[202], p[202], n, max_, source, dest;

bool findpath()
{
	for (int i = 0; i <= dest; i++)
	{
		w[i] = 99999999;
	}
	w[source] = 0;
	p[source] = -1;
	int queue[300], front = -1, rear = 0;
	queue[0] = source;
	while (front < rear)
	{
		int u = queue[++front];
		for (int v = 0; v <= dest; v++)
		{
			if (g[u][v] - f[u][v] > 0 && w[v] > w[u] + 1)
			{
				w[v] = w[u] + 1;
				p[v] = u;
				queue[++rear] = v;
			}
		}
	}
	return w[dest] != 99999999;
}
void update()
{
	int u, v = dest;
	do
	{
		u = p[v];
		f[u][v]++;
		f[v][u] = -f[u][v];
		v = u;
	} while (p[v] != -1);
}
int main()
{
	int caseno = 1;
	while (scanf("%d", &n), n)
	{
		max_ = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%s %d", name[i], &v[i]);
		}
		for (int i = 0; i < n; i++)
		{
			d[i] = 1;
			for (int j = i - 1; j >= 0; j--)
				if (v[j] < v[i] && d[j] + 1 > d[i])
				{
					d[i] = d[j] + 1;
				}
			if (d[i] > max_)
			{
				max_ = d[i];
			}
		}
		source = 0;
		dest = 2 * n + 1;
		memset(g, 0, sizeof(g));
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++)
		{
			g[i][i + n] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			if (d[i] == max_)
			{
				g[i + 1 + n][dest] = 1;
			}
			if (d[i] == 1)
			{
				g[source][i + 1] = 1;
			}
		}
		for (int s = 1; s < max_; s++)
			for (int i = 0; i < n; i++)
				if (d[i] == s)
				{
					for (int j = i + 1; j < n; j++)
						if (d[j] == s + 1 && v[i] < v[j])
						{
							g[i + 1 + n][j + 1] = 1;
						}
				}
		int path = 0;
		while (findpath())
		{
			update();
			path++;
		}
		printf("Case #%d: %d\n", caseno++, max_ * path);
	}
}
