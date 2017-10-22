#include <bits/stdc++.h>

using namespace std;

int main()
{
	int s = 1, t = 0, q, r;
	int u = 0, v = 1, a, b, x, y;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		s = 1;
		v = 1, t = u = 0;
		while (b > 0)
		{
			q = a / b;
			r = a - q * b;
			x = s - q * u;
			y = t - q * v;
			a = b;
			s = u;
			t = v;
			b = r;
			u = x;
			v = y;
		}
		printf("%d %d %d\n", s, t, a);
	}
	return 0;
}
