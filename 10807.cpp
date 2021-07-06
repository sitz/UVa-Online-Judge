#include <bits/stdc++.h>

using namespace std;

#define INF 999999999

struct edge {int a, b, c; bool v;} e[25];
int p[11], p2[11], n, m, min_;

int cmp(const void *a, const void *b)
{
	edge *c = (edge *)a, *d = (edge *)b;
	return c->c - d->c;
}

int find(int x)
{
	while (p[x] > 0)
	{
		x = p[x];
	}
	return x;
}

int find2(int x)
{
	while (p2[x] > 0)
	{
		x = p2[x];
	}
	return x;
}

void union_(int x, int y)
{
	if (p[x] > p[y])
	{
		p[y] += p[x];
		p[x] = y;
	}
	else
	{
		p[x] += p[y];
		p[y] = x;
	}
}

void union_2(int x, int y)
{
	if (p2[x] > p2[y])
	{
		p2[y] += p2[x];
		p2[x] = y;
	}
	else
	{
		p2[x] += p2[y];
		p2[y] = x;
	}
}

int mst(int bound)
{
	for (int i = 1; i <= n; i++)
	{
		p2[i] = -1;
	}
	int count = 0, sum = 0;
	for (int i = 0; i < m && count < n - 1; i++)
	{
		if (e[i].v)
		{
			continue;
		}
		int pa = find2(e[i].a), pb = find2(e[i].b);
		if (pa != pb)
		{
			union_2(pa, pb);
			count++;
			sum += e[i].c;
			if (sum >= bound)
			{
				return INF;
			}
		}
	}
	return (count == n - 1) ? sum : INF;
}

void dfs(int choose, int from, int weight)
{
	if (choose == n - 1)
	{
		if (weight < min_)
		{
			int second = mst(min_ - weight);
			if (weight + second < min_)
			{
				min_ = weight + second;
			}
		}
	}
	else if (choose + m - from >= n - 1)
	{
		if (weight + e[from].c * (n - 1 - m + from) >= min_)
		{
			return;
		}
		int tpa = find(e[from].a), tpb = find(e[from].b);
		if (tpa != tpb)
		{
			int a = p[tpa], b = p[tpb];
			union_(tpa, tpb);
			e[from].v = true;
			dfs(choose + 1, from + 1, weight + e[from].c);
			p[tpa] = a;
			p[tpb] = b;
			e[from].v = false;
		}
		if (weight < min_)
		{
			dfs(choose, from + 1, weight);
		}
	}
}

int main()
{
	while (scanf("%d", &n), n)
	{
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &e[i].a, &e[i].b, &e[i].c);
			e[i].v = false;
		}
		qsort(e, m, sizeof(edge), cmp);
		min_ = INF;
		for (int i = 1; i <= n; i++)
		{
			p[i] = -1;
		}
		dfs(0, 0, 0);
		if (min_ != INF)
		{
			printf("%d\n", min_);
		}
		else
		{
			puts("No way!");
		}
	}
	return 0;
}
