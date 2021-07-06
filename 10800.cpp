#include <bits/stdc++.h>

using namespace std;

int main()
{
	char c[50];
	int t, x[50], m, n, l, p;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		scanf("%s", &c);
		x[0] = 0;
		m = 0, n = 0;
		for (l = 1; c[l] != '\0'; l++)
		{
			x[l] = x[l - 1];
			if (c[l - 1] == 'R')
			{
				x[l]++;
			}
			if (c[l] == 'F')
			{
				x[l]--;
			}
			m = (m > x[l]) ? m : x[l];
			n = (n < x[l]) ? n : x[l];
		}
		printf("Case #%d:\n", i);
		for (int j = m; j >= n; j--)
		{
			printf("| ");
			p = 0;
			for (int k = 0; k < l; k++)
			{
				if (x[k] == j)
				{
					p = k;
				}
			}
			for (int k = 0; k <= p; k++)
			{
				if (x[k] == j)
				{
					if (c[k] == 'R')
					{
						printf("/");
					}
					else if (c[k] == 'F')
					{
						printf("\\");
					}
					else
					{
						printf("_");
					}
				}
				else
				{
					printf(" ");
				}
			}
			printf("\n");
		}
		printf("+");
		for (int j = 0; j < l + 2; j++)
		{
			printf("-");
		}
		printf("\n\n");
	}
	return 0;
}
