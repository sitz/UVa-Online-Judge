#include <bits/stdc++.h>

using namespace std;

int adj[505], ex[3005], ey[3005], ec[3005];

int main()
{
	int n, m, i, j, p, q, c, f, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(adj, 0, sizeof(adj));
		for (i = 0; i < m; i++)
		{
			scanf("%d%d%d", &ex[i], &ey[i], &ec[i]);
		}
		for (p = 1, q = 10005, ans = -1; p <= q;)
		{
			c = ((p + q) >> 1);
			for (i = 0; i < n; i++)
			{
				for (j = 0, f = 0; j < m; j++)
				{
					if (ec[j] + adj[ex[j]] - adj[ey[j]] < c)
					{
						adj[ex[j]] += c - (ec[j] + adj[ex[j]] - adj[ey[j]]);
						f = 1;
					}
				}
				if (f == 0)
				{
					break;
				}
			}
			for (j = 0, f = 0; j < m; j++)
			{
				if (ec[j] + adj[ex[j]] - adj[ey[j]] < c)
				{
					adj[ex[j]] += c - (ec[j] + adj[ex[j]] - adj[ey[j]]);
					f = 1;
				}
			}
			if (f)
			{
				q = c - 1;
			}
			else
			{
				ans = c;
				p = c + 1;
			}
		}
		if (ans > 10000)
		{
			printf("Infinite\n");
		}
		else if (ans == -1)
		{
			printf("No Solution\n");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
	return 0;
}
