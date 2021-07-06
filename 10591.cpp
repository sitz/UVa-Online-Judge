#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, tmp;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		scanf("%d", &n);
		printf("Case #%d: %d is ", i, n);
		while (n > 9)
		{
			tmp = 0;
			while (n)
			{
				tmp += (n % 10) * (n % 10);
				n /= 10;
			}
			n = tmp;
		}
		if (n % 6 == 1)
		{
			printf("a Happy number.\n");
		}
		else
		{
			printf("an Unhappy number.\n");
		}
	}
	return 0;
}
