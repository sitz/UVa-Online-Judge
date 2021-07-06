#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.);

#define cp complex<double>

int dcmp(double a)
{
	if (a < -eps)
	{
		return -1;
	}
	return a > eps;
}

void fft(cp *a, int n, int rev)
{
	int i, j, k, m;
	for (i = 1, j = 0; i < n; i++)
	{
		for (k = n >> 1; k > (j ^= k); k >>= 1)
			;
		if (i < j)
		{
			swap(a[i], a[j]);
		}
	}
	for (m = 2; m <= n; m <<= 1)
	{
		cp wm(cos(2 * pi * rev / m), sin(2 * pi * rev / m));
		for (i = 0; i < n; i += m)
		{
			cp w(1, 0);
			for (j = i; j < i + m / 2; j++)
			{
				cp t = w * a[j + m / 2];
				a[j + m / 2] = a[j] - t;
				a[j] = a[j] + t;
				w = w * wm;
			}
		}
	}
}

cp ya[510000], yb[510000];

void PolyMulti(int *a, int na, int *b, int nb, int *c)
{
	int i, j, n = max(na, nb);
	for (n = 1; n < na + nb; n <<= 1)
		;
	for (i = 0; i < n; ++i)
	{
		ya[i] = (i < na) ? a[i] : 0;
	}
	fft(ya, n, 1);
	for (i = 0; i < n; ++i)
	{
		yb[i] = (i < nb) ? b[i] : 0;
	}
	fft(yb, n, 1);
	for (i = 0; i < n; ++i)
	{
		ya[i] = ya[i] * yb[i];
	}
	fft(ya, n, -1);
	for (i = 0; i < n; ++i)
	{
		c[i] = (ya[i].real() / n + 0.01);
	}
}

int a[110000], b[110000], c[210000];
bool h[51000];

int main()
{
	int T, cases = 1;
	int i, j, k, R, C, N, s1, s2;
	long long ans;
	int x, y, LF;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d", &R, &C, &N);
		ans = (long long)R * C;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(h, 0, sizeof(h));
		LF = R - 1;
		for (i = 0; i < N; ++i)
		{
			scanf("%d %d", &y, &x);
			a[x - y + LF] = 1;
			b[C - x] = 1;
			h[y] = 1;
		}
		for (i = s1 = 0; i < C; ++i)
		{
			s1 += b[i];
		}
		for (i = s2 = 0; i < C; ++i)
		{
			s2 += a[i + LF];
		}
		PolyMulti(a, LF + C, b, C, c);
		for (i = 1; i <= R; ++i)
		{
			if (h[i])
			{
				ans -= C;
			}
			else
			{
				ans -= s1 + s2 - c[-i + LF + C];
			}
			if (a[C - i + LF])
			{
				s2--;
			}
			if (a[0 - i + LF])
			{
				s2++;
			}
		}
		printf("Case %d: %lld\n", cases++, ans);
	}
	return 0;
}
