#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		int h, w, K;
		scanf("%d%d%d", &h, &w, &K);
		static int a[200][200];
		rep(i, h) rep(j, w) scanf("%d", a[i] + j);
		static int sum[201][201];
		rep(i, h) rep(j, w) sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + a[i][j];
		int cnt = 0;
		rep(i1, h) for (int i2 = i1 + 1; i2 <= h; i2++)
		{
			for (int j1 = 0, j2 = 1; j1 < w; j1++)
			{
				while (j2 <= w && sum[i2][j2] - sum[i2][j1] - sum[i1][j2] + sum[i1][j1] < K)
				{
					j2++;
				}
				cnt += w + 1 - j2;
			}
		}
		int cnt2 = h * (h + 1) / 2 * w * (w + 1) / 2;
		int g = gcd(cnt, cnt2);
		printf("Case %d: %d/%d\n", cas, cnt / g, cnt2 / g);
	}
	return 0;
}
