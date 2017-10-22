#include <bits/stdc++.h>

using namespace std;

// DP

typedef long long ll;

const ll INF = 1LL << 50;

int N;
ll H[150], D;
map<int, ll> best[150];

ll Greedy(int a, int b, ll ha, ll hb)
{
	ll lo = hb - D * (b - a - 1), hi = hb + D * (b - a - 1);
	ll at = ha, ret = 0, nat;
	for (int x = a + 1; x != b; ++x, at = nat, lo += D, hi -= D)
	{
		nat = min(min(max(max(lo, at - D), H[x]), at + D), hi);
		ret += abs(H[x] - nat);
	}
	return ret;
}

ll Best(int l, ll hl)
{
	if (l == N - 1)
	{
		return 1;
	}
	ll &ret = best[l][hl];
	if (!ret)
	{
		ret = INF;
		for (int m = l + 1; m < N; ++m)
		{
			ll nh = min(min(max(max(hl - D * (m - l), H[N - 1] - D * (N - 1 - m)), H[m]), H[N - 1] + D * (N - 1 - m)), hl + D * (m - l));
			ll result = abs(nh - H[m]) + Greedy(l, m, hl, nh) + Best(m, nh);
			ret = min(ret, result);
		}
	}
	return ret;
}

void solve()
{
	scanf("%d%lld", &N, &D);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lld", H + i), best[i].clear();
	}
	if (abs(H[0] - H[N - 1]) > D * (N - 1))
	{
		printf("impossible\n");
	}
	else
	{
		printf("%lld\n", Best(0, H[0]) - 1);
	}
}

int main()
{
	int N;
	for (scanf("%d", &N); N--; solve())
		;
	return 0;
}
