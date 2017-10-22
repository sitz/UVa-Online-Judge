#include <bits/stdc++.h>

using namespace std;

int P[500] = {2, 3}, ptr;
int main()
{
	int i, j, k, x, ans, sq, ok, p;
	for (ptr = 2; P[ptr - 1] < 1024; ptr++)
	{
		for (i = P[ptr - 1] + 2; i < 1200; i += 2)
		{
			sq = (int)(sqrt((double)i) + 0.1);
			for (j = 0, ok = 1; P[j] <= sq; j++)
			{
				if (i % P[j])
				{
					continue;
				}
				ok = 0;
				break;
			}
			if (ok)
			{
				break;
			}
		}
		P[ptr] = i;
	}
	while (scanf("%d", &k) == 1)
	{
		ans = 0;
		while (k--)
		{
			scanf("%d", &x);
			p = 0;
			for (i = 0; i < ptr; i++)
			{
				if (x % P[i] == 0)
				{
					x /= P[i];
					p++;
					break;
				}
			}
			for (; i < ptr; i++)
			{
				if (x % P[i] == 0)
				{
					x /= P[i];
					p++;
					break;
				}
			}
			if (x != 1)
			{
				p++;
			}
			if (p == 2)
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
