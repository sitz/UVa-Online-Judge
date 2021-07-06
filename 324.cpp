#include <bits/stdc++.h>

using namespace std;

char mid[10000], in[10000];
main()
{
	char a[10000];
	int i, j, k, c = 0, d = 0, pp, cary, end;
	int m, sum, cary_1, l, x, y, h;
	int fact, t, pos;
	int digit[20];
	while (scanf("%d", &fact) && fact)
	{
		for (i = 0; i < 10; i++)
		{
			digit[i] = 0;
		}
		for (i = 0; i < 10000; i++)
		{
			mid[i] = in[i] = a[i] = 0;
		}
		printf("%d! --\n", fact);
		a[0] = 1;
		x = 1;
		for (i = 2; i <= fact; i++)
		{
			h = i;
			d = 0;
			c = 0;
			while (h)
			{
				k = c;
				cary = 0;
				y = h % 10;
				for (j = 0; j < x; j++)
				{
					pp = y * a[j] + cary;
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
				h = h / 10;
			}
			for (j = d - 1; j >= 0; j--)
			{
				a[j] = mid[j];
			}
			for (j = 0; j < d; j++)
			{
				mid[j] = 0;
			}
			x = d;
		}
		for (i = x - 1; i >= 0; i--)
		{
			pos = a[i];
			digit[pos]++;
		}
		for (i = 0; i < 5; i++)
		{
			printf("   (%d)%4d", i, digit[i]);
		}
		printf("\n");
		for (i = 5; i < 10; i++)
		{
			printf("   (%d)%4d", i, digit[i]);
		}
		printf("\n");
	}
	return 0;
}
