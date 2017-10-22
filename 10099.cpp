#include <bits/stdc++.h>

using namespace std;

#define MAX(A, B) (A > B ? A : B)
#define MIN(A, B) (A > B ? B : A)
#define MAXN 102
#define INF 21474836

int A[MAXN][MAXN], N, M;

void Ini()
{
	int i, j;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
		{
			A[i][j] = 0;
		}
}
void Floyd()
{
	int i, j, k;
	for (k = 1; k <= N; k++)
	{
		for (i = 1; i < N; i++)
		{
			for (j = 1 + i; j <= N; j++)
			{
				A[i][j] = A[j][i] = MAX(A[i][j], MIN(A[i][k], A[k][j]));
			}
		}
	}
}
void Cal(int a, int b, int c)
{
	int p;
	p = c / (A[a][b] - 1);
	if (c > p * (A[a][b] - 1))
	{
		p++;
	}
	printf("Minimum Number of Trips = %d\n", p);
}

int main()
{
	int i, a, b, c;
	int kase = 1;
	while (scanf("%d%d", &N, &M) == 2)
	{
		if (!N && !M)
		{
			break;
		}
		Ini();
		for (i = 0; i < M; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			A[a][b] = A[b][a] = c;
		}
		Floyd();
		scanf("%d%d%d", &a, &b, &c);
		printf("Scenario #%d\n", kase++);
		Cal(a, b, c);
		putchar('\n');
	}
	return 0;
}
