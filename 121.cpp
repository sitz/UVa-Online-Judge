#include <bits/stdc++.h>

using namespace std;

int cnt_skew(double a, double b)
{
	int cols, rows;
	bool same = (a - int(a) >= 0.5);
	cols = int(a);
	rows = 2.0 * (b - 1) / sqrt(3) + 1;
	return cols * rows - (same ? 0 : rows / 2);
}

int main()
{
	double a, b;
	while (scanf("%lf%lf", &a,&b) == 2)
	{
		if (a < 1 || b < 1)
		{
			printf("0 grid\n");
			continue;
		}
		int grid = int(a) * int(b);
		int skew = cnt_skew(a, b);
		skew = max(skew, cnt_skew(b, a));
		if (skew > grid)
		{
			cout << skew << " skew" << endl;
		}
		else
		{
			cout << grid << " grid" << endl;
		}
	}
	return 0;
}
