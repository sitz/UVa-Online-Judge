#include <bits/stdc++.h>

using namespace std;

#define MAXN 20000
/*  MORE 2000*/
char LAN[MAXN][MAXN];
char STORE[MAXN];
int N, R, C, K;

typedef struct list
{
	int index;
	int value;
} ss;
ss V[30];
int sort(const void *a, const void *b)
{
	int m = ((ss *)a)->value;
	int n = ((ss *)b)->value;
	if (m != n)
	{
		return n - m;
	}
	return ((ss *)a)->index - ((ss *)b)->index;
}
void FFILL(int r, int c, char S)
{
	if (r >= R || r < 0 || c >= C || c < 0)
	{
		return;
	}
	if (LAN[r][c] != S)
	{
		return;
	}
	LAN[r][c] = '1';
	FFILL(r + 1, c, S);
	FFILL(r - 1, c, S);
	FFILL(r, c + 1, S);
	FFILL(r, c - 1, S);
}
void CAL()
{
	int i, m, j;
	char c;
	K = 0;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			if (isalpha(LAN[i][j]))
			{
				c = LAN[i][j];
				STORE[K++] = LAN[i][j];
				m = LAN[i][j] - 97;
				V[m].index = m;
				V[m].value++;
				FFILL(i, j, c);
			}
		}
	}
	STORE[K] = NULL;
}
void MAKEZERO()
{
	int i;
	for (i = 0; i < 30; i++)
	{
		V[i].index = 0;
		V[i].value = 0;
	}
}
void PRINT()
{
	int i, k;
	qsort(V, 30, sizeof(V[0]), sort);
	for (i = 0; i < 30; i++)
	{
		k = 0;
		if (V[i].value)
		{
			k = 1;
			printf("%c: %d\n", V[i].index + 97, V[i].value);
		}
		if (k == 0)
		{
			break;
		}
	}
}

int main()
{
	int i, kase = 1;
	char input[20];
	gets(input);
	sscanf(input, "%d", &N);
	while (N--)
	{
		gets(input);
		sscanf(input, "%d%d", &R, &C);
		for (i = 0; i < R; i++)
		{
			gets(LAN[i]);
		}
		CAL();
		printf("World #%d\n", kase++);
		PRINT();
		MAKEZERO();
	}
	return 0;
}
