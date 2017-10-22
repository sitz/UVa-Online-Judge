#include <bits/stdc++.h>

using namespace std;

int main()
{
	int b, i, r, x, h, t;
	while (scanf("%d%d%d", &b, &h, &t) == 3)
	{
		if (t == 0)
		{
			printf("1\n");
			continue;
		}
		for (i = 1, x = h, r = 0;; i++)
		{
			r += x * t;
			if (r == h)
			{
				break;
			}
			x = r % b;
			r /= b;
		}
		printf("%d\n", i);
	}
	return 0;
}
