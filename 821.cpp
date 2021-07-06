#include <bits/stdc++.h>

using namespace std;

/*
821
Page Hopping
*/
#define MAX 105
#define MIN(a, b) (a > b ? b : a)
#define INF 214748
int Link[MAX][MAX];
int A[MAX], F[MAX];
int maxN;
void Ini()
{
	int i, j;
	for (i = 1; i <= 100; i++)
	{
		for (j = i + 1; j <= 100; j++)
		{
			Link[i][j] = Link[j][i] = INF;
		}
		Link[i][i] = 0;
		F[i] = 0;
	}
}
void Floyd()
{
	int i, j, k;
	int p, q, r;
	for (k = 0; k < maxN; k++)
	{
		p = A[k];
		for (i = 0; i < maxN; i++)
		{
			q = A[i];
			for (j = 0; j < maxN; j++)
			{
				r = A[j];
				Link[q][r] = MIN(Link[q][r], Link[q][p] + Link[p][r]);
			}
		}
	}
}
void Cal(int kase)
{
	int i, j, p, q;
	double sum = 0, total;
	Floyd();
	for (i = 0; i < maxN; i++)
	{
		p = A[i];
		for (j = i + 1; j < maxN; j++)
		{
			q = A[j];
			sum += Link[p][q] + Link[q][p];
		}
	}
	total = maxN * (maxN - 1);
	printf("Case %d: average length between pages = %.3lf clicks\n", kase, sum / total);
}
int main()
{
	int a, b, kase = 1;
	while (1)
	{
		maxN = 0;
		scanf("%d%d", &a, &b);
		if (!a && !b)
		{
			break;
		}
		Ini();
		Link[a][b] = 1;
		if (!F[a])
		{
			A[maxN++] = a;
			F[a] = 1;
		}
		if (!F[b])
		{
			A[maxN++] = b;
			F[b] = 1;
		}
		while (1)
		{
			scanf("%d%d", &a, &b);
			if (!a && !b)
			{
				break;
			}
			Link[a][b] = 1;
			if (!F[a])
			{
				A[maxN++] = a;
				F[a] = 1;
			}
			if (!F[b])
			{
				A[maxN++] = b;
				F[b] = 1;
			}
		}
		Cal(kase++);
	}
	return 0;
}
