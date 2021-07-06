#include <bits/stdc++.h>

using namespace std;

#define MX 30
#define INF 900005
#define MIN(a, b) (a > b ? b : a)

int S[MX][MX], M[MX][MX];

void Ini()
{
	int i, j;
	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 26; j++)
		{
			S[i][j] = M[i][j] = INF;
		}
		S[i][i] = M[i][i] = 0;
	}
}

void Set(char p, char dr, char u, char v, int cost)
{
	int U, V;
	U = u - 'A';
	V = v - 'A';
	if (p == 'M')
	{
		if (M[U][V] > cost)
		{
			M[U][V] = cost;
		}
		if (dr == 'B' && M[V][U] > cost)
		{
			M[V][U] = cost;
		}
	}
	if (p == 'Y')
	{
		if (S[U][V] > cost)
		{
			S[U][V] = cost;
		}
		if (dr == 'B' && S[V][U] > cost)
		{
			S[V][U] = cost;
		}
	}
}

void Floyd(int ss[][MX])
{
	int i, j, k;
	for (k = 0; k < 26; k++)
	{
		for (i = 0; i < 26; i++)
		{
			for (j = 0; j < 26; j++)
			{
				ss[i][j] = MIN(ss[i][j], ss[i][k] + ss[k][j]);
			}
		}
	}
}

void Cal(int s, int m)
{
	int i, min = 900000, x, j = 0;
	int dummy[30];
	Floyd(S);
	Floyd(M);
	for (i = 0; i < 26; i++)
	{
		x = S[s][i] + M[m][i];
		if (x < min)
		{
			dummy[0] = i;
			j = 1;
			min = x;
		}
		else if (x == min)
		{
			dummy[j++] = i;
		}
	}
	if (j == 0)
	{
		printf("You will never meet.\n");
		return;
	}
	printf("%d", min);
	for (i = 0; i < j; i++)
	{
		printf(" %c", dummy[i] + 'A');
	}
	printf("\n");
}

int main()
{
	int n, m;
	char p[3], d[3], u[3], v[3];
	while (scanf("%d", &n) && n)
	{
		Ini();
		while (n--)
		{
			scanf("%s%s%s%s%d", p, d, u, v, &m);
			Set(p[0], d[0], u[0], v[0], m);
		}
		scanf("%s%s", p, d);
		Cal(p[0] - 'A', d[0] - 'A');
	}
	return 0;
}
