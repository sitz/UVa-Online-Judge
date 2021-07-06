#include <bits/stdc++.h>

using namespace std;

#define eps 0.0001
int GCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	while ((a %= b) && (b %= a))
		;
	return a + b;
}
int main()
{
	int t, x1, y1, x2, y2, gcd, dx, dy, x, y, B[10][10], i, j, k, sd;
	double d;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lf", &d);
		x1 = (int)(d * 10 + eps);
		scanf("%lf", &d);
		y1 = (int)(d * 10 + eps);
		scanf("%lf", &d);
		x2 = (int)(d * 10 + eps);
		scanf("%lf", &d);
		y2 = (int)(d * 10 + eps);
		gcd = GCD(abs(dx = x2 - x1), abs(dy = y2 - y1));
		if (gcd == 0)
		{
			if (x % 10 == 0 && y % 10 == 0)
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
			continue;
		}
		dx /= gcd, dy /= gcd;
		dx %= 10, dy %= 10;
		if (dx < 0)
		{
			dx += 10;
		}
		if (dy < 0)
		{
			dy += 10;
		}
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				B[i][j] = 0;
			}
		}
		for (x = x1 % 10, y = y1 % 10, k = 0; x | y; k++, x = (x + dx) % 10, y = (y + dy) % 10)
		{
			if (B[x][y])
			{
				break;
			}
			B[x][y] = 1;
		}
		if (x | y)
		{
			printf("0\n");
			continue;
		}
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				B[i][j] = 1;
			}
		}
		for (x = y = i = 0; B[x][y]; i++, x = (x + dx) % 10, y = (y + dy) % 10)
		{
			B[x][y] = i;
		}
		if (gcd < k)
		{
			printf("0\n");
			continue;
		}
		else
		{
			gcd -= k;
			gcd = gcd / i + 1;
			printf("%d\n", gcd);
		}
	}
	return 0;
}
