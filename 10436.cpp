#include <bits/stdc++.h>

using namespace std;

/*
Cheapest way
10436
*/
#define MAXN 22
int N;
struct ss
{
	char city[100];
	int cost;
	int index;
} p[MAXN], c, cc;
int B[MAXN][MAXN], P[MAXN][MAXN], C[MAXN][MAXN];
int Path[MAXN][MAXN];
int com(const void *a, const void *b)
{
	ss *x = (ss *)a;
	ss *y = (ss *)b;
	return strcmp(x->city, y->city);
}
void Ini()
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = i + 1; j <= N; j++)
		{
			B[i][j] = B[j][i] = 2147483;
			P[i][j] = P[j][i] = 2147483;
			Path[i][j] = Path[j][i] = -1;
		}
		B[i][i] = 0;
		P[i][i] = 0;
		Path[i][i] = -1;
	}
}
void Floyd()
{
	int i, j, k;
	int x, y;
	for (k = 1; k <= N; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				x = B[i][j] * 2 + P[i][j];
				y = B[i][k] * 2 + B[k][j] * 2 + P[i][k] + P[k][j] - p[k - 1].cost;
				if (i == k || k == j)
				{
					y += p[k - 1].cost;
				}
				if (x > y)
				{
					C[i][j] = y;
					B[i][j] = B[i][k] + B[k][j];
					P[i][j] = P[i][k] + P[k][j] - p[k - 1].cost;
					if (i == k || k == j)
					{
						P[i][j] += p[k - 1].cost;
					}
					Path[i][j] = Path[k][j];
				}
				else
				{
					C[i][j] = x;
					B[i][j] = B[i][j];
					P[i][j] = P[i][j];
					Path[i][j] = Path[i][j];
				}
			}
		}
	}
}
void PrintPath(int i, int j)
{
	if (i == j)
	{
		printf("%s", p[i - 1].city);
	}
	else
	{
		PrintPath(i, Path[i][j]);
		printf(" %s", p[j - 1].city);
	}
}
double Cost(int m, int y)
{
	double x;
	if (m != y)
	{
		x = ((10 * (double)C[m][y]) / 100) + (double)C[m][y];
	}
	else
	{
		x = ((10 * (double)p[m - 1].cost) / 100) + (double)p[m - 1].cost;
	}
	return x;
}
void Cal()
{
	int i, m, d, q, g = 1;
	double pp;
	ss *x, *y;
	qsort(p, N, sizeof(p[0]), com);
	for (i = 0; i < N; i++)
	{
		p[i].index = i + 1;
	}
	scanf("%d", &m);
	while (m--)
	{
		scanf("%s%s%d", c.city, cc.city, &d);
		x = (ss *)bsearch(&c, p, N, sizeof(p[0]), com);
		y = (ss *)bsearch(&cc, p, N, sizeof(p[0]), com);
		B[x->index][y->index] = B[y->index][x->index] = d;
		P[x->index][y->index] = P[y->index][x->index] = x->cost + y->cost;
		Path[x->index][y->index] = x->index;
		Path[y->index][x->index] = y->index;
	}
	Floyd();
	scanf("%d", &q);
	while (q--)
	{
		scanf("%s%s%d", c.city, cc.city, &d);
		x = (ss *)bsearch(&c, p, N, sizeof(p[0]), com);
		y = (ss *)bsearch(&cc, p, N, sizeof(p[0]), com);
		printf("Query #%d\n", g++);
		PrintPath(x->index, y->index);
		printf("\n");
		pp = Cost(x->index, y->index);
		printf("Each passenger has to pay : %.2lf taka\n", pp / (double)d);
	}
}
int main()
{
	int kase, i, q = 1;
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%d", &N);
		Ini();
		for (i = 0; i < N; i++)
		{
			scanf("%s%d", p[i].city, &p[i].cost);
		}
		if (q > 1)
		{
			putchar('\n');
		}
		printf("Map #%d\n", q++);
		Cal();
	}
	return 0;
}
