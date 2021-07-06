#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

bool overlap(int t1, int l1, int b1, int r1, int t2, int l2, int b2, int r2)
{
	return t1 < b2 && t2 < b1 && l1 < r2 && l2 < r1;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		int n[4], t[4][5], l[4][5], b[4][5], r[4][5];
		scanf("%d%d", n + 0, n + 1);
		rep(i, n[0]) scanf("%d%d%d%d", l[0] + i, t[0] + i, r[0] + i, b[0] + i);
		rep(i, n[1]) scanf("%d%d%d%d", l[1] + i, t[1] + i, r[1] + i, b[1] + i);
		scanf("%d%d", n + 2, n + 3);
		rep(i, n[2]) scanf("%d%d%d%d", l[2] + i, t[2] + i, r[2] + i, b[2] + i);
		rep(i, n[3]) scanf("%d%d%d%d", l[3] + i, t[3] + i, r[3] + i, b[3] + i);

		bool ans1 = false, ans2 = false;
		rep(i, n[0]) rep(j, n[3]) if (overlap(t[0][i], l[0][i], b[0][i], r[0][i], t[3][j], l[3][j], b[3][j], r[3][j]))
		{
			ans1 = true;
		}

		rep(i, n[2]) rep(j, n[1]) if (overlap(t[2][i], l[2][i], b[2][i], r[2][i], t[1][j], l[1][j], b[1][j], r[1][j]))
		{
			ans2 = true;
		}
		printf("Case %d: %s\n", cas, ans1 && ans2 ? "Both" : ans2 ? "First" : ans1 ? "Second" : "Neither");
	}
	return 0;
}
