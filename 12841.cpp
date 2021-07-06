#include <bits/stdc++.h>

using namespace std;

int a[20], vis[20], nxt[20], n, jie;
map<char, int> mp;
vector<int> G[20];

bool dfs(int x, int dep)
{
	if (dep == n && jie == x)
	{
		return true;
	}
	int sz = G[x].size();
	for (int i = 0; i < sz; i++)
	{
		if (!vis[G[x][i]])
		{
			if (dep != n - 1 && G[x][i] == jie)
			{
				continue;
			}
			if (dep == n - 1 && G[x][i] != jie)
			{
				continue;
			}
			vis[G[x][i]] = 1;
			nxt[x] = G[x][i];
			if (dfs(G[x][i], dep + 1))
			{
				return true;
			}
			vis[G[x][i]] = 0;
		}
	}
	return false;
}

int main()
{
	int t, m, cas = 1;
	scanf("%d", &t);
	while (t--)
	{
		printf("Case %d: ", cas++);
		mp.clear();
		scanf("%d%d", &n, &m);
		char st, en;
		for (int i = 0; i < n; i++)
		{
			char temp;
			getchar();
			scanf("%c", &temp);
			if (i == 0)
			{
				st = temp;
			}
			if (i == n - 1)
			{
				en = temp;
			}
			a[i] = temp - 'A';
		}
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			mp[a[i] + 'A'] = i;
			G[i].clear();
		}
		for (int i = 0; i < m; i++)
		{
			getchar();
			char t1, t2;
			scanf("%c %c", &t1, &t2);
			G[mp[t1]].push_back(mp[t2]);
			G[mp[t2]].push_back(mp[t1]);
		}
		for (int i = 0; i < n; i++)
		{
			sort(G[i].begin(), G[i].end());
		}
		int flag = 0, i, kai;
		kai = mp[st];
		jie = mp[en];
		memset(vis, 0, sizeof(vis));
		memset(nxt, -1, sizeof(nxt));
		vis[kai] = 1;
		if (dfs(kai, 1))
		{
			int j = 0, i = kai;
			while (j < n)
			{
				printf("%c", a[i] + 'A');
				i = nxt[i];
				j++;
			}
			printf("\n");
		}
		else
		{
			printf("impossible\n");
		}
	}
	return 0;
}
