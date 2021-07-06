#include <bits/stdc++.h>

using namespace std;

int a[1001];
int main()
{
	int i, j, k, n;
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		k = 1;
		for (j = 0; j < n; j++)
		{
			scanf("%d", &i);
			if (i)
			{
				if (k)
				{
					printf("%d", i);
				}
				else
				{
					printf(" %d", i);
				}
				k = 0;
			}
		}
		if (k)
		{
			printf("0");
		}
		printf("\n");
	}
	return 0;
}
