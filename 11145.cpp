#include <bits/stdc++.h>

using namespace std;

//ifstream fin("f.in");
//ofstream fout("f.out");
#define fin cin
#define fout cout

struct Edge
{
	int h, t;
	double c;

	Edge(int h = -1, int t = -1, double c = -1.0) : h(h), t(t), c(c) {}

	bool operator()(const Edge &a, const Edge &b) const
	{
		return a.c > b.c;
	}
};

int n, m;
vector<bool> mark;
vector<Edge> e;
vector<vector<int>> adj;

bool dfs(int s, int t)
{
	if (s == t)
	{
		return true;
	}
	mark[s] = true;
	for (int i = 0; i < (int)adj[s].size(); i++)
		if (!mark[adj[s][i]] && dfs(adj[s][i], t))
		{
			return true;
		}
	return false;
}

main()
{
	fout.precision(4);
	fout.setf(ios::fixed | ios::showpoint);
	int tn;
	for (fin >> tn; tn--;)
	{
		fin >> n >> m;
		e = vector<Edge>(m, Edge());
		adj = vector<vector<int>>(n, vector<int>());
		for (int i = 0; i < m; i++)
		{
			int h, t;
			double c;
			fin >> h >> t >> c;
			h--;
			t--;
			e[i] = Edge(h, t, c);
			adj[h].push_back(t);
		}
		sort(e.begin(), e.end(), Edge());
		double ans = 0;
		for (int i = 0; i < (int)e.size(); i++)
		{
			adj[e[i].h].erase(find(adj[e[i].h].begin(), adj[e[i].h].end(), e[i].t));
			mark = vector<bool>(n, false);
			if (!dfs(e[i].h, e[i].t))
			{
				adj[e[i].h].push_back(e[i].t);
				adj[e[i].t].push_back(e[i].h);
			}
			else
			{
				adj[e[i].h].push_back(e[i].t);
				ans += e[i].c;
			}
		}
		fout << ans << endl;
	}
	return 0;
}
