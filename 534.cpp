#include <bits/stdc++.h>

using namespace std;

#define MAX(A, B) (A > B ? A : B)
#define MIN(A, B) (A > B ? B : A)
#define MAXN 202

struct ss
{
	int a, b;
} V[202];
int N, A[MAXN][MAXN];

void Ini()
{
	int i;
	for (i = 1; i <= N; i++)
		A[i][i] = 0;
}
void Floyd()
{
	int i, j, k;
	for (k = 1; k <= N; k++)
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				A[i][j] = MIN(A[i][j], MAX(A[i][k], A[k][j]));
}
int Dis(int x1, int y1, int x2, int y2)
{
	int a, b;
	a = (x1 - x2);
	b = (y1 - y2);
	return a * a + b * b;
}
void Cal()
{
	int i, j, c;
	double dis;
	for (i = 0; i < N - 1; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			c = Dis(V[i].a, V[i].b, V[j].a, V[j].b);
			A[i + 1][j + 1] = A[j + 1][i + 1] = c;
		}
	}
	Floyd();
	dis = sqrt((double)A[1][2]);
	printf("Frog Distance = %.3lf\n\n", dis);
}

int main()
{
	int i, kase = 1;
	while (scanf("%d", &N) && N)
	{
		Ini();
		for (i = 0; i < N; i++)
			scanf("%d%d", &V[i].a, &V[i].b);
		printf("Scenario #%d\n", kase++);
		Cal();
	}
	return 0;
}
