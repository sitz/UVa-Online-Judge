#include <bits/stdc++.h>

using namespace std;

const int MaxSize = 200;

int n, ans, Max;

struct node
{
	int x, y;
	char ch;
} temp, temp1, temp2, map_[MaxSize][MaxSize];

queue<node> q, tr1, tr2;

bool input()
{
	int i, j, up;
	if (EOF == scanf("%d", &n) || n == 0)
	{
		return false;
	}
	up = 2 * n;
	memset(map_, 0, sizeof(map_));
	for (i = 0; i < n; ++i)
	{
		getchar();
		--up;
		for (j = 0; j < up; ++j)
		{
			scanf("%c", &map_[i][j].ch);
			map_[i][j].x = i;
			map_[i][j].y = j;
			if (map_[i][j].ch == '-')
			{
				tr1.push(map_[i][j]);
				tr2.push(map_[i][j]);
			}
		}
	}
	return true;
}

bool check(int row, int from, int to)
{
	if (row >= n || row < 0 || from < 0)
	{
		return false;
	}
	int i;
	for (i = from; i <= to; ++i)
		if (map_[row][i].ch != '-')
		{
			return false;
		}
	return true;
}

int bfs1()
{
	int tans;
	while (!q.empty())
	{
		q.pop();
	}
	while (!tr1.empty())
	{
		temp1 = tr1.front();
		tr1.pop();
		tans = temp1.x;
		if ((temp1.x + temp1.y) % 2 == 0)
		{
			continue;
		}
		q.push(temp1);
		q.push(temp1);
		while (!q.empty())
		{
			temp1 = q.front();
			q.pop();
			temp2 = q.front();
			q.pop();
			ans = max(ans, temp1.x - tans + 1);
			if (check(temp1.x + 1, temp1.y - 1, temp2.y + 1))
			{
				q.push(map_[temp1.x + 1][temp1.y - 1]);
				q.push(map_[temp1.x + 1][temp2.y + 1]);
			}
		}
	}
	return ans;
}

int bfs2()
{
	int tans;
	while (!q.empty())
	{
		q.pop();
	}
	while (!tr2.empty())
	{
		temp1 = tr2.front();
		tr2.pop();
		tans = temp1.x;
		if ((temp1.x + temp1.y) % 2)
		{
			continue;
		}
		q.push(temp1);
		q.push(temp1);
		while (!q.empty())
		{
			temp1 = q.front();
			q.pop();
			temp2 = q.front();
			q.pop();
			ans = max(ans, tans - temp1.x + 1);
			if (check(temp1.x - 1, temp1.y - 1, temp2.y + 1))
			{
				q.push(map_[temp1.x - 1][temp1.y - 1]);
				q.push(map_[temp1.x - 1][temp2.y + 1]);
			}
		}
	}
	return ans;
}

void bfs()
{
	ans = 0;
	bfs1();
	bfs2();
	printf("The largest triangle area is %d.\n\n", ans * ans);
}

int main()
{
	int cases;
	for (cases = 1; input(); ++cases)
	{
		printf("Triangle #%d\n", cases);
		bfs();
	}
	return 0;
}
