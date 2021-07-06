#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
const double eps = 1e-10;
#define NEG 0
#define POS 1
inline bool solve(int x, int y, int ai, int bi, int ci)
{
	if (ai * x + bi * y + ci < 0)
	{
		return NEG;
	}
	return POS;
}

main()
{
	int tc = 1;
	int n;
	int a[3000], b[3000], c[3000];
	while (scanf("%d", &n) && n)
	{
		rep(i, n) cin >> a[i] >> b[i] >> c[i];
		int t;
		int cnt = 0;
		cin >> t;
		rep(k, t)
		{
			int x, y;
			int neg = 0, pos = 0;
			scanf("%d%d", &x, &y);
			rep(i, n) if (solve(x, y, a[i], b[i], c[i]) == NEG)
			{
				neg++;
			}
			else
			{
				pos++;
			}
			if (neg > 0)
			{
				neg--;
			}
			if (pos > 0)
			{
				pos--;
			}
			cnt += neg * (neg + 1) / 2 + pos * (pos + 1) / 2;
		}
		printf("Roadmap %d:\n", tc++);
		printf("Negative Builders Ltd. will build %d New Roads.\n", cnt);
	}
	return false;
}
