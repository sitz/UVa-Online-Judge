#include <bits/stdc++.h>

using namespace std;

#define limit 1000000000
int main()
{
	int N[20], O[40];
	int n, len, i, j, k;
	long long int tmp;
	char in[120];
	while (gets(in))
	{
		if (in[1] == '\0' && in[0] == '0')
		{
			printf("1\n");
			continue;
		}
		n = strlen(in);
		len = (n - 1) / 9 + 1;
		for (i = 0; i <= len; i++)
		{
			N[i] = 0;
		}
		for (i = 0; i < n; i++)
		{
			j = (n - i - 1) / 9;
			N[j] = 10 * N[j] + in[i] - '0';
		}
		n = 2 * len;
		for (i = 0; i <= n; i++)
		{
			O[i] = 0;
		}
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < len; j++)
			{
				tmp = O[i + j] + (long long int)N[i] * N[j];
				O[i + j] = tmp % limit;
				O[i + j + 1] += tmp / limit;
			}
		}
		if (!O[n - 1])
		{
			n--;
		}
		O[0] += 2;
		for (i = 0; i < len; i++)
		{
			O[i] -= N[i];
		}
		for (i = 0; i < n; i++)
		{
			if (O[i] >= 0)
			{
				continue;
			}
			O[i + 1]--;
			O[i] += limit;
		}
		printf("%d", O[n - 1]);
		for (i = n - 2; i >= 0; i--)
		{
			printf("%09d", O[i]);
		}
		printf("\n");
	}
	return 0;
}
