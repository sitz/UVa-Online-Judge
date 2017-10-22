#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10001;
int n, k, a[MAXN];
int main()
{
	while (scanf("%d %d", &n, &k) != EOF)
	{
		if (n == -1 && k == -1)
		{
			break;
		}
		memset(a, 0, MAXN);
		for (int i = 0; i <= n; ++i)
		{
			scanf("%d", &a[i]);
		}
		for (int i = n; i >= k; i--)
		{
			if (a[i] == 0)
			{
				continue;
			}
			a[i - k] -= a[i];
			a[i] = 0;
		}
		int s = n;
		while (a[s] == 0 && s > 0)
		{
			s--;
		}
		for (int j = 0; j < s; j++)
		{
			printf("%d ", a[j]);
		}
		printf("%d\n", a[s]);
	}
	return 0;
}
