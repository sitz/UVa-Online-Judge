#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define SIZE 22

#define N 0
#define E 1
#define S 2
#define W 3

int visited[SIZE][SIZE][SIZE / 2][SIZE / 2][SIZE / 2][SIZE / 2] = {0};
char m[4][SIZE][SIZE];

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

class state
{
public:
	int x, y;
	int num[4];
	state(){};
	state(int tx, int ty, int a, int b, int c, int d) : x(tx), y(ty)
	{
		num[0] = a;
		num[1] = b;
		num[2] = c;
		num[3] = d;
	}
};

void bfs(int n, int tc)
{
	int ans = n;
	queue<state> Q;
	Q.push(state(n / 2, n / 2, 0, 0, 0, 0));
	state now;
	visited[n / 2][n / 2][0][0][0][0] = tc;
	while (!Q.empty())
	{
		now = Q.front();
		Q.pop();
		rep(i, 4)
		{
			state next = now;
			next.x += dx[i];
			next.y += dy[i];
			bool flag = true;
			rep(j, 4)
			{
				if (m[j][next.y][next.x] == 'R')
				{
					next.num[j]++;
				}
				if (next.num[j] > n / 2)
				{
					flag = false;
				}
			}
			if (flag == false)
			{
				continue;
			}
			int tmp = max(next.num[0], max(next.num[1], max(next.num[2], next.num[3])));
			if (tmp > ans)
			{
				continue;
			}
			if (next.x == 0 || next.y == 0 || next.x == n - 1 || next.y == n - 1)
			{
				ans = min(ans, tmp);
			}
			else if (visited[next.y][next.x][next.num[0]][next.num[1]][next.num[2]][next.num[3]] != tc)
			{
				visited[next.y][next.x][next.num[0]][next.num[1]][next.num[2]][next.num[3]] = tc;
				Q.push(next);
			}
		}
	}
	cout << "At most " << ans << " rose(s) trampled." << endl;
}

void make_transpose(int n)
{
	REP(k, 1, 4)
	{
		rep(i, n)
		{
			rep(j, n)
			{
				m[k][i][j] = m[k - 1][j][n - i - 1];
			}
		}
	}
}

main()
{
	int n, tc = 1;
	while (cin >> n && n)
	{
		rep(i, n) cin >> m[0][i];
		make_transpose(n);
		bfs(n, tc);
		tc++;
	}
}
