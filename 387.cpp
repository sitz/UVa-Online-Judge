#include <bits/stdc++.h>

using namespace std;

/*
387
A Puzzling Problem
*/
struct ss
{
	char sp[6][6];
	int r, c, total;
} P[6];
char B[5][5];
int tp, to;
void ReadCase()
{
	int i, j, k, c;
	to = 0;
	for (i = 0; i < tp; i++)
	{
		scanf("%d%d", &P[i].r, &P[i].c);
		c = 0;
		for (j = 0; j < P[i].r; j++)
		{
			scanf("%s", P[i].sp[j]);
			for (k = 0; P[i].sp[j][k]; k++)
			{
				if (P[i].sp[j][k] == '1')
				{
					to++;
					c++;
				}
			}
		}
		P[i].total = c;
	}
}
void Print()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d", B[i][j]);
		}
		printf("\n");
	}
}
int Recur(int n, int r, int c, int total, int level)
{
	int i, j, k = n + 1, l, m, f;
	if (level == tp)
	{
		if (total == 16)
		{
			for (i = r; i < r + P[n].r; i++)
			{
				for (j = c; j < c + P[n].c; j++)
				{
					if (P[n].sp[i - r][j - c] == '1')
					{
						B[i][j] = n + 1;
					}
				}
			}
			Print();
			return 1;
		}
		return 0;
	}
	for (i = r; i < r + P[n].r; i++)
	{
		for (j = c; j < c + P[n].c; j++)
		{
			if (P[n].sp[i - r][j - c] == '1')
			{
				B[i][j] = n + 1;
			}
		}
	}
	for (i = 0; i < 4; i++)
	{
		if ((i + P[k].r - 1) > 3)
		{
			break;
		}
		for (j = 0; j < 4; j++)
		{
			if ((j + P[k].c - 1) > 3)
			{
				break;
			}
			f = 1;
			for (l = i; l < i + P[k].r; l++)
			{
				for (m = j; m < j + P[k].c; m++)
				{
					if (B[l][m] && P[k].sp[l - i][m - j] == '1')
					{
						f = 0;
						break;
					}
				}
				if (!f)
				{
					break;
				}
			}
			if (f)
			{
				if (Recur(k, i, j, total + P[k].total, level + 1))
				{
					return 1;
				}
			}
		}
	}
	for (i = r; i < r + P[n].r; i++)// Free
	{
		for (j = c; j < c + P[n].c; j++)
		{
			if (B[i][j] == n + 1)
			{
				B[i][j] = 0;
			}
		}
	}
	return 0;
}
void Cal()
{
	int i, j, d;
	if (to > 16)
	{
		printf("No solution possible\n");
		return;
	}
	for (i = 0; i < 4; i++)
	{
		if ((i + P[0].r - 1) > 3)
		{
			break;
		}
		for (j = 0; j < 4; j++)
		{
			if ((j + P[0].c - 1) > 3)
			{
				break;
			}
			d = Recur(0, i, j, P[0].total, 1);
			if (d)
			{
				return;
			}
		}
	}
	printf("No solution possible\n");
}
void Free()
{
	memset(B, 0, 5 * 5);
}
int main()
{
	int k = 0;
	while (scanf("%d", &tp) && tp)
	{
		ReadCase();
		if (k++)
		{
			putchar('\n');
		}
		Cal();
		Free();
	}
	return 0;
}
