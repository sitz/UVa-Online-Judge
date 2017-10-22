#include <bits/stdc++.h>

using namespace std;

/*
11054
*/
typedef long long SS;
int main()
{
	SS n, m, k, i, d;
	while (scanf("%lld", &n) && n)
	{
		k = d = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%lld", &m);
			k += abs(d);
			d += m;
		}
		printf("%lld\n", k);
	}
	return 0;
}
