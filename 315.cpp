#include <bits/stdc++.h>

using namespace std;

#define MAXN 102

int p[MAXN], rank_[MAXN], N, cp;
char L[MAXN][MAXN];

void Ini()
{
	int i;
	for (i = 1; i <= N; i++)
	{
		p[i] = i;
		rank_[i] = 0;
	}
}
int Find(int x)
{
	if (x != p[x])
	{
		p[x] = Find(p[x]);
	}
	return p[x];
}
void Link(int x, int y)
{
	if (rank_[x] > rank_[y])
	{
		p[y] = x;
	}
	else
	{
		p[x] = y;
		if (rank_[x] == rank_[y])
		{
			rank_[y]++;
		}
	}
}
void ReadCase()
{
	char input[1000], *p;
	int n, m;
	while (gets(input))
	{
		p = strtok(input, " ");
		n = atoi(p);
		if (!n)
		{
			break;
		}
		while (p)
		{
			p = strtok(NULL, " ");
			if (p)
			{
				m = atoi(p);
				L[n][m] = L[m][n] = 1;
			}
		}
	}
}
void SolvedCase()
{
	int i, j, k, c = 0;
	int x, y, t;
	for (i = 1; i <= N; i++)
	{
		Ini();
		t = N - 1;
		for (j = 1; j < N; j++)
		{
			if (j == i)
			{
				continue;
			}
			for (k = j + 1; k <= N; k++)
			{
				if (k == i)
				{
					continue;
				}
				if (L[j][k] == 1)
				{
					x = Find(j);
					y = Find(k);
					if (x != y)
					{
						Link(x, y);
						t--;
					}
				}
			}
		}
		if (t - 1 > 0)
		{
			c++;
		}
	}
	printf("%d\n", c);
}

int main()
{
	char input[1000];
	int i, j;
	while (gets(input))
	{
		sscanf(input, "%d", &N);
		if (!N)
		{
			break;
		}
		Ini();
		cp = N - 1;
		ReadCase();
		SolvedCase();
		for (i = 1; i <= N; i++)
		{
			for (j = i + 1; j <= N; j++)
			{
				L[i][j] = L[j][i] = 0;
			}
		}
	}
	return 0;
}
