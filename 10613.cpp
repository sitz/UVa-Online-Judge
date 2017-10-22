#include <bits/stdc++.h>

using namespace std;

#define sqr(r) ((r) * (r))

struct Circle {double x, y, r;} c[1000];

struct Inteval {int up, down;} inte[1000];

int compare(const void *a, const void *b)
{
	Inteval *c = (Inteval *)a, *d = (Inteval *)b;
	if (c->up != d->up)
	{
		return d->up - c->up;
	}
	else
	{
		return c->down - d->down;
	}
}
int calc(int len)
{
	int sum = 0;
	int p = 99999999;
	for (int i = 0; i < len; i++)
	{
		if (inte[i].down >= p)
		{
			continue;
		}
		if (inte[i].up < p)
		{
			p = inte[i].up;
		}
		sum += p - inte[i].down;
		p = inte[i].down;
	}
	return sum;
}

int size, n, left_, right_;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &size, &n);
		left_ = 99999999;
		right_ = -99999999;
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf%lf", &c[i].x, &c[i].y, &c[i].r);
			int l = (int)floor(c[i].x - c[i].r);
			if (l < left_)
			{
				left_ = l;
			}
			if (left_ < 0)
			{
				left_ = 0;
			}
			int r = (int)ceil(c[i].x + c[i].r);
			if (r > right_)
			{
				right_ = r;
			}
			if (right_ > size)
			{
				right_ = size;
			}
		}
		int total = 0;
		for (int i = left_; i < right_; i++)
		{
			int a = i, b = i + 1, p = 0;
			for (int j = 0; j < n; j++)
			{
				double k;
				if (a <= c[j].x && c[j].x <= b)
				{
					k = 0;
				}
				else if (fabs(c[j].x - a) < fabs(c[j].x - b))
				{
					k = c[j].x - a;
				}
				else
				{
					k = c[j].x - b;
				}
				double t = (sqr(c[j].r) - sqr(k));
				if (t > 0)
				{
					t = sqrt(t);
					inte[p].up = (int)ceil(c[j].y + t);
					if (inte[p].up > size)
					{
						inte[p].up = size;
					}
					inte[p].down = (int)floor(c[j].y - t);
					if (inte[p].down < 0)
					{
						inte[p].down = 0;
					}
					p++;
				}
			}
			if (!p)
			{
				continue;
			}
			qsort(inte, p, sizeof(Inteval), compare);
			int count = calc(p);
			total += count;
		}
		printf("%d\n", total);
	}
	return 0;
}
