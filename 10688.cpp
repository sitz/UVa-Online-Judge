#include <bits/stdc++.h>

using namespace std;

int m[501][501], n, k;
int i, j, l, t;
int main()
{
	for (i = 2; i <= 500; i++)
	{
		for (j = 0; i + j <= 500; j++)
		{
			m[i][j] = 99999999;
			for (l = 1; l <= i / 2 + 1; l++)
			{
				t = (l + j) * i + m[l - 1][j] + m[i - l][j + l];
				if (t < m[i][j])
				{
					m[i][j] = t;
				}
			}
		}
	}
	scanf("%d", &t);
	for (int caseno = 1; caseno <= t; caseno++)
	{
		scanf("%d %d", &n, &k);
		printf("Case %d: %d\n", caseno, m[n][k]);
	}
}
