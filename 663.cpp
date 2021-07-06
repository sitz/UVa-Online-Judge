#include <bits/stdc++.h>

using namespace std;

bool used[1000];
int llink[1000], rlink[1000];
vector<int> toNxt[1000];

bool dfs(int now, int u, int v)
{
	for (int nxt : toNxt[now])
	{
		if (used[nxt] || (now == u && nxt == v))
			continue;

		used[nxt] = true;
		if (rlink[nxt] == -1 || dfs(rlink[nxt], u, v) == true)
		{
			llink[now] = nxt;
			rlink[nxt] = now;
			return true;
		}
	}
	return false;
}

int bipartite(int n, int u, int v)
{
	fill(llink, llink + n, -1);
	fill(rlink, rlink + n, -1);
	int num = 0;
	for (int i = 0; i < n; ++i)
	{
		fill(used, used + n, false);
		if (dfs(i, u, v))
		{
			++num;
		}
	}
	return num;
}

int main()
{
	int n, Case = 1, Xmin[1000], Xmax[1000], Ymin[1000], Ymax[1000], X, Y;
	while (scanf("%d", &n) && n)
	{
		for (auto &v : toNxt)
		{
			v.clear();
		}

		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d%d%d", &Xmin[i], &Xmax[i], &Ymin[i], &Ymax[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d", &X, &Y);
			for (int j = 0; j < n; ++j)
			{
				if (Xmin[j] <= X && X <= Xmax[j] && Ymin[j] <= Y && Y <= Ymax[j])
				{
					toNxt[j].push_back(i);
				}
			}
		}

		int result = bipartite(n, -1, -1);
		int ans[1000];
		for (int i = 0; i < n; ++i)
		{
			ans[i] = llink[i];
		}

		printf("Heap %d\n", Case++);
		bool ok = false;
		for (int i = 0; i < n; ++i)
		{
			if (bipartite(n, i, ans[i]) < result)
			{
				if (ok)
				{
					putchar(' ');
				}
				printf("(%c,%d)", (i + 'A'), ans[i] + 1);
				ok = true;
			}
		}
		if (ok == false)
		{
			printf("none");
		}
		printf("\n\n");
	}
	return 0;
}
