#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 5000005;
const int inf = 1 << 28;
const double eps = 1e-8;

bool prime[N];
int ans[N];

void getprime()
{
	memset(prime, 0, sizeof(prime));
	for (int i = 3; i < N; i++, i++)
	{
		if (prime[i])
		{
			continue;
		}
		if ((LL)i * i >= N)
		{
			continue;
		}
		for (int j = i * i; j < N; j += i)
		{
			prime[j] = 1;
		}
	}
}

void init()
{
	memset(ans, 0, sizeof(ans));
	for (int i = 1, n = N / 5; i <= n; i++)
	{
		if (((3 * i + 7) & 1) && !prime[3 * i + 7])
		{
			ans[i] = 1;
		}
		ans[i] += ans[i - 1];
	}
}

int main()
{
	getprime();
	init();
	int n, t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}
