#include <bits/stdc++.h>

using namespace std;

typedef long long ss;

ss coin, table, C[110], G[110][110];

ss gcd(ss a, ss b)
{
	return b ? gcd(b, a % b) : a;
}
int com(const void *a, const void *b)
{
	return *(ss *)a - *(ss *)b;
}
int Lucky(ss n)
{
	ss i, c = 0;
	for (i = 0; i < coin; i++)
	{
		if (C[i] && n % C[i] == 0)
			c++;
		if (c == 4)
		{
			printf("%lld %lld\n", n, n);
			return 1;
		}
	}
	return 0;
}
void Lower(ss n)
{
	ss i, j, k, l, p, q, r, x, y, s, t, z;
	ss lo = 10000000, up = 100000000;
	ss a[110] = {0};
	for (i = 0; i <= coin - 4; i++)
	{
		if (a[i] || !C[i])
			continue;
		if (C[i] >= n)
			break;
		p = (n / C[i]);
		q = p * C[i];
		r = n - q;
		z = q + C[i];
		if (r > lo && z > up)
			continue;
		for (j = i + 1; j <= coin - 3; j++)
		{
			if (!C[j])
				continue;
			if (C[j] % C[i] == 0)
				a[j] = 1;
			x = gcd(C[i], C[j]);
			s = (C[i] * C[j]) / x;
			q = (n / s);
			p = n - q * s;
			z = q * s + s;
			if (p > lo && z > up)
				continue;
			for (k = j + 1; k <= coin - 2; k++)
			{
				if (!C[k])
					continue;
				if (C[k] % C[i] == 0)
					a[k] = 1;
				y = gcd(s, C[k]);
				t = (s * C[k]) / y;
				q = (n / t);
				p = n - q * t;
				z = q * t + t;
				if (p > lo && z > up)
					continue;
				for (l = k + 1; l < coin; l++)
				{
					if (C[l] % C[i] == 0)
						a[l] = 1;
					y = gcd(t, C[l]);
					y = (t * C[l]) / y;
					q = (n / y);
					p = n - q * y;
					z = q * y + y;
					if (p < lo && y <= n)
						lo = p;
					if (z < up)
						up = z;
				}
			}
		}
	}
	if (lo < 1000000)
		printf("%lld", n - lo);
	else
		printf("0");
	printf(" %lld\n", up);
}

int main()
{
	ss i, n, k = 0;
	while (scanf("%lld%lld", &coin, &table) == 2)
	{
		if (!coin && !table)
			break;
		for (i = 0; i < coin; i++)
			scanf("%lld", &C[i]);
		qsort(C, coin, sizeof(ss), com);
		while (table--)
		{
			scanf("%lld", &n);
			if (Lucky(n))
				continue;
			Lower(n);
		}
	}
	return 0;
}
