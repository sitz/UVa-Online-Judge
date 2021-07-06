#include <bits/stdc++.h>

using namespace std;

#define MAXN 281626
#define MAX 752

struct Edge
{
	int x, y;
	int dis;
} B[MAXN], Mst[MAXN];
struct ss
{
	int x, y;
} pp[MAX];
int P[MAX], Rank[MAX];
char F[MAX][MAX];
int N, E;
int com(const void *a, const void *b)
{
	Edge *x = (Edge *)a;
	Edge *y = (Edge *)b;
	return x->dis - y->dis;
}
int Find(int n)
{
	if (n != P[n])
	{
		P[n] = Find(P[n]);
	}
	return P[n];
}
void Link(int x, int y)
{
	if (Rank[x] > Rank[y])
	{
		P[y] = x;
	}
	else
	{
		P[x] = y;
		if (Rank[x] == Rank[y])
		{
			Rank[y]++;
		}
	}
}
int Dis(int x1, int y1, int x2, int y2)
{
	int a, b, dis;
	a = (x1 - x2) * (x1 - x2);
	b = (y1 - y2) * (y1 - y2);
	dis = (a + b);
	return dis;
}
void MST()
{
	int i, a, b, len = 0;
	qsort(B, E, sizeof(B[0]), com);
	for (i = 0; i < E && len < N - 1; i++)
	{
		a = Find(B[i].x);
		b = Find(B[i].y);
		if (a != b)
		{
			Mst[len++] = B[i];
			Link(a, b);
		}
	}
	if (len == 0)
	{
		printf("No new highways need\n");
		return;
	}
	for (i = 0; i < len; i++)
	{
		printf("%d %d\n", Mst[i].x, Mst[i].y);
	}
}
void Cal()
{
	int given, a, b, x, y;
	int i, j;
	int dis;
	E = 0;
	scanf("%d", &given);
	for (i = 1; i <= N; i++)
	{
		Rank[i] = 0;
		P[i] = i;
	}
	while (given--)
	{
		scanf("%d%d", &a, &b);
		F[a][b] = 1;
		x = Find(a);
		y = Find(b);
		if (x != y)
		{
			Link(x, y);
		}
	}
	for (i = 0; i < N - 1; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (F[i + 1][j + 1] == 1)
			{
				F[i + 1][j + 1] = 0;
				continue;
			}
			dis = Dis(pp[i].x, pp[i].y, pp[j].x, pp[j].y);
			B[E].dis = dis;
			B[E].x = i + 1;
			B[E++].y = j + 1;
		}
	}
	MST();
}

int main()
{
	int i, kase;
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%d", &N);
		for (i = 0; i < N; i++)
		{
			scanf("%d%d", &pp[i].x, &pp[i].y);
		}
		Cal();
		if (kase)
		{
			putchar('\n');
		}
	}
	return 0;
}
