#include <bits/stdc++.h>

using namespace std;

int amax, amin, bmax, bmin, mmax, mmin;

int Neg(int n)
{
	int a, b, c, d;
	if (bmin >= 0)
		return 0;
	b = (int)abs(bmin);
	b *= 2;
	if (bmax >= 0)
		a = 0;
	else
	{
		a = abs(bmax + 1);
		a *= 2;
	}
	c = b / n;
	d = a / n;
	if (n % 2)
	{
		c /= 2;
		d /= 2;
	}
	return c - d;
}
int Pos(int n)
{
	int a, b, c, d;
	if (bmax <= 0)
		return 0;
	if (bmin <= 0)
		a = 0;
	else
		a = (bmin - 1) * 2;
	b = bmax * 2;
	c = b / n;
	d = a / n;
	if (n % 2)
	{
		c /= 2;
		d /= 2;
	}
	return c - d;
}
void Cal()
{
	int total = 0, dif, i;
	dif = bmax - bmin + 1;
	for (i = mmin; i <= mmax; i++)
	{
		if (i == 1 || i == 2)
		{
			total += dif;
			continue;
		}
		total += Neg(i);
		total += Pos(i);
		if (bmax >= 0 && bmin <= 0)
			total++;
	}
	dif = amax - amin + 1;
	printf("%d\n", total * dif);
}

int main()
{
	int ks, k = 1;
	scanf("%d", &ks);
	while (ks--)
	{
		scanf("%d%d%d%d%d%d", &amin, &amax, &bmin, &bmax, &mmin, &mmax);
		printf("Case %d: ", k++);
		Cal();
	}
	return 0;
}
