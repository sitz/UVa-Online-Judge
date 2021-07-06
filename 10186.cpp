#include <bits/stdc++.h>

using namespace std;

int n, o, highest[21], lowest[21], game[21][21][2], num[21][21], point[21], lst[21][2];
char name[21][31];

int find(char *s)
{
	for (int i = 0; i < n; i++)
		if (!strcmp(s, name[i]))
			return i;
	return -1;
}

void dfs(int depth)
{
	int i, j, p, q, high, low;
	if (depth == o)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0, high = n, low = 1; j < n; j++)
			{
				if (i != j)
				{
					if (point[i] > point[j])
					{
						high--;
					}
					else if (point[i] == point[j])
					{
						high--;
						low++;
					}
					else
					{
						low++;
					}
				}
			}
			if (high < highest[i])
			{
				highest[i] = high;
			}
			if (low > lowest[i])
			{
				lowest[i] = low;
			}
		}
		return;
	}
	p = lst[depth][0];
	q = lst[depth][1];

	game[p][q][num[p][q]++] = 1;
	game[q][p][num[q][p]++] = 0;
	point[p] += 3;
	dfs(depth + 1);
	num[p][q]--;
	num[q][p]--;
	point[p] -= 3;

	game[p][q][num[p][q]++] = 0;
	game[q][p][num[q][p]++] = 1;
	point[q] += 3;
	dfs(depth + 1);
	num[p][q]--;
	num[q][p]--;
	point[q] -= 3;

	game[p][q][num[p][q]++] = 2;
	game[q][p][num[q][p]++] = 2;
	point[p]++;
	point[q]++;
	dfs(depth + 1);
	num[p][q]--;
	num[q][p]--;

	point[p]--;
	point[q]--;
}

int main()
{
	int cas, i, j, k, m, g1, g2, i1, i2;
	char s1[100], s2[100];
	cas = 0;
	while (scanf("%d", &n) == 1)
	{
		if (!n)
			break;
		for (i = 0; i < n; i++)
		{
			scanf("%s", name[i]);
			highest[i] = n;
			lowest[i] = 0;
		}
		memset(num, 0, sizeof(num));
		memset(point, 0, sizeof(point));
		scanf("%d", &m);
		while (m--)
		{
			scanf("%s%s%d%d", s1, s2, &g1, &g2);
			i1 = find(s1);
			i2 = find(s2);
			if (g1 > g2)
			{
				game[i1][i2][num[i1][i2]++] = 1;
				game[i2][i1][num[i2][i1]++] = 0;
				point[i1] += 3;
			}
			else if (g1 == g2)
			{
				game[i1][i2][num[i1][i2]++] = game[i2][i1][num[i2][i1]++] = 2;
				point[i1]++;
				point[i2]++;
			}
			else
			{
				game[i1][i2][num[i1][i2]++] = 0;
				game[i2][i1][num[i2][i1]++] = 1;
				point[i2] += 3;
			}
		}
		for (i = 1, o = 0; i < n; i++)
		{
			for (j = 0; j < i; j++)
			{
				if (num[i][j] < 2)
				{
					for (k = num[i][j]; k < 2; k++)
					{
						lst[o][0] = i;
						lst[o++][1] = j;
					}
				}
			}
		}
		dfs(0);
		printf("Group #%d\n", ++cas);
		for (i = 0; i < n; i++)
		{
			printf("%s %d-%d\n", name[i], highest[i], lowest[i]);
		}
		printf("\n");
	}
	return 0;
}
