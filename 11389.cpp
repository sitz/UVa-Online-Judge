#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/113/11389.html

int main()
{
	int n;
	int d;
	int r;
	while (scanf("%d %d %d", &n, &d, &r))
	{
		if (!n && !d && !r)
		{
			return 0;
		}
		int morn[102];
		int eve[102];
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &morn[i]);
		}
		sort(morn, morn + n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &eve[i]);
		}
		sort(eve, eve + n);
		int cost = 0;
		for (int i = 0; i < n; i++)
		{
			int temp = morn[i] + eve[n - i - 1];
			if (temp > d)
			{
				cost += (temp - d);
			}
		}
		printf("%d\n", cost * r);
	}
	return 0;
}
