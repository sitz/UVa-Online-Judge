#include <bits/stdc++.h>

using namespace std;

#define MAX 1 << 29

int c[1000005];

int main()
{
	int D, d, N, n, i, j, T, now;
	scanf(" %d", &T);
	while (T--)
	{
		scanf(" %d %d", &D, &N);
		memset(c, 0, sizeof(c));
		c[0]++;
		now = 0;
		for (n = 0; n < N; n++)
		{
			scanf(" %d", &i);
			now += i;
			now %= D;
			c[now]++;
		}
		long long ans = 0;
		for (d = 0; d < D; d++)
		{
			if (c[d] > 1)
			{
				ans += (long long)(c[d]) * (long long)(c[d] - 1) / 2;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
