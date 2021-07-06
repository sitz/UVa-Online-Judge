#include <bits/stdc++.h>

using namespace std;

int main()
{
	int digit, n, i;
	while (scanf("%d", &n) == 1)
	{
		digit = 1;
		for (i = 1; i;)
		{
			i = (i * 10 + 1) % n;
			digit++;
		}
		printf("%d\n", digit);
	}
	return 0;
}
