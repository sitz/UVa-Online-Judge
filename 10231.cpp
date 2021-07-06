#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < (int)n; i++)
#define rep(i, n) REP(i, 0, n)

const int INF = 1000000000;
const int N = 30;
const int M = 12;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int H, W;
char t[N][N];
bool visited[N][N];
int roboCost[N][N], edge[N][N], man, node, rCost[M];

class State
{
public:
	int cost, y, x;
};

bool invalid(int y, int x)
{
	if (y >= H || x >= W)
	{
		return true;
	}
	if (y < 0 || x < 0)
	{
		return true;
	}
	if (t[y][x] == '#')
	{
		return true;
	}
	return false;
}

void BFS1(int sy, int sx)
{
	rep(i, N) rep(j, N) visited[i][j] = false;
	visited[sy][sx] = true;
	queue<State> Q;
	for (Q.push((State){
					 0, sy, sx});
			 !Q.empty(); Q.pop())
	{
		State now = Q.front();
		int nextCost = now.cost + 1;
		rep(d, 4)
		{
			int nx = now.x + dx[d];
			int ny = now.y + dy[d];
			if (invalid(ny, nx))
			{
				continue;
			}
			if (visited[ny][nx])
			{
				continue;
			}
			visited[ny][nx] = true;
			roboCost[ny][nx] = min(roboCost[ny][nx], nextCost);
			Q.push((State){
					nextCost, ny, nx});
		}
	}
}

int BFS2(int sy, int sx, int gy, int gx)
{
	rep(i, H) rep(j, W) visited[i][j] = false;
	visited[sy][sx] = true;
	queue<State> Q;
	for (Q.push((State){
					 0, sy, sx});
			 !Q.empty(); Q.pop())
	{
		State now = Q.front();
		int nextCost = now.cost + 1;
		rep(d, 4)
		{
			int nx = now.x + dx[d];
			int ny = now.y + dy[d];
			if (invalid(ny, nx))
			{
				continue;
			}
			if (visited[ny][nx])
			{
				continue;
			}
			visited[ny][nx] = true;
			if (ny == gy && nx == gx)
			{
				return nextCost;
			}
			Q.push((State){
					nextCost, ny, nx});
		}
	}
	return INF;
}

void makeGraph()
{
	int X[M], Y[M];
	rep(i, N) rep(j, N) roboCost[i][j] = INF;
	rep(i, M) rep(j, M) edge[i][j] = INF;
	node = 0;
	man = -1;
	rep(i, H)
	{
		rep(j, W)
		{
			if (t[i][j] == 'X')
			{
				BFS1(i, j);
			}
		}
	}
	rep(i, H)
	{
		rep(j, W)
		{
			if (t[i][j] != 'O' && t[i][j] != '*')
			{
				continue;
			}
			if (t[i][j] == 'O')
			{
				man = node;
			}
			X[node] = j;
			Y[node] = i;
			rCost[node] = roboCost[i][j];
			node++;
		}
	}
	rep(i, node)
	{
		REP(j, i + 1, node)
		{
			edge[j][i] = edge[i][j] = BFS2(Y[i], X[i], Y[j], X[j]);
		}
	}
}

void solve()
{
	if (man < 0)
	{
		cout << "No treasures can be collected." << endl;
		return;
	}
	int cost[M][(1 << M)];
	rep(i, node)
	{
		rep(j, (1 << node))
		{
			cost[i][j] = INF;
		}
	}
	cost[man][1 << man] = 0;
	rep(b, (1 << node))
	{
		rep(pos, node)
		{
			if (cost[pos][b] == INF)
			{
				continue;
			}
			rep(nextpos, node)
			{
				if ((b & (1 << nextpos)) > 0)
				{
					continue;
				}
				int nextCost = cost[pos][b] + edge[pos][nextpos] + 1;
				int nextb = b + (1 << nextpos);
				if (rCost[nextpos] <= nextCost)
				{
					continue;
				}
				cost[nextpos][nextb] = min(nextCost, cost[nextpos][nextb]);
			}
		}
	}
	int ans[M];
	rep(i, M) ans[i] = INF;
	rep(i, (1 << node))
	{
		int tmp = __builtin_popcount(i);
		rep(pos, node)
		{
			ans[tmp] = min(ans[tmp], cost[pos][i]);
		}
	}
	int tmp = node;
	while (1)
	{
		if (tmp <= 1)
		{
			cout << "No treasures can be collected." << endl;
			return;
		}
		if (ans[tmp] != INF)
		{
			cout << "Maximum number of collectible treasures: " << tmp - 1 << '.' << endl;
			cout << "Minimum Time: " << ans[tmp] << " sec." << endl;
			return;
		}
		tmp--;
	}
	return;
}

int main()
{
	int tc = 0;
	while (cin >> H >> W)
	{
		tc++;
		cout << "Case " << tc << ":" << endl;
		rep(i, H) rep(j, W) cin >> t[i][j];
		makeGraph();
		solve();
		cout << endl;
	}
	return 0;
}
