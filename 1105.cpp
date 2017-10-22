#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int N = 500005;
const int INF = 1000000000;
int m, n, p, q;
PII a[N];
int c[2005][2005];
int sum[2005][2005];

PII trans(PII cur)
{
	return PII(cur.first + cur.second, cur.first - cur.second + n);
}

inline int calc(int x1, int y1, int x2, int y2)
{
	if (x1 < 1)
		x1 = 1;
	if (y1 < 1)
		y1 = 1;
	if (x2 > m + n)
		x2 = m + n;
	if (y2 > m + n)
		y2 = m + n;
	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int main()
{
	int Tc = 0;
	while (scanf("%d%d%d%d", &m, &n, &p, &q) != EOF && m + n + p + q)
	{
		rep(i, m + n + 1)
				rep(j, m + n + 1)
						sum[i][j] = c[i][j] = 0;
		rep(i, p)
		{
			scanf("%d%d", &a[i].first, &a[i].second);
			a[i] = trans(a[i]);
			c[a[i].first][a[i].second] = 1;
		}
		for (int i = 1; i <= m + n; i++)
		{
			for (int j = 1; j <= m + n; j++)
			{
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + c[i][j];
			}
		}
		printf("Case %d:\n", ++Tc);
		rep(i, q)
		{
			int ans = -1, ansi, ansj;
			int len;
			scanf("%d", &len);
			for (int i = 1; i <= m; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					//					PII p[4];
					int x1, x2, y1, y2, cur;
					//					p[0] = trans(PII(i - len ,j));
					//					p[1] = trans(PII(i + len, j));
					//					p[2] = trans(PII(i, j - len));
					//					p[3] = trans(PII(i, j + len));
					x1 = i + j - len;
					x2 = i + j + len;
					y1 = i - j - len + n;
					y2 = i - j + len + n;
					cur = calc(x1, y1, x2, y2);
					if (cur > ans || (ans == cur && j < ansj) || (ans == cur && j == ansj && i < ansi))
					{
						ans = cur;
						ansi = i;
						ansj = j;
					}
				}
			}
			printf("%d (%d,%d)\n", ans, ansi, ansj);
		}
	}
	return 0;
}
