#include <bits/stdc++.h>

using namespace std;

int n, k, m, min_[501], cnt[501];

bool check()
{
	if (k > n)
	{
		return false;
	}
	for (int i = 1; i <= k; i++)
	{
		min_[i] = min_[i - 1] + ((i / 4) * (i / 4) + 1) * 100;
		cnt[i] = 0;
	}
	if (min_[k] > m)
	{
		return false;
	}
	int left = m, space = n;
	for (int i = k; i >= 1; i--)
	{
		int temp;
		while (space >= i + 1 && left >= min_[i])
		{
			temp = space;
			space -= i + 1;
			left -= min_[i];
			cnt[i]++;
		}
		if (space == i && left >= min_[i])
		{
			temp = space;
			space = 0;
			left -= min_[i];
			cnt[i]++;
		}
		if (((left / 100) & 1) && cnt[i])
		{
			left += min_[i];
			space = temp;
			cnt[i]--;
		}
		if (space == i + 2 && ((left / 100) % 2 == 0) && (left >= min_[i] + 100) && ((min_[i] / 100) & 1))
		{
			space = 0;
			left -= min_[i] + 100;
			cnt[i]++;
			cnt[1]++;
		}
	}
	if (((left / 100) & 1) && cnt[1])
	{
		left += 100;
		space += 1;
		cnt[1]--;
	}
	if (left == 0)
	{
		return true;
	}
	for (int i = k; i >= 1; i--)
	{
		int x = cnt[i] * (2 * min_[i]);
		if (x >= left)
		{
			return true;
		}
		left -= x;
	}
	return left == 0;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d %d", &n, &k, &m);
		if (check())
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}
