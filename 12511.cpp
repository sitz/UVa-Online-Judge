#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T, n, m, a[1505], b[1505];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &b[i]);
		}
		int LCIS[1505] = {};
		for (int i = 0; i < n; i++)
		{
			int tmp = 0;
			for (int j = 0; j < m; j++)
			{
				if (a[i] == b[j] && LCIS[j] < tmp + 1)
				{
					LCIS[j] = tmp + 1;
				}
				if (a[i] > b[j] && LCIS[j] > tmp)
				{
					tmp = LCIS[j];
				}
			}
		}
		int res = 0;
		for (int i = 0; i < m; i++)
		{
			if (LCIS[i] > res)
			{
				res = LCIS[i];
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
