#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int dis[10001], pre[2][10001];
vector<int> vc[10001], vp[10001];
pair<pair<int, int>, int> edges[100001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		memset(dis, 126, sizeof(dis));
		for (int i = 0; i < n + 1; i++)
		{
			vc[i].clear();
			vp[i].clear();
		}
		for (int i = 0; i < m; i++)
		{
			int x, y, w;
			scanf("%d%d%d", &x, &y, &w);
			vc[x].push_back(y);
			vp[x].push_back(w);
			edges[i] = make_pair(make_pair(x, y), w);
		}

		pre[0][1] = 1;
		pre[1][1] = -1;
		dis[1] = 0;
		pq.push(make_pair(0, 1));
		while (!pq.empty())
		{
			pair<int, int> p = pq.top();
			pq.pop();
			for (int i = 0; i < vc[p.second].size(); i++)
			{
				if (dis[vc[p.second][i]] > p.first + vp[p.second][i])
				{
					dis[vc[p.second][i]] = p.first + vp[p.second][i];
					pre[0][vc[p.second][i]] = p.second;
					pre[1][vc[p.second][i]] = -1;
					pq.push(make_pair(dis[vc[p.second][i]], vc[p.second][i]));
				}
				else if (dis[vc[p.second][i]] == p.first + vp[p.second][i])
				{
					if (p.second != pre[0][vc[p.second][i]])
					{
						pre[1][vc[p.second][i]] = p.second;
					}
				}
			}
		}

		LL res = 0LL;
		for (int i = 0; i < m; i++)
		{
			int x = edges[i].first.first, y = edges[i].first.second, w = edges[i].second;
			if (dis[x] + w == dis[y])
			{
				if (pre[1][y] != -1)
				{
					res -= (i + 1);
				}
			}
			else
			{
				res -= (i + 1);
				res += (LL)(i + 1) * (LL)(i + 1) * (LL)(dis[x] + w - dis[y]);
			}
		}
		printf("Case %d: %lld\n", t, res);
	}

	return 0;
}
