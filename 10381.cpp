#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef pair<int, int> pii;

const int N = 50;
const int inf = (1 << 20);
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

char m[N][N];
int cost[N][N];
int ans[N][N];

bool isout(int r, int c, int y, int x)
{
	return y == -1 || x == -1 || y == r || x == c;
}

int bfs(int r, int c, int sy, int sx, int gy, int gx)
{
	rep(i, r) rep(j, c) cost[i][j] = inf;
	cost[sy][sx] = 0;
	queue<int> Q;
	Q.push(sy * c + sx);
	while (!Q.empty())
	{
		int y = Q.front() / c, x = Q.front() % c;
		Q.pop();
		if (y == gy && x == gx)
		{
			return cost[y][x];
		}
		rep(i, 4)
		{
			int ney = y + dy[i], nex = x + dx[i];
			if (isout(r, c, ney, nex) || m[ney][nex] == '#' || cost[ney][nex] != inf)
			{
				continue;
			}
			cost[ney][nex] = cost[y][x] + 1;
			Q.push(ney * c + nex);
		}
	}
	return -1;
}

int solve(int r, int c)
{
	int sy, sx, gy, gx;
	rep(i, r)
	{
		rep(j, c) if (m[i][j] == 'E')
		{
			gy = i, gx = j;
		}
		else if (m[i][j] == 'X')
		{
			sy = i, sx = j;
		}
	}
	bfs(r, c, sy, sx, -1, -1);
	priority_queue<pii, vector<pii>, greater<pii>> Q;
	rep(i, r) rep(j, c) ans[i][j] = inf;
	rep(i, 4)
	{
		int ney = sy + dy[i], nex = sx + dx[i];
		if (isout(r, c, ney, nex) || m[ney][nex] == '#')
		{
			continue;
		}
		Q.push(make_pair(cost[sy][sx] + 1, ney * c + nex));
	}
	while (!Q.empty())
	{
		int nowc = Q.top().first, y = Q.top().second / c, x = Q.top().second % c;
		Q.pop();
		if (ans[y][x] != inf)
		{
			continue;
		}
		ans[y][x] = nowc;
		rep(i, 4)
		{
			int ney = y + dy[i], nex = x + dx[i];
			if (isout(r, c, ney, nex) || m[ney][nex] == '#' || ans[ney][nex] == inf)
			{
				continue;
			}
			char tmp = m[ney][nex];
			m[ney][nex] = '#';
			ans[y][x] = max(ans[y][x], bfs(r, c, y, x, sy, sx));
			m[ney][nex] = tmp;
		}
		rep(i, 4)
		{
			int ney = y + dy[i], nex = x + dx[i];
			if (isout(r, c, ney, nex) || m[ney][nex] == '#')
			{
				continue;
			}
			Q.push(make_pair(ans[y][x] + 1, ney * c + nex));
		}
	}
	return ans[gy][gx];
}

int main()
{
	int te;
	cin >> te;
	while (te--)
	{
		int r, c;
		cin >> r >> c;
		rep(i, r) cin >> m[i];
		cout << solve(r, c) << endl;
	}
	return 0;
}
