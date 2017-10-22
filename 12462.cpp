#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 29)
#define SET(a) memset(a, -1, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define CLR(a) memset(a, 0, sizeof(a))
#define FILL(a, v) memset(a, v, sizeof(a))
#define PB push_back
#define FOR(i, n) for (int i = 0; i < n; i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a, b) make_pair(a, b)
#define LL long long
#define MX 100100

LL colorNum[MX][40];
LL n, c, t, kk = 1, histogram[MX], i, lft[MX], rgt[MX], mx, color[MX];

int main()
{
	stack<LL> stk;
	while (cin >> n >> c && n && c)
	{
		for (i = 1; i <= n; i++)
			scanf("%lld", &histogram[i]);
		CLR(colorNum);
		for (i = 1; i <= n; i++)
		{
			scanf("%lld", &color[i]);
			long long cl = color[i];
			colorNum[i][cl] = (colorNum[i - 1][cl]) + 1;
			for (int j = 0; j < cl; j++)
				colorNum[i][j] = colorNum[i - 1][j];
			for (int j = cl + 1; j < c; j++)
				colorNum[i][j] = colorNum[i - 1][j];
		}
		while (!stk.empty())
			stk.pop();

		stk.push(0);
		histogram[0] = 0;
		for (i = 1; i <= n; i++)
		{
			while (histogram[stk.top()] >= histogram[i])
				stk.pop();
			lft[i] = stk.top() + 1;
			stk.push(i);
		}
		while (!stk.empty())
			stk.pop();

		stk.push(n + 1);
		histogram[n + 1] = 0;
		for (i = n; i > 0; i--)
		{
			while (histogram[stk.top()] >= histogram[i])
				stk.pop();
			rgt[i] = stk.top() - 1;
			stk.push(i);
		}
		mx = 0;
		for (i = 1; i <= n; i++)
		{
			bool chk = true;
			;
			for (int j = 0; j < c; j++)
				if (colorNum[rgt[i]][j] - colorNum[lft[i] - 1][j] == 0)
					chk = false;
			if (chk)
				mx = max(mx, (rgt[i] - lft[i] + 1) * histogram[i]);
		}
		cout << mx << endl;
	}
	return 0;
}
