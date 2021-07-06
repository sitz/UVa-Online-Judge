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
int n, w;
int u[110];
int dp[110][110];
int f(int k, int g)
{
	if (dp[k][g] >= 0)
	{
		return dp[k][g];
	}
	if (k > n)
	{
		if (g == 0)
		{
			return 0;
		}
		else
		{
			return INF;
		}
	}
	int minn = INT_MAX;
	int num = 0;
	for (int i = k; i <= n && n - i >= g - 1; i++)
	{
		num += u[i];
		minn = min(minn, f(i + 1, g - 1) + i * num);
	}
	return dp[k][g] = minn;
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int ca = 1; ca <= t; ca++)
	{
		scanf("%d%d", &n, &w);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &u[i]);
		}
		sort(u + 1, u + 1 + n, greater<int>());
		memset(dp, -1, sizeof(dp));
		int num = f(1, w);
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum += u[i];
		}
		printf("%.4lf\n", (double)num / sum);
	}
	return 0;
}
