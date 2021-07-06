#include <bits/stdc++.h>

using namespace std;

/* by Michal Koucky  */
/*
    Reads input and compute graph components
*/
int n;
struct coords
{
	int x1, y1, x2, y2;
} st[16];			 /* straws endoipnts */
int comps[16]; /* list of components */
int connected(int a, int b)
/* 1 - if a,b geometricaly cconnected
   0 - otherwise */
{
	int d = (st[a].x2 - st[a].x1) * (st[b].y1 - st[b].y2) -
					(st[b].x1 - st[b].x2) * (st[a].y2 - st[a].y1);
	if (d) /* not parallel */
	{
		int dt = (st[a].x1 - st[b].x1) * (st[b].y1 - st[b].y2) -
						 (st[b].x1 - st[b].x2) * (st[a].y1 - st[b].y1);
		int ds = (st[a].x2 - st[a].x1) * (st[a].y1 - st[b].y1) -
						 (st[a].x1 - st[b].x1) * (st[a].y2 - st[a].y1);
		if (d < 0)
		{
			dt = -dt;
			ds = -ds;
			d = -d;
		}
		if (dt < -d || dt > 0 || ds < -d || ds > 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else /* parallel */
	{
		int dx = (st[a].x2 - st[a].x1) * (st[b].y1 - st[a].y2) -
						 (st[b].x1 - st[a].x2) * (st[a].y2 - st[a].y1);
		if (dx)
		{
			return 0;
		}
		if (((st[a].x1 <= st[b].x1 && st[b].x1 <= st[a].x2) || (st[b].x1 <= st[a].x1 && st[a].x1 <= st[b].x2)) && st[a].x1 != st[a].x2)
		{
			return 1;
		}
		if (((st[a].y1 <= st[b].y1 && st[b].y1 <= st[a].y2) || (st[b].y1 <= st[a].y1 && st[a].y1 <= st[b].y2)) && st[a].y1 != st[a].y2)
		{
			return 1;
		}
		return 0;
	}
	return 0;
}

void change(int a)
{
	int p;
	p = st[a].x1;
	st[a].x1 = st[a].x2;
	st[a].x2 = p;
	p = st[a].y1;
	st[a].y1 = st[a].y2;
	st[a].y2 = p;
}
int main()
{
	int i, j, k, a, b, d1, d2, cc;
	bool first = true;
	scanf("%d", &cc);
	while (cc--)
	{
		if (!first)
		{
			printf("\n");
		}
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%d%d%d%d", &(st[i].x1), &(st[i].y1), &(st[i].x2), &(st[i].y2));
			if (st[i].x1 > st[i].x2 || (st[i].x1 == st[i].x2 && st[i].y1 > st[i].y2))
			{
				change(i);
			}
			comps[i] = i;
		}
		for (i = 1; i <= n; i++)
			for (j = i + 1; j <= n; j++)
				if ((comps[i] != comps[j]) && connected(i, j))
				{
					d1 = comps[i];
					d2 = comps[j];
					for (k = 1; k <= n; k++)
						if (comps[k] == d1)
						{
							comps[k] = d2;
						}
				}
		scanf("%d%d", &a, &b);
		while (a && b)
		{
			if (comps[a] == comps[b])
			{
				printf("CONNECTED\n");
			}
			else
			{
				printf("NOT CONNECTED\n");
			}
			scanf("%d%d", &a, &b);
		}
		first = false;
	}
	return 0;
}
