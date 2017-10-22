#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

// lo a, hi b.
// min penalty = a*x^2 + (1-x)^2*b for x in [0,1]:
//   ax^2 + (x^2-2x+1)b = (a+b)x^2 - 2bx + b
//   => min at x = 2b/2(a+b) = b/(a+b) (parabola min of f(x)=ax^2+bx+c is -b/2a)
double min_x(int lo, int hi, long A, long B, double &val)
{
	long gap = hi - lo;
	double x = gap * B / (A + (double)B);
	val = A * x * x + B * (gap - x) * (gap - x);
	return lo + x;
}

int main()
{
	int n, a[10000];
	while (scanf("%d", &n) == 1, n)
	{
		ULL hi = 0ULL;
		scanf("%d", &a[0]);
		for (int i = 1; i < n; ++i)
		{
			scanf("%d", &a[i]);
			ULL hse_diff = (a[i] - a[i - 1]);
			hi += hse_diff * hse_diff * (n - i);
		}

		// find best hse
		ULL lo = 0;
		double best_x = a[0];
		double best_hse_price = hi;
		for (int i = 1; i < n; ++i)
		{
			// try in space up to next hse
			ULL hse_diff = (a[i] - a[i - 1]);
			hi -= hse_diff * hse_diff * (n - i);
			double mid, x = min_x(a[i - 1], a[i], i, n - i, mid), price = lo + hi + mid;
			if (price < best_hse_price - 1e-6)
			{
				best_hse_price = price;
				best_x = x;
			}
			lo += i * hse_diff * hse_diff;
		}

		printf("%.3lf\n", best_x);
	}
	return 0;
}
