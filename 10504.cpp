#include <bits/stdc++.h>

using namespace std;

#define MAXN 302

char grid[MAXN][MAXN];
int N, M;

int Count(char cc)
{
	int t = 0, i, j, k, l;
	int dx, dy, p, q, r, s;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j + 1 < N; j++)
		{
			if (grid[i][j] != cc)
				continue;
			for (k = i; k < N; k++)
			{
				for (l = j + 1; l < N; l++)
				{
					if (grid[k][l] == cc)
					{
						dx = k - i;
						dy = l - j;
						p = k + dy;
						q = l - dx;
						r = i + dy;
						s = j - dx;
						if (grid[p][q] == cc && grid[r][s] == cc)
							t++;
					}
				}
			}
		}
	}
	return t;
}

void Cal()
{
	char ch[3];
	while (M--)
	{
		scanf("%s", &ch);
		printf("%s", ch);
		printf(" %d\n", Count(ch[0]));
	}
}

int main()
{
	int i, k = 0;
	while (scanf("%d", &N), N)
	{
		scanf("%d", &M);
		for (i = 0; i < N; i++)
			scanf("%s", grid[i]);
		if (k++)
			printf("\n");
		Cal();
	}
	return 0;
}
