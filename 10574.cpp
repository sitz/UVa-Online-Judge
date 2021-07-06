#include <bits/stdc++.h>

using namespace std;

/*
10574
Counting Rectangles
*/
#define MAXN 5005
int np;
struct ss
{
	int x, y;
} point[MAXN], dum;
int A[5000], B[5000];
int cur, inda, indb;
int com(const void *a, const void *b)
{
	ss *p, *q;
	p = (ss *)a;
	q = (ss *)b;
	if (p->x == q->x)
	{
		return p->y - q->y;
	}
	return p->x - q->x;
}
int com1(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int Match()
{
	int i, j, count = 0, mt = 0;
	int p = 0, f = B[indb - 1];
	for (i = 0; i < inda; i++)
	{
		if (A[inda - 1] < B[p])
		{
			break;
		}
		for (j = p; j < indb; j++)
		{
			if (A[i] < B[j])
			{
				p = j;
				break;
			}
			if (A[i] == B[j])
			{
				mt++;
				p = j + 1;
				break;
			}
		}
	}
	count = (mt * (mt - 1)) / 2;
	return count;
}
int Cal(int mm)
{
	int j, nt, count = 0;
	cur = point[mm].x;
	indb = 0;
	nt = mm;
	cur = point[nt].x;
	while (nt < np)
	{
		for (j = nt; j < np && point[j].x == cur; j++)
		{
			B[indb++] = point[j].y;
		}
		if (indb > 1)
		{
			count += Match();
		}
		nt = j;
		cur = point[nt].x;
		indb = 0;
	}
	return count;
}
void Select()
{
	int i, k, c = 0;
	int nt = 0, cur = point[0].x;
	while (nt < np)
	{
		k = 0;
		inda = 0;
		for (i = nt; i < np && point[i].x == cur; i++)
		{
			A[inda++] = point[i].y;
		}
		nt = i;
		if (nt >= np - 1)
		{
			break;
		}
		cur = point[i].x;
		if (inda <= 1)
		{
			continue;
		}
		c += Cal(nt);
	}
	printf("%d\n", c);
}
int main()
{
	int kase, i, f = 1;
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%d", &np);
		for (i = 0; i < np; i++)
		{
			scanf("%d%d", &point[i].x, &point[i].y);
		}
		qsort(point, np, sizeof(point[0]), com);
		printf("Case %d: ", f++);
		Select();
	}
	return 0;
}
