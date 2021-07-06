#include <bits/stdc++.h>

using namespace std;

static int t, n, q, i, x, a;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &q);
		int m[256] = {0};
		while (n--)
		{
			scanf("%d", &x);
			m[x & 0xff] = 1;
		}
		while (q--)
		{
			scanf("%d", &a);
			x = 0;
			for (i = 255; i > x; i--)
				if (m[i] && (a & i) > x)
					x = a & i;
			printf("%d\n", x);
		}
	}
	return 0;
}
