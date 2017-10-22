#include <bits/stdc++.h>

using namespace std;

/*
Arbitage-2
436
*/
#define MAXN 32
int N, M;
struct ss
{
	char name[1000];
	int index;
} V[MAXN], a, b;
double C[MAXN][MAXN];
double St[MAXN][MAXN];
int com(const void *a, const void *b)
{
	ss *x = (ss *)a;
	ss *y = (ss *)b;
	return strcmp(x->name, y->name);
}
double MAX(double x, double y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}
void Ini()
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		V[i].index = i;
		for (j = 1; j <= N; j++)
		{
			St[i][j] = 0.0;
			C[i][j] = 0.0;
		}
		St[i][i] = C[i][i] = 1;
	}
}
void Flyod()
{
	int i, j, k;
	for (k = 1; k <= N; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				C[i][j] = MAX(C[i][j], C[i][k] * C[k][j]);
			}
		}
	}
}
void Cal()
{
	int i, j;
	ss *p, *q;
	double cost;
	qsort(&V[1], N, sizeof(V[1]), com);
	while (M--)
	{
		scanf("%s%lf%s", a.name, &cost, b.name);
		p = (ss *)bsearch(&a, &V[1], N, sizeof(V[0]), com);
		q = (ss *)bsearch(&b, &V[1], N, sizeof(V[0]), com);
		C[p->index][q->index] = cost;
		St[p->index][q->index] = cost;
	}
	Flyod();
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (((C[i][j] * St[j][i])) > 1.00)
			{
				printf("Yes\n");
				return;
			}
			else if (((C[j][i] * St[i][j])) > 1.00)
			{
				printf("Yes\n");
				return;
			}
		}
	}
	printf("No\n");
}
int main()
{
	int i, kase = 1;
	while (scanf("%d", &N) == 1)
	{
		if (!N)
		{
			break;
		}
		Ini();
		for (i = 1; i <= N; i++)
		{
			scanf("%s", V[i].name);
		}
		scanf("%d", &M);
		printf("Case %d: ", kase++);
		Cal();
	}
	return 0;
}
