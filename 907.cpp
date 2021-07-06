#include <bits/stdc++.h>

using namespace std;

int C[605];

int main()
{
	int n, i, j, k, day, up, dn, mid, dist;
	while (scanf("%d%d", &n, &k) == 2)
	{
		n++, k++;
		for (i = up = dn = 0; i < n; i++)
		{
			scanf("%d", C + i);
			if (dn < C[i])
			{
				dn = C[i];
			}
			up += C[i];
		}
		for (dn--; up - dn > 1;)
		{
			mid = (up + dn) / 2;// binary search
			for (day = 1, dist = i = 0; i < n; i++)
			{
				if (dist + C[i] <= mid)
				{
					dist += C[i];
				}
				else
				{
					dist = C[i];
					day++;
				}
			}
			if (day > k)
			{
				dn = mid;
			}
			else
			{
				up = mid;
			}
		}
		printf("%d\n", up);
	}
	return 0;
}
