#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000

char GRID[MAXN][51];
char WORD[55];
int M, N, WW, R, C;

int HF(int r, int c)
{
	int i, j;
	for (i = 0; WORD[i]; i++)
		if (WORD[i] != GRID[r][c++])
		{
			return 0;
		}
	R = r;
	C = c - 1;
	return 1;
}
int HB(int r, int c)
{
	int i, j;
	for (i = 0; WORD[i]; i++)
	{
		if (c < 0)
		{
			return 0;
		}
		if (WORD[i] != GRID[r][c--])
		{
			return 0;
		}
	}
	R = r;
	C = c + 1;
	return 1;
}
int VF(int r, int c)
{
	int i, j;
	for (i = 0; WORD[i]; i++)
	{
		if (r >= M)
		{
			return 0;
		}
		if (WORD[i] != GRID[r++][c])
		{
			return 0;
		}
	}
	R = r - 1;
	C = c;
	return 1;
}
int VB(int r, int c)
{
	int i, j;
	for (i = 0; WORD[i]; i++)
	{
		if (r < 0)
		{
			return 0;
		}
		if (WORD[i] != GRID[r--][c])
		{
			return 0;
		}
	}
	R = r + 1;
	C = c;
	return 1;
}
int DWN(int r, int c)
{
	int i, j;
	for (i = 0; WORD[i]; i++)
	{
		if (r < 0 || c < 0)
		{
			return 0;
		}
		if (WORD[i] != GRID[r--][c--])
		{
			return 0;
		}
	}
	R = r + 1;
	C = c + 1;
	return 1;
}
int DNE(int r, int c)
{
	int i, j;
	for (i = 0; WORD[i]; i++)
	{
		if (r < 0 || c >= N)
		{
			return 0;
		}
		if (WORD[i] != GRID[r--][c++])
		{
			return 0;
		}
	}
	R = r + 1;
	C = r - 1;
	return 1;
}
int DES(int r, int c)
{
	int i, j;
	for (i = 0; WORD[i]; i++)
	{
		if (r >= M || c >= N)
		{
			return 0;
		}
		if (WORD[i] != GRID[r++][c++])
		{
			return 0;
		}
	}
	R = r - 1;
	C = c - 1;
	return 1;
}
int DSW(int r, int c)
{
	int i, j;
	for (i = 0; WORD[i]; i++)
	{
		if (r >= M || c < 0)
		{
			return 0;
		}
		if (WORD[i] != GRID[r++][c--])
		{
			return 0;
		}
	}
	R = r - 1;
	C = c + 1;
	return 1;
}
int CHECK(int r, int c)
{
	if (HF(r, c))
	{
		return 1;
	}
	else if (HB(r, c))
	{
		return 1;
	}
	else if (VF(r, c))
	{
		return 1;
	}
	else if (VB(r, c))
	{
		return 1;
	}
	else if (DWN(r, c))
	{
		return 1;
	}
	else if (DNE(r, c))
	{
		return 1;
	}
	else if (DES(r, c))
	{
		return 1;
	}
	else if (DSW(r, c))
	{
		return 1;
	}
	return 0;
}
int SOLVECASE()
{
	int p, q;
	for (p = 0; p < M; p++)
		for (q = 0; q < N; q++)
			if (WORD[0] == GRID[p][q])
				if (CHECK(p, q))
				{
					goto done;
				}
done:;
	printf("%d %d\n", p + 1, q + 1);
	return 0;
}
int main()
{
	int kase, i, n, m, f, j;
	char input[50], fal[10];
	gets(input);
	sscanf(input, "%d", &kase);
	f = kase;
	while (kase--)
	{
		gets(fal);
		gets(input);
		sscanf(input, "%d%d", &M, &N);
		for (i = 0; i < M; i++)
		{
			gets(GRID[i]);
			for (j = 0; GRID[i][j]; j++)
			{
				GRID[i][j] = tolower(GRID[i][j]);
			}
		}
		gets(input);
		sscanf(input, "%d", &WW);
		for (i = 0; i < WW; i++)
		{
			gets(WORD);
			for (j = 0; WORD[j]; j++)
			{
				WORD[j] = tolower(WORD[j]);
			}
			SOLVECASE();
		}
		if (kase > 0)
		{
			printf("\n");
		}
	}
	return 0;
}
