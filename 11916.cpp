#include <bits/stdc++.h>

using namespace std;

#define mod 100000007
#define MOD 60000

typedef long long LL;

struct P
{
	int x, y;
	bool operator<(const P &a) const
	{
		return y == a.y ? x < a.x : y < a.y;
	}
} p[550];

int head[MOD], nxt[MOD * 10], hs[MOD * 10], id[MOD * 10], top;

LL exp(LL b, int p)
{
	LL a = 1;
	for (; p; p >>= 1, b = b * b % mod)
		if (p & 1)
		{
			a = a * b % mod;
		}
	return a;
}

void insert(int x, int y)
{
	int k = x % MOD;
	hs[top] = x, id[top] = y, nxt[top] = head[k], head[k] = top++;
}

int find(int x)
{
	int k = x % MOD;
	for (int i = head[k]; i; i = nxt[i])
	{
		if (hs[i] == x)
		{
			return id[i];
		}
	}
	return -1;
}

int gcd(int n, int m)
{
	int t;
	while (m)
	{
		t = n % m, n = m, m = t;
	}
	return n;
}

int BSGS(int a, int b, int n, int x)
{
	memset(head, 0, sizeof(head));
	top = 1;
	int m = sqrt(n + .0), j;
	LL p = 1;
	for (int i = 0; i < m; ++i, p = p * a % n)
	{
		insert(p * b % n, i);
	}
	for (LL i = m; i < n; i += m)
	{
		if ((j = find(x = x * p % n)) != -1)
		{
			return i - j + 30;
		}
	}
	return -1;
}

int dislog(int a, int b, int n, LL t)
{
	if (t == b)
	{
		return 0;
	}
	for (int i = 1; i <= 30; ++i)
	{
		if ((t = t * a % n) == b)
		{
			return i;
		}
	}
	int d, tb = b;
	while ((d = gcd(a, n)) > 1)
	{
		if (tb % d)
		{
			return -1;
		}
		n /= d, tb /= d;
	}
	return BSGS(a % n, b % n, n, t % n);
}

int main()
{
	int T, n, K, m, b;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas)
	{
		scanf("%d%d%d%d", &n, &K, &m, &b);
		int R = 0;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d", &p[i].x, &p[i].y);
			if (p[i].x > R)
			{
				R = p[i].x;
			}
		}
		sort(p, p + m);
		LL a = 1;
		if (m > 0)
		{
			int cnt = 0;
			for (int j = 0; j < m;)
			{
				++cnt;
				int pre = j;
				while (j < m && p[j].y == p[pre].y)
				{
					++j;
				}
				int x = j - pre, y = 1;
				for (int k = pre; k < j;)
				{
					int nk;
					for (nk = k + 1; nk < j && p[nk].x == p[nk - 1].x + 1; ++nk)
						;
					if (p[k].x != 1 && p[nk - 1].x != R)
					{
						++y;
					}
					k = nk;
				}
				if (x < R)
				{
					a = a * exp(K, y) % mod * exp(K - 1, R - x - y) % mod;
				}
			}
			a = a * exp(K * exp(K - 1, R - 1) % mod, n - cnt) % mod;
		}
		printf("Case %d: ", cas);
		if (a == b)
		{
			printf("%d\n", R);
			continue;
		}
		int cnt = 0;
		if (m == 0)
		{
			cnt = n;
		}
		else
		{
			for (int i = 0; i < m; ++i)
				if (p[i].x == R)
				{
					++cnt;
				}
		}
		a = a * exp(K, cnt) % mod * exp(K - 1, n - cnt) % mod;
		LL ta = exp(K - 1, n);
		LL ans = dislog(ta, b, mod, a) + R + 1;
		printf("%lld\n", ans);
	}
	return 0;
}
