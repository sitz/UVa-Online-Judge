#include <bits/stdc++.h>

using namespace std;

int M[10005];
int main()
{
	int t, tt, a, b, c, m, n, x, i, j, way, total;
	scanf("%d", &tt);
	for (t = 1; t <= tt; t++)
	{
		scanf("%d%d%d%d%d", &a, &b, &c, &m, &n);
		for (i = 1; i < m; i++)
		{
			M[i] = 0;
		}
		M[0] = 1;
		c = (c + 1) % m;
		for (way = total = 0, x = a % m; n--; x = (x * b + c) % m)
		{
			total = (total + x) % m;
			way += M[total];
			M[total]++;
		}
		printf("Case %d: %d\n", t, way);
	}
	return 0;
}
