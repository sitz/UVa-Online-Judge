#include <bits/stdc++.h>

using namespace std;

int main()
{
	int k;
	while (scanf("%d", &k) == 1)
	{
		printf("%d %d\n", k, k - 1);
		for (int i = 1; i <= k - 1; i++)
		{
			printf("%d %d\n", i, i + 1);
		}
		for (int i = 1; i <= k; i++)
		{
			printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}
