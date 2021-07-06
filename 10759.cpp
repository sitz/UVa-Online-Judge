#include <bits/stdc++.h>

using namespace std;

typedef long long ss;

ss F[155][30], N, X;

ss gcd(ss a, ss b)
{
	return b ? gcd(b, a % b) : a;
}
ss recur(ss n, ss level)
{
	ss i, j, d;
	if (F[n][level])
		return F[n][level];
	if (level == N - 1)
	{
		if (n >= X)
			return 1;
		return 0;
	}
	if (n < X)
	{
		d = N - level - 1;
		if (d * 6 + n < X)
			return 0;
	}
	if (n >= X)
	{
		d = N - level - 1;
		j = (ss)pow(6, d);
		if (n <= 6)
			F[n][level] = j;
		return j;
	}
	if (level == N - 2)
	{
		d = X - n;
		if (d > 6)
			return 0;
		d = 6 - d + 1;
		if (d > 6)
			d = 6;
		F[n][level] = d;
		return F[n][level];
	}
	for (i = 1; i < 7; i++)
		F[n][level] += recur(n + i, level + 1);
	return F[n][level];
}
void Cal()
{
	ss x = 0, y, z, i;
	if (X == 0)
	{
		printf("1\n");
		return;
	}
	if (N == 1)
	{
		x = 6 - X + 1;
		if (x <= 0)
		{
			printf("0\n");
			return;
		}
	}
	else
	{
		for (i = 1; i < 7; i++)
			x += recur(i, 0);
	}
	y = pow(6, N);
	z = gcd(x, y);
	x /= z;
	y /= z;
	if (!x)
	{
		printf("0\n");
		return;
	}
	if (x == y || y == 1)
	{
		printf("%lld\n", x);
		return;
	}
	printf("%lld", x);
	if (y)
		printf("/%lld", y);
	printf("\n");
}

int main()
{
	ss f = 0, i, j;
	while (scanf("%lld%lld", &N, &X) == 2)
	{
		if (!N && !X)
			break;
		Cal();
		for (i = 0; i <= X; i++)
			for (j = 0; j <= N; j++)
				F[i][j] = 0;
	}
	return 0;
}
