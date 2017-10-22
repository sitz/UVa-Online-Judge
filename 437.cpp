#include <bits/stdc++.h>

using namespace std;

#define MAXN 256
typedef struct Babylon
{
	int t[4];
};
Babylon a[MAXN] = {0};
int n, m, cas = 0;
int comp(Babylon p, Babylon q)
{
	for (int i = 0; i < 3; i++)
		if (p.t[i] > q.t[i])
		{
			return 1;
		}
		else if (p.t[i] < q.t[i])
		{
			return 0;
		}
	return 0;
}
void Qsort(int x, int y)
{
	if (x >= y)
	{
		return;
	}
	int p = x, q = y;
	Babylon F = a[x];
	while (p < q)
	{
		while (p < q && comp(a[q], F))
		{
			q--;
		}
		if (p < q)
		{
			a[p++] = a[q];
		}
		while (p < q && !comp(a[p], F))
		{
			p++;
		}
		if (p < q)
		{
			a[q--] = a[p];
		}
	}
	a[p] = F;
	Qsort(x, p - 1);
	Qsort(p + 1, y);
}
int cmpare(int *p, int *q)
{
	if (p[0] <= q[0] || p[1] <= q[1])
	{
		return 0;
	}
	return 1;
}
void DAG()
{
	int b[MAXN] = {0}, maxs = 0;
	b[0] = a[0].t[2];
	for (int i = 1; i < m; i++)
	{
		b[i] = a[i].t[2];
		for (int j = 0; j < i; j++)
			if (cmpare(a[i].t, a[j].t) && b[i] < b[j] + a[i].t[2])
			{
				b[i] = b[j] + a[i].t[2];
			}
		if (maxs < b[i])
		{
			maxs = b[i];
		}
	}
	printf("Case %d: maximum height = %d\n", ++cas, maxs);
}
int main()
{
	int h[4] = {0};
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		m = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d", &h[0], &h[1], &h[2]);
			a[m].t[0] = h[0];
			a[m].t[1] = h[1];
			a[m++].t[2] = h[2];
			a[m].t[0] = h[0];
			a[m].t[1] = h[2];
			a[m++].t[2] = h[1];
			a[m].t[0] = h[1];
			a[m].t[1] = h[0];
			a[m++].t[2] = h[2];
			a[m].t[0] = h[1];
			a[m].t[1] = h[2];
			a[m++].t[2] = h[0];
			a[m].t[0] = h[2];
			a[m].t[1] = h[0];
			a[m++].t[2] = h[1];
			a[m].t[0] = h[2];
			a[m].t[1] = h[1];
			a[m++].t[2] = h[0];
		}
		Qsort(0, m - 1);
		DAG();
	}
	return 0;
}
