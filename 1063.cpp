#include <bits/stdc++.h>

using namespace std;

int mx[4] = {0, 0, 1, -1}, my[4] = {1, -1, 0, 0};
struct board
{
	char s[4][4];
	board() {}
	board(char t[4][4])
	{
		memcpy(s, t, 16);
	}
	bool operator<(board rhs) const
	{
		int i, j;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (s[i][j] < rhs.s[i][j])
				{
					return true;
				}
				else if (s[i][j] > rhs.s[i][j])
				{
					return false;
				}
			}
		}
		return false;
	}
};
bool wall[4][4][4];
int main()
{
	map<board, int> dis;
	queue<board> q;
	char t[4][4];
	int n, m, w, i, j, k, x1, y1, x2, y2, d, cs = 1;
	while (scanf("%d%d%d", &n, &m, &w), n || m || w)
	{
		memset(wall, 0, sizeof(wall));
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < n; j++)
			{
				for (k = 0; k < n; k++)
				{
					if (j + mx[i] < 0 || j + mx[i] >= n || k + my[i] < 0 || k + my[i] >= n)
					{
						wall[i][j][k] = true;
					}
				}
			}
		}
		memset(t, 0, sizeof(t));
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d", &x1, &y1);
			t[x1][y1] = i;
		}
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d", &x1, &y1);
			t[x1][y1] = -i;
		}
		for (i = 0; i < w; i++)
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			for (j = 0; j < 4; j++)
			{
				if (x2 == x1 + mx[j] && y2 == y1 + my[j])
				{
					wall[j][x1][y1] = true;
					wall[j ^ 1][x2][y2] = true;
					break;
				}
			}
		}
		dis.clear();
		dis[board(t)] = 0;
		q.push(board(t));
		while (!q.empty())
		{
			d = dis[q.front()];
			for (i = 0; i < 4; i++)
			{
				bool flag, wrong = false;
				memcpy(t, q.front().s, 16);
				do
				{
					flag = false;
					for (j = 0; j < n; j++)
					{
						for (k = 0; k < n; k++)
						{
							if (t[j][k] <= 0 || wall[i][j][k])
							{
								continue;
							}
							else
							{
								x1 = j + mx[i];
								y1 = k + my[i];
								if (t[x1][y1] > 0)
								{
									continue;
								}
								else if (t[x1][y1] == 0)
								{
									t[x1][y1] = t[j][k];
									t[j][k] = 0;
									flag = true;
								}
								else
								{
									if (t[x1][y1] + t[j][k] != 0)
									{
										wrong = true;
										j = n;
										k = n;
									}
									else
									{
										t[x1][y1] = t[j][k] = 0;
										flag = true;
									}
								}
							}
						}
					}
				} while (flag && !wrong);
				if (!wrong && !dis.count(board(t)))
				{
					dis[board(t)] = d + 1;
					q.push(board(t));
				}
			}
			q.pop();
		}
		memset(t, 0, 16);
		if (dis.count(board(t)))
		{
			printf("Case %d: %d moves\n\n", cs++, dis[board(t)]);
		}
		else
		{
			printf("Case %d: impossible\n\n", cs++);
		}
	}
	return 0;
}
