#include <bits/stdc++.h>

using namespace std;

char name[16];
int n, m, time_[120][15], t[15][15];

int main()
{
	while (scanf("%s", name) == 1)
	{
		puts(name);
		scanf("%d %d", &n, &m);
		for (int i = 0; i < 120; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				time_[i][j] = 99999999;
			}
		}
		for (int i = 0; i < 15; i++)
		{
			time_[0][i] = 0;
		}
		for (int i = 1; i <= n - 1; i++)
		{
			for (int j = 0; j < m; j++)
			{
				for (int k = 0; k < m; k++)
				{
					scanf("%d", &t[j][k]);
				}
			}
			for (int j = 0; j < m; j++)
			{
				for (int k = 0; k < m; k++)
				{
					if (time_[i - 1][j] + t[j][k] < time_[i][k])
					{
						time_[i][k] = time_[i - 1][j] + t[j][k];
					}
				}
			}
		}
		int p = 99999999;
		for (int i = 0; i < m; i++)
		{
			if (time_[n - 1][i] < p)
			{
				p = time_[n - 1][i];
			}
		}
		printf("%d\n", p + 2 * (n - 1));
	}
	return 0;
}
