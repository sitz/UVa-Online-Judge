#include <bits/stdc++.h>

using namespace std;

char grid[21][21], ng[21][21], bg[21][21];
int p[4];
int par[21 * 21], d[21 * 21];
int dd[5] = {1, 0, -1, 0, 1};
int n, m;
struct ds
{
	bool operator()(int a, int b)
	{
		return (d[a] == d[b] ? a < b : d[a] < d[b]);
	}
};
int bfs(int s, int t)
{
	memset(par, -1, sizeof par);
	memset(d, -1, sizeof d);
	par[s] = s;
	d[s] = 0;
	set<int, ds> q;
	q.insert(s);
	while (q.size())
	{
		int next = *q.begin();
		q.erase(q.begin());
		if (next == t)
		{
			break;
		}
		for (int k = 0; k < 4; k++)
		{
			int ni = next / 21 + dd[k], nj = next % 21 + dd[k + 1];
			if (ni >= n || ni < 0 || nj >= m || nj < 0 || ng[ni][nj] == '#')
			{
				continue;
			}
			int nd = d[next] + (ng[ni][nj] == 'o');
			if (d[ni * 21 + nj] == -1 || nd < d[ni * 21 + nj])
			{
				par[ni * 21 + nj] = next;
				q.erase(ni * 21 + nj);
				d[ni * 21 + nj] = nd;
				q.insert(ni * 21 + nj);
			}
		}
	}
	return d[t];
}
int main()
{
	bool first = true;
	while (cin >> m >> n)
	{
		if (first)
		{
			first = false;
		}
		else
		{
			cout << endl;
		}
		cout << m << " " << n << endl;
		if (!m)
		{
			break;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> grid[i][j];
				if (grid[i][j] >= 'A' && grid[i][j] <= 'D')
				{
					p[grid[i][j] - 'A'] = i * 21 + j;
				}
			}
		int best = 1000000;
		for (int a = 0; a < 4; a++)
			for (int b = a + 1; b < 4; b++)
				for (int c = 0; c < 4; c++)
					for (int d = c + 1; d < 4; d++)
						for (int e = 0; e < 4; e++)
							for (int f = e + 1; f < 4; f++)
							{
								bool good = true;
								for (int g = 0; g < 4; g++)
									if (g != a && g != b && g != c && g != d && g != e && g != f)
									{
										good = false;
									}
								if (!good)
								{
									continue;
								}
								if (a == c && b == d || a == e && b == f || c == e && d == f)
								{
									continue;
								}
								for (int i = 0; i < n; i++)
									for (int j = 0; j < m; j++)
									{
										ng[i][j] = grid[i][j];
									}
								bfs(p[a], p[b]);
								int cur = par[p[b]];
								while (cur != p[a])
								{
									if (ng[cur / 21][cur % 21] == 'o')
									{
										ng[cur / 21][cur % 21] = '.';
									}
									cur = par[cur];
								}
								bfs(p[c], p[d]);
								cur = par[p[d]];
								while (cur != p[c])
								{
									if (ng[cur / 21][cur % 21] == 'o')
									{
										ng[cur / 21][cur % 21] = '.';
									}
									cur = par[cur];
								}
								bfs(p[e], p[f]);
								cur = par[p[f]];
								while (cur != p[e])
								{
									if (ng[cur / 21][cur % 21] == 'o')
									{
										ng[cur / 21][cur % 21] = '.';
									}
									cur = par[cur];
								}
								int diff = 0;
								for (int i = 0; i < n; i++)
									for (int j = 0; j < m; j++)
										if (ng[i][j] != grid[i][j])
										{
											diff++;
										}
								if (diff < best)
								{
									best = diff;
									for (int i = 0; i < n; i++)
										for (int j = 0; j < m; j++)
										{
											bg[i][j] = ng[i][j];
										}
								}
							}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << bg[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
