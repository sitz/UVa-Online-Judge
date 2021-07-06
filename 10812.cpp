#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tmp;
	scanf("%d ", &tmp);
	int sum, dif;
	while (scanf("%d %d", &sum, &dif) == 2)
	{
		if (sum < dif)
		{
			puts("impossible");
			continue;
		}
		else if (sum % 2 != dif % 2)
		{
			puts("impossible");
			continue;
		}
		int a = (sum + dif) / 2;
		int b = (sum - dif) / 2;
		printf("%d %d\n", a, b);
	}
	return 0;
}
