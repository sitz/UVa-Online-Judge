#include <bits/stdc++.h>

using namespace std;

const int oo = 0x7fffffff;

int numOfCase, numOfBeepers;
int sizeX, sizeY;
int shortest;
bool visited[15];

struct Position
{
	int x, y;
} start, beepers[15];

int CalDistance(Position from, Position to)
{
	return (int)(fabs(from.x - to.x) + fabs(from.y - to.y));
}

void Backtrace(Position now, int index, int cost)
{
	if (index >= numOfBeepers)
	{
		cost += CalDistance(start, now);
		if (cost < shortest)
		{
			shortest = cost;
		}
		return;
	}
	if (cost > shortest)
	{
		return;
	}
	int k;
	Position last = now;
	for (k = 0; k < numOfBeepers; k++)
	{
		if (visited[k] == false)
		{
			visited[k] = true;
			now = beepers[k];
			Backtrace(now, index + 1, cost + CalDistance(now, last));
			now = last;
			visited[k] = false;
		}
	}
}

int main()
{
	scanf("%d", &numOfCase);
	while (numOfCase--)
	{
		scanf("%d%d", &sizeX, &sizeY);
		scanf("%d%d", &start.x, &start.y);
		scanf("%d", &numOfBeepers);
		int i;
		for (i = 0; i < numOfBeepers; i++)
		{
			scanf("%d%d", &beepers[i].x, &beepers[i].y);
		}
		shortest = oo;
		memset(visited, 0, sizeof(visited));
		Backtrace(start, 0, 0);
		printf("The shortest path has length %d\n", shortest);
	}
	return 0;
}
