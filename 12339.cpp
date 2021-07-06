#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define inf 1000000009
#define mod 1000000007
#define N 2509

int s[N][N], a[N];
void init()
{
	s[0][0] = 1;
	for (int i = 1; i < N; i++)
		for (int j = 1; j <= i; j++)
		{
			s[i][j] = (s[i - 1][j - 1] + 1ll * s[i - 1][j] * j) % mod;
		}
}
void extend_gcd(ll &x, ll &y, ll a, ll b)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return;
	}
	extend_gcd(x, y, b, a % b);
	x -= a / b * y;
	y ^= x, x ^= y, y ^= x;
}
ll rev(ll a)
{
	ll x, y;
	extend_gcd(x, y, a, mod);
	return x % mod;
}
ll sumk(int n, int m)
{
	ll r = 0;
	for (int i = m + 1; i; i--)
	{
		r = (r + 1ll * s[m][i - 1] * a[i] % mod * rev(i)) % mod;
	}
	return r;
}
ll mul(ll a, ll b)
{
	ll r = 1;
	for (; b; b >>= 1, a = a * a % mod)
		if (b & 1)
		{
			r = r * a % mod;
		}
	return r;
}
int main()
{
	int T, n, k;
	init();
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		memset(a, 0, sizeof(a));
		a[0] = 1;
		for (int i = 1; i <= k + 1 && i <= n + 1; i++)
		{
			a[i] = 1ll * a[i - 1] * (n + 2 - i) % mod;
		}
		int ans = ((mul(1ll * (n + 1) * n / 2 % mod, k) - sumk(n, k)) % mod + mod) % mod;
		printf("%d\n", ans);
	}
	return 0;
}
