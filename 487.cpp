#include <bits/stdc++.h>

using namespace std;

/**
487
**/
#define MAXN 500000
char F[22][22];
char Temp[22];
char Word[MAXN][30];
char Bog[20][21];
int K, N, L, MAX;
int com(const void *a, const void *s)
{
	char *d = (char *)a;
	char *e = (char *)s;
	int m = strlen(d);
	int n = strlen(e);
	if (m != n)
	{
		return m - n;
	}
	return strcmp((char *)a, (char *)s);
}
void Gen(int r, int c, int level)
{
	int k;
	if (level)
	{
		if (Temp[level - 1] >= Bog[r][c])
		{
			return;
		}
	}
	Temp[level] = Bog[r][c];
	if (level >= 2)
	{
		for (k = 0; k <= level; k++)
		{
			Word[K][k] = Temp[k];
		}
		Word[K][k] = NULL;
		K++;
	}
	if (level == N * N - 1)
	{
		return;
	}
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			int nr = r + i;
			int nc = c + j;
			if (nr < 0 || nr >= N || nc < 0 || nc >= N || F[nr][nc] == 1)
			{
				continue;
			}
			F[nr][nc] = 1;
			Gen(nr, nc, level + 1);
			F[nr][nc] = 0;
		}
	}
}
void Cal()
{
	int i, j;
	K = 0;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			F[i][j] = 1;
			Gen(i, j, 0);
			F[i][j] = 0;
		}
}
void sort()
{
	int i;
	if (K == 0)
	{
		return;
	}
	qsort(Word, K, sizeof(Word[0]), com);
	printf("%s\n", Word[0]);
	for (i = 1; i < K; i++)
	{
		if (!strcmp(Word[i], Word[i - 1]))
		{
			continue;
		}
		printf("%s\n", Word[i]);
	}
}
int main()
{
	int i, kase;
	char input[10];
	gets(input);
	sscanf(input, "%d", &kase);
	gets(input);
	while (kase--)
	{
		gets(input);
		sscanf(input, "%d", &N);
		for (i = 0; i < N; i++)
		{
			gets(Bog[i]);
		}
		Cal();
		sort();
		if (kase)
		{
			putchar('\n');
			gets(input);
		}
	}
	return 0;
}
