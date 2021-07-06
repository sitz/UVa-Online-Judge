#include <bits/stdc++.h>

using namespace std;

#define maxn 110

vector<int> path[maxn * 2];
int n, m;
string ans;

struct TwoSat
{
	int n;
	vector<int> g[maxn * 2];
	bool mark[maxn * 2];
	stack<int> s;
	bool dfs(int x)
	{
		int i, j;
		if (mark[x ^ 1])
			return 0;
		if (mark[x])
			return 1;
		mark[x] = 1;
		s.push(x);
		for (i = 0; i < g[x].size(); i++)
		{
			int v = g[x][i];
			if (!dfs(v))
				return 0;
		}
		return 1;
	}

	void init(int n_)
	{
		n = n_;
		int i;
		for (i = 0; i < 2 * n; i++)
			g[i].clear();
		memset(mark, 0, sizeof(mark));
	}
	void clr()
	{
		memset(mark, 0, sizeof(mark));
		while (!s.empty())
			s.pop();
	}

	void addedge(int x, int y)
	{
		g[x].push_back(y);
	}

	bool solve()
	{
		int i, j;
		for (i = 0; i < 2 * n; i = i + 2)//从0开始
		{
			if (!mark[i] && !mark[i + 1])
			{
				while (!s.empty())
					s.pop();
				if (!dfs(i))
				{
					while (!s.empty())
					{
						mark[s.top()] = false;
						s.pop();
					}
					if (!dfs(i + 1))
						return false;
				}
			}
		}
		return true;
	}
};

TwoSat solver;
int vote[maxn];

void solve()
{
	int i, j;
	ans = "";
	for (i = 0; i < n; i++)
	{
		int judge = 0;
		solver.clr();
		solver.g[i * 2].push_back(i * 2 + 1);
		if (solver.solve())
			judge |= 1;
		solver.g[i * 2].pop_back();
		solver.clr();
		solver.g[i * 2 + 1].push_back(i * 2);
		if (solver.solve())
			judge |= 2;
		solver.g[i * 2 + 1].pop_back();
		if (judge == 0)
		{
			puts("impossible");
			return;
		}
		else if (judge == 1)
			ans += "y";
		else if (judge == 3)
			ans += "?";
		else
			ans += "n";
	}
	cout << ans << endl;
}

int main()
{
	int i, j, test = 0;
	while (scanf("%d %d", &n, &m) == 2 && n + m)
	{
		solver.init(n);
		for (i = 0; i < m; i++)
		{
			int t;
			scanf("%d", &t);
			for (j = 0; j < t; j++)
			{
				char s[2];
				int temp;
				scanf("%d %s", &temp, s);
				temp--;
				vote[j] = temp * 2 + (s[0] == 'y');
			}
			if (t <= 2)
			{
				int a, b;
				for (a = 0; a < t; a++)
					solver.addedge(vote[a] ^ 1, vote[a]);
			}
			else
			{
				int a, b;
				for (a = 0; a < t; a++)
					for (b = 0; b < t; b++)
					{
						if (a == b)
							continue;
						solver.addedge(vote[a] ^ 1, vote[b]);
					}
			}
		}
		printf("Case %d: ", ++test);
		solve();
	}
	return 0;
}
