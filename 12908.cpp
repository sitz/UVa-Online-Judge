#include <bits/stdc++.h>

using namespace std;

int main()
{
	int i, j, c, n = 2, sum;
	double p;
	while (n != 0)
	{
		scanf("%d", &n);
		if (n == 0)
		{
			return 0;
		}
		sum = 0;
		c = 1;
		p = (sqrt(1 + 8 * (n + 1)) - 1) / 2.0;
		sum = ceil(p);
		printf("%d %d\n", sum * (sum + 1) / 2 - n, sum);
	}
	return 0;
}
