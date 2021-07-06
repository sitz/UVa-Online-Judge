#include <bits/stdc++.h>

using namespace std;

int a[200];
double dp[200];

int main()
{
	int n, i, j;
	double r, v, e, f, b;
	while (scanf("%d", &n) != EOF && n != 0)
	{
		a[0] = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		scanf("%lf", &b);
		scanf("%lf %lf %lf %lf", &r, &v, &e, &f);
		dp[0] = 0;
		for (i = 1; i <= n; i++)
		{
			double mx = 1000000000.0;
			for (j = 0; j < i; j++)
			{
				double ct = 0.0;
				int x;
				for (x = 0; x < a[i] - a[j]; x++)
					if (x < r)
					{
						ct += (1.0 / (v - f * (r - x)));
					}
					else
					{
						ct += (1.0 / (v - e * (x - r)));
					}
				ct += dp[j];
				if (j != 0 && j != n)
				{
					ct += b;
				}
				if (ct < mx)
				{
					mx = ct;
				}
			}
			dp[i] = mx;
		}
		printf("%0.4lf\n", dp[n]);
	}
	return 0;
}
