#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

const int N = 20;
int ans;
int color[N];
vector<int> edge[N];
int in[4];

bool check(int now, int c)
{
	rep(i, (int)edge[now].size())
	{
		if (color[edge[now][i]] == c)
		{
			return false;
		}
	}
	return true;
}

void search(int n, int now)
{
	if (now == n)
	{
		int tmp = 0;
		rep(i, n)
		{
			rep(j, (int)edge[i].size())
			{
				if (edge[i][j] > i)
				{
					int a = color[i] - color[edge[i][j]];
					tmp += a * a;
				}
			}
		}
		ans = max(ans, tmp);
		return;
	}
	rep(i, 4)
	{
		if (check(now, in[i]))
		{
			color[now] = in[i];
			search(n, now + 1);
			color[now] = -1;
		}
	}
}

main()
{
	int n, m;
	while (cin >> n >> m >> in[0] >> in[1] >> in[2] >> in[3] && n)
	{
		rep(i, n) color[i] = -1, edge[i].clear();
		rep(i, m)
		{
			int f, t;
			cin >> f >> t;
			f--;
			t--;
			edge[f].push_back(t);
			edge[t].push_back(f);
		}
		ans = 0;
		search(n, 0);
		cout << ans << endl;
	}
	return false;
}
