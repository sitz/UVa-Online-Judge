#include <bits/stdc++.h>

using namespace std;

char B[5][5];

struct sss
{
	int r, c;
} X[5], Y[5];
struct dig
{
	int d1, d2;
} xx, yy;
int Recur(int r, int c, int pice, int level)
{
	int i, j, f = 0;
	if (pice == 0)
	{
		if (X[r].r + 1 == 4)
		{
			return 1;
		}
		if (X[c].c + 1 == 4)
		{
			return 1;
		}
		if (r == c)
		{
			if (xx.d2 + 1 == 4)
			{
				return 1;
			}
			xx.d2++;
		}
		if (r + c == 3)
		{
			if (xx.d1 + 1 == 4)
			{
				return 1;
			}
			xx.d1++;
		}
		B[r][c] = 'x';
		X[r].r++;
		X[c].c++;
	}
	else if (pice == 1)
	{
		if (Y[r].r + 1 == 4)
		{
			return 1;
		}
		if (Y[c].c + 1 == 4)
		{
			return 1;
		}
		if (r == c)
		{
			if (yy.d2 + 1 == 4)
			{
				return 1;
			}
			yy.d2++;
		}
		if (r + c == 3)
		{
			if (yy.d1 + 1 == 4)
			{
				return 1;
			}
			yy.d1++;
		}
		B[r][c] = 'o';
		Y[r].r++;
		Y[c].c++;
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (B[i][j] == '.')
			{
				if (Recur(i, j, !pice, level + 1))
				{
					f = 1;
					break;
				}
			}
		}
		if (f)
		{
			break;
		}
	}
	if (pice == 0)
	{
		B[r][c] = '.';
		X[r].r--;
		X[c].c--;
		if (r == c)
		{
			xx.d2--;
		}
		if (r + c == 3)
		{
			xx.d1--;
		}
	}
	else
	{
		B[r][c] = '.';
		Y[r].r--;
		Y[c].c--;
		if (r == c)
		{
			yy.d2--;
		}
		if (r + c == 3)
		{
			yy.d1--;
		}
	}
	if (f)
	{
		return 0;
	}
	return 1;
}
int Cal()
{
	int i, total = 0, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (B[i][j] == 'x')
			{
				X[i].r++;
				X[j].c++;
				if (i == j)
				{
					xx.d2++;
				}
				if (i + j == 3)
				{
					xx.d1++;
				}
			}
			else if (B[i][j] == 'o')
			{
				Y[i].r++;
				Y[j].c++;
				if (i == j)
				{
					yy.d2++;
				}
				if (i + j == 3)
				{
					yy.d1++;
				}
			}
		}
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (B[i][j] == '.')
			{
				if (Recur(i, j, 0, 0))
				{
					printf("(%d,%d)\n", i, j);
					return 1;
				}
			}
		}
	}
	return 0;
}
void Free()
{
	int i;
	for (i = 0; i < 4; i++)
	{
		X[i].r = X[i].c = 0;
		Y[i].c = Y[i].r = 0;
	}
	xx.d1 = yy.d1 = 0;
	xx.d2 = yy.d2 = 0;
}

int main()
{
	char ss[10];
	int i;
	while (gets(ss))
	{
		if (!strcmp(ss, "$"))
		{
			break;
		}
		for (i = 0; i < 4; i++)
		{
			gets(B[i]);
		}
		if (!Cal())
		{
			puts("#####");
		}
		Free();
	}
	return 0;
}
