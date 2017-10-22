#include <bits/stdc++.h>

using namespace std;

/* Copyright Edmund Dengler (ACM ICPC ECNA 98) */
int main()
{
	int num;
	int j, k, n;
	int done;
	char buf[60][100], str[80];
	int cnt[10];
	while (gets(buf[0]) != NULL)
	{
		if (strcmp(buf[0], "-1") == 0)
		{
			break;
		}
		done = 0;
		j = 0;
		while ((done == 0) && (j < 15))
		{
			int i;
			int len;
			char tbuf[10];
			for (i = 0; i < 10; i += 1)
			{
				cnt[i] = 0;
			}
			len = strlen(buf[j]);
			for (i = 0; i < len; i += 1)
			{
				cnt[buf[j][i] - '0'] += 1;
			}
			buf[j + 1][0] = '\0';
			for (i = 0; i < 10; i += 1)
			{
				if (cnt[i] > 0)
				{
					sprintf(tbuf, "%d%d", cnt[i], i);
					strcat(buf[j + 1], tbuf);
				}
			}
			for (k = 0; k < j + 1; k += 1)
			{
				if (strcmp(buf[k], buf[j + 1]) == 0)
				{
					done = 1;
					printf("%s ", buf[0]);
					if (j == 0)
					{
						printf("is self-inventorying\n");
					}
					else if (k == j)
					{
						printf("is self-inventorying after %d steps\n", j);
					}
					else
					{
						printf("enters an inventory loop of length %d\n", j + 1 - k);
					}
					break;
				}
			}
			j += 1;
		}
		if (!done)
		{
			printf("%s can not be classified after 15 iterations\n", buf[0]);
		}
	}
	return 0;
}
