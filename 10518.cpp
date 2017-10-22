#include <bits/stdc++.h>

using namespace std;

/****
10518
****/
#define MAXN 1000000
long dd[MAXN];
int main()
{
	long long n;
	long b, m;
	long cases = 0;
	while (1)
	{
		scanf("%lld%ld", &n, &b);
		if (!n && !b)
		{
			break;
		}
		cases++;
		dd[0] = 1;
		dd[1] = 1;
		for (m = 2; m < 1000000; m++)
		{
			dd[m] = (dd[m - 1] + dd[m - 2] + 1) % b;
			if (dd[m] == 1 && dd[m - 1] == 1)
			{
				break;
			}
		}
		m--;
		printf("Case %ld: %lld %ld %ld\n", cases, n, b, dd[n % m]);
	}
	return 0;
}
