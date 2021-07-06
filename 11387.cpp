#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/113/11387.html
// Runtime: 0.016s
// Tag: Graph, easy

int main()
{
	int n;
	while (scanf("%d", &n) && n)
	{
		if (n % 2 || n < 4)
		{
			printf("Impossible\n");
		}
		else
		{
			printf("%d\n", n * 3 / 2);
			for (int i = 1; i < n; i++)
			{
				printf("%d %d\n", i, i + 1);
			}
			printf("%d %d\n", n, 1);
			int tmp = n / 2 + 1;
			for (int i = 1; i <= n / 2; i++)
			{
				printf("%d %d\n", i, tmp++);
			}
		}
	}
	return 0;
}
