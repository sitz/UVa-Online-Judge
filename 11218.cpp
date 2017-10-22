#include <bits/stdc++.h>

using namespace std;

#define max(a, b) (a > b) ? a : b
int inf = 1 << 20;
int dp[1 << 9];
int score[9][9][9];
int optimal(int state)
{
	if (state == 511)
	{
		return 0;
	}
	if (dp[state] != -1)
	{
		return dp[state];
	}
	else
	{
		int i, j, k, m = -inf;
		for (i = 0; i < 9; i++)
			if (!(state & (1 << i)))
				for (j = i + 1; j < 9; j++)
					if (!(state & (1 << j)))
						for (k = j + 1; k < 9; k++)
							if (!(state & (1 << k)) && score[i][j][k])
							{
								m = max(m, score[i][j][k] + optimal(state | (1 << i) | (1 << j) | (1 << k)));
							}
		return dp[state] = m;
	}
}
int main()
{
	int c, n, i, j, k, s, cc = 1;
	scanf("%d", &n);
	while (n)
	{
		for (i = 0; i < 9; i++)
			for (j = 0; j < 9; j++)
				for (k = 0; k < 9; k++)
				{
					score[i][j][k] = 0;
				}
		for (i = 0; i < 512; i++)
		{
			dp[i] = -1;
		}
		for (c = 0; c < n; c++)
		{
			scanf("%d %d %d %d", &i, &j, &k, &s);
			i--;
			j--;
			k--;
			score[i][j][k] = score[i][k][j] = score[j][i][k] = score[j][k][i] = score[k][i][j] = score[k][j][i] = s;
		}
		int res = optimal(0);
		if (res > 0)
		{
			printf("Case %d: %d\n", cc++, res);
		}
		else
		{
			printf("Case %d: %d\n", cc++, -1);
		}
		scanf("%d", &n);
	}
	return 0;
}
