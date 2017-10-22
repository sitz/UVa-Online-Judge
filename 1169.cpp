#include <bits/stdc++.h>

using namespace std;

#define maxn 100010

deque<int> q;
int n, c, dist2orgin[maxn], x[maxn], y[maxn], sumdis[maxn], sumweight[maxn], dp[maxn];

int f(int i)
{
	return dp[i] - sumdis[i + 1] + dist2orgin[i + 1];
}

int main()
{
	int i, j, T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &c, &n);
		sumdis[0] = sumweight[0] = 0;
		x[0] = y[0] = 0;
		for (i = 1; i <= n; i++)
		{
			int w;
			scanf("%d %d %d", &x[i], &y[i], &w);
			dist2orgin[i] = abs(x[i]) + abs(y[i]);
			sumdis[i] = sumdis[i - 1] + abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
			sumweight[i] = sumweight[i - 1] + w;
		}
		q.clear();
		dp[0] = 0;
		q.push_back(0);
		for (i = 1; i <= n; i++)
		{
			while (!q.empty() && sumweight[i] - sumweight[q.front()] > c)
				q.pop_front();
			if (!q.empty())
				dp[i] = f(q.front()) + sumdis[i] + dist2orgin[i];
			else
				dp[i] = f(i - 1) + sumdis[i] + dist2orgin[i];
			while (!q.empty() && f(i) <= f(q.back()))
				q.pop_back();
			q.push_back(i);
		}
		printf("%d\n", dp[n]);
		if (T)
			puts("");
	}
	return 0;
}
