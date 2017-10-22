#include <bits/stdc++.h>

using namespace std;

char chk[20], chk2[1201][1201];
int need[20], map_[20][20], dis[20], queue_[1000000], queue_2[1000000];

int main()
{
	int cas, cnt, n, m, o, i, j, k, l, p, q, temp, temp2, sum, ans;
	cas = 0;
	scanf("%d", &cnt);
	while (cnt--)
	{
		scanf("%d", &n);
		for (i = 1; i < n; i++)
		{
			scanf("%d", &need[i]);
		}
		memset(map_, 0, sizeof(map_));
		while (scanf("%d%d%d", &i, &j, &k) == 3)
		{
			if (!(i + j + k))
			{
				break;
			}
			i--;
			j--;
			map_[i][j] = map_[j][i] = k;
		}
		for (i = 1; i < n; i++)
		{
			dis[i] = map_[0][i];
			chk[i] = 1;
		}
		for (i = 1, sum = 0; i < n; i++)
		{
			for (p = 1, j = 2147483647; p < n; p++)
			{
				if (chk[p] && dis[p] && dis[p] < j)
				{
					j = dis[p];
					k = p;
				}
			}
			chk[k] = 0;
			for (p = 1; p < n; p++)
			{
				if (chk[p] && map_[k][p] && (dis[k] + map_[k][p] < dis[p] || !dis[p]))
				{
					dis[p] = dis[k] + map_[k][p];
				}
			}
			dis[k] *= 2;
			sum += need[k] * dis[k];
		}
		if (sum > 3600)
		{
			printf("Test Case #: %d\nToo few trucks\n", ++cas);
		}
		else
		{
			queue_[0] = queue_2[0] = 0;
			memset(chk2, 1, sizeof(chk2));
			for (i = 1, q = 1, ans = sum; i < n; i++)
			{
				temp = dis[i];
				for (j = 0, m = -1; j < need[i]; j++)
				{
					for (p = o = q - 1; p > m; p--)
					{
						k = queue_[p] + temp;
						l = queue_2[p];
						if (k <= l)
						{
							if (chk2[k][l])
							{
								chk2[k][l] = 0;
								queue_[q] = k;
								queue_2[q++] = l;
								if (ans > max(k, max(l, sum - k - l)))
								{
									ans = max(k, max(l, sum - k - l));
								}
							}
						}
						k = queue_[p];
						l = queue_2[p] + temp;
						if (l <= 1200)
						{
							if (chk2[k][l])
							{
								chk2[k][l] = 0;
								queue_[q] = k;
								queue_2[q++] = l;
								if (ans > max(k, max(l, sum - k - l)))
								{
									ans = max(k, max(l, sum - k - l));
								}
							}
						}
					}
					m = o;
				}
			}
			if (ans > 1200)
			{
				printf("Test Case #: %d\nToo few trucks\n", ++cas);
			}
			else
			{
				printf("Test Case #: %d\n%d mins\n", ++cas, ans);
			}
		}
	}
	return 0;
}
