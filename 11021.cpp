#include <bits/stdc++.h>

using namespace std;

double p[2010], f[2010];
int main()
{
	int sec;
	scanf("%d", &sec);
	for (int z = 1; z <= sec; z++)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &k, &m);
		for (int i = 0; i <= n - 1; i++)
		{
			scanf("%lf", &p[i]);
		}
		if (k == 0)
		{
			printf("Case #%d: %.7f\n", z, (double)0);
			continue;
		}
		memset(f, 0, sizeof(f));
		f[0] = 0;
		f[1] = p[0];
		for (int i = 2; i <= m; i++)
		{
			f[i] = p[0];
			for (int j = 1; j <= n - 1; j++)
			{
				f[i] += p[j] * pow(f[i - 1], j);
			}
		}
		double ans = pow(f[m], k);
		printf("Case #%d: %.7f\n", z, ans);
	}
	return 0;
}
