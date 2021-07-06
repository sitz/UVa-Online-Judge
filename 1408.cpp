#include <bits/stdc++.h>

using namespace std;

int n, m;
int f[2][1024 * 1025];

vector<int> vis[2];

const int INF = 0x3f3f3f3f;

int mar[52][20];

#define pb push_back

/*int get(int v, int state) {
    return (state >> ((m - v) * 2)) & 3;
}

int change(int v, int d, int state) {
    return (((state >> ((m - v) * 2) >> 2 << 2) | d) << ((m - v) * 2)) | (state & ((1 << ((m - v) * 2)) - 1));
}*/
int get(int v, int state)
{
	return (state >> ((m - v + 1) * 2)) & 3;
}

int change(int v, int d, int state)
{
	return (((state >> ((m - v + 1) * 2) >> 2 << 2) | d) << ((m - v + 1) * 2)) | (state & ((1 << ((m - v + 1) * 2)) - 1));
}

void update(int state, int now, int d)
{
	if (f[now][state] == INF)
	{
		vis[now].pb(state);
	}
	f[now][state] = min(f[now][state], d);
}

int main()
{
	//    freopen("o", "w", stdout);
	int cas = 0;
	while (scanf("%d%d", &n, &m) == 2 && n && m)
	{
		cas++;
		printf("Case %d: ", cas);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
			{
				scanf("%d", &mar[i][j]);
			}
		int now = 0;
		int pre = 1;
		memset(f, 0x3f, sizeof(f));
		f[0][0] = 0;
		vis[0].clear();
		vis[1].clear();
		vis[now].pb(0);
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				now = 1 - now;
				pre = 1 - pre;
				for (int k = 0; k < (int)vis[now].size(); ++k)
				{
					f[now][vis[now][k]] = INF;
				}
				vis[now].clear();
				for (int k = 0; k < (int)vis[pre].size(); ++k)
				{
					int kk = vis[pre][k];
					int tot = f[pre][kk];
					int k1 = get(j + 1, kk);
					int k2 = get(j, kk);
					if (mar[i][j] == 0)
					{
						update(change(j, 0, change(j + 1, 0, kk)), now, tot);
						continue;
					}
					update(change(j + 1, 1, change(j, 0, kk)), now, tot + (mar[i][j - 1] >= mar[i][j] || k2 != 1));
					update(change(j + 1, 2, change(j, 0, kk)), now, tot + (mar[i][j - 1] <= mar[i][j] || k2 != 2));
					update(change(j + 1, 0, change(j, 1, kk)), now, tot + (mar[i - 1][j] >= mar[i][j] || k1 != 1));
					update(change(j + 1, 0, change(j, 2, kk)), now, tot + (mar[i - 1][j] <= mar[i][j] || k1 != 2));
				}
			}
			now = 1 - now;
			pre = 1 - pre;
			for (int k = 0; k < (int)vis[now].size(); ++k)
			{
				f[now][vis[now][k]] = INF;
			}
			vis[now].clear();
			for (int k = 0; k < (int)vis[pre].size(); ++k)
			{
				int kk = vis[pre][k];
				int tot = f[pre][kk];
				update(kk >> 2, now, tot);
			}
		}
		int ans = INF;
		for (int k = 0; k < (int)vis[now].size(); ++k)
		{
			ans = min(ans, f[now][vis[now][k]]);
		}
		printf("%d\n", ans);
	}
}
