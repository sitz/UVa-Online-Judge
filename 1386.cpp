#include <bits/stdc++.h>

using namespace std;

#define CLR(a, b) memset(a, b, sizeof(a))
#define MAXN 500
typedef long long LL;
int n, d, k, MOD;
LL A[MAXN], B[MAXN];

void mul(LL *a, LL *b)
{
	LL c[MAXN] = {0};
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			c[i] += a[j] * b[i <= j ? (j - i) : (n - i + j)];
		}
	for (int i = 0; i < n; ++i)
	{
		a[i] = c[i] % MOD;
	}
}

void fast_mod(int b)
{
	while (b)
	{
		if (b & 1)
		{
			mul(A, B);
		}
		mul(B, B);
		b >>= 1;
	}
}

void scan(LL &x)
{
	char c;
	while (c = getchar(), c < '0' || c > '9')
		;
	x = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')
	{
		x = x * 10 + c - '0';
	}
}

int main()
{
	while (~scanf("%d %d %d %d", &n, &MOD, &d, &k))
	{
		CLR(A, 0);
		CLR(B, 0);
		for (int i = 0; i < n; ++i)
		{
			scan(A[i]);
		}
		for (int i = -d; i <= d; ++i)
		{
			B[(i + n) % n] = 1;
		}
		fast_mod(k);
		for (int i = 0; i < n; ++i)
		{
			if (i != 0)
			{
				putchar(' ');
			}
			printf("%lld", A[i]);
		}
		putchar('\n');
	}
}
