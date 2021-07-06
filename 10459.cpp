#include <bits/stdc++.h>

using namespace std;

#define MAXN 5002

struct ss
{
	int *child;
	int deg1, deg2;
};
ss *node;
int *Worst, N, worst, Max, tw;
int *Leaf, tf;
char Fg[MAXN];

int com(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
void ReadCase()
{
	int i, j, v, ad;
	tf = 0;
	node = new ss[N + 2];
	Worst = new int[N + 2];
	Leaf = new int[N + 2];
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &ad);
		node[i].deg1 = node[i].deg2 = ad;
		if (ad == 1)
		{
			Leaf[tf++] = i;
			Fg[i] = 1;
		}
		node[i].child = new int[ad + 2];
		for (j = 0; j < ad; j++)
		{
			scanf("%d", &v);
			node[i].child[j] = v;
		}
	}
}
void FindBest()
{
	int i, j = 0, rem, u, v, k;
	rem = N;
	while (rem != tf)
	{
		for (i = 0; i < tf; i++)
		{
			u = Leaf[i];
			rem--;
			for (k = 0; k < node[u].deg2; k++)
			{
				v = node[u].child[k];
				if (Fg[v])
					continue;
				node[v].deg1--;
				if (node[v].deg1 == 1)
				{
					Leaf[j++] = v;
					Fg[v] = 1;
				}
			}
		}
		tf = j;
		j = 0;
	}
	qsort(Leaf, tf, sizeof(int), com);
	printf("Best Roots  :");
	for (i = 0; i < tf; i++)
	{
		printf(" %d", Leaf[i]);
	}
	printf("\n");
	memset(Fg, 0, MAXN);
}
void FindWorst1(int n, int level)
{
	int i, u;
	Fg[n] = 1;
	if (node[n].deg2 == 1)
	{
		if (level > Max)
		{
			Worst[0] = n;
			Max = level;
			worst = 1;
		}
		else if (level == Max)
		{
			Worst[worst++] = n;
		}
		return;
	}
	for (i = 0; i < node[n].deg2; i++)
	{
		u = node[n].child[i];
		if (Fg[u])
		{
			continue;
		}
		FindWorst1(node[n].child[i], level + 1);
	}
}
void FindWorst(int n, int level, int st)
{
	int i, u;
	if (node[n].deg2 == 1 && n != st)
	{
		if (level > Max)
		{
			if (Fg[n] == 0)
			{
				Worst[worst] = n;
				tw = worst + 1;
			}
			else
			{
				tw = worst;
			}
			Max = level;
			Fg[n] = 1;
		}
		else if (level == Max && Fg[n] == 0)
		{
			Fg[n] = 1;
			Worst[tw++] = n;
		}
		return;
	}
	Fg[n] = 1;
	for (i = 0; i < node[n].deg2; i++)
	{
		u = node[n].child[i];
		if (Fg[u] && node[u].deg2 > 1)
		{
			continue;
		}
		FindWorst(node[n].child[i], level + 1, st);
	}
}
void Cal()
{
	int i;
	Max = 0;
	FindWorst1(Leaf[0], 0);
	memset(Fg, 0, MAXN);
	Max = 0;
	for (i = 0; i < worst; i++)
		Fg[Worst[i]] = 1;
	tw = worst;
	FindWorst(Worst[0], 0, Worst[0]);
	qsort(Worst, tw, sizeof(Worst[0]), com);
	printf("Worst Roots :");
	for (i = 0; i < tw; i++)
		printf(" %d", Worst[i]);
	printf("\n");
	memset(Fg, 0, MAXN);
}

int main()
{
	while (scanf("%d", &N) == 1)
	{
		ReadCase();
		FindBest();
		Cal();
	}
	return 0;
}
