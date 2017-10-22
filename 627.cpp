#include <bits/stdc++.h>

using namespace std;

/*
The net
672
*/
#define MAXN 302
int D[MAXN][MAXN];
int P[MAXN][MAXN];
int N;
char input[10000];
void Ini()
{
	int i, j;
	for (i = 1; i < N; i++)
	{
		for (j = i + 1; j <= N; j++)
		{
			D[i][j] = D[j][i] = 100000;
			P[i][j] = P[j][i] = -1;
		}
		P[i][i] = -1;
		D[i][i] = 0;
	}
	P[i][i] = -1;
	D[i][i] = 0;
}
void Sep()
{
	int i, j, k = 0, n, f = 0;
	char temp[100];
	for (i = 0; input[i] != '-'; i++)
	{
		temp[k++] = input[i];
	}
	temp[k] = NULL;
	sscanf(temp, "%d", &n);
	k = 0;
	for (j = i + 1; input[j]; j++)
	{
		f = 1;
		if (input[j] != ',')
		{
			temp[k++] = input[j];
		}
		else
		{
			temp[k] = NULL;
			sscanf(temp, "%d", &i);
			D[n][i] = 1;
			P[n][i] = n;
			k = 0;
		}
	}
	if (f)
	{
		temp[k] = NULL;
		sscanf(temp, "%d", &i);
		D[n][i] = 1;
		P[n][i] = n;
	}
}
void Floyd()
{
	int i, j, k;
	for (k = 1; k <= N; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				if (D[i][j] > (D[i][k] + D[k][j]))
				{
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = P[k][j];
				}
				else
				{
					P[i][j] = P[i][j];
					D[i][j] = D[i][j];
				}
			}
		}
	}
}
void Print(int i, int j)
{
	if (i == j)
	{
		printf("%d", i);
	}
	else
	{
		Print(i, P[i][j]);
		printf(" %d", j);
	}
}
void Cal()
{
	int i, j, k;
	printf("-----\n");
	gets(input);
	sscanf(input, "%d", &k);
	if (k)
	{
		Floyd();
	}
	while (k--)
	{
		gets(input);
		sscanf(input, "%d%d", &i, &j);
		if (P[i][j] == -1)
		{
			printf("connection impossible");
		}
		else
		{
			Print(i, j);
		}
		printf("\n");
	}
}
int main()
{
	int i;
	while (gets(input))
	{
		sscanf(input, "%d", &N);
		Ini();
		for (i = 0; i < N; i++)
		{
			gets(input);
			Sep();
		}
		Cal();
	}
	return 0;
}
