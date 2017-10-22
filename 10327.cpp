#include <bits/stdc++.h>

using namespace std;

int a[1010];

int main()
{
	int i, j, k, n, s;
	while (scanf("%d", &n) == 1)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		s = 0;
		for (i = 0; i < n - 1; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if (a[i] > a[j])
				{
					s++;
				}
			}
		}
		printf("Minimum exchange operations : %d\n", s);
		s = 0;
	}
	return 0;
}
