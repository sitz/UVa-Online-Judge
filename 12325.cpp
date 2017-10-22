#include <bits/stdc++.h>

using namespace std;

int c1, v1, c2, v2, ct;
long long int ans;

int main()
{
	int _, t;
	scanf("%d", &_);
	for (t = 1; t <= _; t++)
	{
		scanf("%d%d%d%d%d", &ct, &c1, &v1, &c2, &v2);
		if (c1 > c2)
		{
			swap(c1, c2);
			swap(v1, v2);
		}
		ans = 0;
		if (ct / c2 >= 50000)
		{
			for (long long int i = 0; i <= c1; i++)
			{
				ans = max(ans, v2 * i + (ct - c2 * i) / c1 * v1);
			}
			for (long long int i = 0; i <= c2; i++)
			{
				ans = max(ans, v1 * i + (ct - c1 * i) / c2 * v2);
			}
		}
		else
		{
			for (long long int i = 0; c2 * i <= ct; i++)
			{
				ans = max(ans, v2 * i + (ct - c2 * i) / c1 * v1);
			}
		}
		printf("Case #%d: %lld\n", t, ans);
	}
	return 0;
}
