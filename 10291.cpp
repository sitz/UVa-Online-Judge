#include <bits/stdc++.h>

using namespace std;

struct Point
{
	double x, y;
} p[51];
Point origin = {0, 0};
int len[51];
int n, ptr, total;
const double PI = 3.1415926535897932384626433832795;
double cross(Point &a, Point &b, Point &ref)
{
	return (a.x - ref.x) * (b.y - ref.y) - (a.y - ref.y) * (b.x - ref.x);
}
bool check()
{
	double area = 0;
	for (int i = 0; i < ptr; i++)
	{
		area += p[i].x * p[i + 1].y - p[i].y * p[i + 1].x;
	}
	area = fabs(area) * 0.5;
	double sum = 0;
	for (int i = 0; i < ptr; i++)
	{
		double c = cross(p[i], p[i + 1], origin);
		c = fabs(c) * 0.5;
		if (c <= 1e-10)
		{
			return false;
		}
		sum += c;
	}
	if (fabs(sum - area) <= 1e-10)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int x = 0;
	while (scanf("%d", &n) == 1)
	{
		int min = 99999999;
		if (!n)
		{
			break;
		}
		if (x++)
		{
			puts("");
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &len[i]);
		}
		for (int i = 0; i < n; i++)
		{
			ptr = total = 0;
			for (int j = 0; j < n; j++)
			{
				if (len[j] >= len[i])
				{
					p[ptr].x = cos(2 * j * PI / n);
					p[ptr].y = sin(2 * j * PI / n);
					ptr++;
					total += len[j] - len[i];
				}
			}
			p[ptr] = p[0];
			if (ptr < 3)
			{
				continue;
			}
			if (check() && total < min)
			{
				min = total;
			}
		}
		printf("%d\n", min);
	}
	return 0;
}
