#include <bits/stdc++.h>

using namespace std;

int a[101], n;
bool used[221];

// binary search
long long sqrt(long long x)
{
	long long left = 1, right = x, mid = (left + right) / 2;
	while (left <= right)
	{
		if (mid * mid == x)
		{
			return mid;
		}
		else if (mid * mid > x)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
		mid = (left + right) / 2;
	}
	return -1;
}

void solve()
{
	long long t;
	srand(time(NULL));
	while (true)
	{
		memset(used, false, sizeof(used));
		t = 0;
		for (int i = 1; i < n - 1; i++)
		{
			if (rand() % 2)
			{
				a[i] = 2 * i + 1;
			}
			else
			{
				a[i] = 2 * i + 2;
			}
			used[a[i]] = true;
			t += a[i] * a[i] * a[i];
		}
		for (int i = 1; i <= 220; i++)
		{
			if (used[i])
			{
				continue;
			}
			a[n - 1] = i;
			long long x = t + i * i * i;
			long long k = (9 - 4 * 3 * (1 - x));
			long long p = sqrt(k);
			if (p < 0 || p * p != k)
			{
				continue;
			}
			int x1 = (int)(-3 + p), x2 = (int)(-3 - p);
			if (x1 % 6 == 0)
			{
				x1 /= 6;
				a[n] = x1;
				a[0] = x1 + 1;
				for (int j = 0; j <= n; j++)
				{
					if (j)
					{
						putchar(' ');
					}
					printf("%d", a[j]);
				}
				printf("\n");
				return;
			}
			if (x2 % 6 == 0)
			{
				x2 /= 6;
				a[n] = x2;
				a[0] = x2 + 1;
				for (int j = 0; j <= n; j++)
				{
					if (j)
					{
						putchar(' ');
					}
					printf("%d", a[j]);
				}
				printf("\n");
				return;
			}
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int c = 1; c <= t; c++)
	{
		printf("Case %d: ", c);
		scanf("%d", &n);
		if (n == 1)
		{
			printf("1 1\n");
		}
		else if (n == 2)
		{
			printf("-1 0 0\n");
		}
		else
		{
			solve();
		}
	}
	return 0;
}
