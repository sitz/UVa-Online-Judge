#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

const int N = 10000;
int edge[N][2];
int p[N];
bool vis[N];
int ans = 0;
int assign[N];

void dfs(int now, int prev, int cnt)
{
	if (vis[now])
	{
		ans += cnt - 2;
		return;
	}
	vis[now] = true;
	rep(i, p[now])
	{
		if (edge[now][i] != prev)
		{
			dfs(edge[now][i], now, cnt + 1);
			break;
		}
	}
}

inline int getindex(int in, int &index)
{
	if (assign[in] == -1)
	{
		assign[in] = index++;
	}
	return assign[in];
}

main()
{
	int te;
	scanf("%d", &te);
	rep(tc, te)
	{
		map<int, int> M;
		int n;
		int index = 0;
		scanf("%d", &n);
		rep(i, N) assign[i] = -1;
		rep(i, n) vis[i] = false, p[i] = 0;
		rep(i, n)
		{
			int f, t;
			scanf("%d%d", &f, &t);
			f--;
			t--;
			f = getindex(f, index);
			t = getindex(t, index);
			if (f == t)
			{
				continue;
			}
			edge[f][p[f]++] = t;
			edge[t][p[t]++] = f;
		}
		/*
		rep(i,n){
		  sort(edge[i].begin(),edge[i].end());
		  edge[i].erase(unique(edge[i].begin(),edge[i].end()),
		        edge[i].end());
		}
		*/
		int tmp = 0;
		rep(i, n)
		{
			if (p[i] != 0 && edge[i][0] == edge[i][1])
			{
				tmp++;
				p[i] = 0;
			}
		}
		ans = 0;
		rep(i, n)
		{
			if (p[i] && !vis[i])
			{
				dfs(i, -1, 1);
			}
		}
		ans += tmp / 2;
		cout << ans << endl;
	}
	return 0;
}
