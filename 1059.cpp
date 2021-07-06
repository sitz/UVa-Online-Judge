#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct vec
{
	int x, y;
	void read()
	{
		cin >> x >> y;
	}
	ll mul(const vec &a, const vec &b)
	{
		return (a.x - x) * (ll)(b.y - y) - (a.y - y) * (ll)(b.x - x);
	}
};
vec p[1024], q[1024];
int n, m, N;
ll solve()
{
	if (N <= 2)
	{
		return 0;
	}
	int g = 0;
	q[N] = q[0];
	for (int i = 0; i <= N; ++i)
	{
		g = __gcd(g, __gcd(q[i].x -= q[N].x, q[i].y -= q[N].y));
	}
	for (int i = 1; i < N; ++i)
	{
		q[i].x /= g;
		q[i].y /= g;
	}
	ll a = 0, p = 0;
	for (int i = 2; i < N; ++i)
	{
		a += q[0].mul(q[i - 1], q[i]);
	}
	if (a < 0)
	{
		a = -a;
	}
	for (int i = 0; i < N; ++i)
	{
		p += abs(__gcd(q[i + 1].x - q[i].x, q[i + 1].y - q[i].y));
	}
	//(a*k^2-p*k)/2 +1, k = 1..m
	ll M = m;
	ll x = M * (M + 1) >> 1,
		 y = a * (M << 1 | 1) - p * 3;
	if (x & 1)
	{
		y >>= 1;
	}
	else
	{
		x >>= 1;
	}
	if (x % 3)
	{
		y /= 3;
	}
	else
	{
		x /= 3;
	}
	return M + x * y;
}
int main()
{
	for (int Tc = 1; cin >> n >> m, n || m; ++Tc)
	{
		for (int i = 0; i < n; ++i)
		{
			p[i].read();
		}
		N = 0;
		for (int i = 0; i < n; ++i)
			if (p[i].mul(p[(i + n - 1) % n], p[(i + 1) % n]))
			{
				q[N++] = p[i];
			}
		cout << "Case " << Tc << ": " << solve() << endl;
	}
}
