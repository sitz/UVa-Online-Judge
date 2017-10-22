#include <bits/stdc++.h>

using namespace std;

#define esp 1e-6
#define LL long long
#define inf 0x0f0f0f0f
#define maxn 4

const int dice24[24][6] =
		{
				{2, 1, 5, 0, 4, 3}, {2, 0, 1, 4, 5, 3}, {2, 4, 0, 5, 1, 3}, {2, 5, 4, 1, 0, 3}, {4, 2, 5, 0, 3, 1}, {5, 2, 1, 4, 3, 0}, {1, 2, 0, 5, 3, 4}, {0, 2, 4, 1, 3, 5}, {0, 1, 2, 3, 4, 5}, {4, 0, 2, 3, 5, 1}, {5, 4, 2, 3, 1, 0}, {1, 5, 2, 3, 0, 4}, {5, 1, 3, 2, 4, 0}, {1, 0, 3, 2, 5, 4}, {0, 4, 3, 2, 1, 5}, {4, 5, 3, 2, 0, 1}, {1, 3, 5, 0, 2, 4}, {0, 3, 1, 4, 2, 5}, {4, 3, 0, 5, 2, 1}, {5, 3, 4, 1, 2, 0}, {3, 4, 5, 0, 1, 2}, {3, 5, 1, 4, 0, 2}, {3, 1, 0, 5, 4, 2}, {3, 0, 4, 1, 5, 2},
};
int n, dice[maxn][6], ans;
vector<string> names;
int id(char *name)
{
	string s(name);
	int n = names.size();
	for (int i = 0; i < n; i++)
		if (s == names[i])
		{
			return i;
		}
	names.push_back(s);
	return n;
}
int r[maxn], color[maxn][6];
void check()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 6; j++)
		{
			color[i][dice24[r[i]][j]] = dice[i][j];
		}
	int tot = 0;
	for (int j = 0; j < 6; j++)
	{
		int cnt[maxn * 6];
		memset(cnt, 0, sizeof(cnt));
		int max1 = 0;
		for (int i = 0; i < n; i++)
		{
			max1 = max(max1, ++cnt[color[i][j]]);
		}
		tot += n - max1;
	}
	ans = min(ans, tot);
}
void dfs(int d)
{
	if (d == n)
	{
		check();
	}
	else
	{
		for (int i = 0; i < 24; i++)
		{
			r[d] = i;
			dfs(d + 1);
		}
	}
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		names.clear();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 6; j++)
			{
				char ss[30];
				scanf("%s", ss);
				dice[i][j] = id(ss);
			}
		ans = n * 6;
		r[0] = 0;
		dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}
