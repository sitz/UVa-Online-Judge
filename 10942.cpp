#include <bits/stdc++.h>

using namespace std;

int best;
void Test(int c, int m, int day, int y)
{
	bool leap = false;
	if (c + y == 0)
	{
		leap = true;
	}
	c %= 4;
	if (c == 0)
	{
		c = 4;
	}
	int t = c * 100 + y;
	if ((t % 4 == 0 && t % 100 != 0) || t % 400 == 0)
	{
		leap = true;
	}
	if (m < 1 || m > 12)
	{
		return;
	}
	int bd;
	if (m == 2)
	{
		bd = (leap) ? 29 : 28;
	}
	else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		bd = 31;
	}
	else
	{
		bd = 30;
	}
	if (day < 1 || day > bd)
	{
		return;
	}
	t = 10000 * y + 100 * m + day;
	if (t < best)
	{
		best = t;
	}
}
int main()
{
	int t, c, x, y, z;
	scanf("%d", &t);
	while (t--)
	{
		best = 999999;
		scanf("%d %d %d %d", &c, &x, &y, &z);
		Test(c, x, y, z);
		Test(c, x, z, y);
		Test(c, y, x, z);
		Test(c, y, z, x);
		Test(c, z, x, y);
		Test(c, z, y, x);
		if (best == 999999)
		{
			puts("-1");
		}
		else
		{
			printf("%02d %02d %02d\n", best / 10000, (best / 100) % 100, best % 100);
		}
	}
}
