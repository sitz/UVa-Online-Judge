#include <bits/stdc++.h>

using namespace std;

const int maxn = 60001;
const int inf = 1 << 28;

int miny[maxn], maxy[maxn], h[maxn];

int main()
{
	int T;
	scanf("%d", &T);
	int n, m;
	int x1, y1, x2, y2;
	while (T--)
	{
		scanf("%d%d", &n, &m);
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (x1 > x2)
		{
			swap(x1, x2);
			swap(y1, y2);
		}
		for (int i = x1 + 1; i < x2; i++)
		{
			miny[i] = inf;
			maxy[i] = -inf;
		}
		for (int i = 2; i < m; i++)
		{
			int ita, itb;
			scanf("%d%d", &ita, &itb);
			if (itb >= y1)
				miny[ita] = min(miny[ita], itb);
			if (itb <= y1)
				maxy[ita] = max(maxy[ita], itb);
		}
		for (int i = x1; i <= x2; i++)
			h[i] = min(y1 - maxy[i], miny[i] - y1);
		h[x1] = 0;
		for (int i = x1 + 1; i < x2; i++)
			h[i] = min(h[i], h[i - 1] + 1);
		h[x2] = 0;
		for (int i = x2 - 1; i > x1; i--)
			h[i] = min(h[i], h[i + 1] + 1);
		long long ans = 0;
		for (int i = x1; i <= x2; i++)
			if (h[i])
			{
				ans++;
				ans += min(h[i] - 1, y1);
				ans += min(h[i] - 1, n - y1 - 1);
			}
		cout << ans << endl;
	}
	return 0;
}
