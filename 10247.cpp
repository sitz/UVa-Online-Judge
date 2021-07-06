#include <bits/stdc++.h>

using namespace std;

#define PI 462

int pw[32][32], prime[PI], fact_p[64][PI], fact_n[64], fact_a[4096], fact_k;

int factpp(int n, int p)
{
	int r, i;
	for (r = 0, i = p; i <= n; i *= p)
	{
		r += n / i;
	}
	return r;
}

void sieve()
{
	int s[4096], i, j, k, d;
	for (i = 0; i <= 21; i++)
		for (pw[i][0] = 1, j = 1; j <= 21; j++)
		{
			pw[i][j] = pw[i][j - 1] * i;
		}
	memset(s, 0, sizeof(s));
	for (i = 3; i < 57; i += 2)
		if (s[i] == 0)
			for (j = i * i; j < 3279; j += 2 * i)
			{
				s[j] = 1;
			}
	prime[0] = 2;
	for (i = 3, j = 1; i < 3279; i += 2)
		if (s[i] == 0)
		{
			prime[j++] = i;
		}
	memset(fact_a, 0, sizeof(fact_a));
	for (k = 2; k <= 21; k++)
		for (d = 0; d <= 21; d++)
			if (k * d <= 21)
			{
				fact_a[(pw[k][d] - 1) / (k - 1)] = fact_a[k * (pw[k][d] - 1) / (k - 1)] = 1;
			}
	for (k = i = 0; i < 4096; i++)
		if (fact_a[i])
		{
			fact_a[i] = k;
			fact_n[k++] = i;
		}
	fact_k = k;
	for (i = 0; i < fact_k; i++)
		for (j = 0; j < PI; j++)
		{
			fact_p[i][j] = factpp(fact_n[i], prime[j]);
		}
}

int R[PI], K;
unsigned D[65536];

void muldig(unsigned a)
{
	unsigned i, c;
	for (c = 0, i = 0; i < K; i++, c /= 10000)
	{
		D[i] = (c += D[i] * a) % 10000;
	}
	if (c)
	{
		D[K++] = c;
	}
}

void mulfact(int m, int n)
{
	int i;
	n = fact_a[n];
	for (i = 0; i < PI; i++)
	{
		R[i] += m * fact_p[n][i];
	}
}

char *solve(int k, int d)
{
	static char buf[65536];
	int i, j, t;
	if (k <= 1 || d <= 0)
	{
		return "1";
	}
	memset(R, 0, sizeof(R));
	for (i = 1; i <= d; i++)
	{
		for (j = 0; j < PI; j++)
		{
			R[j] *= k;
		}
		mulfact(+1, (k * (pw[k][i] - 1)) / (k - 1));
		mulfact(-k, (pw[k][i] - 1) / (k - 1));
	}
	K = 1;
	D[0] = 1;
	for (t = 1, i = 0; i < PI; i++)
	{
		for (j = 0; j < R[i]; j++)
		{
			if ((t * prime[i]) >= 10000)
			{
				muldig(t);
				t = 1;
			}
			t *= prime[i];
		}
	}
	if (t > 1)
	{
		muldig(t);
	}
	sprintf(buf, "%d", D[--K]);
	i = strlen(buf);
	while (K-- > 0)
	{
		j = D[K];
		buf[i + 3] = (j % 10) + '0';
		j /= 10;
		buf[i + 2] = (j % 10) + '0';
		j /= 10;
		buf[i + 1] = (j % 10) + '0';
		j /= 10;
		buf[i] = (j % 10) + '0';
		i += 4;
	}
	buf[i] = 0;
	return buf;
}

int main()
{
	char *sol[32][32];
	int k, d;
	sieve();
	memset(sol, 0, sizeof(sol));
	while (scanf("%d %d", &k, &d) == 2)
	{
		if (sol[k][d] == NULL)
		{
			sol[k][d] = strdup(solve(k, d));
		}
		printf("%s\n", sol[k][d]);
	}
	return 0;
}
