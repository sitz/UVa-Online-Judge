#include <bits/stdc++.h>

using namespace std;

#define maxm 1050
#define inf (1 << 29)
#define ii int

#define pi acos(-1.0)
#define eps 1e-9
#define iseq(a, b) (fabs(a - b) < eps)

#define pii pair<int, int>
#define mp make_pair
#define uu first
#define vv second

ii on(ii n, ii k)
{
	return (n | (1 << k));
}
ii off(ii n, ii k)
{
	return (n - (n & (1 << k)));
}
bool chck(ii n, ii k)
{
	return (n & (1 << k));
}

ii mini(ii a, ii b)
{
	if (a < b)
	{
		return a;
	}
	return b;
}
ii maxi(ii a, ii b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

int r, c, s;
char grid[maxm][maxm];
int coln[maxm], cols[maxm];
int flagn[maxm][maxm], flags[maxm][maxm], kas = 1;

int dfss(int x, int y)
{
	if (x > r || x < 1 || y > c || y < 1)
	{
		return 0;
	}
	if (grid[x][y] == '#')
	{
		return 0;
	}
	if (x == r)
	{
		return 1;
	}
	if (flags[x][y] == kas)
	{
		return 0;
	}
	flags[x][y] = kas;
	if (dfss(x + 1, y))
	{
		return 1;
	}
	if (dfss(x, y + 1))
	{
		return 1;
	}
	if (dfss(x, y - 1))
	{
		return 1;
	}
	if (dfss(x - 1, y))
	{
		return 1;
	}
	return 0;
}

int dfsn(int x, int y)
{
	if (x > r || x < 1 || y > c || y < 1)
	{
		return 0;
	}
	if (grid[x][y] == '#')
	{
		return 0;
	}
	if (x == 1)
	{
		return 1;
	}
	if (flagn[x][y] == kas)
	{
		return 0;
	}
	flagn[x][y] = kas;
	if (dfsn(x - 1, y))
	{
		return 1;
	}
	if (dfsn(x, y + 1))
	{
		return 1;
	}
	if (dfsn(x, y - 1))
	{
		return 1;
	}
	if (dfsn(x + 1, y))
	{
		return 1;
	}
	return 0;
}

int main()
{
	int i, j, k, l, test, t = 1;
	//freopen("i.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while (scanf("%d", &r) == 1)
	{
		//if (r==-1) break;
		scanf("%d %d", &c, &s);
		//memset(flagn,0,sizeof(flagn));
		//memset(flags,0,sizeof(flags));
		kas++;
		for (i = 1; i <= r; i++)
		{
			scanf("%s", grid[i] + 1);
		}
		for (i = 1; i <= c; i++)
		{
			coln[i] = r + 1;
			for (j = 1; j <= r; j++)
			{
				if (grid[j][i] == '#')
				{
					coln[i] = j;
					break;
				}
			}
			cols[i] = 0;
			for (j = r; j >= 1; j--)
			{
				if (grid[j][i] == '#')
				{
					cols[i] = j;
					break;
				}
			}
		}
		int shot;
		int ans, ans1 = 1;
		ans = -1;
		for (j = 1; j <= c; j++)
		{
			if (dfss(1, j))
			{
				ans = 0;
				break;
			}
			if (dfsn(r, j))
			{
				ans = 0;
				break;
			}
		}
		for (i = 1; i <= s; i++)
		{
			scanf("%d", &shot);
			if (ans != -1)
			{
				continue;
			}
			if (shot < 0)
			{
				shot = -shot;
				if (cols[shot] == 0)
				{
					continue;
				}
				grid[cols[shot]][shot] = '.';
				if (dfsn(cols[shot], shot))
				{
					ans = i;
					ans1 = -1;
					continue;
				}
				for (j = cols[shot]; j >= 1; j--)
				{
					if (grid[j][shot] == '#')
					{
						cols[shot] = j;
						break;
					}
				}
				if (j < 1)
				{
					cols[shot] = 0;
				}
			}
			else
			{
				if (coln[shot] > r)
				{
					continue;
				}
				grid[coln[shot]][shot] = '.';
				if (dfss(coln[shot], shot))
				{
					ans = i;
					ans1 = 1;
					continue;
				}
				for (j = coln[shot]; j <= r; j++)
				{
					if (grid[j][shot] == '#')
					{
						coln[shot] = j;
						break;
					}
				}
				if (j > r)
				{
					coln[shot] = j;
				}
			}
		}
		if (ans == -1)
		{
			puts("X");
			continue;
		}
		ans *= ans1;
		printf("%d\n", ans);
	}
	return 0;
}
