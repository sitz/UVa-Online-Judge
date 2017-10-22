#include <bits/stdc++.h>

using namespace std;

/*
10879
*/
void Cal(int n)
{
	int i;
	printf(" %d = ", n);
	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			printf("%d * %d = ", i, n / i);
			break;
		}
	}
	for (++i; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			printf("%d * %d\n", i, n / i);
			break;
		}
	}
}
int main()
{
	int n, ks, c = 1;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &ks);
		printf("Case #%d: ", c++);
		Cal(ks);
	}
	return 0;
}
