#include <bits/stdc++.h>

using namespace std;

#define MAXN 505

int A[MAXN][MAXN], F[MAXN][MAXN];
int Kase, N;
char Fase[6][7] = {"front", "back", "left", "right", "top", "bottom"};

struct SS
{
	int row;
	int col;
} V[MAXN][MAXN];
void PrintPath(int r, int c)
{
	int g;
	if (V[r][c].row == -1)
	{
		g = c + 1;
		if (c % 2)
		{
			g = c - 1;
		}
		printf("%d %s\n", r, Fase[g]);
		return;
	}
	PrintPath(V[r][c].row, V[r][c].col);
	g = c + 1;
	if (c % 2)
	{
		g = c - 1;
	}
	printf("%d %s\n", r, Fase[g]);
}
void LIS()
{
	int i, j, max, largest = 0, k, m, g;
	int pr, pc, str, stc;
	for (i = 1; i <= N; i++)
	{
		for (j = 0; j < 6; j++)
		{
			max = 0;
			pr = pc = -1;
			for (k = i - 1; k >= 0; k--)
			{
				for (m = 0; m < 6; m++)
				{
					if (F[k][m] > max)
						if (A[i][j] == A[k][m])
						{
							pr = k;
							pc = m;
							max = F[k][m];
						}
				}
			}
			g = j + 1;
			if (j % 2)
			{
				g = j - 1;
			}
			F[i][g] = max + 1;
			V[i][g].row = pr;
			V[i][g].col = pc;
			if (F[i][g] > largest)
			{
				largest = F[i][g];
				str = i;
				stc = g;
			}
		}
	}
	printf("Case #%d\n", Kase++);
	printf("%d\n", largest);
	PrintPath(str, stc);
}

int main()
{
	int i, j;
	Kase = 1;
	while (scanf("%d", &N) && N)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 0; j < 6; j++)
			{
				scanf("%d", &A[i][j]);
			}
		}
		if (Kase > 1)
		{
			putchar('\n');
		}
		LIS();
	}
	return 0;
}
