#include <bits/stdc++.h>

using namespace std;

char mid[100000], in[100000];

int main()
{
	char a[1000], s[1000], g[2], ch;
	int i, j, k, c = 0, d = 0, pp, cary, end;
	int m, sum, cary_1, l, x = 0, y = 0;
	int ck = 0, ck_1 = 1, ck_2 = 1;
	while ((ch = getc(stdin)) != EOF)
	{
		if (ch != '\n' && ck_1)
		{
			g[0] = ch;
			g[1] = NULL;
			a[x++] = atoi(g);
		}
		else if (ck_2)
		{
			ck_1 = 0;
			if (ch == '\n')
			{
				ck++;
				if (ck == 2)
				{
					goto done;
				}
				continue;
			}
			g[0] = ch;
			g[1] = NULL;
			s[y++] = atoi(g);
			if (ck == 2)
			{
				ck_2 = 0;
			}
		}
		else
		{
		done:
			for (i = 0; i < 1000; i++)
			{
				mid[i] = in[i] = 0;
			}
			for (i = y - 1; i >= 0; i--)
			{
				k = c;
				cary = 0;
				for (j = x - 1; j >= 0; j--)
				{
					pp = s[i] * a[j] + cary;
					cary = pp / 10;
					in[k++] = pp % 10;
				}
				if (cary)
				{
					in[k++] = cary;
				}
				if (k > d)
				{
					end = k;
				}
				else
				{
					end = d;
				}
				d = 0;
				cary_1 = 0;
				for (m = 0; m < end; m++)
				{
					sum = in[m] + mid[m] + cary_1;
					mid[d++] = sum % 10;
					cary_1 = sum / 10;
				}
				if (cary_1)
				{
					mid[d++] = cary_1;
				}
				for (l = 0; l < k; l++)
				{
					in[l] = 0;
				}
				c++;
			}
			for (l = d - 1; !mid[l]; l--)
				;
			if (l < 0)
			{
				printf("0");
				goto st;
			}
			for (i = l; i >= 0; i--)
			{
				printf("%d", mid[i]);
			}
			for (i = 0; i < 1000; i++)
			{
				a[i] = s[i] = 0;
			}
		st:
			printf("\n");
			ck = x = y = c = 0;
			ck_1 = ck_2 = 1;
		}
	}
	return 0;
}
