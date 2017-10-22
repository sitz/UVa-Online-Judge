#include <bits/stdc++.h>

using namespace std;

static int N[505], O[1005], T[1005];
static char in[1005], cp[1005];

int main()
{
	int t, first = 1, len, n, i, i2, j, k;
	scanf("%d", &t);
	getchar();
	while (t--)
	{
		getchar();
		gets(in);
		len = strlen(in);
		if (len & 1)
		{
			for (i = len; i > 0; i--)
			{
				in[i] = in[i - 1];
			}
			in[0] = '0', in[++len] = '\0';
		}
		n = len >> 1;
		for (i = 0; i < len; i++)
		{
			O[i] = 0;
		}
		for (i = 0; i < len; i++)
		{
			cp[i] = '0';
		}
		cp[len] = '\0';
		for (i = 1; i <= n; i++)
		{
			i2 = i * 2;
			for (j = 0; j < i2; j++)
			{
				T[j] = O[j];
			}
			for (N[i - 1] = 0; N[i - 1] < 10; N[i - 1]++)
			{
				for (j = 0; j < i; j++)
				{
					T[i + j] += 2 * N[j];
				}
				T[i2 - 1]++;
				for (j = i2 - 1; j > 0; j--)
				{
					T[j - 1] += T[j] / 10;
					T[j] %= 10;
				}
				for (j = 0; j < i2; j++)
				{
					cp[j] = T[j] + '0';
				}
				if (strncmp(cp, in, i2) > 0)
				{
					break;
				}
				for (j = 0; j < i2; j++)
				{
					O[j] = T[j];
				}
			}
		}
		if (first)
		{
			first = 0;
		}
		else
		{
			printf("\n");
		}
		for (i = 0; i < n; i++)
		{
			printf("%d", N[i]);
		}
		printf("\n");
	}
	return 0;
}
