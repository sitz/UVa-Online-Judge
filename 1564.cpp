#include <bits/stdc++.h>

using namespace std;

const int N = 305;
char week[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int n, m, k, A[N][N], cnt[N];
char day1[5], day2[5];

int find(char *day)
{
	for (int i = 0; i < 7; i++)
		if (strcmp(week[i], day) == 0)
		{
			return i;
		}
}

int inv(int x)
{
	int ans = 1;
	for (int i = 0; i < 5; i++)
	{
		ans = ans * x % 7;
	}
	return ans;
}

void build()
{
	for (int i = 0; i < m; i++)
	{
		scanf("%d%s%s", &k, day1, day2);
		A[i][n] = (find(day2) - find(day1) + 8) % 7;
		int tmp;
		memset(cnt, 0, sizeof(cnt));
		while (k--)
		{
			scanf("%d", &tmp);
			cnt[tmp]++;
		}
		for (int j = 1; j <= n; j++)
		{
			A[i][j - 1] = cnt[j] % 7;
		}
	}
}

int gauss()
{
	int i = 0, j = 0;
	while (i < m && j < n)
	{
		int r;
		for (r = i; r < m; r++)
			if (A[r][j])
			{
				break;
			}
		if (r == m)
		{
			j++;
			continue;
		}
		for (int k = j; k <= n; k++)
		{
			swap(A[r][k], A[i][k]);
		}
		for (int k = 0; k < m; k++)
		{
			if (i == k)
			{
				continue;
			}
			if (A[k][j])
			{
				int tmp = A[k][j] * inv(A[i][j]) % 7;
				for (int x = j; x <= n; x++)
				{
					A[k][x] = ((A[k][x] - tmp * A[i][x]) % 7 + 7) % 7;
				}
			}
		}
		i++;
	}
	for (int k = i; k < m; k++)
		if (A[k][n])
		{
			return 2;
		}
	if (i < n)
	{
		return 1;
	}
	for (int i = 0; i < n; i++)
	{
		int ans = A[i][n] * inv(A[i][i]) % 7;
		if (ans < 3)
		{
			ans += 7;
		}
		printf("%d%c", ans, i == n - 1 ? '\n' : ' ');
	}
	return 0;
}

void solve()
{
	int tmp = gauss();
	if (tmp == 1)
	{
		printf("Multiple solutions.\n");
	}
	else if (tmp == 2)
	{
		printf("Inconsistent data.\n");
	}
}

int main()
{
	while (~scanf("%d%d", &n, &m) && n)
	{
		build();
		solve();
	}
	return 0;
}
