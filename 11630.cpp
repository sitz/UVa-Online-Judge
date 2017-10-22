#include <bits/stdc++.h>

using namespace std;

#define maxn 10010
#define maxe 201010
#define INF 1 << 29
#define LL long long
int main()
{
	int n, a, b;
	while (scanf("%d", &n), n)
	{
		if (n == 3)
		{
			puts("3 1 2");
			continue;
		}
		if (n == 4)
		{
			puts("3 1 4 2");
			continue;
		}
		a = 5, b = 2;
		if (n & 1)
		{
			printf("3 1 ");
			while (a <= n)
			{
				if (a == n)
				{
					printf("%d %d %d\n", a, b, n - 1);
					break;
				}
				else
				{
					printf("%d %d ", a, b);
					a += 2;
					b += 2;
				}
			}
		}
		else
		{
			printf("3 1 ");
			while (a <= n)
			{
				if (a == n - 1)
				{
					printf("%d %d %d %d\n", a, b, n, n - 2);
					break;
				}
				else
				{
					printf("%d %d ", a, b), a += 2, b += 2;
				}
			}
		}
	}
}
