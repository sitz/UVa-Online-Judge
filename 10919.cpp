#include <bits/stdc++.h>

using namespace std;

int C[10000] = {0};
int main()
{
	int t, k, m, x, c, r, suc;
	for (t = 1; scanf("%d", &k) == 1; t++)
	{
		if (k == 0)
		{
			break;
		}
		scanf("%d", &m);
		while (k--)
		{
			scanf("%d", &x);
			C[x] = t;
		}
		suc = 1;
		while (m--)
		{
			scanf("%d%d", &c, &r);
			while (c--)
			{
				scanf("%d", &x);
				if (C[x] == t)
				{
					r--;
				}
			}
			if (r > 0)
			{
				suc = 0;
			}
		}
		printf(suc ? "yes\n" : "no\n");
	}
	return 0;
}
