#include <bits/stdc++.h>

using namespace std;

#define MAXN 30

char Have[MAXN], Rec[MAXN], input[10000], link[MAXN][MAXN], temp[10000], F[MAXN];
int tc, min_, H[MAXN], A[MAXN];

void Sep()
{
	char *p;
	int i, j, k = 0, u, v;
	for (i = 0; input[i]; i++)
	{
		if (input[i] != ' ')
		{
			temp[k++] = input[i];
		}
	}
	temp[k] = '\0';
	p = strtok(temp, ";");
	while (p)
	{
		u = p[0] - 'A';
		Have[u] = 1;
		for (j = 2; p[j]; j++)
		{
			v = p[j] - 'A';
			link[u][v] = link[v][u] = 1;
			Have[v] = 1;
		}
		p = strtok(NULL, ";");
	}
}
void Record()
{
	int i, t = 0, u, j, v, m = 0;
	for (i = 1; i < tc; i++)
	{
		u = A[i];
		for (j = tc; j > i; j--)
		{
			v = A[j];
			if (link[u][v] || link[v][u])
			{
				break;
			}
		}
		v = j - i;
		if (v > m)
			m = v;
	}
	if (m >= min_)
	{
		return;
	}
	min_ = m;
	for (i = 1; i <= tc; i++)
	{
		Rec[i] = A[i];
	}
}
void recur(int n, int level)
{
	int i;
	A[level] = H[n];
	if (level == tc)
	{
		Record();
		return;
	}
	F[n] = 1;
	for (i = 0; i < tc; i++)
	{
		if (F[i] == 0)
		{
			recur(i, level + 1);
		}
	}
	F[n] = 0;
}
void Cal()
{
	int i, j;
	min_ = 1000000000;
	tc = 0;
	for (i = 0; i < 26; i++)
	{
		if (Have[i])
		{
			H[tc++] = i;
		}
	}
	for (i = 0; i < tc; i++)
	{
		recur(i, 1);
	}
	for (i = 1; i <= tc; i++)
	{
		printf("%c ", Rec[i] + 'A');
	}
	printf("-> %d\n", min_);
	for (i = 0; i < MAXN; i++)
	{
		Have[i] = 0;
		for (j = 0; j < MAXN; j++)
		{
			link[i][j] = 0;
		}
	}
}

int main()
{
	while (scanf("%s", input) != EOF)
	{
		if (!strcmp(input, "#"))
		{
			break;
		}
		Sep();
		Cal();
	}
	return 0;
}
