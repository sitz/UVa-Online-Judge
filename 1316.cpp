#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		vector<int> vec[10010];
		for (int i = 0; i < n; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			vec[b].push_back(a);
		}
		priority_queue<int> que;
		int ans = 0;
		for (int i = 10000; i >= 1; i--)
		{
			for (int j = 0; j < vec[i].size(); j++)
			{
				que.push(vec[i][j]);
			}
			if (que.size() == 0)
			{
				continue;
			}
			ans += que.top();
			que.pop();
		}
		printf("%d\n", ans);
	}
	return 0;
}
