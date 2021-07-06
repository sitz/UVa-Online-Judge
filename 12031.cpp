#include <bits/stdc++.h>

using namespace std;

int hefa[1010];
int cal(int n)
{
	int i, j, k, m, t;
	for (i = 0; i * i <= n; i++)
	{
		m = n - i * i;
		for (j = i; j * j <= m; j++)
		{
			t = m - j * j;
			k = sqrt(t) + 1;
			if (k * k > t)
				k--;
			if (k * k > t)
				k--;
			if (k * k == t)
				return 1;
		}
	}
	return 0;
}
long long a[10];
int pri[51000];
int isp[210000];
int cnt;
int dfs(int dep, long long now, long long ji)
{
	if (!now)
	{
		a[dep] = a[dep + 1] = a[dep + 2] = a[dep + 3] = 0;
		return 1;
	}
	if (dep > 3)
		return 0;
	int i, tim;
	for (int i = 1; i <= 10; i++)
		if (now % (pri[i] * pri[i]) == 0)
		{
			while (now % (pri[i] * pri[i]) == 0)
				ji *= pri[i], now /= pri[i] * pri[i];
		}
	long long t = sqrt(now + 0.0);
	if ((t + 1) * (t + 1) <= now)
		t++;
	if (t * t > now)
		t--;
	if (dep == 3)
	{
		a[dep] = t * ji;
		if (dfs(dep + 1, now - t * t, ji))
			return 1;
		return 0;
	}
	if (dep == 0)
		tim = 1000;
	else if (dep == 1)
	{
		if (hefa[now % 1000])
			return 0;
		tim = 2;
	}
	else
	{
		long long tmp = now;
		while (!(tmp & 1))
			tmp >>= 1;
		if (tmp % 4 - 1 || now > 100000)
			return 0;
		tim = 2;
	}
	for (i = 0; i < tim && t >= 0; i++)
	{
		a[dep] = t * ji;
		if (dfs(dep + 1, now - t * t, ji))
			return 1;
		t--;
	}
	return 0;
}

inline void scan(long long &u)
{
	char c;
	while (c = getchar(), c < '0' || c > '9')
		;
	u = c - '0';
	while (c = getchar(), c <= '9' && c >= '0')
		u = u * 10 + c - '0';
}

int main()
{
	long long n, ji;
	int i, j, t, ii = 0;
	//freopen("r","r",stdin);
	//freopen("w2","w",stdout);
	for (i = 1; i <= 1000; i++)
		if (!cal(i))
			hefa[i] = 1;
	for (i = 2; i < 210000; i++)
		if (!isp[i])
		{
			pri[++cnt] = i;
			for (j = i + i; j < 210000; j += i)
				isp[j] = 1;
		}
	long long MA = 0;
	scanf("%d", &t);
	while (t--)
	{
		scan(n);
		if (dfs(0, n, 1))
		{
			printf("%lld %lld %lld %lld\n", a[0], a[1], a[2], a[3]);
			if (a[3] > MA)
				MA = a[3];
		}
		else
			printf("Impossible.\n");
	}
}
