#include <bits/stdc++.h>

using namespace std;

#define IN(i) ((i) > 0 && (i) <= n)

const int maxn = 40 + 10;
const int w[4][4] = {{-3, -1, 4, -4}, {1, 3, 4, -4}, {1, -1, 4, -4}, {1, -1, 4, -4}};
const int limit = 100000;

int p[maxn], map_[maxn][maxn], n, test, ans;

void pre()
{
	for (int i = 1; i <= 40; i++)
	{
		for (int j = 1; j <= 40; j++)
		{
			map_[i][j] = (i == j) ? 0 : limit;
		}
	}
	for (int i = 1; i <= 40; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i + w[i % 4][j] > 0 && i + w[i % 4][j] <= 40)
			{
				map_[i][i + w[i % 4][j]] = map_[i + w[i % 4][j]][i] = 1;
			}
		}
	}
	for (int k = 1; k <= 40; ++k)
	{
		for (int i = 1; i <= 40; ++i)
		{
			for (int j = 1; j <= 40; ++j)
			{
				map_[i][j] = map_[i][j] < map_[i][k] + map_[k][j]
					? map_[i][j] : map_[i][k] + map_[k][j];
			}
		}
	}
}

bool dfs(int pos, int c, int dep, int last)
{
	if (!c)
	{
		return true;
	}
	if (c + dep > ans)
	{
		return false;
	}
	int np, nc;
	for (int i = 0; i < 4; i++)
	{
		np = pos + w[pos % 4][i];
		if (IN(np) && (np != last))
		{
			nc = c - map_[np][p[np]] + map_[pos][p[np]];
			if (nc < 0)
			{
				cout << "nc < 0" << endl;
				return true;
			}
			p[pos] = p[np];
			p[np] = 1;
			if (dfs(np, nc, dep + 1, pos))
			{
				return true;
			}
			p[np] = p[pos];
			p[pos] = 1;
		}
	}
	return false;
}

void work()
{
	int k = 0, pos;
	for (int i = 1; i <= n; i++)
	{
		k += map_[i][p[i]];
		if (p[i] == 1)
		{
			pos = i;
		}
	}
	k -= map_[pos][1];
	printf("Set %d:\n", ++test);
	for (ans = 0;; ans++)
	{
		if (dfs(pos, k, 0, -1))
		{
			printf("%d\n", ans);
			return;
		}
	}
}

int main()
{
	pre();
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &p[i]);
		}
		work();
	}
	return 0;
}
