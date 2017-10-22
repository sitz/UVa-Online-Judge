#include <bits/stdc++.h>

using namespace std;

int c[4], q, d[4], v;
long long int cnt[100001];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d%d", c + 0, c + 1, c + 2, c + 3, &q);
		memset(cnt, 0, sizeof(cnt));
		cnt[0] = 1;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j <= 100000 - c[i]; j++)
			{
				if (cnt[j])
				{
					cnt[j + c[i]] += cnt[j];
				}
			}
		}
		while (q--)
		{
			long long int total = 0;
			scanf("%d %d %d %d %d", d + 0, d + 1, d + 2, d + 3, &v);
			for (int i = 0; i < 16; i++)
			{
				int tv = v, s = 0;
				for (int j = 1, k = 0; j < 16; j <<= 1, k++)
				{
					if (i & j)
					{
						tv -= c[k] * (d[k] + 1);
						s++;
					}
				}
				if (tv < 0)
				{
					continue;
				}
				if (s & 1)
				{
					total -= cnt[tv];
				}
				else
				{
					total += cnt[tv];
				}
			}
			printf("%lld\n", total);
		}
	}
	return 0;
}
