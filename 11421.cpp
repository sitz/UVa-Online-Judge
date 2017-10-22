#include <bits/stdc++.h>

using namespace std;

int pnum[5] = {1, 1, 2, 3, 5};
int part[5][5] = {{0}, {1}, {2, 1}, {3, 2, 1}, {4, 3, 2, 2, 1}};
int cost[5][5] = {{0}, {0}, {0, 1}, {0, 1, 2}, {0, 1, 2, 2, 3}};
int perm[5][5] = {{1}, {1}, {1, 2}, {1, 6, 6}, {1, 12, 24, 12, 24}};

char ary[55][5];
double dp[25][55];
int tbl[20], hash_[128], lst[55], used[55];
long long c[55][55], fac[10], m;

int cmp(const void *p, const void *q)
{
	if (*(char *)p != *(char *)q)
	{
		return hash_[*(char *)p] - hash_[*(char *)q];
	}
	return *((char *)p + 1) - *((char *)q + 1);
}

long long calc(int head)
{
	int i, j, k, l, p, q, r, sum;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (i = 1, sum = 0; i <= 14; i++)
	{
		if (i == head)
		{
			tbl[14] = tbl[i];
			tbl[i] = 0;
		}
		else if (i == 14)
		{
			sum--;
		}
		for (j = 0; j < pnum[tbl[i]]; j++)
		{
			p = part[tbl[i]][j];
			q = cost[tbl[i]][j];
			r = perm[tbl[i]][j];
			for (k = 0; k <= sum + 1; k++)
			{
				for (l = 0; l <= p && l <= k; l++)
				{
					dp[i][k - l + q] += dp[i - 1][k] * c[p][l] * c[k][l] * fac[l] * c[sum - k + 1][p - l] * fac[p - l] * r;
				}
			}
		}
		sum += tbl[i];
	}
	tbl[head] = tbl[14];
	return dp[14][0] > m ? m + 1 : (long long)dp[14][0];
}

int main()
{
	int cas, n, i, j, last;
	long long cnt;
	cas = 0;
	c[0][0] = 1;
	for (i = 1; i < 55; i++)
	{
		c[i][0] = 1;
		for (j = 1; j < 55; j++)
		{
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
	fac[0] = 1;
	for (i = 1; i < 10; i++)
	{
		fac[i] = fac[i - 1] * i;
	}
	for (i = '2'; i <= '9'; i++)
	{
		hash_[i] = i - '1';
	}
	hash_['T'] = 13;
	hash_['J'] = 10;
	hash_['Q'] = 12;
	hash_['K'] = 11;
	hash_['A'] = 9;
	while (scanf("%d%lld", &n, &m) == 2)
	{
		if (n == 0)
		{
			break;
		}
		memset(tbl, 0, sizeof(tbl));
		for (i = 0; i < n; i++)
		{
			scanf("%s", ary[i]);
			used[i] = 0;
			tbl[hash_[ary[i][0]]]++;
		}
		qsort(ary, n, sizeof(ary[0]), cmp);
		for (i = 0; i < n; i++)
		{
			for (j = 0, last = 0; j < n; j++)
			{
				if (used[j] == 0 && (i == 0 || *ary[j] != *ary[lst[i - 1]]))
				{
					tbl[hash_[ary[j][0]]]--;
					cnt = calc(hash_[ary[j][0]]);
					if (cnt >= m)
					{
						lst[i] = j;
						used[j] = 1;
						break;
					}
					m -= cnt;
					tbl[hash_[ary[j][0]]]++;
					last = cnt;
				}
			}
			if (j >= n)
			{
				break;
			}
		}
		if (i < n)
		{
			printf("Case %d: Not found\n", ++cas);
		}
		else
		{
			printf("Case %d:", ++cas);
			for (i = 0; i < n; i++)
			{
				printf(" %s", ary[lst[i]]);
			}
			printf("\n");
		}
	}
	return 0;
}
