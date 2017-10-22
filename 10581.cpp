#include <bits/stdc++.h>

using namespace std;

int c[221][11][221], n, m, k;
void init()
{
	for (int i = 1; i <= 220; i++)
	{
		c[i][1][i] = 1;
	}
	for (int i = 1; i <= 220; i++)
		for (int j = 2; j <= 10; j++)
			for (int k = 1; j * k <= i; k++)
				for (int l = k; (j - 1) * l <= (i - k); l++)
				{
					c[i][j][k] += c[i - k][j - 1][l];
				}
}
int main()
{
	int t;
	init();
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d %d", &m, &n, &k);
		for (int now = 0, i = 1; n; m -= i, n--)
		{
			for (; now + c[m][n][i] < k; now += c[m][n][i], i++)
				;
			printf("%d\n", i);
		}
	}
	return 0;
}
