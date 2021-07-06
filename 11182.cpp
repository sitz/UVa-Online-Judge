#include <bits/stdc++.h>

using namespace std;

typedef long long int int64;
int64 T(int64 a, int64 d, int64 n)
{
	int64 sum = n * (a - d) * (a - d);
	sum += d * (a - d) * n * (n + 1);
	sum += d * d * n * (n + 1) * (2 * n + 1) / 6;
	sum += n * (a - d);
	sum += d * n * (n + 1) / 2;
	return sum / 2;
}
int64 n, b;
int64 bases[100], c[100];
int len;
void factorize(int64 value)
{
	len = 0;
	for (int i = 2; i * i <= value; i++)
		if (value % i == 0)
		{
			bases[len] = i;
			int64 s = 0;
			while (value % i == 0)
			{
				value /= i;
				s++;
			}
			c[len++] = s;
		}
	if (value > 1)
	{
		bases[len] = value;
		c[len++] = 1;
	}
}
int main()
{
	while (scanf("%lld %lld", &n, &b) == 2)
	{
		if (!n && !b)
		{
			break;
		}
		factorize(b);
		int64 min = -1;
		for (int i = 0; i < len; i++)
		{
			int64 sum = 0;
			for (int64 s = bases[i]; s <= n; s *= bases[i])
			{
				sum += T((n + 1) - (n / s) * s, s, n / s);
			}
			if (min == -1 || (sum / c[i]) < min)
			{
				min = sum / c[i];
			}
		}
		printf("%lld\n", min);
	}
}
