#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tgts[1000];
	while (1)
	{
		int n;
		scanf("%d", &n);
		if (n == 0)
		{
			break;
		}
		while (1)
		{
			scanf("%d", &tgts[0]);
			if (tgts[0] == 0)
			{
				printf("\n");
				break;
			}
			for (int i = 1; i < n; i++)
			{
				scanf("%d", &tgts[i]);
			}
			int curr_coach = 1, tgts_idx = 0;
			stack<int> station;
			while (curr_coach <= n)
			{
				station.push(curr_coach);
				while (!station.empty() && station.top() == tgts[tgts_idx])
				{
					station.pop();
					tgts_idx++;
					if (tgts_idx >= n)
					{
						break;
					}
				}
				curr_coach++;
			}
			printf(station.empty() ? "Yes\n" : "No\n");
		}
	}
	return 0;
}
