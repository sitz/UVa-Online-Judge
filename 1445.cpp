#include <bits/stdc++.h>

using namespace std;

int a[11], b[11], vis[21];

int main()
{
	int w, d;
	while (scanf("%d%d", &w, &d) && (w + d))
	{
		int ans = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < w; i++)
		{
			scanf("%d", &a[i]);
			ans += a[i];
			vis[a[i]]++;
		}
		for (int i = 0; i < d; i++)
		{
			scanf("%d", &b[i]);
			if (!vis[b[i]])
				ans += b[i];
			else
				vis[b[i]]--;
		}
		printf("%d\n", ans);
	}
	return 0;
}
