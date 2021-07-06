#include <bits/stdc++.h>

using namespace std;

const int maxn = 3000005;
const int sigma_size = 26;

struct Tire
{
	int sz;
	int g[maxn][sigma_size];
	int val[maxn], vis[maxn];

	int deep, ans;
	char s[15];

	void init();
	int idx(char ch);
	void insert(char *str);
	int solve(char *str, int x);
	void dfs(int u, int d, int x);
	void clear(int u, int flag);
} AC;

int main()
{
	int n, x;
	char str[15];
	while (scanf("%d", &n) == 1)
	{
		AC.init();

		for (int i = 0; i < n; i++)
		{
			scanf("%s", str);
			AC.insert(str);
		}

		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%s%d", str, &x);
			printf("%d\n", AC.solve(str, x));
		}
	}
	return 0;
}

void Tire::init()
{
	sz = 1;
	val[0] = 0;
	//memset(vis, 0, sizeof(vis));
	memset(g[0], 0, sizeof(g[0]));
}

int Tire::idx(char ch)
{
	return ch - 'a';
}

void Tire::dfs(int u, int d, int x)
{
	if (x < 0)
		return;

	if (vis[u] == 0)
		vis[u] = 1;

	if (d == deep)
	{
		vis[u] = 2;
		return;
	}

	int v = idx(s[d]);
	if (g[u][v])
		dfs(g[u][v], d + 1, x);

	dfs(u, d + 1, x - 1);

	for (int i = 0; i < sigma_size; i++)
	{
		if (g[u][i])
		{
			dfs(g[u][i], d, x - 1);
			dfs(g[u][i], d + 1, x - 1);
		}
	}
}

void Tire::clear(int u, int flag)
{
	if (vis[u] == 0)
		return;

	if (flag && vis[u] == 2)
	{
		ans += val[u];
		flag = 0;
	}

	for (int i = 0; i < sigma_size; i++)
	{
		if (g[u][i])
			clear(g[u][i], flag);
	}
	vis[u] = 0;
}

int Tire::solve(char *str, int x)
{
	ans = 0;
	deep = strlen(str);
	strcpy(s, str);

	dfs(0, 0, x);
	clear(0, 1);
	return ans;
}

void Tire::insert(char *str)
{
	int u = 0, n = strlen(str);

	for (int i = 0; i < n; i++)
	{
		int v = idx(str[i]);

		if (g[u][v] == 0)
		{
			val[sz] = 0;
			memset(g[sz], 0, sizeof(g[sz]));
			g[u][v] = sz++;
		}

		u = g[u][v];
		val[u]++;
	}
}
