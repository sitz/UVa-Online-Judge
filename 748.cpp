#include <bits/stdc++.h>

using namespace std;

char mid[5000], in[5000];

int main()
{
	char a[5000], R[10], inter[3];
	int i, j, k, c = 0, d = 0, pp, cary, end;
	int m, sum, cary_1, l, x, y, h, len;
	int fact, t, point, q, z;
	while (scanf("%s %d", R, &fact) != EOF)
	{
		k = 0;
		if (fact == 0)
		{
			printf("1\n");
			continue;
		}
		if (fact == 1)
		{
			printf("%s\n", R);
			continue;
		}
		if (atof(R) == 1)
		{
			printf("1\n");
			continue;
		}
		if (atof(R) == 0)
		{
			printf("0\n");
			continue;
		}
		for (i = 0; R[i]; i++)
			if (R[i] == '.')
			{
				break;
			}
		point = strlen(R) - 1 - i;
		for (i = 0; R[i]; i++)
			if (R[i] != '.')
			{
				R[k++] = R[i];
			}
		R[k] = NULL;
		for (i = 0; i < 1000; i++)
		{
			mid[i] = in[i] = a[i] = 0;
		}
		len = strlen(R) - 1;
		a[0] = 1;
		x = 1;
		k = 0;
		for (i = len; i >= 0; i--)
		{
			inter[0] = R[i];
			inter[1] = NULL;
			a[k] = atoi(inter);
			k++;
		}
		x = k;
		z = point;
		for (q = 1; q < fact; q++)
		{
			d = 0;
			c = 0;
			z += point;
			for (i = strlen(R) - 1; i >= 0; i--)
			{
				inter[0] = R[i];
				inter[1] = NULL;
				h = atoi(inter);
				k = c;
				cary = 0;
				for (j = 0; j < x; j++)
				{
					pp = h * a[j] + cary;
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
		if (point == -1)
		{
			for (i = x - 1; i >= 0; i--)
			{
				printf("%d", a[i]);
			}
			printf("\n");
			continue;
		}
		z = x - z + 1;
		z = x - z;
		c = 0;
		for (i = x - 1; i > z && !a[i]; i--)
			;
		if (i > z)
		{
			for (i = i; i > z; i--)
			{
				printf("%d", a[i]);
			}
		}
		for (i = 0; i <= z && !a[i]; i++)
			;
		c = i;
		if (i <= z)
		{
			printf(".");
			for (i = z; i >= c; i--)
			{
				printf("%d", a[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
