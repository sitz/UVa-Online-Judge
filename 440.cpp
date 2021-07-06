#include <bits/stdc++.h>

using namespace std;

main()
{
	int a[152], i, d, k, c, p = 0, n, j, ck;
	while (scanf("%d", &n) && n)
	{
		for (j = 2;; j++)
		{
			ck = 1;
			p = 0;
			for (i = 1; i <= n; i++)
			{
				a[i] = i;
			}
			k = 1;
			while (1)
			{
				a[k] = 0;
				d = k + 1;
				c = 0;
				if (d > n)
				{
					d = 1;
				}
				for (;;)
				{
					if (a[d])
					{
						c++;
					}
					if (c == j)
					{
						break;
					}
					d++;
					if (d > n)
					{
						d = 1;
					}
				}
				if (d == 2)
				{
					ck = 0;
					break;
				}
				k = d;
				p++;
				if (p == n - 2)
				{
					break;
				}
			}
			if (ck)
			{
				printf("%d\n", j);
				break;
			}
		}
	}
	return 0;
}
