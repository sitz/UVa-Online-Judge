#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> L(15000);
int memo[15000];
int count(int v)
{
	if (v == 0)
	{
		return 1;
	}
	if (memo[v] != -1)
	{
		return memo[v];
	}
	memo[v] = 0;
	for (int i = L[v].size() - 1; i >= 0; i--)
	{
		memo[v] += count(L[v][i]);
	}
	return memo[v];
}
int main()
{
	int n, m, x, ans;
	bool first = false;
	while (scanf("%d", &n) == 1)
	{
		if (first)
		{
			printf("\n");
		}
		for (int i = 0; i < n; i++)
		{
			L[i].clear();
		}
		ans = 0;
		fill(memo, memo + n, -1);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &m);
			if (m == 0)
			{
				ans += count(i);
			}
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &x);
				L[x].push_back(i);
			}
		}
		printf("%d\n", ans);
		first = true;
	}
	return 0;
}
