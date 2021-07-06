#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-10
#define MAXN 131072

pair<int, int> D[MAXN];

int main()
{
	int N, x, y;
	while (scanf("%d", &N) == 1)
	{
		for (int i = 0; i < N; i++)
		{
			scanf("%d%d", &x, &y);
			D[i] = make_pair(x, y);
		}
		sort(D, D + N);
		double l = 0.0f, r = 1000000.0f, mid, ret = 0.0f;
		for (int it = 0; it < 100; it++)
		{
			mid = (l + r) / 2;
			double left = 0.0f;
			int ok = 1;
			for (int i = 0; i < N && ok; i++)
			{
				if (D[i].first > left)
				{
					left = D[i].first;
				}
				if (left + mid > D[i].second)
				{
					ok = 0;
				}
				left += mid;
			}
			if (ok)
			{
				l = mid;
				ret = mid;
			}
			else
			{
				r = mid;
			}
		}
		int rp = 0, rq = 1;
		for (int p, q = 1; q <= N; q++)
		{
			p = round(ret * q);
			if (fabs((double)p / q - ret) < fabs((double)rp / rq - ret))
			{
				rp = p;
				rq = q;
			}
		}
		printf("%d/%d\n", rp, rq);
	}
	return 0;
}
