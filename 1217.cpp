#include <bits/stdc++.h>

using namespace std;

int a[105][105], dp[1 << 20][20], N, sc[20], c;
char s[10005];

int main()
{
	int i, j, k, n, M;
	scanf(" %d %d", &N, &M);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			scanf(" %d", &a[i][j]);
		}
	gets(s);
	while (M--)
	{
		gets(s);
		char *ptr = strtok(s, " ");
		c = 0;
		do
		{
			sscanf(ptr, " %d", &sc[c]);
			sc[c]--;
			c++;
		} while (ptr = strtok(NULL, " "));
		if (c == 2)
		{
			printf("%d\n", a[sc[0]][sc[1]]);
			continue;
		}
		int lim = 1 << (c - 1);
		for (i = 0; i < lim; i++)
			for (j = 0; j < c; j++)
			{
				dp[i][j] = 1e9;
			}
		dp[1][0] = 0;
		for (i = 1; i < lim; i++)
		{
			for (j = 0; j < c - 1; j++)
			{
				if (dp[i][j] == 1e9)
				{
					continue;
				}
				for (k = 0; k < c - 1; k++)
				{
					if (i & (1 << k))
					{
						continue;
					}
					if (a[sc[j]][sc[k]] != 0 && dp[i][j] + a[sc[j]][sc[k]] < dp[i | (1 << k)][k])
					{
						dp[i | (1 << k)][k] = dp[i][j] + a[sc[j]][sc[k]];
					}
				}
			}
		}
		/*for(i=0;i<c;i++)
		    printf("%d ",sc[i]);
		printf("\n");*/
		int ans = 1e9;
		for (i = 1; i < c - 1; i++)
		{
			//printf("sc[%d] = %d, %d\n",i,sc[i],a[sc[i]][sc[c-1]]);
			if (a[sc[i]][sc[c - 1]] != 0)
			{
				//printf("dp = %d\n",dp[lim-1][i]);
				ans = min(ans, dp[lim - 1][i] + a[sc[i]][sc[c - 1]]);
			}
		}
		//printf("ans = %d\n",ans);
		if (ans == 1e9)
		{
			ans = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}
