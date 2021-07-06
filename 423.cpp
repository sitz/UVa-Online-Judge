#include <bits/stdc++.h>

using namespace std;

#define MIN(a, b) (a > b ? b : a)
#define MAXN 102
#define INF 21474836

int N, A[MAXN][MAXN];

void Floyd()
{
	int i, j, k;
	for (k = 1; k <= N; k++)
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				A[i][j] = MIN(A[i][j], A[i][k] + A[k][j]);
}
void Cal()
{
	int i, min = 0;
	Floyd();
	for (i = 1; i <= N; i++)
		if (A[1][i] > min)
			min = A[1][i];
	printf("%d\n", min);
}
void Ini()
{
	int i;
	for (i = 1; i <= N; i++)
		A[i][i] = 0;
}

int main()
{
	int i, j;
	char dummy[100];
	while (scanf("%d", &N) == 1)
	{
		Ini();
		for (i = 2; i <= N; i++)
		{
			for (j = 1; j < i; j++)
			{
				scanf("%s", dummy);
				if (!strcmp(dummy, "x"))
					A[j][i] = A[i][j] = INF;
				else
					A[i][j] = A[j][i] = atoi(dummy);
			}
		}
		if (N == 1)
		{
			printf("0\n");
			continue;
		}
		Cal();
	}
	return 0;
}
