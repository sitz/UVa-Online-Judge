#include <bits/stdc++.h>

using namespace std;

int main()
{
	int i, n, k, t;
	double ans, fac[100005] = {0};
	for (i = 1; i < 100003; i++)
	{
		fac[i] = fac[i - 1] + log((double)i);
	}
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		k = n / 2;
		ans = fac[n - 2] - 2.0 * fac[k - 1];
		ans = ans - (double)(n - 2) * log(2.0);
		ans = 1.0 - exp(ans);
		printf("%.4lf\n", ans + 0.00000001);
	}
	return 0;
}
