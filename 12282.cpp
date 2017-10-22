#include <bits/stdc++.h>

using namespace std;

#define F(i, a, b) for (int i = a; i < b; i++)
#define NL printf("\n");
#define cp printf("here\n");
#define MEM(a, val) memset(a, val, sizeof(a))
#define CHR getchar()
#define PB(x) push_back(x)
#define sz() size()

#define MX 100007
#define MOD 1000000007
#define INF (1 << 30) - 1 + (1 << 30)
#define eps 1e-9

map<char, int> mp;
int block[11][11], came[9][9][9][9][9][9][9][9];
char s[12][12];

struct z
{
	int axx, ayy, bxx, byy, cxx, cyy, dxx, dyy;
};

int check_area(int x, int y, int dir)
{
	if (dir == 0)
	{
		if (y < 7)
		{
			if (block[x][y + 2] == 0 && block[x + 1][y + 2] == 0)
			{
				return 1;
			}
		}
		return 0;
	}
	else if (dir == 1)
	{
		if (y > 1)
		{
			if (block[x][y - 1] == 0 && block[x + 1][y - 1] == 0)
			{
				return 1;
			}
		}
		return 0;
	}
	else if (dir == 2)
	{
		if (x > 1)
		{
			if (block[x - 1][y] == 0 && block[x - 1][y + 1] == 0)
			{
				return 1;
			}
		}
		return 0;
	}
	else
	{
		if (x < 7)
		{
			if (block[x + 2][y] == 0 && block[x + 2][y + 1] == 0)
			{
				return 1;
			}
		}
		return 0;
	}
}

void change(int x, int y)
{
	block[x][y] = 1;
	block[x][y + 1] = 1;
	block[x + 1][y + 1] = 1;
	block[x + 1][y] = 1;
	return;
}

z BFS_DIRECTION(int dir, z a)
{
	int ax, ay, bx, by, cx, cy, dx, dy;
	ax = a.axx;
	ay = a.ayy;
	bx = a.bxx;
	by = a.byy;
	cx = a.cxx;
	cy = a.cyy;
	dx = a.dxx;
	dy = a.dyy;
	if (dir == 1)
	{
		/// east dir
		int vis[9][9][5];
		MEM(vis, 0);
		queue<int> q;
		q.push(0);
		q.push(ax);
		q.push(ay);
		vis[ax][ay][0] = 1;
		q.push(1);
		q.push(bx);
		q.push(by);
		vis[bx][by][1] = 1;
		q.push(2);
		q.push(cx);
		q.push(cy);
		vis[cx][cy][2] = 1;
		q.push(3);
		q.push(dx);
		q.push(dy);
		vis[dx][dy][3] = 1;
		while (q.size())
		{
			int x, y, id;
			id = q.front();
			q.pop();
			x = q.front();
			q.pop();
			y = q.front();
			q.pop();
			vis[x][y][id]++;
			if (check_area(x, y, 0))
			{
				if (id == 0)
				{
					q.push(0);
					ay = ay + 1;
					q.push(ax);
					q.push(ay);
				}
				else if (id == 1)
				{
					q.push(1);
					by = by + 1;
					q.push(bx);
					q.push(by);
				}
				else if (id == 2)
				{
					q.push(2);
					cy = cy + 1;
					q.push(cx);
					q.push(cy);
				}
				else
				{
					q.push(3);
					dy = dy + 1;
					q.push(dx);
					q.push(dy);
				}
				block[x + 1][y] = 0;
				block[x][y] = 0;
				change(x, y + 1);
			}
			else if (vis[x][y][id] <= 5)
			{
				q.push(id);
				q.push(x);
				q.push(y);
			}
		}
	}
	else if (dir == 2)
	{
		/// west dir
		int vis[9][9][5];
		MEM(vis, 0);
		queue<int> q;
		q.push(0);
		q.push(ax);
		q.push(ay);
		vis[ax][ay][0] = 1;
		q.push(1);
		q.push(bx);
		q.push(by);
		vis[bx][by][1] = 1;
		q.push(2);
		q.push(cx);
		q.push(cy);
		vis[cx][cy][2] = 1;
		q.push(3);
		q.push(dx);
		q.push(dy);
		vis[dx][dy][3] = 1;
		while (q.size())
		{
			int x, y, id;
			id = q.front();
			q.pop();
			x = q.front();
			q.pop();
			y = q.front();
			q.pop();
			vis[x][y][id]++;
			if (check_area(x, y, 1))
			{
				// cout<<x<< " "<<y<< " "<<id<< "lucky"<<endl;
				if (id == 0)
				{
					ay = ay - 1;
					q.push(0);
					q.push(ax);
					q.push(ay);
				}
				else if (id == 1)
				{
					by = by - 1;
					q.push(1);
					q.push(bx);
					q.push(by);
				}
				else if (id == 2)
				{
					cy = cy - 1;
					q.push(2);
					q.push(cx);
					q.push(cy);
				}
				else
				{
					dy = dy - 1;
					q.push(3);
					q.push(dx);
					q.push(dy);
				}
				block[x + 1][y + 1] = 0;
				block[x][y + 1] = 0;
				change(x, y - 1);
			}
			else if (vis[x][y][id] <= 5)
			{
				q.push(id);
				q.push(x);
				q.push(y);
			}
		}
	}
	else if (dir == 3)
	{
		/// north dir
		int vis[9][9][5];
		MEM(vis, 0);
		queue<int> q;
		q.push(0);
		q.push(ax);
		q.push(ay);
		vis[ax][ay][0] = 1;
		q.push(1);
		q.push(bx);
		q.push(by);
		vis[bx][by][1] = 1;
		q.push(2);
		q.push(cx);
		q.push(cy);
		vis[cx][cy][2] = 1;
		q.push(3);
		q.push(dx);
		q.push(dy);
		vis[dx][dy][3] = 1;
		while (q.size())
		{
			int x, y, id;
			id = q.front();
			q.pop();
			x = q.front();
			q.pop();
			y = q.front();
			q.pop();
			vis[x][y][id]++;
			if (check_area(x, y, 2))
			{
				if (id == 0)
				{
					ax = ax - 1;
					q.push(0);
					q.push(ax);
					q.push(ay);
				}
				else if (id == 1)
				{
					bx = bx - 1;
					q.push(1);
					q.push(bx);
					q.push(by);
				}
				else if (id == 2)
				{
					cx = cx - 1;
					q.push(2);
					q.push(cx);
					q.push(cy);
				}
				else
				{
					dx = dx - 1;
					q.push(3);
					q.push(dx);
					q.push(dy);
				}
				block[x + 1][y] = 0;
				block[x + 1][y + 1] = 0;
				change(x - 1, y);
			}
			else if (vis[x][y][id] <= 5)
			{
				q.push(id);
				q.push(x);
				q.push(y);
			}
		}
	}
	else
	{
		/// south dir
		int vis[9][9][5];
		MEM(vis, 0);
		queue<int> q;
		q.push(0);
		q.push(ax);
		q.push(ay);
		vis[ax][ay][0] = 1;
		q.push(1);
		q.push(bx);
		q.push(by);
		vis[bx][by][1] = 1;
		q.push(2);
		q.push(cx);
		q.push(cy);
		vis[cx][cy][2] = 1;
		q.push(3);
		q.push(dx);
		q.push(dy);
		vis[dx][dy][3] = 1;
		while (q.size())
		{
			int x, y, id;
			id = q.front();
			q.pop();
			x = q.front();
			q.pop();
			y = q.front();
			q.pop();
			vis[x][y][id]++;
			//cout<<x<< " "<<y<< " "<<id<<" "<<vis[x][y][id]<<endl;
			if (check_area(x, y, 3))
			{
				//cp;
				if (id == 0)
				{
					ax = ax + 1;
					q.push(0);
					q.push(ax);
					q.push(ay);
				}
				else if (id == 1)
				{
					bx = bx + 1;
					q.push(1);
					q.push(bx);
					q.push(by);
				}
				else if (id == 2)
				{
					cx = cx + 1;
					q.push(2);
					q.push(cx);
					q.push(cy);
				}
				else
				{
					dx = dx + 1;
					q.push(3);
					q.push(dx);
					q.push(dy);
				}
				block[x][y] = 0;
				block[x][y + 1] = 0;
				change(x + 1, y);
			}
			else if (vis[x][y][id] <= 5)
			{
				q.push(id);
				q.push(x);
				q.push(y);
			}
		}
	}
	z ans;
	ans.axx = ax;
	ans.ayy = ay;
	ans.bxx = bx;
	ans.byy = by;
	ans.cxx = cx;
	ans.cyy = cy;
	ans.dxx = dx;
	ans.dyy = dy;
	//cout<<dir<<endl;
	return ans;
}

long long ans;
int tst;
void DFS(z a)
{
	int ax, ay, bx, by, cx, cy, dx, dy;
	ax = a.axx;
	ay = a.ayy;
	bx = a.bxx;
	by = a.byy;
	cx = a.cxx;
	cy = a.cyy;
	dx = a.dxx;
	dy = a.dyy;
	// NL;
	//cout<<ax<< " "<<ay<< " "<<bx<< " "<<by<< " "<<cx<< " "<<cy<< " "<<dx<< " "<<dy<<endl;
	//if(kk>=2) return;
	if (came[ax][ay][bx][by][cx][cy][dx][dy] == tst)
	{
		return;
	}
	came[ax][ay][bx][by][cx][cy][dx][dy] = tst;
	ans++;
	F(i, 1, 5)
	{
		int nw[10][10];
		F(j, 0, 10)
		{
			F(k, 0, 10)
			{
				nw[j][k] = block[j][k];
			}
		}
		DFS(BFS_DIRECTION(i, a));
		F(j, 0, 10)
		{
			F(k, 0, 10)
			{
				block[j][k] = nw[j][k];
			}
		}
	}
	return;
}

int main()
{
	int ax, ay, bx, by, cx, cy, dx, dy;
	int t;
	cin >> t;
	tst = 1;
	F(cs, 1, t + 1)
	{
		mp.clear();
		F(i, 0, 10)
		{
			block[i][0] = 1;
		}
		F(i, 0, 10)
		{
			block[9][i] = 1;
		}
		F(i, 0, 10)
		{
			block[i][9] = 1;
		}
		F(i, 0, 9)
		{
			block[0][i] = 1;
		}
		F(i, 1, 9)
		{
			cin >> s[i];
			F(j, 0, 8)
			{
				if (s[i][j] == '#')
				{
					block[i][1 + j] = 1;
				}
				else if (s[i][j] == '.')
				{
					block[i][j + 1] = 0;
				}
				else
				{
					char ch = s[i][j];
					if (mp[ch] == 0)
					{
						int x, y;
						x = i, y = j + 1;
						mp[ch] = 1;
						if (ch == 'A')
						{
							ax = x;
							ay = y;
						}
						else if (ch == 'B')
						{
							bx = x;
							by = y;
						}
						else if (ch == 'C')
						{
							cx = x;
							cy = y;
						}
						else
						{
							dx = x;
							dy = y;
						}
					}
				}
			}
		}
		z tp;
		tp.axx = ax;
		tp.ayy = ay;
		tp.bxx = bx;
		tp.byy = by;
		tp.cxx = cx;
		tp.cyy = cy;
		tp.dxx = dx;
		tp.dyy = dy;
		change(ax, ay);
		change(bx, by);
		change(cx, cy);
		change(dx, dy);
		ans = 0;
		F(i, 1, 5)
		{
			int nw[10][10];
			F(j, 0, 10)
			{
				F(k, 0, 10)
				{
					nw[j][k] = block[j][k];
				}
			}
			DFS(BFS_DIRECTION(i, tp));
			F(j, 0, 10)
			{
				F(k, 0, 10)
				{
					block[j][k] = nw[j][k];
				}
			}
		}
		printf("Case %d: ", cs);
		cout << ans << endl;
		tst++;
	}
	return 0;
}
