#include <bits/stdc++.h>

using namespace std;

#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define LL long long
#define inf INT_MAX / 3
#define mod 1000000007ll
#define PI 2.0 * acos(0.0)
#define linf (1 << 60) - 1
#define FOR(I, A, B) for (int I = (A); I < (B); ++I)
#define REP(I, N) FOR(I, 0, N)
#define ALL(A) ((A).begin(), (A).end())
#define set0(ar) memset(ar, 0, sizeof ar)
#define vsort(v) sort(v.begin(), v.end())
#define setinf(ar) memset(ar, 126, sizeof ar)

template <class T>
inline T bigmod(T p, T e, T M)
{
	if (e == 0)
		return 1;
	if (e % 2 == 0)
	{
		LL t = bigmod(p, e / 2, M);
		return (T)((t * t) % M);
	}
	return (T)(((LL)bigmod(p, e - 1, M) * (LL)(p)) % M);
}
template <class T>
inline T gcd(T a, T b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) { return bigmod(a, M - 2, M); }

int md = 50431, n, m;
int dp[1 << 16][20][10];
char pp[9][21];

int go(int bp, int cur, int i)
{
	if (bp == 0 && cur == m - 1)
		return 1;
	if (bp < 1 << n)
	{
		bp = bp << n;
		REP(j, n)
		if (pp[j][cur + 2] != '#') bp |= 1 << j;
		return go(bp, cur + 1, 0);
	}
	if (i == n)
		return 0;
	if (dp[bp][cur][i] != -1)
		return dp[bp][cur][i];
	int &res = dp[bp][cur][i];
	res = go(bp, cur, i + 1);
	if ((bp & 1 << (i + n)) == 0)
		return res;
	if (pp[i][cur] == '#')
		return res;
	if (i > 0 && n > 1)
	{
		if ((pp[i][cur] == '.' || pp[i][cur] == 'R') && (bp & 1 << (i + n)) > 0 &&
				(pp[i - 1][cur] == '.' || pp[i - 1][cur] == 'R') && (bp & 1 << (i + n - 1)) > 0 &&
				(pp[i][cur + 1] == '.' || pp[i][cur + 1] == 'R') && (bp & 1 << i) > 0)
		{
			LL nb = bp & ~(1 << (i + n));
			nb = nb & ~(1 << (i + n - 1));
			nb = nb & ~(1 << i);
			res = (res + go(nb, cur, i + 1)) % md;
		}
		if ((pp[i][cur] == '.' || pp[i][cur] == 'G') && (bp & 1 << (i + n)) > 0 &&
				(pp[i - 1][cur + 1] == '.' || pp[i - 1][cur + 1] == 'G') && (bp & 1 << (i - 1)) > 0 &&
				(pp[i][cur + 1] == '.' || pp[i][cur + 1] == 'G') && (bp & 1 << i) > 0)
		{
			LL nb = bp & ~(1 << (i + n));
			nb = nb & ~(1 << (i - 1));
			nb = nb & ~(1 << i);
			res = (res + go(nb, cur, i + 1)) % md;
		}
		if ((pp[i][cur] == '.' || pp[i][cur] == 'B') && (bp & 1 << (i + n)) > 0 &&
				(pp[i - 1][cur] == '.' || pp[i - 1][cur] == 'B') && (bp & 1 << (i + n - 1)) > 0 &&
				(pp[i - 1][cur + 1] == '.' || pp[i - 1][cur + 1] == 'B') && (bp & 1 << (i - 1)) > 0)
		{
			LL nb = bp & ~(1 << (i + n));
			nb = nb & ~(1 << (i + n - 1));
			nb = nb & ~(1 << (i - 1));
			res = (res + go(nb, cur, i + 1)) % md;
		}
		if ((pp[i][cur] == '.' || pp[i][cur] == 'W') && (bp & 1 << (i + n)) > 0 &&
				(pp[i - 1][cur] == '.' || pp[i - 1][cur] == 'W') && (bp & 1 << (i + n - 1)) > 0)
		{
			LL nb = bp & ~(1 << (i + n));
			nb = nb & ~(1 << (i + n - 1));
			res = (res + go(nb, cur, i + 1)) % md;
		}
	}
	if ((pp[i][cur] == '.' || pp[i][cur] == 'P') && (bp & 1 << (i + n)) > 0 &&
			(pp[i][cur + 1] == '.' || pp[i][cur + 1] == 'P') && (bp & 1 << (i)) > 0)
	{
		LL nb = bp & ~(1 << (i + n));
		nb = nb & ~(1 << i);
		res = (res + go(nb, cur, i + 1)) % md;
	}
	if ((pp[i][cur] == '.' || pp[i][cur] == 'L') && (bp & 1 << (i + n)) > 0)
	{
		LL nb = bp & ~(1 << (i + n));
		res = (res + go(nb, cur, i + 1)) % md;
	}
	if (i < n - 1 && n > 1)
	{
		if ((pp[i][cur + 1] == '.' || pp[i][cur + 1] == 'N') && (bp & 1 << i) > 0 &&
				(pp[i][cur] == '.' || pp[i][cur] == 'N') && (bp & 1 << (i + n)) > 0 &&
				(pp[i + 1][cur + 1] == '.' || pp[i + 1][cur + 1] == 'N') && (bp & 1 << (i + 1)) > 0)
		{
			LL nb = bp & ~(1 << i);
			nb = nb & ~(1 << (i + n));
			nb = nb & ~(1 << (i + 1));
			res = (res + go(nb, cur, i + 1)) % md;
		}
	}
	return res;
}
int tmp[10];

int main()
{
	LL a, b, c, d, e, f, g, h = 1, x, y, z;
	cin >> a;
	while (a--)
	{
		cout << "Case " << h++ << ": ";
		cin >> n >> m;
		memset(dp, -1, sizeof dp);
		set0(pp);
		REP(i, n)
		{
			cin >> pp[i];
			pp[i][m] = '#';
		}
		c = 0;
		REP(i, n)
		{
			if (pp[i][1] != '#')
				c |= 1 << i;
			if (pp[i][0] != '#')
				c |= 1 << (i + n);
		}
		cout << go(c, 0, 0) << endl;
	}
	return 0;
}
