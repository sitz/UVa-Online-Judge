#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
typedef long long ll;
#define N 1001
ll table[N][N] = {0};//v,n
ll ans[N][N] = {0};
ll tmp[N];

void make_table()
{
	rep(i, N) table[0][i] = 1;
	rep(i, N) table[1][i] = 1;//
	rep(i, N)
	{
		tmp[i] = 1;
		table[2][i] = i + 1;
		if (i)
		{
			tmp[i] = tmp[i - 1] + table[2][i];
		}
	}
	REP(v, 3, N)
	{
		tmp[0] = 1;
		table[v][0] = 1;
		REP(n, 1, N)
		{
			table[v][n] = tmp[n];
			tmp[n] = tmp[n - 1] + table[v][n];
		}
	}
	REP(v, 1, N)
	{
		ans[v][0] = table[v][0];
		ans[v][1] = table[v][1];
		for (int n = 3; n < N; n += 2)
		{
			ans[v][n] = ans[v][n - 2] + table[v][n];
		}
		for (int n = 2; n < N; n += 2)
		{
			ans[v][n] = ans[v][n - 2] + table[v][n];
		}
	}
}

main()
{
	int n, v;
	make_table();
	while (cin >> n >> v && v)
	{
		cout << ans[v][n] << endl;
	}
}
