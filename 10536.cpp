#include <bits/stdc++.h>

using namespace std;

#define maxn 65539

int B[5][5], Res[maxn];
char F[maxn];

int Dec()
{
	int sum = 0, p = 1;
	int i, j;
	for (i = 3; i >= 0; i--)
	{
		for (j = 3; j >= 0; j--)
		{
			sum += B[i][j] * p;
			p *= 2;
		}
	}
	return sum;
}
int Recur(int r, int c, int lim, int dir)
{
	int i, j, k, d, f = 0;
	if (dir == 1)
		for (i = c; i <= lim; i++)
			B[r][i] = 1;
	else
		for (i = r; i <= lim; i++)
			B[i][c] = 1;
	d = Dec();
	if (F[d] == 1 || d == 65535)
	{
		if (dir == 1)
			for (i = c; i <= lim; i++)
				B[r][i] = 0;
		else
			for (i = r; i <= lim; i++)
				B[i][c] = 0;
		if (d == 65535)
			return 1;
		return Res[d];
	}
	F[d] = 1;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (B[i][j] == 0)
			{
				k = Recur(i, j, j, 1);
				if (!k)
				{
					f = 1;
					break;
				}
				if (j + 1 < 4 && (j == 0 || j == 2) && !B[i][j + 1])
				{
					k = Recur(i, j, j + 1, 1);
					if (!k)
					{
						f = 1;
						break;
					}
				}
				if (j + 2 < 4 && (j == 0 || j == 1) && !B[i][j + 2] && !B[i][j + 1])
				{
					k = Recur(i, j, j + 2, 1);
					if (!k)
					{
						f = 1;
						break;
					}
				}
				if (i + 1 < 4 && (i == 0 || i == 2) && !B[i + 1][j])
				{
					k = Recur(i, j, i + 1, 2);
					if (!k)
					{
						f = 1;
						break;
					}
				}
				if (i + 2 < 4 && (i == 0 || i == 1) && !B[i + 2][j] && !B[i + 1][j])
				{
					k = Recur(i, j, i + 2, 2);
					if (!k)
					{
						f = 1;
						break;
					}
				}
			}
		}
		if (f)
			break;
	}
	d = Dec();
	if (dir == 1)
		for (i = c; i <= lim; i++)
			B[r][i] = 0;
	else
		for (i = r; i <= lim; i++)
			B[i][c] = 0;
	Res[d] = 0;
	if (f)
		Res[d] = 1;
	return Res[d];
}
void Cal()
{
	int i, j, k, f = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (B[i][j] == 0)
			{
				k = Recur(i, j, j, 1);
				if (!k)
				{
					f = 1;
					break;
				}
				if (j + 1 < 4 && (j == 0 || j == 2) && !B[i][j + 1])
				{
					k = Recur(i, j, j + 1, 1);
					if (!k)
					{
						f = 1;
						break;
					}
				}
				if (j + 2 < 4 && (j == 0 || j == 1) && !B[i][j + 2] && !B[i][j + 1])
				{
					k = Recur(i, j, j + 2, 1);
					if (!k)
					{
						f = 1;
						break;
					}
				}
				if (i + 1 < 4 && (i == 0 || i == 2) && !B[i + 1][j])
				{
					k = Recur(i, j, i + 1, 2);
					if (!k)
					{
						f = 1;
						break;
					}
				}
				if (i + 2 < 4 && (i == 0 || i == 1) && !B[i + 2][j] && !B[i + 1][j])
				{
					k = Recur(i, j, i + 2, 2);
					if (!k)
					{
						f = 1;
						break;
					}
				}
			}
		}
		if (f)
		{
			break;
		}
	}
	printf(f ? "WINNING\n" : "LOSING\n");
}
int main()
{
	int ks, i;
	char ss[10];
	scanf("%d", &ks);
	while (ks--)
	{
		for (i = 0; i < 4; i++)
		{
			scanf("%s", ss);
			for (int j = 0; ss[j]; j++)
			{
				if (ss[j] == 'X')
					B[i][j] = 1;
				else
					B[i][j] = 0;
			}
		}
		Cal();
	}
	return 0;
}
