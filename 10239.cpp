#include <bits/stdc++.h>

using namespace std;

int w[1001], h[1001], ans[1001], sw, mh, mw, n;
double ww, dh, dw;

int main()
{
	while (scanf("%d%lf", &n, &ww) == 2)
	{
		if (n == 0)
		{
			break;
		}
		sw = (int)(10000 * (ww + 0.00001));
		for (int i = 1; i <= n; i++)
		{
			double th, tw;
			scanf("%lf %lf", &th, &tw);
			h[i] = (int)(10000 * (th + 0.00001));
			w[i] = (int)(10000 * (tw + 0.00001));
			ans[i] = ans[i - 1] + h[i];
			mh = h[i];
			mw = w[i];
			for (int j = i - 2; j >= 0; j--)
			{
				mw += w[j + 1];
				if (h[j + 1] > mh)
				{
					mh = h[j + 1];
				}
				if (mw > sw)
				{
					break;
				}
				if (ans[j] + mh < ans[i])
				{
					ans[i] = ans[j] + mh;
				}
			}
		}
		int a = ans[n];
		printf("%d.%d%d%d%d\n", a / 10000, (a % 10000) / 1000, (a % 1000) / 100,
					 (a % 100) / 10, a % 10);
	}
	return 0;
}
