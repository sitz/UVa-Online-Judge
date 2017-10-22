#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const long long INF = 1000000000000000000LL;

#define MP make_pair
#define FI first
#define SE second
typedef pair<int, long long> PIL;

struct Node
{
	int D, P, R, G;
	bool operator<(const Node &t) const
	{
		return D < t.D;
	}
} a[N];

int n, C, D, tot, top;
long long dp[N];
PIL q[N], st[N];

bool cmpr(PIL a, PIL b, PIL c)
{
	pair<double, double> t1 = MP(1.0 * b.FI - 1.0 * a.FI, 1.0 * b.SE - 1.0 * a.SE), t2 = MP(1.0 * c.FI - 1.0 * b.FI, 1.0 * c.SE - 1.0 * b.SE);
	return t1.SE * t2.FI <= t1.FI * t2.SE;
}

void deal(int l, int r)
{
	if (l == r - 1)
	{
		return;
	}
	int mid = (l + r) / 2;
	deal(l, mid);
	tot = top = 0;
	for (int i = l; i < mid; i++)
	{
		q[tot++] = MP(a[i].G, dp[i] + a[i].R - a[i].P - 1LL * (a[i].D + 1) * a[i].G);
	}
	sort(q, q + tot);
	for (int i = 0; i < tot; i++)
	{
		while (top > 0 && st[top - 1].FI == q[i].FI && st[top - 1].SE < q[i].SE)
		{
			top--;
		}
		while (top > 1 && cmpr(st[top - 2], st[top - 1], q[i]))
		{
			top--;
		}
		st[top++] = q[i];
	}
	for (int i = mid, j = 0; i < r; i++)
	{
		while (j < top - 1 && st[j + 1].SE - st[j].SE > -1LL * a[i].D * (st[j + 1].FI - st[j].FI))
		{
			j++;
		}
		dp[i] = max(dp[i], st[j].SE + 1LL * a[i].D * st[j].FI);
		if (dp[i] < a[i].P)
		{
			dp[i] = -INF;
		}
	}
	deal(mid, r);
}

void solve()
{
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d%d", &a[i].D, &a[i].P, &a[i].R, &a[i].G), dp[i] = -INF;
	}
	dp[0] = C;
	sort(a + 1, a + n + 1);
	deal(0, n + 1);
	long long ans = C;
	for (int i = 1; i <= n; i++)
	{
		dp[i] += a[i].R - a[i].P + 1LL * a[i].G * (D - a[i].D);
		if (dp[i] > ans)
		{
			ans = dp[i];
		}
	}
	//    for(int i=0;i<=n;i++)
	//        printf("%lld ", dp[i]);puts("");
	printf("%lld\n", ans);
}

int main()
{
	int T = 0;
	while (scanf("%d%d%d", &n, &C, &D) != EOF)
	{
		if (n == 0 && C == 0 && D == 0)
		{
			break;
		}
		printf("Case %d: ", ++T);
		solve();
	}
	return 0;
}
