#include <bits/stdc++.h>

using namespace std;

#define MAXL (100000 >> 5) + 1
#define GET(x) (mark[(x) >> 5] >> ((x)&31) & 1)
#define SET(x) (mark[(x) >> 5] |= 1 << ((x)&31))

int mark[MAXL];

int main()
{
	int T, n, m, A[10];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &A[i]);
		}
		for (int i = 1; i < m; i++)
		{
			A[i] += A[i - 1];
		}
		memset(mark, 0, sizeof(mark));
		SET(0);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j + A[i] <= n; j++)
			{
				if (GET(j))
				{
					SET(j + A[i]);
				}
			}
		}
		printf(GET(n) ? "YES\n" : "NO\n");
		if (T)
		{
			printf("\n");
		}
	}
	return 0;
}
