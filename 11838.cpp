#include <bits/stdc++.h>

using namespace std;

list<int> E[2000 + 1];
bool v[2000 + 1];

int dfs(int u)
{
	int res = 1;
	v[u] = true;
	for (list<int>::iterator v = E[u].begin(); v != E[u].end(); ++v)
		if (!::v[*v])
			res += dfs(*v);
	return res;
}

int main()
{
	for (int n, m; scanf("%d %d", &n, &m) && !(n == 0 && m == 0);)
	{
		for (int i = 1; i <= n; ++i)
		{
			E[i].clear();
			v[i] = false;
		}
		for (int i = 0, v, w, p; i < m; ++i)
		{
			scanf("%d %d %d", &v, &w, &p);
			E[v].push_back(w);
			if (p == 2)
				E[w].push_back(v);
		}
		bool G = true;
		for (int i = 1; i <= n && G; ++i)
		{
			for (int i = 1; i <= n; ++i)
				v[i] = false;
			if (!::v[i])
				G = (dfs(i) == n);
		}
		printf("%d\n", G ? 1 : 0);
	}
	return 0;
}
