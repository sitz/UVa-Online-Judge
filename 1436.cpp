#include <bits/stdc++.h>

using namespace std;

const int N = 500005;
int t, n, cnt[N], prime[N], vis[N], pn = 0, f[N], ispri[N];
long long m;

int bfs()
{
	queue<int> Q;
	for (int i = 1; i <= n; i++)
		if (!vis[i])
		{
			Q.push(i);
		}
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		if (now == 0)
		{
			break;
		}
		cnt[f[now]] += cnt[now];
		vis[f[now]]--;
		if (vis[f[now]] == 0)
		{
			Q.push(f[now]);
		}
	}
}

void solve(int num, int v)
{
	for (int i = 0; i < pn && prime[i] <= num; i++)
	{
		while (num % prime[i] == 0)
		{
			cnt[prime[i]] += v;
			num /= prime[i];
		}
		if (ispri[num])
		{
			cnt[num] += v;
			break;
		}
	}
}

long long pow_mod(long long x, int k)
{
	long long ans = 1;
	while (k)
	{
		if (k & 1)
		{
			ans = ans * x % m;
		}
		x = x * x % m;
		k >>= 1;
	}
	return ans;
}

int main()
{
	for (int i = 2; i < N; i++)
	{
		if (vis[i])
		{
			continue;
		}
		ispri[i] = 1;
		prime[pn++] = i;
		for (int j = i; j < N; j += i)
		{
			vis[j] = 1;
		}
	}
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%lld", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			cnt[i] = 1;
		}
		f[1] = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 2; i <= n; i++)
		{
			scanf("%d", &f[i]);
			vis[f[i]]++;
		}
		bfs();
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++)
		{
			vis[cnt[i]]++;
		}
		memset(cnt, 0, sizeof(cnt));
		for (int i = 2; i <= n; i++)
		{
			solve(i, 1);
			if (vis[i])
			{
				solve(i, -vis[i]);
			}
		}
		long long ans = 1;
		for (int i = 0; i < pn; i++)
		{
			if (cnt[prime[i]] == 0)
			{
				continue;
			}
			ans = (ans * pow_mod((long long)prime[i], cnt[prime[i]])) % m;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
