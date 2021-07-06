#include <bits/stdc++.h>

using namespace std;

/**
836
**/
#define Dif(i, j, k) (Table[i + k][j] - Table[i][j])
#define MAXN 110
int N, M, MAX;
int Table[MAXN][MAXN];
void ReadCase()
{
	int i, j, k;
	char input[100];
	N = 1;
	while (gets(input))
	{
		for (i = 0; input[i]; i++)
			if (input[i] == '\n')
			{
				input[i] = NULL;
			}
		if (strlen(input) < 1)
		{
			break;
		}
		for (j = 0; input[j]; j++)
		{
			k = input[j] - '0';
			if (k == 1)
			{
				Table[N][j] = 1;
			}
			else
			{
				Table[N][j] = -1000;
			}
		}
		N++;
	}
	N--;
}
void Cal()
{
	int i, j, k, t;
	for (i = 1; i <= N; i++)
	{
		for (j = 0; j < N; j++)
		{
			Table[i][j] = Table[i][j] + Table[i - 1][j];
		}
	}
	MAX = Table[1][0];
	for (k = 1; k <= N; k++)
	{
		for (i = 0; i <= N - k; i++)
		{
			for (t = 0, j = 0; j < N; j++)
			{
				if (t >= 0)
				{
					t += Dif(i, j, k);
				}
				else
				{
					t = Dif(i, j, k);
				}
				if (t > MAX)
				{
					MAX = t;
				}
			}
		}
	}
	if (MAX <= 0)
	{
		MAX = 0;
	}
	printf("%d\n", MAX);
}
void FREE()
{
	int i, j;
	for (i = 0; i <= N; i++)
		for (j = 0; j <= N; j++)
		{
			Table[i][j] = 0;
		}
}
int main()
{
	int f = 0, kase;
	char input[100];
	gets(input);
	sscanf(input, "%d", &kase);
	gets(input);
	while (kase--)
	{
		ReadCase();
		Cal();
		if (kase)
		{
			FREE();
			printf("\n");
		}
	}
	return 0;
}
