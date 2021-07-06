#include <bits/stdc++.h>

using namespace std;

#define maxp 2000005
#define maxn 100010

int a[maxp];
int x;
int prime[maxp], k = 0;
int sta[maxn];
stack<int> s;

void pri()
{
	int i = 0, j = 0;
	int t = 0;
	for (i = 2; i <= maxp; i++)
	{
		if (!a[i])
		{
			prime[k++] = i;
			if (k > maxn)
			{
				break;
			}
		}
		if (i == 100016)
		{
			t = 0;
		}
		for (j = 0; j < k && i * prime[j] <= maxp; j++)
		{
			a[i * prime[j]] = 1;
			if (!(i % prime[j]))
			{
				break;
			}
		}
	}
}

int main()
{
	int n = 0, m = 0, t = 0;
	int ans = 0;
	int i = 0;
	pri();
	scanf("%d", &t);
	while ((t--) > 0)
	{
		scanf("%d%d", &n, &m);
		ans = 0;
		while (!s.empty())
		{
			s.pop();
		}
		for (i = 0; i < n; i++)
		{
			x = prime[i] % m;
			while (!s.empty() && s.top() <= x)
			{
				s.pop();
			}
			if (i == 7)
			{
				k = 0;
			}
			if (s.empty())
			{
				ans = (ans + i + 1) % m;
			}
			else
			{
				ans = (ans + i - sta[s.top()]) % m;
			}
			s.push(x);
			sta[x] = i;
		}
		printf("%d\n", ans % m);
	}
	return 0;
}
