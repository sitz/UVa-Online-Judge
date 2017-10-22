#include <bits/stdc++.h>

using namespace std;

int R[50005];
int r(int x)
{
	if (R[x] == x)
	{
		return x;
	}
	return R[x] = r(R[x]);
}
int main()
{
	int t, n, m, i, j, ra, rb, rr;
	for (t = 1; scanf("%d%d", &n, &m) == 2; t++)
	{
		if ((n | m) == 0)
		{
			break;
		}
		rr = n;
		for (i = 1; i <= n; i++)
		{
			R[i] = i;
		}
		while (m--)
		{
			scanf("%d%d", &i, &j);
			ra = r(i);
			rb = r(j);
			if (ra == rb)
			{
				continue;
			}
			rr--;
			R[ra] = rb;
		}
		printf("Case %d: %d\n", t, rr);
	}
	return 0;
}
