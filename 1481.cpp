#include <bits/stdc++.h>

using namespace std;

const int maxn = 3001;

int a[maxn], b[maxn], p[1000001];

int main()
{
	int n;
	while (scanf("%d", &n) && n)
	{
		memset(p, 0, sizeof(p));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			p[a[i]] = i;
		}
		for (int i = 1; i <= n; i++)
			scanf("%d", &b[i]);
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!p[b[i]])
				continue;
			int maxpos = p[b[i]], minpos = p[b[i]];
			for (int j = i + 1; j <= n; j++)
			{
				if (!p[b[j]])
					break;
				maxpos = max(maxpos, p[b[j]]);
				minpos = min(minpos, p[b[j]]);
				if (j - i > 0 && maxpos - minpos == j - i)
					ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
