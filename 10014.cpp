#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int(i) = int(a); (i) < int(b); (i)++)

static int cases, t, n, f = 0, n1;
static double a0, a_last, c, sum = 0.0f;

int main()
{
	scanf("%d", &cases);
	FOR(t, 0, cases)
	{
		sum = 0.0f;
		scanf("%d\n%lf\n%lf\n", &n, &a0, &a_last);
		n1 = n;
		FOR(s, 0, n)
		{
			scanf("%lf", &c);
			sum += (n1--) * c;
		}
		printf("%.2lf\n", (n * a0 + a_last - 2 * sum) / (double)(n + 1));
		if (t < cases - 1)
		{
			printf("\n");
		}
	}
	return 0;
}
