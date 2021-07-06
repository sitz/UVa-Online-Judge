#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x, y) memset(x, y, sizeof(x))
#define out(x) printf(#x " %d\n", x)

typedef long long lint;
const int maxint = -1u >> 1;
const double esp = 1e-8;
string g[13];
int head, last;
int dui[400][2];
int mov[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int sum, n, m, t, ans, T, top;
struct hh
{
	int x, y;
	bool move;
} h[20];
void ind(int x, int y, string g[], bool hwalk[13][13])
{
	if (x <= 0 || x > n || y <= 0 || y > m || hwalk[x][y] || g[x][y] == 'X' || g[x][y] == 'O')
	{
		return;
	}
	g[x][y] = '.';
	hwalk[x][y] = true;
	last++;
	dui[last][0] = x;
	dui[last][1] = y;
}
void walk(int x, int y, string g[], bool hwalk[13][13])
{
	head = 0;
	last = 1;
	dui[1][0] = x;
	dui[1][1] = y;
	hwalk[x][y] = true;
	while (head < last)
	{
		head++;
		int x = dui[head][0], y = dui[head][1];
		//cout<<x<<" "<<y<<endl;
		ind(x, y + 1, g, hwalk);
		ind(x, y - 1, g, hwalk);
		ind(x + 1, y, g, hwalk);
		ind(x - 1, y, g, hwalk);
	}
}
int cal(string g[])
{
	int ret = 0;
	repf(i, 1, n)
			repf(j, 1, m)
					ret += (g[i][j] == 'C');
	return sum - ret;
}
bool ok(int tag, int x, int y, string g[], bool hwalk[13][13])
{
	if (x <= 0 || x > n || y <= 0 || y > m)
	{
		return false;
	}
	if (tag == 0)
	{
		if (hwalk[x][y] == false)
		{
			return false;
		}
	}
	else if (tag == 1)
	{
		if (g[x][y] == 'C' || g[x][y] == 'O' || g[x][y] == 'X')
		{
			return false;
		}
	}
	return true;
}
bool domove(int way, int x, int y, string g[], bool hwalk[13][13])
{
	int sx = x + mov[way][0], sy = y + mov[way][1];
	int tx = x - mov[way][0], ty = y - mov[way][1];
	if (ok(0, sx, sy, g, hwalk) && ok(1, tx, ty, g, hwalk))
	{
		g[tx][ty] = 'X';
		g[x][y] = '.';
		return true;
	}
	return false;
}
void dfs(int i, int x, int y, string g[])
{
	//cout<<n<<"--------------------"<<endl;
	//repf( j, 1, n )
	//cout<<g[j]<<endl;
	//cout<<"---------------"<<endl;
	string temp[13];
	bool hwalk[13][13];
	clr(hwalk);
	walk(x, y, g, hwalk);
	repf(j, 1, n) temp[j] = g[j];
	if (i == top + 1)
	{
		ans = max(ans, cal(g));
		return;
	}
	dfs(i + 1, x, y, g);
	repf(j, 1, n) g[j] = temp[j];
	repf(k, 1, top)
	{
		if (!h[k].move)
		{
			repf(way, 1, 4)
			{
				if (domove(way, h[k].x, h[k].y, g, hwalk))
				{
					h[k].move = true;
					dfs(i + 1, h[k].x, h[k].y, g);
					repf(j, 1, n) g[j] = temp[j];
					h[k].move = false;
				}
			}
		}
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &n, &m);
		repf(i, 1, n) g[i].clear();
		repf(i, 1, n)
		{
			char s[20];
			clr(s);
			scanf("%s", s);
			g[i] = (string)s;
			g[i] = '.' + g[i];
		}
		sum = 0, top = 0;
		int x, y;
		repf(i, 1, n)
		{
			repf(j, 1, m)
			{
				if (g[i][j] == 'C')
				{
					sum++;
				}
				if (g[i][j] == 'O')
				{
					top++;
					h[top].x = i;
					h[top].y = j;
					h[top].move = false;
				}
				if (g[i][j] == 'S')
				{
					x = i;
					y = j;
				}
			}
		}
		//cout<<sum<<endl;
		ans = 0;
		dfs(1, x, y, g);
		//cout<<sum<<endl;
		printf("%d\n", ans);
	}
	return 0;
}
