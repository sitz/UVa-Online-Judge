#include <bits/stdc++.h>

using namespace std;

#define MAX 10005

struct Road
{
	int v, c;
	Road(int v, int c) : v(v), c(c) {}
	inline bool operator<(const Road &that) const
	{
		return c < that.c;
	}
};

bool V[MAX];
int CStart[MAX], CCount[MAX], nc, n, m;
priority_queue<Road> Q;
vector<int> R;
vector<Road> G[MAX];

int dfs(int v)
{
	V[v] = true;
	int accum = 1;
	for (int i = 0; i < G[v].size(); i++)
	{
		if (!V[G[v][i].v])
		{
			accum += dfs(G[v][i].v);
		}
	}
	return accum;
}

int main()
{
	int T; scanf("%d", &T);
	for (int t=1; t<=T; t++)
	{
		scanf("%d%d", &n,&m);
		memset(V, 0, sizeof(V));
		memset(G, 0, sizeof(G));
		nc = 0;
		R.clear();
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			G[a].push_back(Road(b, c));
			G[b].push_back(Road(a, c));
		}
		for (int i = 1; i <= n; i++)
		{
			if (!V[i])
			{
				CStart[nc] = i;
				CCount[nc] = dfs(i);
				nc++;
			}
		}
		int res = 0;
		for (int i = 0; i < nc; i++)
		{
			int totalc = 0;
			Q.push(Road(CStart[i], 0));
			memset(V, 0, sizeof(V));
			while (totalc < CCount[i])
			{
				Road item = Q.top();
				Q.pop();
				if (V[item.v])
				{
					res += item.c;
					continue;
				}
				V[item.v] = true;
				totalc++;
				for (int j = 0; j < G[item.v].size(); j++)
				{
					if (!V[G[item.v][j].v])
					{
						Q.push(G[item.v][j]);
					}
				}
			}
			while (!Q.empty())
			{
				res += Q.top().c;
				Q.pop();
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
