#include <bits/stdc++.h>

using namespace std;

int T, cc, n;
double p = 0.0, q = 0.0;
int main()
{
	scanf("%d", &T);
	for (int cc = 0; cc < T; ++cc)
	{
		scanf("%d", &n);
		q = 0.0;
		for (int r = 1 + n / 2; r <= n; ++r)
		{
			q += 1 / (double)r;
		}
		p = 1 - q;
		printf("Case #%d: %lf %lf\n", cc + 1, p, 1 / p);
	}
	return 0;
}
