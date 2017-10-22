#include <bits/stdc++.h>

using namespace std;

#define MAX 13

int a[MAX + 1][MAX + 1][MAX + 1];

void init()
{
	a[1][1][1] = 1;
	for (int n = 2; n <= MAX; n++)
	{
		for (int l = 1; l <= n; l++)
		{
			int max_r = n - l + 1;
			for (int r = 1; r <= max_r; r++)
			{
				a[n][l][r] = a[n - 1][l - 1][r] + a[n - 1][l][r - 1] +
										 (n - 2) * a[n - 1][l][r];
			}
		}
	}
}

int main()
{
	init();
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int n, l, r;
		scanf("%d %d %d", &n, &l, &r);
		int x = (0 < l && l <= MAX && 0 < r && r <= MAX) ? a[n][l][r] : 0;
		printf("%d\n", x);
	}
	return 0;
}
