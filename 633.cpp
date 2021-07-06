#include <bits/stdc++.h>

using namespace std;

struct Step {int x, y, dist, type;};
Step queue_[5000], start, end_;

bool state[41][41][3];
char map_[41][41];
int dist[41][41], front, rear, n;

int input()
{
	int i, j, k, tx, ty;
	scanf("%d", &n);
	if (!n)
	{
		return 0;
	}
	n *= 2;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			map_[i][j] = ' ';
			dist[i][j] = 999999;
			for (k = 0; k < 3; k++)
			{
				state[i][j][k] = false;
			}
		}
	}
	scanf("%d %d", &start.x, &start.y);
	start.type = -1;
	start.dist = 0;
	scanf("%d %d", &end_.x, &end_.y);
	while (true)
	{
		scanf("%d %d", &tx, &ty);
		if (!tx && !ty)
		{
			break;
		}
		map_[tx][ty] = '#';
	}
	return 1;
}
void run0(Step u)
{
	int tx, ty;
	int dirx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int diry[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	Step v;
	v.type = 0;
	v.dist = u.dist + 1;
	for (int i = 0; i < 8; i++)
	{
		tx = u.x + dirx[i];
		ty = u.y + diry[i];
		if (tx > 0 && tx <= n && ty > 0 && ty <= n && !state[tx][ty][0] && map_[tx][ty] != '#')
		{
			state[tx][ty][0] = true;
			v.x = tx;
			v.y = ty;
			queue_[++rear] = v;
		}
	}
}
void run1(Step u)
{
	int tx, ty;
	int dirx[4] = {2, 2, -2, -2};
	int diry[4] = {2, -2, 2, -2};
	Step v;
	v.type = 1;
	v.dist = u.dist + 1;
	for (int i = 0; i < 4; i++)
	{
		tx = u.x + dirx[i];
		ty = u.y + diry[i];
		if (tx > 0 && tx <= n && ty > 0 && ty <= n && !state[tx][ty][1] && map_[tx][ty] != '#')
		{
			state[tx][ty][1] = true;
			v.x = tx;
			v.y = ty;
			queue_[++rear] = v;
		}
	}
}
void run2(Step u)
{
	int tx, ty;
	Step v;
	v.type = 2;
	v.dist = u.dist + 1;
	tx = n + 1 - u.x;
	ty = u.y;
	if (tx > 0 && tx <= n && ty > 0 && ty <= n && !state[tx][ty][2] && map_[tx][ty] != '#')
	{
		state[tx][ty][2] = true;
		v.x = tx;
		v.y = ty;
		queue_[++rear] = v;
	}
	tx = u.x;
	ty = n + 1 - u.y;
	if (tx > 0 && tx <= n && ty > 0 && ty <= n && !state[tx][ty][2] && map_[tx][ty] != '#')
	{
		state[tx][ty][2] = true;
		v.x = tx;
		v.y = ty;
		queue_[++rear] = v;
	}
}
void solve()
{
	Step u, v;
	front = -1, rear = 0;
	queue_[0] = start;
	while (front < rear)
	{
		u = queue_[++front];
		if (u.dist < dist[u.x][u.y])
		{
			dist[u.x][u.y] = u.dist;
		}
		if (u.type != 0)
		{
			run0(u);
		}
		if (u.type != 1)
		{
			run1(u);
		}
		if (u.type != 2)
		{
			run2(u);
		}
	}
	if (dist[end_.x][end_.y] != 999999)
	{
		printf("Result : %d\n", dist[end_.x][end_.y]);
	}
	else
	{
		puts("Solution doesn't exist");
	}
}
int main()
{
	while (input())
	{
		solve();
	}
}
