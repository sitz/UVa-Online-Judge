#include <bits/stdc++.h>

using namespace std;

//#pragma comment(linker, "/STACK:1024000000,1024000000")

typedef long long ll;
typedef pair<int, int> pii;
#define pb(a) push_back(a)
#define INF 0x1f1f1f1f
#define lson idx << 1, l, mid
#define rson idx << 1 | 1, mid + 1, r
#define PI 3.1415926535898
template <class T>
T min(const T &a, const T &b, const T &c)
{
	return min(min(a, b), min(a, c));
}
template <class T>
T max(const T &a, const T &b, const T &c)
{
	return max(max(a, b), max(a, c));
}
void debug()
{
#ifdef ONLINE_JUDGE
#else
	freopen("d:\\in.txt", "r", stdin);
	freopen("d:\\out1.txt", "w", stdout);
#endif
}
int getch()
{
	int ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch != ' ' && ch != ' ')
		{
			return ch;
		}
	}
	return EOF;
}
int n, m;
int a[550][550], b[550][550];
int dp[550][550];
int f(int k, int maxl)
{
	if (dp[k][maxl] >= 0)
	{
		return dp[k][maxl];
	}
	if (k > n)
	{
		return 0;
	}
	int num = 0;
	int maxx = -1;
	for (int i = 0; i <= m; i++)
	{
		num += a[k][i];
		if (i >= maxl)
		{
			maxx = max(maxx, f(k + 1, max(i, maxl)) + num + b[k][i + 1]);
		}
	}
	return dp[k][maxl] = maxx;
}
int main()
{
	while (scanf("%d%d", &n, &m) != EOF && (n || m))
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				scanf("%d", &a[i][j]);
			}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				scanf("%d", &b[i][j]);
			}
		for (int i = 1; i <= n; i++)
		{
			b[i][m + 1] = 0;
		}
		for (int i = 1; i <= n; i++)
			for (int j = m - 1; j >= 1; j--)
			{
				b[i][j] += b[i][j + 1];
			}
		memset(dp, -1, sizeof(dp));
		printf("%d\n", f(1, 0));
	}
	return 0;
}
