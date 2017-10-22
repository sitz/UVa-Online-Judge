#include <bits/stdc++.h>

using namespace std;

#define NMAX 100001
int n, k;
int tree[NMAX];
long long ans;
int lowbit(int x)
{
	return x & (x ^ (x - 1));
}
void update(int i)
{
	while (i <= k)
	{
		tree[i]++;
		i += lowbit(i);
	}
}
int sum(int i)
{
	int ret = 0;
	while (i > 0)
	{
		ret += tree[i];
		i -= lowbit(i);
	}
	return ret;
}
void add(int Min, int Max, int t)
{
	long long ret = 0;
	if (Min < Max)
	{
		ret = sum(Max) - sum(Min);
	}
	else
	{
		ret = sum(k) - sum(Min) + sum(Max);
	}
	ans += t * ret + (t - 1) * (sum(k) - ret);
}
int main()
{
	int T;
	int i, j;
	int b;
	int Min, Max;
	int temp;
	scanf("%d", &T);
	for (j = 1; j <= T; j++)
	{
		ans = 0;
		memset(tree, 0, sizeof(tree));
		scanf("%d%d", &n, &k);
		for (b = n; b > 0; b--)
		{
			temp = ((long long)b * b * b - 1) % k + 1;
			update(temp);
			temp = ((long long)b * b - 1) % k + 1;
			Max = (b % k + temp + k - 1) % k + 1;
			Min = temp % k;
			add(Min, Max, (b - 1) / k + 1);
		}
		printf("Case %d: %lld\n", j, ans);
	}
	return 0;
}
