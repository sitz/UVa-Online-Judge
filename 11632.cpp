#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;
main()
{
	int n;
	while (scanf("%d", &n) && n)
	{
		uint total = 0, sum[n];
		sum[0] = 0;
		for (int i = 0; i < n; i++)
		{
			int t;
			scanf("%d", &t);
			if (i)
			{
				sum[i] = sum[i - 1];
			}
			sum[i] += t;
			total += t;
		}
		uint table[n][n];
		int INF = total * (n + n) + 1;
		fill(&table[0][0], &table[n - 1][n], INF);
		for (int i = 0; i < n; i++)
		{
			table[0][i] = (1 + i + 1) * (sum[i]);//i+1 bit has already decided
		}
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					uint dif = sum[k] - sum[j];
					table[i + 1][k] = min(table[i + 1][k], table[i][j] + (i + 2 + k + 1) * dif);
				}
			}
		}
		uint ans = INF;
		for (int i = 0; i < n; i++)
		{
			ans = min(ans, table[i][n - 1]);
		}
		printf("%d\n", ans);
	}
}
