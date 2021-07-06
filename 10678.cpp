#include <bits/stdc++.h>

using namespace std;

const double pi = 2 * acos(0);

int main()
{
	int N, t;
	double a, b, l, d;
	cin >> N;
	for (t = 0; t < N; t++)
	{
		cin >> d >> l;
		a = l / 2;
		b = sqrt(a * a - (d / 2) * (d / 2));
		printf("%.3lf\n", pi * a * b);
	}
	return 0;
}
