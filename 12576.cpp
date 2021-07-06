#include <bits/stdc++.h>

using namespace std;

#define i64 long long

const int mod = 7477777;
const int MAX = 100005;
i64 f2[MAX], f3[MAX], p2[MAX], p3[MAX];

i64 cal2(i64 x)
{
	return x * (x + 1) * (x + x + 1) / 6 % mod;
}

i64 cal3(i64 x)
{
	return x * (x + 1) / 2 % mod * (x * (x + 1) / 2) % mod;
}

void init()
{
	i64 i, temp = 0;
	for (i = 2; i < MAX; i++)
	{
		f2[i] = cal2(i - 1) * 2 % mod;
		p2[i] = i - 1;
	}
	for (i = 3; i < MAX; i++)
	{
		temp += f2[i - 1];
		f3[i] = i * cal2(i - 2) % mod - cal3(i - 2) - cal2(i - 2) + temp;
		f3[i] = (f3[i] % mod + mod) % mod;
		p3[i] = (i - 1) * (i - 2) / 2;
	}
}

int C, num = 0, n;

int main()
{
	init();
	for (scanf("%d", &C); C--;)
	{
		scanf("%d", &n);
		printf("Case %d: ", ++num);
		if (n < 5)
		{
			puts("0");
			continue;
		}
		i64 ans = 0, i;
		for (i = 3; i <= n - 2; i++)
		{
			ans += p3[i] * f2[n - i] + p2[n - i] * f3[i];
			ans %= mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
