#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
bool table[12][12][4];
bool inp[12][12][4];
#define N 0
#define E 1
#define S 2
#define W 3

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int od[] = {2, 3, 0, 1};//opposite direction

bool solve(int r, int c, int now)
{
	if (r * c == now)
	{
		return true;
	}
	int y = now / c, x = now % c;
	rep(i, 4)
	{
		table[y][x][N] = inp[y][x][(N + i) % 4];
		table[y][x][E] = inp[y][x][(E + i) % 4];
		table[y][x][S] = inp[y][x][(S + i) % 4];
		table[y][x][W] = inp[y][x][(W + i) % 4];
		if (i == 1 && ((inp[y][x][N] == 0 && inp[y][x][E] == 0 && inp[y][x][S] == 0 && inp[y][x][W] == 0) ||
									 (inp[y][x][N] == 1 && inp[y][x][E] == 1 && inp[y][x][S] == 1 && inp[y][x][W] == 1)))
		{
			return false;
		}
		if (i == 2 && ((inp[y][x][N] == 0 && inp[y][x][E] == 1 && inp[y][x][S] == 0 && inp[y][x][W] == 1) ||
									 (inp[y][x][N] == 1 && inp[y][x][E] == 0 && inp[y][x][S] == 1 && inp[y][x][W] == 0)))
		{
			return false;
		}
		bool flag = true;
		rep(j, 4)
		{
			int nex = x + dx[j], ney = y + dy[j];
			if (nex < 0)
			{
				if (table[y][x][W] == true)
				{
					flag = false;
					break;
				}
				continue;
			}
			if (nex >= c)
			{
				if (table[y][x][E] == true)
				{
					flag = false;
					break;
				}
				continue;
			}
			if (ney < 0)
			{
				if (table[y][x][N] == true)
				{
					flag = false;
					break;
				}
				continue;
			}
			if (ney >= r)
			{
				if (table[y][x][S] == true)
				{
					flag = false;
					break;
				}
				continue;
			}
			if (now < ney * c + nex)
			{
				continue;
			}
			if (table[y][x][j] != table[ney][nex][od[j]])
			{
				flag = false;
				break;
			}
		}
		if (flag == false)
		{
			continue;
		}
		if (solve(r, c, now + 1))
		{
			return true;
		}
	}
	return false;
}

main()
{
	int r, c;
	while (cin >> r >> c && r)
	{
		rep(i, r)
		{
			rep(j, c)
			{
				string a;
				cin >> a;
				inp[i][j][0] = inp[i][j][1] = inp[i][j][2] = inp[i][j][3] = false;
				if (a == "x")
				{
					continue;
				}
				rep(k, a.size())
				{
					if (a[k] == 'N')
					{
						inp[i][j][N] = true;
					}
					if (a[k] == 'W')
					{
						inp[i][j][W] = true;
					}
					if (a[k] == 'E')
					{
						inp[i][j][E] = true;
					}
					if (a[k] == 'S')
					{
						inp[i][j][S] = true;
					}
				}
			}
		}
		if (solve(r, c, 0))
		{
			puts("SOLVABLE");
		}
		else
		{
			puts("UNSOLVABLE");
		}
	}
}
