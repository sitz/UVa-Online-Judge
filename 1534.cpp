#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MEM(a, b) memset((a), (b), sizeof(a))
const LL INF = 1000000007;
const int N = 510;

double dp[N][N];
double a[N];
double b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		double *x = a;
		double *y = b;
		int n, m;
		cin >> n >> m;
		MEM(dp, 0x6f);
		if (n < m)
		{
			swap(x, y);
		}
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		for (int j = 0; j < m; j++)
		{
			cin >> y[j];
		}
		if (n < m)
		{
			swap(n, m);
		}
		sort(a, a + n);
		sort(b, b + m);
		for (int i = 0; i < m; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (i == j)
				{
					if (i > 0)
					{
						dp[i][j] = dp[i - 1][j - 1] + abs(b[i] - a[j]);
					}
					else
					{
						dp[i][j] = abs(b[i] - a[j]);
					}
				}
				else
				{
					if (i > 0)
					{
						dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(b[i] - a[j]));
					}
					else
					{
						dp[i][j] = min(dp[i][j - 1], abs(b[i] - a[j]));
					}
				}
			}
		}
		printf("%.1lf\n", dp[m - 1][n - 1]);
	}
	return 0;
}
