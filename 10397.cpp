#include <bits/stdc++.h>

using namespace std;

#define MAXN 281626
#define MAX 752

struct Edge
{
	int x, y;
	double dis;
} B[MAXN];
struct ss
{
	double x, y;
} pp[MAX];
int P[MAX], Rank[MAX];
char F[MAX][MAX];
int N, E;
int com(const void *a, const void *b)
{
	Edge *x = (Edge *)a;
	Edge *y = (Edge *)b;
	if (x->dis > y->dis)
	{
		return 1;
	}
	if (x->dis < y->dis)
	{
		return -1;
	}
	return 0;
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
double Dis(double x1, double y1, double x2, double y2)
{
	double a, b, dis;
	a = (x1 - x2) * (x1 - x2);
	b = (y1 - y2) * (y1 - y2);
	dis = sqrt(a + b);
	return dis;
}
double MST()
{
	int i, a, b;
	double Sum = 0.0;
	qsort(B, E, sizeof(B[0]), com);
	for (i = 0; i < E; i++)
	{
		a = Find(B[i].x);
		b = Find(B[i].y);
		if (a != b)
		{
			Sum += B[i].dis;
			Link(a, b);
		}
	}
	return Sum;
}
void Cal()
{
	int given, a, b, x, y;
	int i, j;
	double dis;
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
	printf("%.2lf\n", MST());
}

int main()
{
	int i;
	while (scanf("%d", &N) == 1)
	{
		for (i = 0; i < N; i++)
		{
			scanf("%lf%lf", &pp[i].x, &pp[i].y);
		}
		Cal();
	}
	return 0;
}
