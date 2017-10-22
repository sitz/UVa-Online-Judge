#include <bits/stdc++.h>

using namespace std;

#define MAX 20001

int p[MAX], dis[MAX], n;
int find(int x)
{
	if (p[x] == x)
	{
		return x;
	}
	int ita = p[x];
	p[x] = find(p[x]);
	dis[x] += dis[ita];
	return p[x];
}
int main()
{
	int cas;
	scanf("%d", &cas);
	while (cas--)
	{
		memset(dis, 0, sizeof(dis));
		scanf("%d", &n);
		for (int i = 0; i <= n; i++)
		{
			p[i] = i;
		}
		char op[5];
		while (scanf("%s", op) && op[0] != 'O')
		{
			if (op[0] == 'E')
			{
				int x;
				scanf("%d", &x);
				find(x);
				printf("%d\n", dis[x]);
			}
			else
			{
				int u, v;
				scanf("%d%d", &u, &v);
				dis[u] = abs(u - v) % 1000;
				p[u] = v;
			}
		}
	}
	return 0;
}
