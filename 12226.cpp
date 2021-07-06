#include <bits/stdc++.h>

using namespace std;

#define MAX 1 << 29

const double eps = 1e-10;

typedef struct List
{
	double x, y, deg;
	int id;
} LIST;
LIST a[2005];

int com(const void *aa, const void *bb)
{
	LIST c, d;
	c = *(LIST *)(aa);
	d = *(LIST *)(bb);
	if (c.deg - d.deg > eps)
	{
		return 1;
	}
	else if (c.deg - d.deg < -eps)
	{
		return -1;
	}
	return 0;
}

int main()
{
	int T, N, n, i, j;
	double cx, cy;
	scanf(" %d", &T);
	while (T--)
	{
		scanf(" %d", &N);
		cx = cy = 0.0000;
		for (n = 0; n < N; n++)
		{
			scanf(" %lf %lf", &a[n].x, &a[n].y);
			a[n].id = n;
			cx += a[n].x;
			cy += a[n].y;
		}
		cx /= (double)N;
		cy /= (double)N;
		for (n = 0; n < N; n++)
		{
			a[n].deg = atan2((a[n].y - cy), (a[n].x - cx));
		}
		qsort(a, N, sizeof(a[0]), com);
		for (n = 0; n < N; n++)
		{
			if (n == 0)
			{
				printf("%d", a[n].id);
			}
			else
			{
				printf(" %d", a[n].id);
			}
		}
		printf("\n");
	}
	return 0;
}
