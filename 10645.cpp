#include <bits/stdc++.h>

using namespace std;

static int dp[101][21][51][3], last[101][21][51][3], last2[101][21][51][3], cost[51], benefit[51];
static char chk[101][21][51][3];
static int n, m, o, i, j, k, l, p, q, b, ans;

inline void backtrack(int i, int j, int k, int l)
{
	if (j > 1)
	{
		backtrack(i - cost[k - 1], j - 1, last[i][j][k][l], last2[i][j][k][l]);
		printf(" %d", k);
	}
	else
	{
		printf("%d", k);
	}
}

int main()
{
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		if (!(n + m + o))
		{
			break;
		}
		for (i = 0; i < m; i++)
		{
			scanf("%d%d", &cost[i], &benefit[i]);
		}
		memset(chk, 0, sizeof(chk));
		chk[0][0][0][0] = 1;
		for (i = 0; i < n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				b = benefit[j - 1] + benefit[j - 1];
				for (k = o; k >= cost[j - 1]; k--)
				{
					for (l = 0; l <= m; l++)
					{
						if (j != l)
						{
							if (chk[k - cost[j - 1]][i][l][0])
							{
								if (dp[k - cost[j - 1]][i][l][0] + b > dp[k][i + 1][j][0] || !chk[k][i + 1][j][0])
								{
									chk[k][i + 1][j][0] = 1;
									dp[k][i + 1][j][0] = dp[k - cost[j - 1]][i][l][0] + b;
									last[k][i + 1][j][0] = l;
									last2[k][i + 1][j][0] = 0;
								}
							}
							if (chk[k - cost[j - 1]][i][l][1])
							{
								if (dp[k - cost[j - 1]][i][l][1] + b > dp[k][i + 1][j][0] || !chk[k][i + 1][j][0])
								{
									chk[k][i + 1][j][0] = 1;
									dp[k][i + 1][j][0] = dp[k - cost[j - 1]][i][l][1] + b;
									last[k][i + 1][j][0] = l;
									last2[k][i + 1][j][0] = 1;
								}
							}
							if (chk[k - cost[j - 1]][i][l][2])
							{
								if (dp[k - cost[j - 1]][i][l][2] + b > dp[k][i + 1][j][0] || !chk[k][i + 1][j][0])
								{
									chk[k][i + 1][j][0] = 1;
									dp[k][i + 1][j][0] = dp[k - cost[j - 1]][i][l][2] + b;
									last[k][i + 1][j][0] = l;
									last2[k][i + 1][j][0] = 2;
								}
							}
						}
						else
						{
							if (chk[k - cost[j - 1]][i][l][0])
							{
								chk[k][i + 1][j][1] = 1;
								dp[k][i + 1][j][1] = dp[k - cost[j - 1]][i][l][0] + benefit[j - 1];
								last[k][i + 1][j][1] = l;
								last2[k][i + 1][j][1] = 0;
							}
							if (chk[k - cost[j - 1]][i][l][1])
							{
								chk[k][i + 1][j][2] = 1;
								dp[k][i + 1][j][2] = dp[k - cost[j - 1]][i][l][1];
								last[k][i + 1][j][2] = l;
								last2[k][i + 1][j][2] = 1;
							}
							if (chk[k - cost[j - 1]][i][l][2])
							{
								if (dp[k - cost[j - 1]][i][l][2] > dp[k][i + 1][j][2] || !chk[k][i + 1][j][2])
								{
									chk[k][i + 1][j][2] = 1;
									dp[k][i + 1][j][2] = dp[k - cost[j - 1]][i][l][2];
									last[k][i + 1][j][2] = l;
									last2[k][i + 1][j][2] = 2;
								}
							}
						}
					}
				}
			}
		}
		for (i = 0, ans = -1; i <= o; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (chk[i][n][j][0])
				{
					if (dp[i][n][j][0] > ans)
					{
						ans = dp[i][n][j][0];
						k = i;
						l = j;
						p = 0;
					}
				}
				if (chk[i][n][j][1])
				{
					if (dp[i][n][j][1] > ans)
					{
						ans = dp[i][n][j][1];
						k = i;
						l = j;
						p = 1;
					}
				}
				if (chk[i][n][j][2])
				{
					if (dp[i][n][j][2] > ans)
					{
						ans = dp[i][n][j][2];
						k = i;
						l = j;
						p = 2;
					}
				}
			}
		}
		if (ans == -1)
		{
			printf("0.0\n");
		}
		else
		{
			if (ans % 2)
			{
				printf("%d.5\n", ans / 2);
			}
			else
			{
				printf("%d.0\n", ans / 2);
			}
			backtrack(k, n, l, p);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
