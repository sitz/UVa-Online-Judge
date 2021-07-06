#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXA = 2005;
const int MAXB = 2000005;

int phi[MAXA + 5];

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	memset(phi, 0, sizeof(phi));
	phi[1] = 1;
	for (int i = 2; i <= MAXA; i++)
	{
		if (!phi[i])
		{
			for (int j = i; j <= MAXA; j += i)
			{
				if (!phi[j])
				{
					phi[j] = j;
				}
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}

	LL a, b;
	while (scanf("%lld%lld", &a, &b) == 2)
	{
		if (!a && !b)
		{
			return 0;
		}
		LL ans = 0LL;
		for (int i = 1; i <= a; i++)
		{
			int v = b / i;
			ans += v * phi[i];
			for (int j = v * i + 1; j <= b; j++)
			{
				if (gcd(i, j) == 1)
				{
					ans++;
				}
			}
		}
		ans = 4 * ans + 4;
		LL N = 4 * a * b + 2 * a + 2 * b;
		printf("%.7lf\n", ans * 1.0f / N);
	}
	return 0;
}
