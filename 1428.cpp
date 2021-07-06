#include <bits/stdc++.h>

using namespace std;

#define MAX 40001

struct node
{
	int id, val;
	bool operator<(const node &a) const
	{
		return val < a.val;
	}
} a[MAX];

int n, c[2][MAX], posa[MAX], posb[MAX];

int lowbit(int x)
{
	return x & (-x);
}

void add(int t, int x, int val)
{
	while (x <= n)
	{
		c[t][x] += val;
		x += lowbit(x);
	}
}

int sum(int t, int x)
{
	int sum = 0;
	while (x > 0)
	{
		sum += c[t][x];
		x -= lowbit(x);
	}
	return sum;
}

int main()
{
	int cas;
	scanf("%d", &cas);
	while (cas--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i].val);
			a[i].id = i;
		}
		sort(a + 1, a + n + 1);
		memset(c, 0, sizeof(c));
		memset(posa, 0, sizeof(posa));
		memset(posb, 0, sizeof(posb));
		for (int i = 1; i <= n; i++)
		{
			posa[a[i].id] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			posb[a[i].id] = n - i + 1;
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int ita = sum(0, posa[i]);
			add(0, posa[i], 1);
			ans += ita * (n - posa[i] - (i - ita - 1));
			ita = sum(1, posb[i]);
			add(1, posb[i], 1);
			ans += ita * (n - posb[i] - (i - ita - 1));
		}
		printf("%lld\n", ans);
	}
	return 0;
}
