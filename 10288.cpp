#include <bits/stdc++.h>

using namespace std;

long long int GCD(long long int a, long long int b)
{
	return (b == 0) ? a : GCD(b, a % b);
}
long long int c[34], p[34];
int getLength(long long int d)
{
	int len = 0;
	for (len = 0; d > 9; len++, d /= 10)
		;
	len++;
	return len;
}
void print(int n, char c)
{
	for (int i = 0; i < n; i++)
	{
		putchar(c);
	}
}

int main()
{
	long long int one = 1ll, d, ba, bb;
	int n;
	c[1] = one;
	p[1] = one;
	for (int i = 2; i <= 33; i++)
	{
		long long int t = (long long int)i;
		d = GCD(p[i - 1], t);
		p[i] = p[i - 1] * t / d;
		ba = p[i] / p[i - 1];
		bb = p[i] / t;
		c[i] = c[i - 1] * ba + bb;
	}
	while (scanf("%d", &n) == 1)
	{
		d = p[n] / (long long int)n;
		if (d == 1)
		{
			printf("%lld\n", c[n]);
		}
		else
		{
			long long int a = c[n] / d;
			int spaces = getLength(a) + 1;
			ba = c[n] - a * d;
			bb = GCD(ba, d);
			ba /= bb;
			d /= bb;
			int dashspaces = getLength(d);
			print(spaces, ' ');
			printf("%lld\n", ba);
			printf("%lld ", a);
			print(dashspaces, '-');
			printf("\n");
			print(spaces, ' ');
			printf("%lld\n", d);
		}
	}
	return 0;
}
