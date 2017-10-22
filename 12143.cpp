#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct Frac
{
	LL a, b;
	Frac()
	{
		a = 0, b = 1;
	}
	Frac(LL x, LL y)
	{
		a = x, b = y;
		reduce();
	}
	Frac operator+(const Frac &y)
	{
		LL ta, tb;
		tb = this->b / gcd(this->b, y.b) * y.b;
		ta = this->a * (tb / this->b) + y.a * (tb / y.b);
		Frac z(ta, tb);
		return z;
	}
	Frac operator-(const Frac &y)
	{
		LL ta, tb;
		tb = this->b / gcd(this->b, y.b) * y.b;
		ta = this->a * (tb / this->b) - y.a * (tb / y.b);
		Frac z(ta, tb);
		return z;
	}
	Frac operator*(const Frac &y)
	{
		LL tx, ty, tz, tw, g;
		tx = this->a, ty = y.b;
		g = gcd(tx, ty), tx /= g, ty /= g;
		tz = this->b, tw = y.a;
		g = gcd(tz, tw), tz /= g, tw /= g;
		Frac z(tx * tw, ty * tz);
		return z;
	}
	Frac operator/(const Frac &y)
	{
		LL tx, ty, tz, tw, g;
		tx = this->a, ty = y.a;
		g = gcd(tx, ty), tx /= g, ty /= g;
		tz = this->b, tw = y.b;
		g = gcd(tz, tw), tz /= g, tw /= g;
		Frac z(tx * tw, ty * tz);
		return z;
	}

	static LL gcd(LL x, LL y)
	{
		if (!y)
		{
			return x;
		}
		if (x < 0)
		{
			x *= -1;
		}
		if (y < 0)
		{
			y *= -1;
		}
		LL t;
		while (x % y)
		{
			t = x, x = y, y = t % y;
		}
		return y;
	}
	void reduce()
	{
		LL g = gcd(a, b);
		a /= g, b /= g;
		if (b < 0)
		{
			a *= -1, b *= -1;
		}
	}
};

inline LL mpow(LL x, LL y, LL mod)
{
	if (y == 0)
	{
		return 1;
	}
	if (y & 1)
	{
		return (x * mpow((x * x) % mod, y >> 1, mod)) % mod;
	}
	return mpow((x * x) % mod, y >> 1, mod);
}

Frac x[20];

inline void gauss()
{
#define poly 11

	int i, j, k, l, m, n;
	Frac mtx[20][20];
	for (n = 1; n <= poly; n++)
	{
		LL sum = 0;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				for (k = 1; k <= n; k++)
					for (l = 1; l <= n; l++)
						for (m = 1; m <= n; m++)
						{
							sum += (LL)abs(i - j) * abs(j - k) * abs(k - l) * abs(l - m) * abs(m - i);
						}
		mtx[n][poly + 1] = Frac(sum, 1);
		for (i = 1; i <= poly; i++)
		{
			mtx[n][i] = Frac(mpow(n, i - 1, 1LL << 60), 1LL);
		}
	}
	for (i = 1; i <= poly; i++)
	{
		k = i;
		for (j = i + 1; j <= poly; j++)
		{
			if (mtx[j][i].a > mtx[k][i].a)
			{
				k = j;
			}
		}
		if (mtx[k][i].a == 0)
		{
			continue;
		}
		if (k != i)
		{
			for (j = 1; j <= poly + 1; j++)
			{
				swap(mtx[k][j], mtx[i][j]);
			}
		}
		for (j = 1; j <= poly; j++)
		{
			if (i == j)
			{
				continue;
			}
			for (k = poly + 1; k >= i; k--)
			{
				mtx[j][k] = mtx[j][k] - mtx[j][i] / mtx[i][i] * mtx[i][k];
			}
		}
	}
	for (i = 1; i <= poly; i++)
	{
		x[i - 1] = mtx[i][poly + 1] / mtx[i][i];
	}
}

int main()
{
	gauss();
	int n, i;
	while (scanf("%d", &n) == 1 && n)
	{
		LL ret = 0;
		for (i = 0; i <= 10; i++)
		{
			ret += x[i].a * mpow(n, i, 10007) * mpow(x[i].b, 10007 - 2, 10007);
			ret %= 10007;
		}
		printf("%lld\n", ret);
	}
	return 0;
}
