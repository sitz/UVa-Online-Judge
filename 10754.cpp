#include <bits/stdc++.h>

using namespace std;

typedef long long int INT64;
INT64 c[25], a[24];
INT64 n, mod, k;
INT64 bm[26][26];
INT64 matrix[26][26];
void init(int dim)
{
	for (int i = 0; i <= dim; i++)
		for (int j = 0; j <= dim; j++)
		{
			bm[i][j] = 0;
		}
	for (int i = 0; i <= dim; i++)
	{
		bm[0][i] = c[i];
	}
	for (int i = 1; i < dim; i++)
	{
		bm[i][i - 1] = 1;
	}
	bm[dim][dim] = 1;
}
void Perform(int value, int dim)
{
	INT64 tmp[26][26], tmp1[26][26], tmp2[26][26];
	INT64(*src)
	[26] = tmp,
 (*dst)[26] = tmp1, (*temp)[26] = tmp2, (*backup)[26];
	int bits;
	for (bits = 31; bits >= 0; bits--)
		if (value & (1 << bits))
		{
			break;
		}
	for (int i = 0; i <= dim; i++)
		for (int j = 0; j <= dim; j++)
		{
			src[i][j] = bm[i][j];
		}
	for (bits--; bits >= 0; bits--)
	{
		for (int i = 0; i <= dim; i++)
			for (int j = 0; j <= dim; j++)
			{
				INT64 sum = 0;
				for (int k = 0; k <= dim; k++)
				{
					sum = (sum + (src[i][k] * src[k][j]) % mod) % mod;
				}
				dst[i][j] = sum;
			}
		if (value & (1 << bits))
		{
			for (int i = 0; i <= dim; i++)
				for (int j = 0; j <= dim; j++)
				{
					INT64 sum = 0;
					for (int k = 0; k <= dim; k++)
					{
						sum = (sum + (dst[i][k] * bm[k][j]) % mod) % mod;
					}
					temp[i][j] = sum;
				}
			backup = src;
			src = temp;
			temp = backup;
		}
		else
		{
			backup = src;
			src = dst;
			dst = backup;
		}
	}
	memcpy(matrix, src, sizeof(matrix));
}
int main()
{
	int t, i;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		if (i)
		{
			puts("");
		}
		//INT64 matrix[26][26];
		scanf("%lld %lld %lld", &k, &mod, &n);
		for (int i = 0; i <= 25; i++)
		{
			c[i] = 0;
		}
		for (int i = 0; i < k + 1; i++)
		{
			scanf("%lld", c + i);
			c[i] %= mod;
			if (c[i] < 0)
			{
				c[i] += mod;
			}
		}
		for (int i = 0; i <= 23; i++)
		{
			a[i] = 0;
		}
		for (int i = 0; i <= k - 1; i++)
		{
			scanf("%lld", a + i);
			a[i] %= mod;
			if (a[i] < 0)
			{
				a[i] += mod;
			}
		}
		INT64 ans;
		if (n < k)
		{
			ans = a[n];
		}
		else if (k == 0)
		{
			ans = c[0];
		}
		else
		{
			init((int)k);
			Perform(n - k + 1, k);
			ans = 0;
			for (int i = 0; i <= k - 1; i++)
			{
				ans = (ans + (matrix[0][i] * a[k - 1 - i]) % mod) % mod;
			}
			ans = (ans + matrix[0][k]) % mod;
		}
		printf("%lld\n", ans);
	}
}
