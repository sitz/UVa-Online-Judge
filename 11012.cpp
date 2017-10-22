#include <bits/stdc++.h>

using namespace std;

#define INF 2147483647

int X[8] = {1, 1, 1, 1, -1, -1, -1, -1}, Y[8] = {1, 1, -1, -1, 1, 1, -1, -1}, Z[8] = {1, -1, 1, -1, 1, -1, 1, -1}, min_[8], max_[8];

int main()
{
	int i, j, t, tt, n, x, y, z, dist;
	scanf("%d", &tt);
	for (t = 1; t <= tt; t++)
	{
		scanf("%d", &n);
		for (i = 0; i < 8; i++)
		{
			min_[i] = INF;
		}
		for (i = 0; i < 8; i++)
		{
			max_[i] = -INF;
		}
		for (i = 0; i < n; i++)
		{
			scanf("%d%d%d", &x, &y, &z);
			for (j = 0; j < 8; j++)
			{
				dist = X[j] * x + Y[j] * y + Z[j] * z;
				if (dist < min_[j])
				{
					min_[j] = dist;
				}
				if (dist > max_[j])
				{
					max_[j] = dist;
				}
			}
		}
		for (i = dist = 0; i < 8; i++)
		{
			if (max_[i] - min_[i] > dist)
			{
				dist = max_[i] - min_[i];
			}
		}
		printf("Case #%d: %d\n", t, dist);
	}
	return 0;
}
