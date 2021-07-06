#include <bits/stdc++.h>

using namespace std;

#define init(i, a, n)     \
	for (i = 0; i < n; i++) \
	a[i] = i
typedef struct edge
{
	int f, t;
	double d;
} E;
int getParent(int i, int *set)
{
	if (i == set[i])
	{
		return i;
	}
	else
	{
		return (set[i] = getParent(set[i], set));
	}
}
int isUnion(int a, int b, int *set)
{
	return getParent(a, set) == getParent(b, set);
}
void makeUnion(int a, int b, int *set)
{
	set[getParent(a, set)] = getParent(b, set);
}
int cmp(const void *a, const void *b)
{
	return (((E *)a)->d < ((E *)b)->d) ? -1 : 1;
}
int distance(int x1, int y1, int x2, int y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int main()
{
	E list[500505];
	int coordinates[1005][2], i, j, c, cc, v, t, d, top, set[1005], states;
	double roads, railroads;
	scanf("%d", &c);
	cc = 1;
	while (c--)
	{
		v = 0;
		scanf("%d %d", &v, &t);
		for (i = 0; i < v; i++)
		{
			scanf("%d %d", coordinates[i], coordinates[i] + 1);
		}
		top = 0;
		for (i = 0; i < v; i++)
			for (j = i + 1; j < v; j++)
			{
				list[top].f = i;
				list[top].t = j;
				list[top].d = sqrt(distance(coordinates[i][0], coordinates[i][1], coordinates[j][0], coordinates[j][1]));
				top++;
			}
		qsort(list, top, sizeof(E), &cmp);
		d = 0;
		roads = 0;
		railroads = 0;
		states = 0;
		;
		init(i, set, v);
		for (i = 0; i < top && d < v - 1; i++)
		{
			if (!isUnion(list[i].f, list[i].t, set))
			{
				makeUnion(list[i].f, list[i].t, set);
				d++;
				if (list[i].d > t)
				{
					railroads += list[i].d;
					states++;
				}
				else
				{
					roads += list[i].d;
				}
			}
		}
		printf("Case #%d: %d %.lf %.lf\n", cc++, states + 1, roads, railroads);
	}
	return 0;
}
