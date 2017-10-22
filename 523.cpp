#include <bits/stdc++.h>

using namespace std;

/*
Minimum Transport Cost
523
*/
#define MIN(a, b) (a > b ? b : a)
#define MAXN 202
#define INF 21474836
int D[MAXN][MAXN], N;
int P[MAXN][MAXN];
char text[10000];
struct ss
{
	int tax;
} V[MAXN];
void Ini()
{
	int i;
	for (i = 0; i < N; i++)
	{
		P[i][i] = -1;
	}
}
void ReadCase()
{
	int i, j, c;
	char *p;
	for (i = 1; i < N; i++)
	{
		gets(text);
		p = strtok(text, " ");
		j = 0;
		c = atoi(p);
		if (c >= 0)
		{
			D[i][j] = c;
			P[i][j] = i;
			j++;
		}
		else
		{
			D[i][j] = INF;
			P[i][j] = -1;
			j++;
		}
		while (p)
		{
			p = strtok(NULL, " ");
			if (p)
			{
				c = atoi(p);
				if (c >= 0)
				{
					D[i][j] = c;
					P[i][j] = i;
					j++;
				}
				else
				{
					D[i][j] = INF;
					P[i][j] = -1;
					j++;
				}
			}
		}
	}
	j = 0;
	gets(text);
	p = strtok(text, " ");
	if (p)
	{
		V[j++].tax = atoi(p);
	}
	while (p)
	{
		p = strtok(NULL, " ");
		if (p)
		{
			V[j++].tax = atoi(p);
		}
	}
}
void Flyod()
{
	int i, j, k;
	for (k = 0; k < N; k++)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (D[i][j] > (D[i][k] + D[k][j] + V[k].tax))
				{
					D[i][j] = D[i][k] + D[k][j] + V[k].tax;
					P[i][j] = P[k][j];
				}
				else
				{
					D[i][j] = D[i][j];
					P[i][j] = P[i][j];
				}
			}
		}
	}
}
void PrintPath(int a, int b)
{
	if (a == b)
	{
		printf("%d", a + 1);
	}
	else
	{
		PrintPath(a, P[a][b]);
		printf("-->%d", b + 1);
	}
}
void Cal()
{
	int a, b, i, c = 0;
	Flyod();
	while (gets(text))
	{
		for (i = 0; text[i]; i++)
			if (text[i] == '\n')
			{
				text[i] = NULL;
			}
		if (strlen(text) == 0)
		{
			break;
		}
		sscanf(text, "%d%d", &a, &b);
		a--;
		b--;
		if (c++)
		{
			putchar('\n');
		}
		printf("From %d to %d :\n", a + 1, b + 1);
		printf("Path: ");
		PrintPath(a, b);
		putchar('\n');
		printf("Total cost : %d\n", D[a][b]);
	}
}
int main()
{
	char input[100], *p;
	int kase, c;
	gets(input);
	sscanf(input, "%d", &kase);
	gets(input);
	while (kase--)
	{
		N = 0;
		gets(text);
		p = strtok(text, " ");
		c = atoi(p);
		if (c >= 0)
		{
			D[0][N] = c;
			P[0][N] = 0;
			N++;
		}
		else
		{
			D[0][N] = INF;
			P[0][N] = -1;
			N++;
		}
		while (p)
		{
			p = strtok(NULL, " ");
			if (p)
			{
				c = atoi(p);
				if (c >= 0)
				{
					D[0][N] = c;
					P[0][N] = 0;
					N++;
				}
				else
				{
					D[0][N] = INF;
					P[0][N] = -1;
					N++;
				}
			}
		}
		ReadCase();
		Ini();
		Cal();
		if (kase)
		{
			printf("\n");
		}
	}
	return 0;
}
