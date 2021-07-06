#include <bits/stdc++.h>

using namespace std;

typedef struct List
{
	int st, ed;
} LIST;
LIST lst[305];

typedef struct Node
{
	int t, id;
} NODE;
NODE node[610];

int dp[605][605];

int cmp(const void *a, const void *b);
int cmp1(const void *a, const void *b);

int main()
{
	int T, t, i, j, k, N, n, len, top;
	scanf(" %d", &T);
	for (t = 0; t < T; t++)
	{
		scanf(" %d", &N);
		for (n = 0; n < N; n++)
		{
			scanf(" %d %d", &lst[n].st, &lst[n].ed);
		}
		qsort(lst, N, sizeof(lst[0]), cmp);
		for (i = top = 0; i < N; i++)
		{
			node[top].t = lst[i].st;
			node[top].id = (i + 1) * 10;
			top++;
			node[top].t = lst[i].ed;
			node[top].id = (i + 1) * 10 + 1;
			top++;
		}
		qsort(node, top, sizeof(node[0]), cmp1);
		memset(dp, 0, sizeof(dp));
		for (len = 2; len <= top; len++)
		{
			for (i = 0; i <= top - len; i++)
			{
				int MAX = 0;
				k = i + len - 1;
				for (j = i; j <= k; j++)
				{
					if (node[i].id / 10 == node[k].id / 10)
					{
						MAX = max(MAX, dp[i][j] + dp[j][k] + 1);
					}
					else
					{
						MAX = max(MAX, dp[i][j] + dp[j][k]);
					}
				}
				dp[i][k] = MAX;
			}
		}
		printf("%d\n", dp[0][top - 1]);
	}
	return 0;
}

int cmp(const void *a, const void *b)
{
	LIST c, d;
	c = *(LIST *)(a);
	d = *(LIST *)(b);
	if (c.st != d.st)
	{
		return c.st > d.st ? 1 : -1;
	}
	else if (c.ed != d.ed)
	{
		return c.ed > d.ed ? -1 : 1;
	}
	return 0;
}

int cmp1(const void *a, const void *b)
{
	NODE c, d;
	c = *(NODE *)(a);
	d = *(NODE *)(b);
	if (c.t != d.t)
	{
		return c.t > d.t ? 1 : -1;
	}
	else if (c.id % 2 == 1 && d.id % 2 == 1)
	{
		return c.id > d.id ? -1 : 1;
	}
	else if (c.id % 2 == 1 && d.id % 2 == 0)
	{
		return -1;
	}
	else if (c.id % 2 == 0 && d.id % 2 == 1)
	{
		return 1;
	}
	else if (c.id % 2 == 0 && d.id % 2 == 0)
	{
		return c.id > d.id ? 1 : -1;
	}
}
