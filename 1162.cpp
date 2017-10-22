#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int abs(int x)
{
	return x < 0 ? -x : x;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a < b ? a : b;
}

int dp[502][502], d[601][601];
char s[20][30], s1[502], s2[502];

int main()
{
	int n, m, k, i, j, p, q, l1, l2;
	while (~scanf("%d", &n))
	{
		getchar();
		for (i = 0; i < n; i++)
		{
			gets(s[i]);
		}
		m = strlen(s[0]);
		int Top = max(n, m), tmp;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
			{
				for (p = 0; p < n; p++)
					for (q = 0; q < m; q++)
					{
						d[s[i][j]][s[p][q]] = Top - max(abs(i - p), abs(j - q));
					}
			}
		gets(s1 + 1);
		l1 = strlen(s1 + 1);
		gets(s2 + 1);
		l2 = strlen(s2 + 1);
		for (i = 0; i <= l1; i++)
		{
			dp[i][0] = -i * Top;
			for (j = 1; j <= l2; j++)
			{
				dp[i][j] = -INF;
			}
		}
		for (i = 1; i <= l1; i++)
			for (j = 1; j <= i; j++)
			{
				dp[i][j] = max(dp[i - 1][j] - Top, dp[i - 1][j - 1] + d[s1[i]][s2[j]]);
			}
		printf("%d\n", dp[l1][l2]);
	}
	return 0;
}
