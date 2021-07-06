#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 100005;

int n, a[MAXN], L[MAXN], R[MAXN];
LL sum[MAXN];
stack<int> q;

void init()
{
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	a[0] = a[n + 1] = -0x3f3f3f3f;
	while (!q.empty())
	{
		q.pop();
	}
	q.push(0);
	for (int i = 1; i <= n; i++)
	{
		while (a[q.top()] >= a[i])
		{
			q.pop();
		}
		L[i] = q.top();
		q.push(i);
	}
	while (!q.empty())
	{
		q.pop();
	}
	q.push(n + 1);
	for (int i = n; i; i--)
	{
		while (a[q.top()] >= a[i])
		{
			q.pop();
		}
		R[i] = q.top();
		q.push(i);
	}
}

int main()
{
	int T = 0;
	while (scanf("%d", &n) == 1)
	{
		if (T++)
		{
			printf("\n");
		}

		init();

		int l, r;
		LL ans = 0;
		for (int i = 1; i <= n; i++)
		{
			LL t = a[i] * (sum[R[i] - 1] - sum[L[i]]);
			if (t > ans)
			{
				ans = t;
				l = L[i] + 1;
				r = R[i] - 1;
			}
			else if (t == ans && R[i] - L[i] - 1 < r - l + 1)
			{
				l = L[i] + 1;
				r = R[i] - 1;
			}
		}
		if (ans == 0)
		{
			printf("0\n1 1\n");
		}
		else
		{
			printf("%lld\n%d %d\n", ans,l,r);
		}
	}
	return 0;
}
