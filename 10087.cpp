#include <bits/stdc++.h>

using namespace std;

int m[101][101], L, S;

int main()
{
	while (scanf("%d %d", &L, &S) == 2)
	{
		int p = L * (L * L + 1) / 2;
		if (L == 2 || (S - p) % L)
		{
			puts("You can't be like Shahjahan!\n");
		}
		else if (L == 1)
		{
			printf("%10d\n\n", S);
		}
		else
		{
			int diff = (S - p) / L;
			if (L % 2)
			{
				for (int i = 1; i <= L; i++)
				{
					for (int j = 1; j <= L; j++)
					{
						m[i][j] = 0;
					}
				}
				int nc = (L + 1) / 2, nr = nc + 1, k = 0;
				while (k < L * L)
				{
					if (m[nr][nc] == 0)
					{
						m[nr++][nc++] = ++k;
					}
					else
					{
						nr++, nc--;
					}
					if (nr > L)
					{
						nr = 1;
					}
					if (nc < 1)
					{
						nc = L;
					}
					if (nc > L)
					{
						nc = 1;
					}
				}
			}
			else if (L % 4 == 0)
			{
				int x = L / 4;
				for (int i = 1; i <= L; i++)
				{
					for (int j = 1; j <= L; j++)
					{
						m[i][j] = (i - 1) * L + j;
					}
				}
				for (int i = 1, k = L; i <= x; i++, k--)
				{
					for (int j = 1, l = L; j <= L; j++, l--)
					{
						if (j <= x || j > L - x)
						{
							swap(m[i][j], m[k][l]);
						}
					}
				}
				for (int i = x + 1, k = L - x; i < k; i++, k--)
				{
					for (int j = x + 1, l = L - x; j <= L - x; j++, l--)
					{
						swap(m[i][j], m[k][l]);
					}
				}
			}
			else
			{
				int x = L / 4;
				for (int i = 1; i <= L; i++)
				{
					for (int j = 1; j <= L; j++)
					{
						m[i][j] = (i - 1) * L + j;
					}
				}
				for (int i = x + 2; i < 3 * x + 2; i++)
				{
					for (int j = 1, k = L; j < k; j++, k--)
					{
						if (j != x + 1)
						{
							swap(m[i][j], m[i][k]);
						}
					}
				}
				for (int i = x + 2; i < 3 * x + 2; i++)
				{
					for (int j = 1, k = L; j < k; j++, k--)
					{
						if (j != x + 1)
						{
							swap(m[j][i], m[k][i]);
						}
					}
				}
				for (int j = 1, k = L; j < x + 1; j++, k--)
				{
					swap(m[x + 1][j], m[x + 1][k]);
					swap(m[3 * x + 2][j], m[3 * x + 2][k]);
					swap(m[x + 2][j], m[x + 2][k]);
				}
				for (int i = x + 2; i < 3 * x + 2; i++)
				{
					swap(m[x + 1][i], m[3 * x + 2][i]);
				}
				for (int i = 1, j = L; i < j; i++, j--)
				{
					if (i != x + 1)
					{
						swap(m[i][x + 1], m[j][x + 1]);
					}
				}
				swap(m[x + 1][1], m[3 * x + 2][1]);
				for (int i = x + 2, j = 3 * x + 1; i < j; i++, j--)
				{
					swap(m[x + 1][i], m[x + 1][j]);
				}
				for (int i = x + 2; i < 3 * x + 2; i++)
				{
					if (i != 2 * x + 1)
					{
						swap(m[i][x + 1], m[i][3 * x + 2]);
					}
				}
			}
			for (int i = 1; i <= L; i++)
			{
				for (int j = 1; j <= L; j++)
				{
					printf("%10d", m[i][j] + diff);
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	return 0;
}
