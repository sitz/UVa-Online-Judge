#include <bits/stdc++.h>

using namespace std;

#define N 10005

struct Point
{
	int x, y;
	Point(){};
	Point(int _x, int _y)
	{
		x = _x, y = _y;
	}
} p[N];

bool solve(Point &ave, int n)
{
	if ((ave.x % n) || (ave.y % n))
	{
		return 0;
	}
	ave.x /= n, ave.y /= n;
	for (int i = 0; i < n; i++)
	{
		int x = 2 * ave.x - p[i].x;
		int y = 2 * ave.y - p[i].y;
		bool mk = 0;
		for (int j = 0; j < n; j++)
		{
			if (x == p[j].x && y == p[j].y)
			{
				mk = 1;
				break;
			}
		}
		if (!mk)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		Point ave(0, 0);
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &p[i].x, &p[i].y);
			ave.x += p[i].x, ave.y += p[i].y;
		}
		if ((n == 1) || solve(ave, n))
		{
			puts("yes");
		}
		else
		{
			puts("no");
		}
	}
	return 0;
}
