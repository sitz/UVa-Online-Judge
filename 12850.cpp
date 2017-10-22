#include <bits/stdc++.h>

using namespace std;

template <class T>
inline char read(T &n)
{
	T x = 0, tmp = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-' && c != EOF)
	{
		c = getchar();
	}
	if (c == '-')
	{
		c = getchar(), tmp = -1;
	}
	while (c >= '0' && c <= '9')
	{
		x *= 10, x += (c - '0'), c = getchar();
	}
	n = x * tmp;
	return c;
}

template <class T>
inline void write(T n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	int len = 0, data[20];
	while (n)
	{
		data[len++] = n % 10;
		n /= 10;
	}
	if (!len)
	{
		data[len++] = 0;
	}
	while (len--)
	{
		putchar(data[len] + 48);
	}
}

const double eps = 1e-8;

int main()
{
	int T, ic = 1;
	read(T);
	while (T--)
	{
		double r, t, s, v;
		scanf("%lf %lf", &r, &t);
		s = (t * r) / (r - 1) + eps;
		v = t / (r - 1) + eps;
		printf("Case %d: %.3f %.3f\n", ic++, v, s);
	}
	return 0;
}
