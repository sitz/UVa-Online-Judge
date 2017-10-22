#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define N 2001
#define mp make_pair
#define x first
#define y second
#define MY 1
#define OP 2
typedef pair<int, int> PII;
bool visited[N][N];
int mark[N][N];
int cost[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
pair<int, int> Q[N * N];

int solve(int tail)
{
	int head = 0;
	while (head < tail)
	{
		rep(i, 4)
		{
			int nex = Q[head].x + dx[i], ney = Q[head].y + dy[i];
			if (nex < 0 || ney < 0 || nex >= N || ney >= N || visited[ney][nex] == true)
			{
				continue;
			}
			if (mark[ney][nex] == OP)
			{
				return cost[Q[head].y][Q[head].x] + 1;
			}
			visited[ney][nex] = true;
			cost[ney][nex] = cost[Q[head].y][Q[head].x] + 1;
			Q[tail].x = nex;
			Q[tail++].y = ney;
		}
		head++;
	}
	return -1;
}

main()
{
	int n;
	while (scanf("%d", &n) != -1 && n)
	{
		rep(i, N) rep(j, N) visited[i][j] = false, mark[i][j] = 0;
		int tx, ty;
		int tail = 0;
		rep(i, n)
		{
			scanf("%d%d", &tx, &ty);
			mark[ty][tx] = MY;
			Q[tail].x = tx;
			Q[tail++].y = ty;
			cost[ty][tx] = 0;
			visited[ty][tx] = true;
		}
		int p;
		cin >> p;
		rep(i, p)
		{
			scanf("%d%d", &tx, &ty);
			mark[ty][tx] = OP;
		}
		cout << solve(tail) << endl;
	}
	return false;
}
