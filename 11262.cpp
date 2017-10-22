#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 3;

struct Edge
{
	double cost;
	int dst;
	Edge() {}
	Edge(int d, double c) : cost(c), dst(d) {}
};

vector<Edge> g[N];
const int src = N - 1;
const int dst = N - 2;

bool f[N][N];

int path[N];

const double eps = 1e-11;

inline bool eq(double a, double b)
{
	return fabs(a - b) < eps;
}

inline bool lessThan(double a, double b)
{
	return !eq(a, b) && a < b;
}

inline bool greaterThan(double a, double b)
{
	return !eq(a, b) && a < b;
}

int bfs(int lim)
{
	static int p[N];
	static bool vis[N];
	queue<int> q;
	fill(vis, vis + N, false);
	fill(p, p + N, -1);
	vis[src] = true;
	for (q.push(src); q.size(); q.pop())
	{
		int n = q.front();
		for (int i = 0; i < g[n].size(); ++i)
		{
			int m = g[n][i].dst;
			if (vis[m])
			{
				continue;
			}
			if (!f[n][m])
			{
				continue;
			}
			if (lessThan(lim, g[n][i].cost))
			{
				continue;
			}
			vis[m] = true;
			q.push(m);
			p[m] = n;
		}
	}
	if (!vis[dst])
	{
		return 0;
	}
	int size = 0;
	for (int i = dst; i != -1; i = p[i])
	{
		path[size++] = i;
	}
	reverse(path, path + size);
	return size;
}

int flow(int lim)
{
	static bool tmp[N][N];
	copy(&f[0][0], &f[N - 1][N], &tmp[0][0]);
	int sum = 0;
	for (int size; size = bfs(lim); ++sum)
	{
		for (int i = 0; i + 1 < size; ++i)
		{
			f[path[i]][path[i + 1]] = false;
			f[path[i + 1]][path[i]] = true;
		}
	}
	copy(&tmp[0][0], &tmp[N - 1][N], &f[0][0]);
	return sum;
}

bool make_graph(int size, int m)
{
	pair<double, double> p[size];
	char color[size];
	fill(g, g + N, vector<Edge>());
	for (int i = 0; i < size; ++i)
	{
		string s;
		cin >> p[i].first >> p[i].second >> s;
		color[i] = s[0];
	}
	if (count(color, color + size, 'r') < m)
	{
		return false;
	}
	if (count(color, color + size, 'b') < m)
	{
		return false;
	}
	for (int i = 0; i < size; ++i)
	{
		if (color[i] == 'b')
		{
			continue;
		}
		for (int j = 0; j < size; ++j)
		{
			if (color[j] == 'r')
			{
				continue;
			}
			double a = p[i].first - p[j].first;
			double b = p[i].second - p[j].second;
			double c = sqrt(a * a + b * b);
			f[i][j] = true;
			f[j][i] = false;
			g[i].push_back(Edge(j, c));
			g[j].push_back(Edge(i, c));
		}
	}
	for (int i = 0; i < size; ++i)
	{
		if (color[i] == 'r')
		{
			f[src][i] = true;
			g[src].push_back(Edge(i, 0));
		}
	}
	for (int i = 0; i < size; ++i)
	{
		if (color[i] == 'b')
		{
			f[i][dst] = true;
			g[i].push_back(Edge(dst, 0));
		}
	}
	return true;
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m;
		cin >> n >> m;
		if (!make_graph(n, m))
		{
			cout << "Impossible" << endl;
			continue;
		}
		int s = 1, b = 2000 * 2;
		while (s + 1 < b)
		{
			int c = (s + b) / 2;
			int f = flow(c);
			//cout << c << ' ' << (m <= f ? "T" : "F") << endl;
			if (m <= f)
			{
				b = c;
			}
			else
			{
				s = c;
			}
		}
		double mx = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < g[i].size(); ++j)
			{
				if (lessThan(b, g[i][j].cost))
				{
					continue;
				}
				mx = max(mx, g[i][j].cost);
			}
		}
		cout << (int)ceil(mx) << endl;
	}
	return 0;
}
