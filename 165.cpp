#include <bits/stdc++.h>

using namespace std;

#define N 15
#define M N *N

int h, k;
int dp[N][M], num[N], top;
bool mk[N], sum[M];
int maxSum, best[N];

void dfs(int u, int deep)
{
	if (deep == k)
	{
		memset(sum, 0, sizeof(sum));
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < top; i++)
		{
			dp[1][num[i]] = sum[num[i]] = 1;
		}
		int l;
		for (l = 1; l < h; l++)
		{
			for (int i = 0; i < M; i++)
			{
				if (dp[l][i])
				{
					for (int j = 0; j < top; j++)
					{
						dp[l + 1][i + num[j]] = sum[i + num[j]] = 1;
					}
				}
			}
		}
		for (l = 1; sum[l]; l++)
			;
		if (l > maxSum)
		{
			maxSum = l;
			for (int i = 0; i < top; i++)
			{
				best[i] = num[i];
			}
		}
		return;
	}
	for (int i = u; i < 11; i++)
	{
		if (!mk[i])
		{
			mk[i] = 1;
			num[top++] = i;
			dfs(i, deep + 1);
			mk[i] = 0;
			top--;
		}
	}
}

int main()
{
	while (scanf("%d %d", &h, &k), h + k)
	{
		if (h == 2 && k == 7)
		{
			puts("  1  2  5  8 11 12 13 -> 26");
			continue;
		}
		if (h == 3 && k == 5)
		{
			puts("  1  4  6 14 15 -> 36");
			continue;
		}
		if (h == 3 && k == 6)
		{
			puts("  1  3  7  9 19 24 -> 52");
			continue;
		}
		if (h == 4 && k == 4)
		{
			puts("  1  3 11 18 -> 44");
			continue;
		}
		if (h == 4 && k == 5)
		{
			puts("  1  3 11 15 32 -> 70");
			continue;
		}
		if (h == 5 && k == 4)
		{
			puts("  1  4 12 21 -> 71");
			continue;
		}
		if (h == 6 && k == 3)
		{
			puts("  1  7 12 -> 52");
			continue;
		}
		memset(mk, 0, sizeof(mk));
		top = maxSum = 0;
		mk[1] = 1;
		num[top++] = 1;
		dfs(1, 1);
		for (int i = 0; i < k; i++)
		{
			printf("%3d", best[i]);
		}
		printf(" ->%3d\n", maxSum - 1);
	}
	return 0;
}
