#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, m, i, j, max, a, b, ra, rb;
	short R[30001], N[30001];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (i = 0, max = 1; i <= n; i++)
		{
			R[i] = i;
			N[i] = 1;
		}
		while (m--)
		{
			scanf("%d%d", &a, &b);
			for (ra = a; ra != R[ra]; ra = R[ra])
				;
			for (rb = b; rb != R[rb]; rb = R[rb])
				;
			R[a] = R[b] = ra;
			if (ra == rb)
			{
				continue;
			}
			R[rb] = ra;
			N[ra] += N[rb];
			if (N[ra] > max)
			{
				max = N[ra];
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
