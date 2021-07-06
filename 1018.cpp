#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 0, 1, 1, 1, -1, -1, -1},
		dy[] = {-1, 1, 0, -1, 1, 0, 1, -1};

struct E
{
	int x, y, w;
};
E lst[25 * 1000000 + 25];

char grid[105][105];
int r, c, col[105][105], set_[10005], edge[5005][5005];

bool cmp(E a, E b)
{
	return a.w < b.w;
}

void color(int x, int y, int cl)
{
	col[x][y] = cl;
	int xx, yy, i;
	for (i = 0; i < 8; i++)
	{
		xx = x + dx[i];
		yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx > r - 1 || yy > c - 1)
		{
			continue;
		}
		if (grid[xx][yy] != '#' || col[xx][yy] != 0)
		{
			continue;
		}
		color(xx, yy, cl);
	}
}

int getparent(int i)
{
	if (set_[i] == i)
	{
		return i;
	}
	else
	{
		return set_[i] = getparent(set_[i]);
	}
}
int isunion(int a, int b)
{
	return getparent(a) == getparent(b);
}
void makeunion(int a, int b)
{
	set_[getparent(a)] = getparent(b);
}

int main()
{
	int t = 0, clr;
	while (scanf("%d%d", &r, &c) == 2)
	{
		if (r == 0 && c == 0)
		{
			return 0;
		}
		for (int i = 0; i < r; i++)
		{
			scanf("%s", &grid[i]);
		}
		if (t)
		{
			printf("\n");
		}
		printf("City %d\n", ++t);

		memset(col, 0, sizeof(col));

		clr = 0;

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (grid[i][j] == '#' && col[i][j] == 0)
				{
					++clr;
					color(i, j, clr);
				}
			}
		}

		if (clr <= 1)
		{
			printf("No bridges are needed.\n");
			continue;
		}
		for (int i = 1; i <= clr; i++)
		{
			for (int j = 1; j <= clr; j++)
			{
				if (i == j)
				{
					edge[i][j] = 0;
				}
				else
				{
					edge[i][j] = 2000;
				}
			}
		}

		// build edges
		int a, b;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (grid[i][j] == '.')
				{
					continue;
				}
				// along right
				for (int k = j + 2; k < c; k++)
				{
					if (i - 1 >= 0 && grid[i - 1][k] == '#' && col[i - 1][k] != col[i][j])
					{
						a = col[i - 1][k];
						b = col[i][j];
						edge[a][b] = min(edge[a][b], k - j - 1);
						edge[b][a] = min(edge[b][a], k - j - 1);
					}
					if (grid[i][k] == '#' && col[i][k] != col[i][j])
					{
						a = col[i][k];
						b = col[i][j];
						edge[a][b] = min(edge[a][b], k - j - 1);
						edge[b][a] = min(edge[b][a], k - j - 1);
					}
					if (i + 1 < r && grid[i + 1][k] == '#' && col[i + 1][k] != col[i][j])
					{
						a = col[i + 1][k];
						b = col[i][j];
						edge[a][b] = min(edge[a][b], k - j - 1);
						edge[b][a] = min(edge[b][a], k - j - 1);
					}
				}
				// along downward
				for (int k = i + 2; k < r; k++)
				{
					if (j - 1 >= 0 && grid[k][j - 1] == '#' && col[k][j - 1] != col[i][j])
					{
						a = col[k][j - 1];
						b = col[i][j];
						edge[a][b] = min(edge[a][b], k - i - 1);
						edge[b][a] = min(edge[b][a], k - i - 1);
					}
					if (grid[k][j] == '#' && col[k][j] != col[i][j])
					{
						a = col[k][j];
						b = col[i][j];
						edge[a][b] = min(edge[a][b], k - i - 1);
						edge[b][a] = min(edge[b][a], k - i - 1);
					}
					if (j + 1 < c && grid[k][j + 1] == '#' && col[k][j + 1] != col[i][j])
					{
						a = col[k][j + 1];
						b = col[i][j];
						edge[a][b] = min(edge[a][b], k - i - 1);
						edge[b][a] = min(edge[b][a], k - i - 1);
					}
				}
			}
		}
		int num = 0;
		for (int i = 1; i <= clr; i++)
		{
			for (int j = i + 1; j <= clr; j++)
			{
				E ed;
				ed.x = i;
				ed.y = j;
				ed.w = min(edge[i][j], edge[j][i]);
				if (ed.w != 2000)
				{
					lst[num++] = ed;
				}
			}
		}

		sort(lst, lst + num, cmp);
		for (int i = 1; i <= clr; i++)
		{
			set_[i] = i;
		}
		int cnt = 0, cost = 0;
		for (int i = 0; i < num && cnt <= clr - 1; i++)
		{
			a = lst[i].x;
			b = lst[i].y;
			if (!isunion(a, b))
			{
				makeunion(a, b);
				++cnt;
				cost += lst[i].w;
			}
		}

		if (cnt == 0)
		{
			printf("No bridges are possible.\n", cost);
		}
		else if (cnt == 1)
		{
			printf("1 bridge of total length %d\n", cost);
		}
		else
		{
			printf("%d bridges of total length %d\n", cnt, cost);
		}
		int disc = clr - cnt;
		if (disc > 1)
		{
			printf("%d disconnected groups\n", disc);
		}
	}
	return 0;
}
