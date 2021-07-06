#include <bits/stdc++.h>

using namespace std;

int n, k;
double f[12][102] = {0}, ans = 0, pow_;

int main()
{
	while (scanf("%d%d", &k, &n) == 2)
	{
		memset(f, 0, sizeof(f));
		for (int i = 0; i <= k; i++)
		{
			f[i][1] = 1;
		}
		for (int j = 2; j <= n; j++)
		{
			for (int i = 0; i <= k; i++)
			{
				if (i == 0)
				{
					f[i][j] = f[i][j - 1] + f[i + 1][j - 1];
				}
				else if (i == k)
				{
					f[i][j] = f[i - 1][j - 1] + f[i][j - 1];
				}
				else
				{
					f[i][j] = f[i - 1][j - 1] + f[i][j - 1] + f[i + 1][j - 1];
				}
			}
		}
		ans = 0;
		for (int i = 0; i <= k; i++)
		{
			ans += f[i][n];
		}
		k++;
		pow_ = (double)k;
		for (int i = 1; i < n; i++)
		{
			pow_ *= k;
		}
		printf("%.5lf\n", ans / pow_ * 100, ans, pow_);
	}
	return 0;
}
