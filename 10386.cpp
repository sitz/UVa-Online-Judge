#include <bits/stdc++.h>

using namespace std;

#define PREC 1.0e-8

int main()
{
	int N;
	double pi, l, h, m, Y, r, s, m1, m2;
	pi = acos(-1.0);
	scanf("%d", &N);
	r = 1;
	m2 = 0.43171784545542;
	m1 = 0.75435478480197;
	while (N--)
	{
		scanf("%lf", &r);
		s = 8 * r * cos(m1) + 2 * sqrt(3.0) * r;
		printf("%.10lf", s);
		s = 2 * r * sqrt(3.0) + 8 * r * cos(m2);
		printf(" %.10lf\n", s);
	}
	return 0;
}
