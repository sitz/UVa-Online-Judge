#include <bits/stdc++.h>

using namespace std;

int main()
{
	double r, d, h1;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> r >> d >> h1;
		double ab = sqrt((r * r) - ((r - d) * (r - d)));
		ab = ab * 2;
		double w = asin((r - h1) / r);
		double t = asin((r - d) / r);
		double ot = w - t;
		double h2 = h1 + ab * sin(ot);
		printf("Case %d: %.4lf\n", i, h2);
	}
	return 0;
}
