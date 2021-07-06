#include <bits/stdc++.h>

using namespace std;

struct Edge
{
	int a, b, c;
} e[1000];
int compare(const void *a, const void *b)
{
	return ((Edge *)a)->c - ((Edge *)b)->c;
}
int p[201], m, n, q, s, d;
int find(int s)
{
	while (p[s] > 0)
	{
		s = p[s];
	}
	return s;
}
void unions(int a, int b)
{
	int pa = find(a), pb = find(b);
	if (p[pa] > p[pb])
	{
		p[pb] = +p[pa], p[pa] = pb;
	}
	else
	{
		p[pa] += p[pb], p[pb] = pa;
	}
}
int run()
{
	int min = 99999999;
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			p[j] = -1;
		}
		for (int j = i; j < m; j++)
		{
			if (e[j].c - e[i].c > min)
			{
				break;
			}
			if (find(e[j].a) == find(e[j].b))
			{
				continue;
			}
			unions(e[j].a, e[j].b);
			if (find(s) == find(d))
			{
				min = e[j].c - e[i].c;
				break;
			}
		}
	}
	return min;
}
int main()
{
	int k1, k2;
	while (scanf("%d %d", &n, &m) == 2)
	{
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &e[i].a, &e[i].b, &e[i].c);
		}
		qsort(e, m, sizeof(Edge), compare);
		scanf("%d %d", &k1, &k2);
		scanf("%d", &q);
		for (int i = 0; i < q; i++)
		{
			scanf("%d %d", &s, &d);
			printf("%d\n", run() + k1 + k2);
		}
	}
	return 0;
}
