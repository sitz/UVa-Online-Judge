#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	if (!b)
	{
		return a;
	}
	while ((a %= b) && (b %= a))
		;
	return a + b;
}
int D[5000];
int main()
{
	int i, n, k, z, ans, t, g;
	while (scanf("%d%d", &n, &k) == 2)
	{
		for (i = 1; i <= n; i++)
		{
			D[i] = i;
		}
		while (k--)
		{
			scanf("%d", &z);
			for (; z; z--)
			{
				t = z;
				for (i = n; t != 1; i--)
				{
					g = gcd(D[i], t);
					D[i] /= g;
					t /= g;
				}
			}
		}
		for (i = ans = 1; i <= n; i++)
		{
			ans *= D[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
