#include <bits/stdc++.h>

using namespace std;

#define MAXN 47100

typedef long long LL;

bool prime[MAXN + 10];
int prm[MAXN + 10], fat[MAXN + 10], arr[MAXN + 10], sz, k, T;
LL dp[MAXN + 10], n;
map<int, LL> m;

void pre()
{
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 4; i < MAXN; i += 2)
	{
		fat[i] = 2;
		prime[i] = false;
	}
	fat[2] = 2;
	sz = 0;
	prm[sz++] = 2;
	for (int i = 3; i < MAXN; i += 2)
	{
		if (prime[i])
		{
			prm[sz++] = i;
			fat[i] = i;
			for (LL j = (LL)i * i; j < MAXN; j += i)
			{
				fat[j] = i;
				prime[j] = false;
			}
		}
	}
	int s;
	LL res;
	for (int i = 2; i < MAXN; i++)
	{
		s = sqrt(i);
		res = 1;
		if (s * s == i)
		{
			res += dp[s];
		}
		else
		{
			s++;
		}
		for (int j = 2; j < s; j++)
		{
			if (i % j == 0)
			{
				res += dp[j] + dp[i / j];
			}
		}
		dp[i] = res;
	}
}

LL rec(int x)
{
	if (x < MAXN)
	{
		return dp[x];
	}
	else if (m.count(x) > 0)
	{
		return m[x];
	}
	int s = sqrt(x);
	LL res = 1LL;
	int stor = -1;
	for (int i = 0; i < k; i++)
	{
		if (arr[i] > s)
		{
			break;
		}
		if (x % arr[i] == 0)
		{
			res += dp[arr[i]];
			if (arr[i] != x / arr[i])
			{
				res += rec(x / arr[i]);
			}
		}
	}
	return m[x] = res;
}

int main()
{
	int t = 1;
	pre();
	scanf("%d", &T);
	m.clear();
	while (T--)
	{
		scanf("%lld", &n);
		n++;
		if (n < MAXN)
		{
			printf("Case %d: %lld\n", t++, dp[n]);
		}
		else
		{
			int s = sqrt(n);
			LL res = 1;
			int stor = -1;
			if (s * s == n)
			{
				res += dp[s];
				stor = s;
			}
			else
			{
				s++;
			}
			k = 0;
			for (int i = 2; i < s; i++)
			{
				if (n % i == 0)
				{
					res += dp[i];
					arr[k++] = i;
					arr[k++] = n / i;
				}
			}
			if (~stor)
			{
				arr[k++] = stor;
			}
			sort(arr, arr + k);
			for (int i = 2; i < s; i++)
			{
				if (n % i == 0)
				{
					res += rec(n / i);
				}
			}
			printf("Case %d: %lld\n", t++, res);
		}
	}
}
