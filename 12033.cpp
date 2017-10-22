#include <bits/stdc++.h>

using namespace std;

int hea[1100], nex[2100], vv[2100], len[2100];

int dfs(int x, int fa)
{
	int res = 0;
	for (int e = hea[x]; e != -1; e = nex[e])
		if (vv[e] != fa)
		{
			int sg = dfs(vv[e], x);
			if (len[e] == 1)
			{
				res ^= (sg + 1);
			}
			else if (len[e] & 1)
			{
				res ^= (sg + ((sg & 1) ? -1 : 1));
			}
			else
			{
				res ^= sg;
			}
		}
	return res;
}

int main()
{
	int tes, n, u, v, w;
	scanf("%d", &tes);
	for (int h = 1; h <= tes; ++h)
	{
		memset(hea, -1, sizeof(hea));
		scanf("%d", &n);
		for (int i = 1; i < n; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			vv[i] = v;
			nex[i] = hea[u];
			hea[u] = i;
			len[i] = w;
			vv[i + n] = u;
			nex[i + n] = hea[v];
			hea[v] = i + n;
			len[i + n] = w;
		}
		if (dfs(0, -1))
		{
			printf("Case %d: Emily\n", h);
		}
		else
		{
			printf("Case %d: Jolly\n", h);
		}
	}
	return 0;
}
