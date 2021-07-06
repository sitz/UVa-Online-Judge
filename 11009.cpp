#include <bits/stdc++.h>

using namespace std;

int main()
{
	int st, ed, i;
	double a, b, r, aa;
	while (scanf("%lf%d%d", &a, &st, &ed) == 3)
	{
		if (a == 0.0 && st == 0 && ed == 0)
		{
			break;
		}
		for (i = st, aa = 0.0; i <= ed; i++)
		{
			b = a + i;
			r = sqrt(9 * a * a + 24 * b * b);
			r = 2 * sqrt(a * a + 5 * b * b - b * r);
			aa += r;
		}
		printf("%d\n", (int)(aa + 0.5));
	}
	return 0;
}
