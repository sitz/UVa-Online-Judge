#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int mod = 20437;
const int INF = 120437;
char m[10][10];

pair<int, int> bfs(int now, int sx, int sy, int n, int c, int p)
{
	int table[n][n], path[n][n];
	bool visited[n][n];
	rep(i, n) rep(j, n)
	{
		if (m[i][j] == '#' || m[i][j] - 'A' > now + 1)
		{
			visited[i][j] = true;
		}
		else
		{
			visited[i][j] = false;
		}
		if (i != sy || j != sx)
		{
			table[i][j] = INF, path[i][j] = 0;
		}
	}
	queue<pair<int, int>> Q;
	Q.push(make_pair(sx, sy));
	visited[sy][sx] = true;
	path[sy][sx] = p;
	table[sy][sx] = c;
	while (!Q.empty())
	{
		int x = Q.front().first, y = Q.front().second;
		Q.pop();
		if (m[y][x] - 'A' == now + 1)
		{
			return make_pair(table[y][x], path[y][x]);
		}
		rep(i, 4)
		{
			int nex = x + dx[i], ney = y + dy[i];
			if (nex < 0 || ney < 0 || nex >= n || ney >= n)
			{
				continue;
			}
			if (visited[ney][nex] == true &&
					table[y][x] + 1 != table[ney][nex])
			{
				continue;
			}
			if (visited[ney][nex] == false)
			{
				Q.push(make_pair(nex, ney));
			}
			visited[ney][nex] = true;
			table[ney][nex] = table[y][x] + 1;
			path[ney][nex] = (path[ney][nex] + path[y][x]) % mod;
		}
	}
	return make_pair(-1, -1);
}

void solve(int size, int n, int *x, int *y)
{
	pair<int, int> res = make_pair(0, 1);
	rep(i, size)
	{
		res = bfs(i, x[i], y[i], n, res.first, res.second);
		if (res.first == -1)
		{
			printf(" Impossible\n");
			return;
		}
	}
	printf(" %d %d\n", res.first, res.second);
	return;
}

main()
{
	int n;
	int tc = 1;
	while (cin >> n && n)
	{
		int x[27], y[27], size = 0;
		rep(i, n) cin >> m[i];
		rep(i, n)
		{
			rep(j, n)
			{
				if (isalpha(m[i][j]))
				{
					size = max(size, m[i][j] - 'A');
					x[m[i][j] - 'A'] = j;
					y[m[i][j] - 'A'] = i;
				}
			}
		}
		printf("Case %d:", tc++);
		solve(size, n, x, y);
	}
	return false;
}
