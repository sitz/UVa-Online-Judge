#include <bits/stdc++.h>

using namespace std;

int G[101][101];
const int INF = 1e8;

void solve()
{
	int n, e, t, m;
	cin >> n >> e >> t >> m;
	--e;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			G[i][j] = INF;
		}
	for (int i = 0; i < n; i++)
	{
		G[i][i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		G[a][b] = c;
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (G[i][e] <= t)
		{
			res++;
		}
	}
	cout << res << endl;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		if (i != 0)
		{
			cout << endl;
		}
		solve();
	}
	return 0;
}
