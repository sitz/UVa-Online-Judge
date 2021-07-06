#include <bits/stdc++.h>

using namespace std;

int ans;
int tim[15];
int used[2050000], dp[2050000];
char s1[10000], s2[10000];
int cnt[15];

int has(int stat, int bit)
{
	return stat % tim[bit + 1] >= tim[bit];
}

int recurs(int stat)
{
	int i, s, p, q;
	if (used[stat])
	{
		return dp[stat];
	}
	used[stat] = 1;
	dp[stat] = 0;
	if (stat == 0)
	{
		return 0;
	}
	for (i = 0; i < 9; i++)
	{
		if (has(stat, i))
		{
			s = stat;
			p = i - i % 3 + (i % 3 + 1) % 3;
			q = i - i % 3 + (i % 3 + 2) % 3;
			if (has(stat, p) && has(stat, q))
			{
				s -= tim[i] + tim[p] + tim[q];
				if (recurs(s) + 1 > dp[stat])
				{
					dp[stat] = recurs(s) + 1;
				}
			}
			s = stat;
			p = i % 3 + (i / 3 + 1) % 3 * 3;
			q = i % 3 + (i / 3 + 2) % 3 * 3;
			if (has(stat, p) && has(stat, q))
			{
				s -= tim[i] + tim[p] + tim[q];
				if (recurs(s) + 1 > dp[stat])
				{
					dp[stat] = recurs(s) + 1;
				}
			}
			s = stat;
			p = (i / 3 + 1) % 3 * 3 + (i % 3 + 1) % 3;
			q = (i / 3 + 2) % 3 * 3 + (i % 3 + 2) % 3;
			if (has(stat, p) && has(stat, q))
			{
				s -= tim[i] + tim[p] + tim[q];
				if (recurs(s) + 1 > dp[stat])
				{
					dp[stat] = recurs(s) + 1;
				}
			}
			s = stat;
			p = (i / 3 + 1) % 3 * 3 + (i % 3 + 2) % 3;
			q = (i / 3 + 2) % 3 * 3 + (i % 3 + 1) % 3;
			if (has(stat, p) && has(stat, q))
			{
				s -= tim[i] + tim[p] + tim[q];
				if (recurs(s) + 1 > dp[stat])
				{
					dp[stat] = recurs(s) + 1;
				}
			}
		}
	}
	return dp[stat];
}

void dfs(int stat, int depth, int val)
{
	int i;
	if (depth == 9)
	{
		if (val + recurs(stat) > ans)
		{
			ans = val + recurs(stat);
		}
		return;
	}
	for (i = cnt[depth] % 3; i <= cnt[depth] && i < 5; i += 3)
	{
		dfs(stat + i * tim[depth], depth + 1, val + (cnt[depth] - i) / 3);
	}
	if (i != 4 && cnt[depth] >= 4)
	{
		dfs(stat + 4 * tim[depth], depth + 1, val + (cnt[depth] - 4) / 3);
	}
}

int main()
{
	int i, j, f, n, t, temp;
	tim[0] = 1;
	for (i = 1; i <= 10; i++)
	{
		tim[i] = tim[i - 1] * 5;
	}
	recurs(tim[9] - 1);
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		memset(cnt, 0, sizeof(cnt));
		for (i = 0; i < n; i++)
		{
			scanf("%s%s", s1, s2);
			if (*s1 == 'u')
			{
				t = 0;
			}
			if (*s1 == 'd')
			{
				t = 3;
			}
			if (*s1 == 't')
			{
				t = 6;
			}
			if (*s2 == 't')
			{
				t++;
			}
			if (*s2 == 'q')
			{
				t += 2;
			}
			cnt[t]++;
		}
		ans = 0;
		dfs(0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
