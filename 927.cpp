#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, i;
	long long int d, k, x, sum, C[25], tmp;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i <= n; i++)
		{
			scanf("%lld", &C[i]);
		}
		scanf("%lld%lld", &d, &k);
		k = (k - 1) / d + 1;
		x = sqrt(k);
		while (k > x * (x + 1) / 2)
		{
			x++;
		}
		sum = 0LL, tmp = 1LL;
		for (i = 0; i <= n; i++)
		{
			sum += C[i] * tmp;
			tmp *= x;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
