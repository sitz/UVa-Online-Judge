#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define ran 65536
#define modulo 50000000001507329LL
#define primitive 3

int base, bound, m, n, a[40000];
LL pri, invpri, invn, e[6][ran], f[6][ran], ans[ran];

// return (a*b)%p
LL mulmod(LL a, LL b, LL p)
{
	LL y = (LL)((double)a * (double)b / p + 0.5);
	LL r = (a * b - y * p) % p;
	if (r < 0)
	{
		r += p;
	}
	return r;
}

LL powmod(LL a, LL b, LL p)
{
	LL r = 1;
	while (b)
	{
		if (b & 1)
		{
			r = mulmod(r, a, p);
		}
		if (b /= 2)
		{
			a = mulmod(a, a, p);
		}
	}
	return r;
}

void fft(int n, LL root, LL a[])
{
	for (int m = n; m >= 2; m >>= 1)
	{
		int mh = m >> 1;
		LL w = 1;
		for (int i = 0; i < mh; i++)
		{
			for (int j = i; j < n; j += m)
			{
				int k = j + mh;
				LL x = a[j] - a[k];
				if (x < 0)
				{
					x += modulo;
				}
				a[j] += a[k];
				if (a[j] >= modulo)
				{
					a[j] -= modulo;
				}
				a[k] = mulmod(w, x, modulo);
			}
			w = mulmod(w, root, modulo);
		}
		root = mulmod(root, root, modulo);
	}
	int i = 0;
	for (int j = 1; j < n - 1; j++)
	{
		for (int k = n >> 1; k > (i ^= k); k >>= 1)
			;
		if (j < i)
		{
			swap(a[i], a[j]);
		}
	}
}

int main()
{
	LL inv24 = powmod(24, modulo - 2, modulo);
	LL inv120 = powmod(120, modulo - 2, modulo);
	int t, T, __;
	scanf("%d", &__);
	for (int _ = 1; _ <= __; _++)
	{
		scanf("%d%d", &m, &t);
		base = 10001;
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &a[i]);
			base = min(base, a[i]);
		}
		printf("Case #%d:\n", _);
		if (t == 1)
		{
			sort(a, a + m);
			for (int i = 0; i < m; i++)
			{
				printf("%d: 1\n", a[i]);
			}
			puts("");
			continue;
		}
		for (int i = 0; i < m; i++)
		{
			a[i] -= base;
		}
		bound = 1;
		for (int i = 0; i < m; i++)
		{
			bound = max(bound, a[i]);
		}
		bound *= t;
		for (n = 1; n <= bound; n *= 2)
			;
		pri = powmod(primitive, modulo / n, modulo);
		invpri = powmod(pri, modulo - 2, modulo);
		invn = powmod(n, modulo - 2, modulo);
		for (int i = 1; i < t; i++)
		{
			memset(e[i], 0, sizeof(LL) * n);
			for (int j = 0; j < m; j++)
			{
				e[i][a[j] * i] = 1;
			}
			fft(n, pri, e[i]);
		}
		if (t == 2)
		{
			T = 1;
			for (int i = 0; i < n; i++)
			{
				f[0][i] = mulmod(e[1][i], e[1][i], modulo);
			}
		}
		if (t == 3)
		{
			T = 2;
			for (int i = 0; i < n; i++)
			{
				f[0][i] = mulmod(mulmod(e[1][i], e[1][i], modulo), e[1][i], modulo);
				f[1][i] = mulmod(e[2][i], e[1][i], modulo);
			}
		}
		if (t == 4)
		{
			T = 4;
			for (int i = 0; i < n; i++)
			{
				f[0][i] = mulmod(e[1][i], e[1][i], modulo);
				f[0][i] = mulmod(f[0][i], f[0][i], modulo);
				f[1][i] = mulmod(mulmod(e[1][i], e[1][i], modulo), e[2][i], modulo);
				f[2][i] = mulmod(e[2][i], e[2][i], modulo);
				f[3][i] = mulmod(e[3][i], e[1][i], modulo);
			}
		}
		if (t == 5)
		{
			T = 6;
			for (int i = 0; i < n; i++)
			{
				f[0][i] = mulmod(e[1][i], e[1][i], modulo);
				f[0][i] = mulmod(f[0][i], f[0][i], modulo);
				f[0][i] = mulmod(f[0][i], e[1][i], modulo);
				f[1][i] = mulmod(mulmod(e[1][i], e[1][i], modulo),
												 mulmod(e[1][i], e[2][i], modulo), modulo);
				f[2][i] = mulmod(mulmod(e[1][i], e[1][i], modulo), e[3][i], modulo);
				f[3][i] = mulmod(mulmod(e[2][i], e[2][i], modulo), e[1][i], modulo);
				f[4][i] = mulmod(e[4][i], e[1][i], modulo);
				f[5][i] = mulmod(e[2][i], e[3][i], modulo);
			}
		}
		for (int j = 0; j < T; j++)
		{
			fft(n, invpri, f[j]);
		}
		for (int j = 0; j < T; j++)
			for (int i = 0; i < n; i++)
			{
				f[j][i] = mulmod(f[j][i], invn, modulo);
			}
		if (t == 2)
		{
			for (int i = 0; i < n; i++)
			{
				ans[i] = f[0][i];
			}
			for (int i = 0; i < m; i++)
			{
				ans[a[i] * 2]--;
			}
			for (int i = 0; i < n; i++)
			{
				ans[i] /= 2;
			}
		}
		if (t == 3)
		{
			for (int i = 0; i < n; i++)
			{
				ans[i] = f[0][i] - f[1][i] * 3;
			}
			for (int i = 0; i < m; i++)
			{
				ans[a[i] * 3] += 2;
			}
			for (int i = 0; i < n; i++)
			{
				ans[i] /= 6;
			}
		}
		if (t == 4)
		{
			for (int i = 0; i < n; i++)
			{
				ans[i] = f[0][i] - f[1][i] * 6 + f[2][i] * 3 + f[3][i] * 8;
			}
			for (int i = 0; i < m; i++)
			{
				ans[a[i] * 4] -= 6;
			}
			for (int i = 0; i < n; i++)
			{
				ans[i] = mulmod(ans[i], inv24, modulo);
			}
		}
		if (t == 5)
		{
			for (int i = 0; i < n; i++)
				ans[i] = f[0][i] - f[1][i] * 10 + f[2][i] * 20 + f[3][i] * 15 - f[4][i] * 30 - f[5][i] * 20;
			for (int i = 0; i < m; i++)
			{
				ans[a[i] * 5] += 24;
			}
			for (int i = 0; i < n; i++)
			{
				ans[i] = mulmod(ans[i], inv120, modulo);
			}
		}
		for (int i = 0; i < n; i++)
			if (ans[i] > 0)
			{
				printf("%d: %lld\n", i + base * t, ans[i]);
			}
		puts("");
	}
	return 0;
}
