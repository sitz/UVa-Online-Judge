#include <bits/stdc++.h>

using namespace std;

#define MAX 10
int A[MAX];
int BORD[MAX][MAX];
int MAXVALUE;
char F[MAX];

int ABS(int n)
{
	if (n < 0)
	{
		return -n;
	}
	else
	{
		return n;
	}
}

void MAXIMUM(int n)
{
	int i, c = 0;
	for (i = 0; i < n; i++)
	{
		int x = A[i];
		c += BORD[i][x - 1];
	}
	if (c > MAXVALUE)
	{
		MAXVALUE = c;
	}
}

void PERM(int level)
{
	int x = level - 1;
	for (int j = level - 2; j >= 0; j--)
	{
		int p = j;
		if (x >= 0 && p >= 0)
		{
			int y = A[x];
			int q = A[p];
			if (ABS(x - p) == ABS(y - q))
			{
				return;
			}
		}
	}
	if (level == 8)
	{
		MAXIMUM(8);
		return;
	}
	for (int i = 1; i <= 8; i++)
	{
		if (F[i] == 0)
		{
			F[i] = 1;
			A[level] = i;
			PERM(level + 1);
			F[i] = 0;
		}
	}
	return;
}

int main()
{
	int N;
	scanf("%d", &N);
	while (N--)
	{
		MAXVALUE = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
			{
				scanf("%d", &BORD[i][j]);
			}
		PERM(0);
		printf("%5d\n", MAXVALUE);
	}
	return 0;
}
