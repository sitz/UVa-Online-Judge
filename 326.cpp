#include <bits/stdc++.h>

using namespace std;

/*
Extrapolation Using a Difference Table
326
*/
int a[50];
int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	while (n)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		scanf("%d", &k);
		for (j = n - 1; j > 0; j--)
			for (i = 0; i < j; i++)
			{
				a[i] = a[i + 1] - a[i];
			}
		for (i = 0; i < k; i++)
			for (j = 1; j < n; j++)
			{
				a[j] += a[j - 1];
			}
		printf("Term %d of the sequence is %d\n", n + k, a[n - 1]);
		scanf("%d", &n);
	}
	return 0;
}
