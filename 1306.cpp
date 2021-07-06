#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))

typedef long long LL;
typedef int F;

#define inf (1 << 29)
#define maxV 1000
#define maxE 400000

struct Dinic
{
	int V, E;
	F cap[maxE], flow[maxE];
	int to[maxE], prev[maxE];
	int level[maxV], used[maxV], last[maxV];

	void init(int n)
	{
		V = n;
		E = 0;
		for (int i = 0; i < V; i++)
		{
			last[i] = -1;
		}
	}

	void addCap(int x, int y, F f)
	{
		cap[E] = f;
		flow[E] = 0;
		to[E] = y;
		prev[E] = last[x];
		last[x] = E;
		E++;
		cap[E] = 0;
		flow[E] = 0;
		to[E] = x;
		prev[E] = last[y];
		last[y] = E;
		E++;
	}

	bool bfs(int s, int t)
	{
		for (int i = 0; i < V; i++)
		{
			level[i] = -1;
		}
		queue<int> q;
		q.push(s);
		level[s] = 0;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = last[x]; i != -1; i = prev[i])
				if (level[to[i]] == -1 && cap[i] > flow[i])
				{
					q.push(to[i]);
					level[to[i]] = level[x] + 1;
				}
		}
		return (level[t] != -1);
	}

	F dfs(int v, int t, F f)
	{
		if (v == t)
		{
			return f;
		}
		for (int i = used[v]; i != -1; used[v] = i = prev[i])
			if (level[to[i]] > level[v] && cap[i] > flow[i])
			{
				F tmp = dfs(to[i], t, min(f, cap[i] - flow[i]));
				if (tmp > 0)
				{
					flow[i] += tmp;
					flow[i ^ 1] -= tmp;
					return tmp;
				}
			}
		return 0;
	}

	bool solve(int s, int t)
	{
		while (bfs(s, t))
		{
			for (int i = 0; i < V; i++)
			{
				used[i] = last[i];
			}
			while (dfs(s, t, inf) != 0)
				;
		}
		bool ans = true;
		for (int i = last[s]; i != -1; i = prev[i])
		{
			ans &= (cap[i] - flow[i] == 0);
		}
		return ans;
	}
} mf;

int match[33][33], tmp[33][33];
int w[33], d[33];

int main()
{
	int Test;
	scanf("%d", &Test);
	while (Test--)
	{
		int n, m = 0;
		map<pair<int, int>, int> mp;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &w[i], &d[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &match[i][j]);
				if (match[i][j])
				{
					mp[MP(i, j)] = ++m;
				}
			}
		}
		vector<int> ans;
		for (int win = 1; win <= n; win++)
		{
			memcpy(tmp, match, sizeof(match));
			int sum = w[win];
			for (int i = 1; i <= n; i++)
			{
				if (tmp[win][i])
				{
					sum += tmp[win][i];
					tmp[win][i] = tmp[i][win] = 0;
				}
			}
			bool flag = true;
			for (int i = 1; i <= n; i++)
			{
				if (i == win)
				{
					continue;
				}
				if (sum < w[i])
				{
					flag = false;
					break;
				}
			}
			if (!flag)
			{
				continue;
			}
			mf.init(m + n + 2);
			int source = 0, sink = n + m + 1;
			for (int i = 1; i <= n; i++)
				for (int j = i + 1; j <= n; j++)
				{
					if (tmp[i][j] == 0)
					{
						continue;
					}
					int idx = mp[MP(i, j)];
					mf.addCap(source, idx, tmp[i][j]);
					mf.addCap(idx, m + i, tmp[i][j]);
					mf.addCap(idx, m + j, tmp[i][j]);
				}
			for (int i = 1; i <= n; i++)
			{
				if (i == win)
				{
					continue;
				}
				mf.addCap(m + i, sink, max(sum - w[i], 0));
			}
			flag = mf.solve(source, sink);
			if (flag)
			{
				ans.PB(win);
			}
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
		{
			printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
		}
	}
	return 0;
}
