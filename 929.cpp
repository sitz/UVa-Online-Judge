#include <bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for (int i = (int)(x); i <= (int)(y); ++i)
#define REP(i, n) FOR(i, 0, n - 1)
#define FORD(i, x, y) for (int i = (int)(x); i >= (int)(y); --i)
#define ALL(a) (a).begin(), (a).end()
#define FORE(t, i) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
template <typename T>
string tostr(const T &t)
{
	ostringstream os;
	os << t;
	return os.str();
}

struct node
{
	int cost;
	int x;
	int y;
	node(int ncost, int nx, int ny)
	{
		cost = ncost;
		x = nx;
		y = ny;
	}
};

bool operator<(const node &a, const node &b)
{
	if (a.cost != b.cost)
	{
		return b.cost < a.cost;
	}
	return false;
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int D[1001][1001];
int v[1001][1001];
int INF = 987654321;

int dijkstra(int v[1001][1001], int nrows, int ncols)
{
	priority_queue<node> q;
	for (int i = 0; i < nrows; ++i)
		for (int j = 0; j < ncols; ++j)
		{
			D[i][j] = INF;
		}
	q.push(node(v[0][0], 0, 0));
	D[0][0] = v[0][0];
	while (!q.empty())
	{
		node s = q.top();
		q.pop();
		if (s.x == nrows - 1 && s.y == ncols - 1)
		{
			return s.cost;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = s.x + dx[i];
			int ny = s.y + dy[i];
			if (nx >= 0 && nx < nrows && ny >= 0 && ny < ncols)
			{
				if (D[nx][ny] > D[s.x][s.y] + v[nx][ny])
				{
					D[nx][ny] = D[s.x][s.y] + v[nx][ny];
					q.push(node(D[s.x][s.y] + v[nx][ny], nx, ny));
				}
			}
		}
	}
	return -1;
}

int main()
{
	int nboards;
	scanf("%d", &nboards);
	for (int k = 0; k < nboards; ++k)
	{
		int ncols, nrows;
		scanf("%d\n%d\n", &nrows, &ncols);
		for (int i = 0; i < nrows; ++i)
		{
			char line[3000];
			gets(line);
			for (int j = 0; j < ncols; ++j)
			{
				v[i][j] = line[j * 2] - '0';
			}
		}
		printf("%d\n", dijkstra(v, nrows, ncols));
	}
	return 0;
}
