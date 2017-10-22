#include <bits/stdc++.h>

using namespace std;

int main()
{
	int k;
	scanf("%d", &k);
	while (k--)
	{
		int n;
		scanf("%d\n", &n);
		char original[200][82], required[200][82];
		for (int i = 0; i < n; ++i)
		{
			fgets(original[i], 82, stdin);
		}
		for (int i = 0; i < n; ++i)
		{
			fgets(required[i], 82, stdin);
		}
		int rIdx = n - 1;
		for (int oIdx = n - 1; oIdx >= 0; --oIdx)
		{
			if (strcmp(original[oIdx], required[rIdx]) == 0)
			{
				rIdx--;
			}
		}
		for (int i = rIdx; i >= 0; --i)
		{
			printf(required[i]);
		}
		putchar('\n');
	}
	return 0;
}
