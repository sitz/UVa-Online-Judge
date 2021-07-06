#include <bits/stdc++.h>

using namespace std;

#define mod 10007
#define mod1 10006
#define be 20000
#define maxl 1000000000
#define maxn 1100

typedef long long ll;

vector<pair<int, int>> v[maxn][maxn];
int f[maxn][maxn], maxr[maxn], maxc[maxn], maxy[maxn], maxx[maxn];

void update(int x, int y, int data)
{
	maxr[x] = max(maxr[x], data);
	maxc[y] = max(maxc[y], data);
	if (x >= y)
		maxx[x - y] = max(maxx[x - y], data);
	else
		maxy[y - x] = max(maxy[y - x], data);
}

int get(int x, int y)
{
	int re = max(maxr[x], maxc[y]);
	if (x >= y)
		re = max(re, maxx[x - y]);
	else
		re = max(re, maxy[y - x]);
	return re + 1;
}

void solve()
{
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	if (v[n][m].size() > 0)
		printf("Sita %d\n", f[n][m] + p * 2);
	else
		printf("Gita %d\n", f[n][m] + p * 2);
}

int main()
{
	int n = 1000, m = 1000, i, j, k;
	for (i = 0; i <= n; ++i)
		for (j = 0; j <= m; ++j)
			v[i][j].clear();
	for (i = 0; i <= n; ++i)
		for (j = 0; j <= m; ++j)
			if (v[i][j].size() == 0)
			{
				for (k = i + 1; k <= n; ++k)
					v[k][j].push_back(make_pair(i, j));
				for (k = j + 1; k <= m; ++k)
					v[i][k].push_back(make_pair(i, j));
				for (k = 1; i + k <= n && j + k <= m; ++k)
					v[i + k][j + k].push_back(make_pair(i, j));
			}
	for (i = 0; i <= n; ++i)
		maxr[i] = -1;
	for (i = 0; i <= m; ++i)
		maxc[i] = -1;
	for (i = 0; i <= max(n, m); ++i)
	{
		maxx[i] = -1;
		maxy[i] = -1;
	}
	for (i = 0; i <= n; ++i)
		for (j = 0; j <= m; ++j)
			if (v[i][j].size() > 0)
			{
				f[i][j] = maxl;
				for (k = 0; k < v[i][j].size(); ++k)
				{
					pair<int, int> p = v[i][j][k];
					f[i][j] = min(f[i][j], f[p.first][p.second] + 1);
					update(i, j, f[i][j]);
				}
			}
			else
			{
				f[i][j] = get(i, j);
			}
	int t;
	scanf("%d", &t);
	while (t-- > 0)
		solve();
	return 0;
}
