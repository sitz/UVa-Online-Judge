#include <bits/stdc++.h>

using namespace std;

int c[300005];
int a[100005];
int ans[100005];
int n, m;

int lowbit(int x)
{
	return x & (-x);
}

int sum(int m)
{
	int sum = 0;
	while (m > 0)
	{
		sum += c[m];
		m -= lowbit(m);
	}
	return sum;
}

int insert(int i, int num)
{
	while (i <= n + 100000)
	{
		c[i] += num;
		i += lowbit(i);
	}
}

int main()
{
	int T, num;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= n; i++)
		{
			a[i] = i + 100000;
		}
		for (int i = 2; i <= n; i++)
		{
			insert(i + 100000, 1);
		}
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &num);
			ans[i] = sum(a[num]);
			insert(a[num], -1);
			insert(100000 - i + 2, 1);
			a[num] = 100000 - i + 1;
		}
		for (int i = 1; i <= m; i++)
			if (i != m)
			{
				printf("%d ", ans[i]);
			}
			else
			{
				printf("%d\n", ans[i]);
			}
	}
	return 0;
}
