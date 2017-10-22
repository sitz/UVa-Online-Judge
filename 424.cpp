#include <bits/stdc++.h>

using namespace std;

int result[11000];

int main()
{
	char a[101][101];
	int i, j, sum, k = 0, max = 0;
	int cary, n, g, l;
	while (scanf("%s", a[k]) && strcmp(a[k], "0"))
	{
		k++;
	}
	for (i = 0; i < k; i++)
		if (strlen(a[i]) > max)
		{
			max = strlen(a[i]);
		}
	for (i = 0; i < k; i++)
	{
		g = 0;
		l = strlen(a[i]);
		if (l >= 99)
		{
			continue;
		}
		for (j = l - 1; j >= 0; j--)
		{
			a[i][99 - g] = a[i][j];
			g++;
		}
		for (j = 0; j <= 99 - g; j++)
		{
			a[i][j] = '0';
		}
	}
	n = 0;
	cary = 0;
	for (i = 99; i > 99 - max; i--)
	{
		sum = 0;
		for (j = 0; j < k; j++)
			if (a[j][i])
			{
				sum += a[j][i] - 48;
			}
		sum = sum + cary;
		cary = sum / 10;
		result[n++] = sum % 10;
	}
	if (cary)
	{
		result[n++] = cary;
	}
	for (i = n - 1; i >= 0; i--)
	{
		printf("%d", result[i]);
	}
	printf("\n");
	return 0;
}
