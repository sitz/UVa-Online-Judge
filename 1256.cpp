#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6

template <typename T>
T gcd(T a, T b)
{
	T c;
	while (b)
	{
		c = b;
		b = a % b;
		a = c;
	}
	return a;
}

int main()
{
	int t = 1;
	char v_s[10];
	while (scanf("%s", v_s) == 1)
	{
		double v = strtod(v_s, NULL);
		if (fabs(v - (-1.0)) < EPS)
		{
			break;
		}

		// int n = strlen(v_s) - (strstr(v_s, ".") - v_s + 1);
		// int cnt = 1;
		// double vd = abs(v - round(v));
		// double i = round(cnt / vd);
		// while (abs((i * v) - round(i * v)) > i * 0.5 * pow(10,-n))
		// {
		// 	cnt++;
		// 	i = round(cnt / vd);
		// }

		int n = 0, base = 1;
		for (int i = strlen(v_s) - 1; i >= 0; i--)
		{
			if ('0' <= v_s[i] && v_s[i] <= '9')
			{
				n += (v_s[i] - '0') * base;
				base *= 10;
			}
		}
		base /= 10;

		vector<int> coeffs;
		while (1)// n!=1 && base!=1)
		{
			int gcd_ = gcd(n, base);
			n /= gcd_;
			base /= gcd_;

			fprintf(stderr, "%d ; %d/%d\n", n / base, n % base, base);
			coeffs.push_back(n / base);
			n %= base;

			if (n == 1)
			{
				coeffs.push_back(base);
				break;
			}

			swap(n, base);
		}

		fprintf(stderr, "\ncoeffs[]: ");
		for (int i = 0; i < coeffs.size(); i++)
		{
			fprintf(stderr, "%d ", coeffs[i]);
		}
		fprintf(stderr, "\n\n");

		int lo = 0, hi = coeffs.size() - 1, ans = -1;
		while (lo < hi)
		{
			int mid = lo + (hi - lo) / 2;

			int frac[2] = {1, coeffs[mid]};
			for (int i = mid - 1; i >= 0; i--)
			{
				frac[0] = (coeffs[i]) * frac[1] + frac[0];
				swap(frac[0], frac[1]);
			}
			swap(frac[0], frac[1]);

			char f_s[n + 2];
			sprintf(f_s, "%.*lf", strlen(v_s) - 2, frac[0] / (double)frac[1]);

			fprintf(stderr, "%d %d/%d = %lf %s %s\n", mid, frac[0], frac[1], frac[0] / (double)frac[1], v_s, f_s);

			if (strcmp(f_s, v_s) == 0)
			{
				hi = mid;
				ans = frac[1];
			}
			else
			{
				lo = mid + 1;
			}
		}
		fprintf(stderr, "lo=%d; hi=%d; coeffs.size()-1=%d\n", lo, hi, coeffs.size() - 1);

		printf("Case %d: %d\n", t++, ans);
	}
	return 0;
}
