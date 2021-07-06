#include <bits/stdc++.h>

using namespace std;

#define M 1005

int main()
{
	char s[M];
	int t, i, j, k, n, a, b, cc = 0, ans[M];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", s);
		n = strlen(s);
		memset(ans, 0, sizeof(ans));
		printf("Case #%d: %d", ++cc, n);
		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				a = i, b = j;
				k = 1;
				while (b < n)
				{
					if (s[a] == s[b])
					{
						++a, ++b;
					}
					else
					{
						break;
					}
					if (a == j)
					{
						a = i;
						++k;
					}
				}
				int tp = (j - i) * k;
				if (ans[k] < tp)
				{
					ans[k] = tp;
				}
			}
		}
		for (i = 2; i <= n; i++)
		{
			printf(" %d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
