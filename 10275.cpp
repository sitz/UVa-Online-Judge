#include <bits/stdc++.h>

using namespace std;

int bin_srch(int len, int left, int right)
{
	int mid = (left + right) / 2;
	while (left <= right)
	{
		int p = (int)(mid * log10(mid)) + 1;
		if (p == len)
		{
			return mid;
		}
		else if (p < len)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
		mid = (left + right) / 2;
	}
	return -1;
}

int powermod(int base, int exp, int mod)
{
	if (exp == 1)
	{
		return base % mod;
	}
	else if (exp % 2)
	{
		int k = (exp - 1) / 2;
		return (powermod(base, k, mod) * powermod(base, k, mod) * base) % mod;
	}
	else
	{
		return (powermod(base, exp / 2, mod) * powermod(base, exp / 2, mod)) % mod;
	}
}

int main()
{
	int n, i, k, m, c, len;
	char str[500000];
	scanf("%d\n", &n);
	for (; n; n--)
	{
		m = len = 0;
		gets(str);
		len = strlen(str);
		for (i = 0; i < len; i++)
		{
			m = (m * 10 + str[i] - '0') % 11;
		}
		if (strcmp(str, "1") == 0)
		{
			printf("1\n");
			continue;
		}
		int k = bin_srch(len, 2, 100000);
		if (k == -1)
		{
			printf("-1\n");
		}
		else if (powermod(k, k, 11) != m)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", k);
		}
	}
	return 0;
}
