#include <bits/stdc++.h>

using namespace std;

/*
493
Rational Spiral
*/
#define MAXN 1000000
char F[2000][2000];
struct ss
{
	int num, den;
} point[MAXN];
int ind;
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
void Gen()
{
	int i, j, k, p = 3, x, y, cd, g;
	int num = 1, den = 1;
	ind = 0;
	while (1)
	{
		//g = abs(den);
		for (i = 1; i <= p; i++)
		{
			//  x = abs(num);
			cd = gcd(num, den);
			x = (num / cd) + 1000;
			y = (den / cd) + 1000;
			num--;
			if (F[x][y])
			{
				continue;
			}
			point[ind].num = x - 1000;
			point[ind++].den = y - 1000;
			F[x][y] = 1;
			if (ind >= MAXN)
			{
				return;
			}
		}
		num++;
		//g = abs(num);
		for (j = 1; j <= p; j++)
		{
			if (den == 0)
			{
				den--;
				continue;
			}
			//y = abs(den);
			cd = gcd(num, den);
			x = (num / cd) + 1000;
			y = (den / cd) + 1000;
			den--;
			if (F[x][y])
			{
				continue;
			}
			point[ind].num = x - 1000;
			point[ind++].den = y - 1000;
			F[x][y] = 1;
			if (ind >= MAXN)
			{
				return;
			}
		}
		den++;
		p++;
		//g = abs(den);
		for (k = 1; k <= p; k++)
		{
			//  x = abs(num);
			cd = gcd(num, den);
			x = (num / cd) + 1000;
			y = (den / cd) + 1000;
			num++;
			if (F[x][y])
			{
				continue;
			}
			point[ind].num = x - 1000;
			point[ind++].den = y - 1000;
			F[x][y] = 1;
			if (ind >= MAXN)
			{
				return;
			}
		}
		num--;
		//g = abs(num);
		for (j = 1; j <= p; j++)
		{
			if (den == 0)
			{
				den++;
				continue;
			}
			y = abs(den);
			cd = gcd(num, den);
			x = (num / cd) + 1000;
			y = (den / cd) + 1000;
			den++;
			if (F[x][y])
			{
				continue;
			}
			point[ind].num = x - 1000;
			point[ind++].den = y - 1000;
			F[x][y] = 1;
			if (ind >= MAXN)
			{
				return;
			}
		}
		den--;
		p++;
	}
}
int main()
{
	int n, y;
	Gen();
	while (scanf("%d", &n) == 1)
	{
		y = point[n].den;
		if (point[n].den < 0)
		{
			printf("-");
			y *= -1;
		}
		printf("%d / %d\n", point[n].num, y);
	}
	return 0;
}
