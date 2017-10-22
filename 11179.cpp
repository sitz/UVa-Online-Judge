#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int int64;

#define MAXSIZE 65537

int b, len, bit;
int64 pow_[MAXSIZE], state, L, n, m, C, v;

int64 pow_mod(int64 base, int64 exp, int64 mod)
{
	if (exp < MAXSIZE && pow_[exp] != -1)
	{
		return pow_[exp];
	}
	if (exp == 0)
	{
		return 1;
	}
	else if (exp & 1)
	{
		int64 temp = pow_mod(base, exp / 2, mod);
		temp = (temp * temp) % mod;
		temp = (temp * base) % mod;
		if (exp < MAXSIZE)
		{
			pow_[exp] = temp;
		}
		return temp;
	}
	else
	{
		int64 temp = pow_mod(base, exp / 2, mod);
		temp = (temp * temp) % mod;
		if (exp < MAXSIZE)
		{
			pow_[exp] = temp;
		}
		return temp;
	}
}

int64 series(int s)
{
	if (s == 0)
	{
		return 1;
	}
	else if (s & 1)
	{
		int k = s / 2;
		int64 temp = pow_mod(n, k + 1, m), t = series(k);
		temp = (temp * t) % m;
		temp = (t + temp) % m;
		return temp;
	}
	else
	{
		int k = s / 2;
		int64 temp = pow_mod(n, k, m), temp1 = temp, t = series(k - 1);
		temp = (temp * t) % m;
		temp = (t + temp) % m;
		t = (temp1 * temp1) % m;
		temp = (temp + t) % m;
		return temp;
	}
}

int main()
{
	int caseno = 1;
	while (scanf("%lld", &L) == 1)
	{
		if (!L)
		{
			break;
		}
		scanf("%d %lld %lld %lld", &b, &n, &m, &C);
		bit = len = 0;
		state = 0;
		int64 total = 0;
		scanf("%lld", &v);
		int64 k = 0;
		const int64 onemask = (b == 32) ? 4294967295LL : (1 << b) - 1;
		memset(pow_, -1, sizeof(pow_));

		while (1)
		{
			total += v;
			if (len + v < b)
			{
				int64 s = (bit) ? (1 << v) - 1 : 0;
				state = (state << v) | s;
				len += v;
			}
			else
			{
				if (len)
				{
					int leftshift = b - len;
					int64 s = (bit) ? (1 << leftshift) - 1 : 0;
					state = (state << leftshift) | s;
					k = ((k * n) + state) % m;
					state = 0;
					len = 0;
					v -= leftshift;
				}
				int64 chunks = v / b, left = v % b;
				if (chunks)
				{
					int64 temp = pow_mod(n, chunks, m);
					k = (k * temp) % m;
					if (bit)
					{
						int64 t = series(chunks - 1);
						t = (onemask * t) % m;
						k = (k + t) % m;
					}
				}
				if (left)
				{
					int64 s = (bit) ? (1 << left) - 1 : 0;
					state = (state << left) | s;
					len += left;
				}
			}
			bit = !bit;
			scanf("%lld", &v);
			if (!v)
			{
				break;
			}
		}

		if (len)
		{
			int left = b - len;
			state = (state << left);
			len += left;
			k = ((k * n) + state) % m;
		}

		if (total != L)
		{
			printf("Bitstream %d: Invalid Length\n", caseno++);
			continue;
		}
		if (k == C)
		{
			printf("Bitstream %d: Compression OK\n", caseno++);
		}
		else
		{
			printf("Bitstream %d: Invalid Checksum\n", caseno++);
		}
	}
	return 0;
}
