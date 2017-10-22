#include <bits/stdc++.h>

using namespace std;

long long int fib[60];
int N, prime[1000010], p[100010];
long double a[60][4], b[4];

void prepare()
{
	int i, j, k, n;
	fib[0] = 0, fib[1] = 1;
	for (i = 2; i < 50; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	k = (int)sqrt((double)1000001);
	memset(prime, -1, sizeof(prime));
	n = 0;
	for (i = 2; i <= k; i++)
		if (prime[i])
		{
			p[n++] = i;
			for (j = i * i; j < 1000001; j += i)
			{
				prime[j] = 0;
			}
		}
	for (; i < 1000001; i++)
		if (prime[i])
		{
			p[n++] = i;
		}
	a[0][0] = a[0][1] = a[0][2] = 1;
	a[0][3] = 0;
}
void pow_mod(int n, int e)
{
	if (n == 1)
	{
		a[e][0] = a[e][1] = a[e][2] = 1;
		a[e][3] = 0;
		return;
	}
	pow_mod(n / 2, e + 1);
	a[e][0] = a[e + 1][0] * a[e + 1][0] + a[e + 1][1] * a[e + 1][2];
	a[e][1] = a[e + 1][0] * a[e + 1][1] + a[e + 1][1] * a[e + 1][3];
	a[e][2] = a[e + 1][2] * a[e + 1][0] + a[e + 1][3] * a[e + 1][2];
	a[e][3] = a[e + 1][2] * a[e + 1][1] + a[e + 1][3] * a[e + 1][3];
	if (n % 2)
	{
		b[0] = a[e][0] * a[0][0] + a[e][1] * a[0][2];
		b[1] = a[e][0] * a[0][1] + a[e][1] * a[0][3];
		b[2] = a[e][2] * a[0][0] + a[e][3] * a[0][2];
		b[3] = a[e][2] * a[0][1] + a[e][3] * a[0][3];
		a[e][0] = b[0], a[e][1] = b[1], a[e][2] = b[2], a[e][3] = b[3];
	}
	while (a[e][0] > 10000)
	{
		a[e][0] /= 10, a[e][1] /= 10, a[e][2] /= 10, a[e][3] /= 10;
	}
}
void solve()
{
	int i, j, n;
	long long int t;
	long double x;
	n = p[N - 1];
	pow_mod(n - 1, 1);
	x = a[1][0];
	while (x < 100000000)
	{
		x *= 10;
	}
	t = (long long int)x;
	printf("%lld\n", t);
}

int main()
{
	prepare();
	while (scanf("%d", &N) == 1)
	{
		if (N <= 2)
		{
			printf("%s\n", N == 1 ? "2" : "3");
		}
		else if (N <= 14)
		{
			printf("%lld\n", fib[p[N - 1]]);
		}
		else
		{
			solve();
		}
	}
	return 0;
}
