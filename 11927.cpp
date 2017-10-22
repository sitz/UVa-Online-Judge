#include <bits/stdc++.h>

using namespace std;

vector<int> mp[1111], vis[1111];
int n, m, c[1111], Q[1111111], sg[1111], used[1111];

void getsg()
{
	int i, j, k;
	int st = 0, ed = 0;
	for (i = 0; i < n; i++)
		if (c[i] == 0)
			Q[ed++] = i, sg[i] = 0;
	while (st < ed)
	{
		k = Q[st++];
		for (i = 0; i < n; i++)
			used[i] = 0;
		for (i = 0; i < vis[k].size(); i++)
			used[vis[k][i]] = 1;
		for (i = 0; i < n; i++)
			if (!used[i])
			{
				sg[k] = i;
				break;
			}
		for (i = 0; i < mp[k].size(); i++)
		{
			int tm = mp[k][i];
			c[tm]--;
			vis[tm].push_back(sg[k]);
			if (c[tm] == 0)
				Q[ed++] = tm;
		}
	}
}
int main()
{
	int i, j, k, x, y;
	while (scanf("%d%d", &n, &m) != -1 && m + n)
	{
		for (i = 0; i < n; i++)
			mp[i].clear(), vis[i].clear();
		while (m--)
		{
			scanf("%d%d", &x, &y);
			c[x]++;
			mp[y].push_back(x);
		}
		getsg();
		int ans = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &x);
			if (x & 1)
				ans ^= sg[i];
		}
		if (ans)
			puts("First");
		else
			puts("Second");
	}
	return 0;
}
