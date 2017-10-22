#include <bits/stdc++.h>

using namespace std;

int mapi[50][50], mapt[50][50];

int main()
{
	int i, j, k, l, m, n, o, p, ans, x, y, sum;
	char buf[1001], *str, check;
	gets(buf);
	while (1)
	{
		for (n = 0;; n++)
		{
			gets(buf);
			if (!strcmp(buf, "T"))
			{
				break;
			}
			str = strtok(buf, " ");
			m = 0;
			do
			{
				mapi[n][m++] = atoi(str);
			} while (str = strtok(NULL, " "));
		}
		for (o = 0;; o++)
		{
			gets(buf);
			if (!strcmp(buf, "I") || !strcmp(buf, "F"))
			{
				break;
			}
			str = strtok(buf, " ");
			p = 0;
			do
			{
				mapt[o][p++] = atoi(str);
			} while (str = strtok(NULL, " "));
		}
		n = n - o + 1;
		m = m - p + 1;
		ans = 0;
		x = 0;
		y = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				sum = 0;
				for (k = 0; k < o; k++)
				{
					for (l = 0; l < p; l++)
					{
						sum += mapi[i + k][j + l] * mapt[k][l];
					}
				}
				if (sum > ans)
				{
					ans = sum;
					x = i;
					y = j;
				}
			}
		}
		printf("(%d,%d)\n", y, x);
		if (!strcmp(buf, "F"))
		{
			break;
		}
	}
	return 0;
}
