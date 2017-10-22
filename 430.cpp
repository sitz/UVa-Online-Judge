#include <bits/stdc++.h>

using namespace std;

int ary[30], dp[50001][30];

int max(int p, int q)
{
	if (p > q)
	{
		return p;
	}
	return q;
}

int main()
{
	int n, m, i, j, k, now;
	char buf[100], *ptr;
	while (gets(buf))
	{
		for (i = 0, j = 0, k = 0, m = -1; buf[i]; i++)
		{
			if (buf[i] > 47 && buf[i] < 58)
			{
				k *= 10;
				k += buf[i] - 48;
				j = 1;
			}
			else
			{
				if (j)
				{
					if (m == -1)
					{
						n = k;
					}
					else
					{
						ary[m] = k;
					}
					m++;
					j = k = 0;
				}
			}
		}
		if (j)
		{
			if (m == -1)
			{
				n = k;
			}
			else
			{
				ary[m] = k;
			}
			m++;
			j = k = 0;
		}
		if (m < 0)
		{
			continue;
		}
		memset(dp, 0, sizeof(dp));
		/*ptr = strtok(buf, " ");
		n = atoi(ptr);
		m = 0;
		memset(dp, 0, sizeof(dp));
		while(ptr = strtok(NULL, " "))
		{
		    ary[m++] = atoi(ptr);
		}*/
		for (i = 0; i < m; i++)
		{
			dp[0][i] = 1;
		}
		for (j = 0; j < m; j++)
		{
			for (i = n; i >= ary[j]; i--)
			{
				for (k = 0; k < m; k++)
				{
					if (k != j)
					{
						dp[i][k] += dp[i - ary[j]][k];
					}
				}
			}
		}
		for (j = 0; j < m; j++)
		{
			for (i = max(n - ary[j], 0), k = 0; i < n; i++)
			{
				k += dp[i][j];
			}
			if (j)
			{
				printf(" %d", k);
			}
			else
			{
				printf("%d", k);
			}
		}
		printf("\n");
	}
	return 0;
}
