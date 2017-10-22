#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n, K, m, anss;
LL ans[30][30], num[50][30][30], tmp[30][30], g[30][30];
LL mul(LL a, LL b, LL c)
{
	a %= c;
	LL ans = 0, num = a;
	while (b)
	{
		if (b % 2 == 1)
		{
			ans = (ans + num) % c;
		}
		num = (num + num) % c;
		b = b / 2;
	}
	return ans;
}
void mul(LL a[30][30], LL b[30][30], LL c[30][30])
{
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 13; j++)
		{
			if (b[i][j] == 0)
			{
				continue;
			}
			for (int k = 0; k < 13; k++)
			{
				tmp[i][k] += mul(b[i][j], c[j][k], m);
				tmp[i][k] %= m;
			}
		}
	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 13; j++)
		{
			a[i][j] = tmp[i][j];
		}
}
LL b[13], tb[13];
LL cal(int L)
{
	L += 2;
	if (K <= 2 || L < 5)
	{
		return 0;
	}
	L -= 3;
	int id = 0;
	memset(b, 0, sizeof(b));
	b[0] = 1;
	while (L)
	{
		if (L % 2 == 1)
		{
			for (int i = 0; i < 13; i++)
			{
				LL tmp = 0;
				for (int j = 0; j < 13; j++)
				{
					tmp += mul(b[j], num[id][j][i], m);
					if (tmp >= m)
					{
						tmp -= m;
					}
				}
				tb[i] = tmp;
			}
			for (int i = 0; i < 13; i++)
			{
				b[i] = tb[i];
			}
		}
		id++;
		L = L / 2;
	}
	LL anss = mul(K - 2, K - 1, m);
	anss = mul(anss, K, m);
	anss = mul(anss, b[6], m);
	return anss;
}
int gs[10010], yz[10010], pr[10010], pcnt;
int flag[10010];
void dfs(int now, int end, int euler, int tnum)
{
	if (now == end)
	{
		LL tmp = cal(n / tnum);
		anss += mul(tmp, euler, m);
		anss %= m;
		return;
	}
	dfs(now + 1, end, euler, tnum);
	LL temp = 1;
	for (int i = 1; i <= gs[now]; i++)
	{
		temp *= yz[now];
		dfs(now + 1, end, mul(euler, temp - temp / yz[now], m), tnum * temp);
	}
	return;
}
void init()
{
	int p[10], q[10], ck[100], Cnt = 0;
	int ok[100];
	memset(ok, 0, sizeof(ok));
	for (int i = 0; i < 27; i++)
	{
		int x = i;
		int zeros = 0, ones = 0, twos = 0;
		for (int j = 0; j < 3; j++)
		{
			p[2 - j] = x % 3;
			x /= 3;
			if (p[2 - j] == 0)
			{
				zeros++;
			}
			else if (p[2 - j] == 1)
			{
				ones++;
			}
			else
			{
				twos++;
			}
		}
		if (zeros > 1 || ones > 1)
		{
			continue;
		}
		ok[i] = 1;
		ck[i] = Cnt++;
	}
	for (int ii = 0; ii < 27; ii++)
	{
		if (!ok[ii])
		{
			continue;
		}
		int i = ck[ii];
		int x = ii;
		for (int j = 0; j < 3; j++)
		{
			p[2 - j] = x % 3;
			x /= 3;
		}
		for (int jj = 0; jj < 27; jj++)
		{
			if (!ok[jj])
			{
				continue;
			}
			int j = ck[jj];
			int x = jj;
			for (int k = 0; k < 3; k++)
			{
				q[2 - k] = x % 3;
				x /= 3;
			}
			if (p[1] == q[0] && p[2] == q[1])
			{
				int zeros = 0, ones = 0, twos = 0;
				for (int k = 0; k < 3; k++)
				{
					if (q[k] == 0)
					{
						zeros++;
					}
					else if (q[k] == 1)
					{
						ones++;
					}
					else
					{
						twos++;
					}
				}
				if (zeros > 1 || ones > 1)
				{
					continue;
				}
				if (q[2] == 0)
				{
					g[i][j] = 1;
				}
				else if (q[2] == 1)
				{
					g[i][j] = 1;
				}
				else
				{
					if (q[2] == 0)
					{
						zeros--;
					}
					else if (q[2] == 1)
					{
						ones--;
					}
					else
					{
						twos--;
					}
					g[i][j] = max(0, (int)K - 2 - twos);
				}
			}
		}
	}
}
int main()
{
	memset(flag, -1, sizeof(flag));
	pcnt = 0;
	for (int i = 2; i <= 10000; i++)
	{
		if (flag[i])
		{
			pr[pcnt++] = i;
		}
		for (int j = 0; j < pcnt && pr[j] <= 10000 / i; j++)
		{
			flag[i * pr[j]] = 0;
			if (i % pr[j] == 0)
			{
				break;
			}
		}
	}
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++)
	{
		scanf("%lld%lld%lld", &n, &K, &m);
		init();
		m *= n;
		for (int i = 0; i < 13; i++)
			for (int j = 0; j < 13; j++)
			{
				num[0][i][j] = g[i][j];
			}
		for (int i = 1; i <= 30; i++)
		{
			mul(num[i], num[i - 1], num[i - 1]);
		}
		int cnt = 0;
		LL tn = n;
		for (int i = 0; i < pcnt && pr[i] <= n / pr[i]; i++)
		{
			if (n % pr[i] == 0)
			{
				yz[cnt] = pr[i];
				gs[cnt] = 0;
				while (n % pr[i] == 0)
				{
					n /= pr[i];
					gs[cnt]++;
				}
				cnt++;
				if (n == 1)
				{
					break;
				}
			}
		}
		if (n != 1)
		{
			yz[cnt] = n;
			gs[cnt] = 1;
			cnt++;
		}
		n = tn;
		anss = 0;
		dfs(0, cnt, 1, 1);
		printf("Case %d: %lld\n", ii, anss / n);
	}
	return 0;
}
