#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MOD = 1000000009LL;

int kk = 1;
char s[1005];
int n, fr[26], ncr[1005][1005], qs[26];
LL p[2][26][1005][1005];
int vs[2][26][1005][1005];
LL q[1005][1005];

LL dp2(int i, int r)
{
	if (r == 0)
	{
		return 1;
	}
	if (i == -1)
	{
		return 0;
	}
	LL &pr = q[i][r];
	if (pr != -1)
	{
		return pr;
	}
	pr = dp2(i - 1, r) + dp2(i, r - 1);
	if (pr >= MOD)
	{
		pr = MOD;
	}
	return pr;
}

LL dp(bool g, int i, int ln, int r)
{
	if (i == 26)
	{
		if (g && r == 1)
		{
			return 1;
		}
		return 0;
	}
	LL &pr = p[g][i][ln][r];
	if (vs[g][i][ln][r] == kk)
	{
		return pr;
	}
	vs[g][i][ln][r] = kk;
	pr = 0;
	for (int j = 0; j <= fr[i]; j++)
	{
		LL qq = dp2(ln, j);
		if (qq > r)
		{
			return pr;
		}
		if (r % qq)
		{
			continue;
		}
		qs[i] = j;
		pr += dp(g || (j > 0), i + 1, ln + j, r / qq) * ncr[fr[i]][j];
		if (pr >= MOD)
		{
			pr %= MOD;
		}
	}
	return pr;
}

int main()
{
	int t, i, j, k;
	ncr[0][0] = 1;
	for (int i = 1; i < 1005; i++)
	{
		ncr[i][0] = ncr[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
			if (ncr[i][j] >= MOD)
			{
				ncr[i][j] -= MOD;
			}
		}
	}
	memset(q, -1, sizeof(q));
	while (scanf("%s", s) != EOF)
	{
		kk++;
		scanf("%d", &n);
		memset(fr, 0, sizeof(fr));
		int ln = strlen(s);
		for (int i = 0; i < ln; i++)
		{
			fr[s[i] - 'a']++;
		}
		printf("%d\n", dp(0, 0, 0, n));
	}
	return 0;
}
