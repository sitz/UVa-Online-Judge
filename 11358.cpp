#include <bits/stdc++.h>

using namespace std;

#define N 150

int map_[N][N], left_[N], right_[N], lst[N], cap[N], used[N], queue_[N], qflow[N], from[N];

int cmp(const void *p, const void *q)
{
	return *(int *)p - *(int *)q;
}

int main()
{
	int count, n, m, i, j, k, l, f, t, u, v, now;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &m, &n);
		memset(map_, 0, sizeof(map_));
		for (i = 1, j = 0; i <= n; i++)
		{
			scanf("%d%d%d", &left_[i], &map_[0][i], &right_[i]);
			lst[j++] = left_[i];
			lst[j++] = right_[i];
		}
		qsort(lst, j, sizeof(int), cmp);
		for (i = 1, k = 1; i < j; i++)
		{
			if (lst[i] != lst[i - 1])
			{
				u = left_[n + k] = lst[i - 1];
				v = right_[n + k] = lst[i] - 1;
				cap[n + k] = v - u + 1;
				for (l = 1; l <= n; l++)
				{
					if (left_[l] <= u && right_[l] > v)
					{
						map_[l][n + k] = cap[n + k];
					}
				}
				k++;
			}
		}
		t = n + k;
		for (i = n + 1; i < t; i++)
		{
			map_[i][t] = cap[i] * m;
		}
		for (;;)
		{
			memset(used, 0, sizeof(used));
			queue_[0] = 0;
			qflow[0] = 1 << 30;
			from[0] = -1;
			used[0] = 1;
			for (i = 0, j = 1; i < j; i++)
			{
				now = queue_[i];
				f = qflow[i];
				if (!now || now > n)
				{
					if (map_[now][t])
					{
						queue_[j] = t;
						qflow[j] = min(map_[now][t], f);
						from[j] = i;
						break;
					}
					for (k = 1; k <= n; k++)
					{
						if (!used[k] && map_[now][k])
						{
							used[k] = 1;
							queue_[j] = k;
							qflow[j] = min(map_[now][k], f);
							from[j++] = i;
						}
					}
				}
				else
				{
					for (k = n + 1; k <= t; k++)
					{
						if (!used[k] && map_[now][k])
						{
							used[k] = 1;
							queue_[j] = k;
							qflow[j] = min(map_[now][k], f);
							from[j++] = i;
						}
					}
				}
			}
			if (i == j)
			{
				break;
			}
			else
			{
				f = qflow[j];
				for (; from[j] != -1; j = from[j])
				{
					u = queue_[from[j]];
					v = queue_[j];
					map_[u][v] -= f;
					map_[v][u] += f;
				}
			}
		}
		for (i = 1; i <= n; i++)
		{
			if (map_[0][i])
			{
				break;
			}
		}
		if (i > n)
		{
			printf("FEASIBLE\n");
		}
		else
		{
			printf("NO WAY\n");
		}
	}
	return 0;
}
