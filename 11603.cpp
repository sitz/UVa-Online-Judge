#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(), a.end()
#define clr(a) memset(a, 0, sizeof(a))
#define fill(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<pair<int, int>> VII;

const double eps = 1e-14;
const double pi = acos(-1.0);
#define N 205
int dis[N], vis[N];
int a[N][N], pre[N], b[N][N];
int okay[N][N];

int main()
{
	// freopen("1.txt","r",stdin);
	int tt, cal = 0, i, j, k, tmp, ff, n;
	cin >> tt;
	while (tt--)
	{
		printf("Case #%d: ", ++cal);
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				cin >> a[i][j], b[i][j] = a[i][j];
		if (n == 1)
		{
			cout << 0 << endl;
			continue;
		}
		memset(pre, -1, sizeof(pre));
		for (k = 1; k <= n; k++)
			for (i = 1; i <= n; i++)
				for (j = 1; j <= n; j++)
					if (i != j && j != k && k != i)
					{
						b[i][j] = max(b[i][j], min(b[i][k], b[k][j]));
					}
		ff = 1;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				ff &= a[i][j] == b[i][j];
		if (ff == 0)
		{
			puts("Impossible");
			continue;
		}

		memset(dis, 0, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		int mm, uu;
		for (i = 1; i < n; i++)
		{
			mm = -1;
			for (j = 1; j <= n; j++)
				if (!vis[j] && dis[j] > mm)
					mm = dis[j], uu = j;
			vis[uu] = 1;
			for (j = 1; j <= n; j++)
				if (!vis[j] && a[uu][j] > dis[j])
					dis[j] = a[uu][j], pre[j] = uu;
		}
		cout << n - 1 << endl;
		for (i = 2; i <= n; i++)
			cout << pre[i] - 1 << ' ' << i - 1 << ' ' << a[pre[i]][i] << endl;
	}
	return 0;
}
