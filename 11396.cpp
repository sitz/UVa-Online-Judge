#include <bits/stdc++.h>

using namespace std;

#pragma warning(disable : 4786)

#define SIZE 350

char flag, color[SIZE];
int i, j, k, n, u, v;

vector<int> mv[SIZE];
queue<int> q;

int main()
{
	while (scanf("%d", &n) == 1 && n)
	{
		while (!q.empty())
		{
			q.pop();
		}
		for (i = 1; i <= n; i++)
		{
			mv[i].clear();
		}
		memset(color, 0, sizeof(color));
		while (scanf("%d %d", &u, &v) == 2 && (u || v))
		{
			mv[u].push_back(v);
			mv[v].push_back(u);
		}
		for (i = flag = 1; i <= n; i++)
		{
			if (!color[i])
			{
				q.push(i);
				color[i] = 1;
			}
			while (!q.empty())
			{
				u = q.front();
				q.pop();
				for (j = 0, k = mv[u].size(); j < k; j++)
				{
					v = mv[u][j];
					if (!color[v])
					{
						q.push(v);
						color[v] = 3 - color[u];
					}
					else if (color[u] == color[v] && u != v)
					{
						flag = 0;
						break;
					}
				}
				if (!flag)
				{
					break;
				}
			}
			if (!flag)
			{
				break;
			}
		}
		if (flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
