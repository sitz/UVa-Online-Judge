#include <bits/stdc++.h>

using namespace std;

struct node
{
	int x, y;
} queue_[1000];

int dir[4][2] = {-1, 0, 0, -1, 0, 1, 1, 0};

char map_[20][20], ans[35], stk[35];
int n, m, max_, flag, total;

bool yes(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}
int bfs(int x, int y)
{
	node t;
	char g[20][20];
	for (int i = 0; i < n; i++)
	{
		strcpy(g[i], map_[i]);
	}
	int head, tail;
	head = tail = 0;
	t.x = x, t.y = y;
	queue_[tail++] = t;
	while (head < tail)
	{
		x = queue_[head].x;
		y = queue_[head++].y;
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if (!yes(xx, yy) || g[xx][yy] == '#')
			{
				continue;
			}
			g[xx][yy] = '#';
			t.x = xx, t.y = yy;
			queue_[tail++] = t;
		}
	}
	return head;
}
void dfs(int x, int y, int cnt)
{
	if (max_ < cnt || (max_ == cnt && flag == 1))
	{
		stk[cnt] = 0;
		strcpy(ans, stk);
		max_ = cnt;
		flag = 0;
	}
	int res = bfs(x, y);
	if (res + cnt - 1 < max_ || (res + cnt - 1 == max_ && flag == -1))
	{
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if (!yes(xx, yy) || map_[xx][yy] == '#')
		{
			continue;
		}
		if (flag != 1 && ans[cnt] > map_[xx][yy] && total == max_)
		{
			continue;
		}
		stk[cnt] = map_[xx][yy];
		map_[xx][yy] = '#';
		if (flag == 0)
		{
			if (cnt >= max_)
			{
				flag = 1;
			}
			else if (ans[cnt] == stk[cnt])
			{
				flag = 0;
			}
			else if (ans[cnt] < stk[cnt])
			{
				flag = 1;
			}
			else
			{
				flag = -1;
			}
			dfs(xx, yy, cnt + 1);
			flag = 0;
		}
		else
		{
			dfs(xx, yy, cnt + 1);
		}
		map_[xx][yy] = stk[cnt];
	}
}
int main()
{
	while (scanf("%d%d", &n, &m) && n + m)
	{
		total = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", map_ + i);
			for (int j = 0; j < m; j++)
			{
				if (map_[i][j] != '#')
				{
					total++;
				}
			}
		}
		max_ = 1;
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map_[i][j] == '#')
				{
					continue;
				}
				if (max_ == total && ans[0] > map_[i][j])
				{
					continue;
				}
				stk[0] = map_[i][j];
				map_[i][j] = '#';
				if (ans[0] == stk[0])
				{
					flag = 0;
				}
				else if (ans[0] < stk[0])
				{
					flag = 1;
				}
				else
				{
					flag = -1;
				}
				dfs(i, j, 1);
				map_[i][j] = stk[0];
			}
		}
		printf("%s\n", ans);
	}
	return 0;
}
