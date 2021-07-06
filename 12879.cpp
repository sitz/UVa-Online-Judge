#include <bits/stdc++.h>

using namespace std;

typedef complex<double> base;

#define PI (2.0 * acos(0))

inline void fft(vector<base> &a, bool invert)
{
	int n = (int)a.size();
	for (int i = 1, j = 0; i < n; ++i)
	{
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1)
		{
			j -= bit;
		}
		j += bit;
		if (i < j)
		{
			swap(a[i], a[j]);
		}
	}
	for (int len = 2; len <= n; len <<= 1)
	{
		double ang = 2 * PI / len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (int i = 0; i < n; i += len)
		{
			base w(1);
			for (int j = 0; j < len / 2; ++j)
			{
				base u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i = 0; i < n; ++i)
		{
			a[i] /= n;
		}
}

inline void multiply(const vector<int> &a, vector<int> &res)
{
	vector<base> fa(a.begin(), a.end());
	size_t n = 1;
	while (n < a.size())
	{
		n <<= 1;
	}
	n <<= 1;
	fa.resize(n);
	fft(fa, false);
	for (size_t i = 0; i < n; ++i)
	{
		fa[i] *= fa[i];
	}
	fft(fa, true);
	res.resize(n);
	for (size_t i = 0; i < n; ++i)
	{
		res[i] = int(fa[i].real() + 0.5);
	}
}

vector<int> va, vr;
bool a[300000];

int main()
{
	int i, j, k, n, m, mx = 0, ret;
	while (scanf("%d", &n) == 1)
	{
		memset(a, 0, sizeof(a));
		for (i = 0; i < n; i++)
		{
			scanf("%d", &k);
			mx = max(mx, k);
			a[k] = 1;
		}
		va.clear();
		vr.clear();
		va.push_back(1);
		for (i = 1; i <= mx; i++)
		{
			va.push_back(a[i] ? 1 : 0);
		}
		multiply(va, vr);
		scanf("%d", &m);
		ret = 0;
		for (i = 0; i < m; i++)
		{
			scanf("%d", &k);
			if (k > 2 * mx)
			{
				continue;
			}
			ret += (vr[k] > 0);
		}
		printf("%d\n", ret);
	}
	return 0;
}
