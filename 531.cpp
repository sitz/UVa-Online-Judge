#include <bits/stdc++.h>

using namespace std;

#define MAX 100

char s1[MAX + 1][30], s2[MAX + 1][30];
int dp[MAX + 1][MAX + 1];
int n, m;

void LCS()
{
	int i, j;
	for (i = 0; i <= n; i++)
	{
		dp[i][m] = 0;
	}
	for (j = 0; j <= m; j++)
	{
		dp[n][j] = 0;
	}
	for (i = n - 1; i >= 0; i--)
	{
		for (j = m - 1; j >= 0; j--)
		{
			if (strcmp(s1[i], s2[j]) == 0)
			{
				dp[i][j] = 1 + dp[i + 1][j + 1];
			}
			else
			{
				dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}
}

int main()
{
	int i, j;
	bool first;
	while (scanf("%s", s1[0]) != EOF)
	{
		n = 1;
		while (scanf("%s", s1[n]) && (strcmp(s1[n], "#") != 0))
		{
			n++;
		}
		m = 0;
		while (scanf("%s", s2[m]) && (strcmp(s2[m], "#") != 0))
		{
			m++;
		}
		LCS();
		first = true;
		i = j = 0;
		while (dp[i][j] != 0)
		{
			if (strcmp(s1[i], s2[j]) == 0)
			{
				if (first == true)
				{
					printf("%s", s1[i]);
					first = false;
				}
				else
				{
					printf(" %s", s1[i]);
				}
				i++;
				j++;
			}
			else if (dp[i + 1][j] >= dp[i][j + 1])
			{
				i++;
			}
			else
			{
				j++;
			}
		}
		printf("\n");
	}
	return 0;
}
