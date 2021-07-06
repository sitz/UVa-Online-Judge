#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, s, t) for (int i = (s); i < (t); i++)
#define FOREACH(i, v) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define FILL(x, v) memset(x, v, sizeof(x))
const int INF = (int)1E9;
#define MAXN 105

int N, M, Q;
bool g[MAXN][MAXN][4];
int mt[505][2];
bool v[MAXN][MAXN][505];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
struct dij
{
	int x, y, t;
	dij(int _x, int _y, int _t)
	{
		x = _x;
		y = _y;
		t = _t;
	}
};
void bfs()
{
	queue<dij> que;
	que.push(dij(0, 0, 0));
	FILL(v, 0);
	v[0][0][0] = 1;
	while (!que.empty())
	{
		dij now = que.front();
		que.pop();
		int x = now.x, y = now.y, t = now.t, nt = t > 500 ? 501 : t + 1;
		if (x == N - 1 && y == M - 1)
		{
			printf("%d\n", t);
			return;
		}
		REP(i, 0, 4)
		{
			if (!g[x][y][i])
				continue;
			int nx = x + dir[i][0], ny = y + dir[i][1];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M || v[nx][ny][nt])
				continue;
			if (nx == mt[nt][0] && ny == mt[nt][1])
				continue;
			v[nx][ny][nt] = 1;
			que.push(dij(nx, ny, t + 1));
		}
		if (!v[x][y][nt])
		{
			v[x][y][nt] = 1;
			que.push(dij(x, y, t + 1));
		}
	}
}
int main()
{
	while (scanf("%d%d", &N, &M) != EOF)
	{
		FILL(mt, -1);
		FILL(g, 1);
		int k;
		scanf("%d", &k);
		while (k--)
		{
			int x1, x2, y1, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			REP(i, 0, 4)
			{
				if (x1 + dir[i][0] == x2 && y1 + dir[i][1] == y2)
				{
					g[x1][y1][i] = 0;
					break;
				}
			}
		}
		scanf("%d", &k);
		while (k--)
		{
			int t, x, y;
			scanf("%d%d%d", &t, &x, &y);
			mt[t][0] = x;
			mt[t][1] = y;
		}
		bfs();
	}
	return 0;
}
