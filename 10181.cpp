#include <bits/stdc++.h>

using namespace std;

#define LEN 4
#define IDA_MAX 1000
#define MAX 100
#define BASE 6731

const char direct[5] = "URLD";
const int step[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
const int answer[LEN][LEN] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};

bool flag;
int rev[LEN * LEN][2], pre[LEN * LEN][LEN][LEN], map_[LEN][LEN], ans[100], c1, c2, anscnt;

bool valid(int x, int y)
{
	return x >= 0 && y >= 0 && x < LEN && y < LEN;
}

int abs(int p)
{
	if (p < 0)
	{
		return -p;
	}
	return p;
}
int Heuristic(int map_[LEN][LEN])
{
	bool found = 0;
	int p1, q1, p2, q2, x = 0;
	for (p1 = 0; p1 < LEN; p1++)
	{
		for (q1 = 0; q1 < LEN; q1++)
		{
			if (answer[p1][q1])
			{
				for (p2 = 0, found = 0; p2 < LEN; p2++)
				{
					for (q2 = 0; q2 < LEN; q2++)
					{
						if (map_[p2][q2] == answer[p1][q1])
						{
							x += (abs(p1 - p2) + abs(q1 - q2));
							found = 1;
							break;
						}
					}
					if (found)
					{
						break;
					}
				}
			}
		}
	}
	return x;
}

int IDA_DFS(int bound, int depth, int nscore, int nx, int ny)
{
	if (nscore > bound)
	{
		return nscore;
	}
	if (nscore - depth + 1 == 0)
	{
		flag = 1;
		return -1;
	}
	int k, next = IDA_MAX, tmp, tx, ty, tscore;
	for (k = 0; k < 4; k++)
	{
		tx = nx + step[k][0], ty = ny + step[k][1];
		if (!valid(tx, ty))
		{
			continue;
		}
		if (k + ans[anscnt - 1] == 3)
		{
			continue;
		}
		tmp = map_[tx][ty], map_[nx][ny] = map_[tx][ty], map_[tx][ty] = 0;
		tscore = nscore - pre[tmp][tx][ty] + pre[tmp][nx][ny] + 1;
		ans[anscnt++] = k;
		tmp = IDA_DFS(bound, depth + 1, tscore, tx, ty);
		if (flag)
		{
			return -1;
		}
		if (tmp < next)
		{
			next = tmp;
		}
		map_[tx][ty] = map_[nx][ny], map_[nx][ny] = 0;
		anscnt--;
	}
	return next;
}

int main()
{
	int i, j, k, t, num, cnt, a, b, c, d, bound, x, y, score;
	for (k = 0; k < LEN * LEN; k++)
	{
		for (i = 0; i < LEN; i++)
		{
			for (j = 0; j < LEN; j++)
			{
				if (answer[i][j] == k)
				{
					rev[k][0] = i, rev[k][1] = j;
				}
			}
		}
	}
	for (k = 0; k < LEN * LEN; k++)
	{
		for (i = 0; i < LEN; i++)
		{
			for (j = 0; j < LEN; j++)
			{
				pre[k][i][j] = abs(i - rev[k][0]) + abs(j - rev[k][1]);
			}
		}
	}
	scanf("%ld", &cnt), ans[0] = -1;
	for (t = 0; t < cnt; t++)
	{
		for (i = 0; i < LEN; i++)
		{
			for (j = 0; j < LEN; j++)
			{
				scanf("%d", &map_[i][j]);
			}
		}
		for (i = 0; i < LEN; i++)
		{
			for (j = 0; j < LEN; j++)
			{
				if (map_[i][j] == 0)
				{
					x = i, y = j, map_[i][j] = 16;
				}
			}
		}
		score = Heuristic(map_);
		for (a = 0, k = x + y; a < LEN; a++)
		{
			for (b = 0; b < LEN; b++)
			{
				for (c = 0; c < LEN; c++)
				{
					for (d = 0; d < LEN; d++)
					{
						if (((a * LEN + b) < (c * LEN + d)) && map_[a][b] > map_[c][d])
						{
							k++;
						}
					}
				}
			}
		}
		map_[x][y] = 0;
		if (score == 0)
		{
			printf("\n");
			continue;
		}
		else if (k % 2 == 1)
		{
			printf("This puzzle is not solvable.\n");
			continue;
		}
		bound = 46;
		anscnt = 1;
		for (flag = 0; !flag;)
		{
			bound = IDA_DFS(bound, 1, score, x, y);
		}
		for (i = 1; i < anscnt; i++)
		{
			printf("%c", direct[ans[i]]);
		}
		printf("\n");
	}
	return 0;
}
