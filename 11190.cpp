#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6

int main()
{
	int t = 0, L, H, K;
	while (scanf("%d%d%d", &L, &H, &K) == 3 && L >= 0)
	{
		double m = 0.0f, n = 0.0f, tt = 0.0f, exp = 0.0f;
		for (int i = H; i >= L; i--)
		{
			double v = log10(i) * K;
			exp = max(exp, floor(v));
		}
		for (int i = H; i >= L; i--)
		{
			double v = log10(i) * K - exp;
			tt += pow(10, v);
		}
		while (tt >= 1)
		{
			tt /= 10, exp++;
		}
		if (fabs(t) < EPS && exp == 0)
		{
			exp = 1;
		}
		printf("Case %04d: %.6lfe%010lld\n", ++t, tt, (long long)exp);
	}
	return 0;
}
