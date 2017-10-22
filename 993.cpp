#include <bits/stdc++.h>

using namespace std;

int getResult(int n)
{
	int i;
	int res[100], p = 0;
	for (i = 9; i >= 2; i--)
	{
		while (n % i == 0)
		{
			res[p++] = i;
			n /= i;
		}
		if (n == 1)
		{
			break;
		}
	}
	if (n > 9)
	{
		printf("-1\n");
		return 0;
	}
	for (i = p - 1; i >= 0; i--)
	{
		printf("%d", res[i]);
	}
	printf("\n");
	return 0;
}
int main()
{
	int k, n;
	scanf("%d", &k);
	while (k--)
	{
		scanf("%d", &n);
		if (n == 0)
		{
			printf("10\n");
			continue;
		}
		if (n == 1)
		{
			printf("1\n");
			continue;
		}
		getResult(n);
	}
	return 0;
}
