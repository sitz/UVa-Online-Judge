#include <bits/stdc++.h>

using namespace std;

int k, sp, dp[1001][1001], used[1001][1001], ptr[26], alp[26][1001];
char str[1001], lst[1001];

inline int calc(int p, int q)
{
	if (used[p][q])
	{
		return dp[p][q];
	}
	used[p][q] = 1;
	if (p > q)
	{
		return 0;
	}
	if (p == q)
	{
		dp[p][q] = 1;
		return dp[p][q];
	}
	if (str[p] == str[q])
	{
		dp[p][q] = calc(p + 1, q - 1) + 2;
		return dp[p][q];
	}
	dp[p][q] = max(calc(p + 1, q), calc(p, q - 1));
	return dp[p][q];
}

inline void recurs(int dep)
{
	if (dep == k)
	{
		if (sp)
		{
			printf("%c", sp);
		}
	}
	else
	{
		printf("%c", lst[dep]);
		recurs(dep + 1);
		printf("%c", lst[dep]);
	}
	if (dep == 0)
	{
		printf("\n");
	}
}

int main()
{
	int len, res, i, j, l, r, p, q;
	while (gets(str))
	{
		memset(ptr, 0, sizeof(ptr));
		for (len = 0; str[len]; len++)
		{
			alp[str[len] - 'a'][ptr[str[len] - 'a']++] = len;
		}
		memset(used, 0, sizeof(used));
		res = calc(0, len - 1);
		sp = 0;
		for (i = res, l = 0, r = len - 1, k = 0; i > 0;)
		{
			for (j = 0; j < 26; j++)
			{
				for (p = 0; p < ptr[j]; p++)
				{
					if (alp[j][p] >= l)
					{
						break;
					}
				}
				if (p < ptr[j])
				{
					for (q = ptr[j] - 1; q >= p; q--)
					{
						if (alp[j][q] <= r)
						{
							break;
						}
					}
					if (q >= p)
					{
						p = alp[j][p];
						q = alp[j][q];
						if (dp[p][q] == i)
						{
							if (p == q)
							{
								sp = str[p];
								i--;
							}
							else
							{
								lst[k++] = str[p];
								i -= 2;
							}
							l = p + 1;
							r = q - 1;
							break;
						}
					}
				}
			}
		}
		recurs(0);
	}
	return 0;
}
