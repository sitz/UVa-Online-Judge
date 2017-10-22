#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 10000005
bool f[N];
int n;
int prime[N], tot;
vector<int> p;
void init()
{
	n = 32000;
	int i, j, x;
	for (i = 2; i <= n; ++i)
	{
		if (!f[i])
		{
			prime[tot++] = i;
		}
		for (j = 0; j < tot; ++j)
		{
			x = i * prime[j];
			if (x > n)
			{
				break;
			}
			f[x] = 1;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
int a, b, k, s;
void work()
{
	int i, j, x;
	memset(f, 0, sizeof(f));
	p.clear();
	scanf("%d%d%d%d", &a, &b, &k, &s);
	for (i = 0; i < tot && prime[i] * prime[i] <= b; ++i)
	{
		x = prime[i], j = (x - a % x) % x;
		if (x == a + j)
		{
			j += x;
		}
		for (; j <= b - a; j += x)
		{
			f[j] = 1;
		}
	}
	for (i = 0; i <= b - a; ++i)
		if (a + i > 1 && !f[i])
		{
			p.push_back(a + i);
		}
	int ans = 0;
	for (i = 0; i + k - 1 < p.size(); ++i)
		if (p[i + k - 1] - p[i] == s)
		{
			++ans;
		}
	printf("%d\n", ans);
}

int main()
{
	init();
	int _;
	scanf("%d", &_);
	while (_--)
	{
		work();
	}
	return 0;
}
