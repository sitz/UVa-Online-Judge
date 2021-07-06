#include <bits/stdc++.h>

using namespace std;

char dig[50];

int ccmp(const void *a, const void *b)
{
	return *((char *)a) - (int)*((char *)b);
}

main()
{
	int i, j, k, x, y, z, n;
	for (;;)
	{
		scanf(" %s", dig);
		if (!dig[1])
		{
			break;
		}
		n = strlen(dig);
		dig[n - 2] = dig[n - 1];
		dig[n - 1] = 0;
		n--;
		for (i = n - 1; i >= 0; i--)
		{
			for (j = dig[i] + 1; j <= '9'; j++)
			{
				for (k = i; dig[k]; k++)
				{
					if (dig[k] == j ||
							dig[k] == '2' && j == '5' ||
							dig[k] == '5' && j == '2' ||
							dig[k] == '6' && j == '9' ||
							dig[k] == '9' && j == '6')
					{
						dig[k] = dig[i];
						dig[i] = j;
						goto found;
					}
				}
			}
		}
	found:
		if (i < 0)
		{
			printf("The price cannot be raised.\n");
			continue;
		}
		for (k = i + 1; dig[k]; k++)
		{
			if (dig[k] == '5')
			{
				dig[k] = '2';
			}
			if (dig[k] == '9')
			{
				dig[k] = '6';
			}
		}
		qsort(&dig[i + 1], n - i - 1, sizeof(char), ccmp);
		dig[n] = dig[n - 1];
		dig[n - 1] = '.';
		printf("%s\n", dig);
	}
}
