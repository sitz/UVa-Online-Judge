#include <bits/stdc++.h>

using namespace std;

double E[50005];
int main()
{
	int t, tt, n, i, j;
	double ans, x, p, lg = log(2.0);
	for (i = 1; i < 50005; i++)
	{
		E[i] = log(i);
	}
	scanf("%d", &tt);
	for (t = 1; t <= tt; t++)
	{
		scanf("%d", &n);
		n--;
		p = -n * lg;
		scanf("%lf", &x);
		ans = x * exp(p);
		for (i = 1, j = n; i <= n; i++, j--)
		{
			p = p + E[j] - E[i];
			scanf("%lf", &x);
			ans += x * exp(p);
		}
		printf("Case #%d: %.3lf\n", t, ans);
	}
	return 0;
}
