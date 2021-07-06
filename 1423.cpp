#include <bits/stdc++.h>

using namespace std;

char map_[11][11];
int n, ans[11], sum[11];

bool DFS(int idx)
{
	if (idx == n + 1)
	{
		return true;
	}
	for (int i = -10; i <= 10; i++)
	{
		int m, flag = 0;
		if (i <= 0)
		{
			m = -(i + 10);
		}
		else
		{
			m = i;
		}
		for (int j = 1; j <= idx; j++)
		{
			if (map_[idx][j] == '+')
			{
				if (m + sum[idx - 1] - sum[j - 1] <= 0)
				{
					flag = 1;
					break;
				}
			}
			else if (map_[idx][j] == '-')
			{
				if (m + sum[idx - 1] - sum[j - 1] >= 0)
				{
					flag = 1;
					break;
				}
			}
			else
			{
				if (m + sum[idx - 1] - sum[j - 1] != 0)
				{
					flag = 1;
					break;
				}
			}
		}
		if (!flag)
		{
			ans[idx] = m;
			sum[idx] = sum[idx - 1] + m;
			if (DFS(idx + 1))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char str[1001];
		scanf("%d", &n);
		scanf("%s", str);
		int cou = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				map_[j][i] = str[cou++];
			}
		}
		memset(ans, 0, sizeof(ans));
		memset(sum, 0, sizeof(sum));
		DFS(1);
		for (int i = 1; i <= n; i++)
		{
			printf("%d%c", ans[i], i == n ? '\n' : ' ');
		}
	}
	return 0;
}
