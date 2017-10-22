#include <bits/stdc++.h>

using namespace std;

long l, w, h, x1, y1_, z1, x2, y2, z2, r;

void swap(long &x, long &y)
{
	long t;
	t = x;
	x = y;
	y = t;
}

void turn(int i, int j, long x, long y, long z, long x0, long y0, long l, long w, long h)
{
	long rr;
	if (z == 0)
	{
		rr = x * x + y * y;
		if (rr < r)
		{
			r = rr;
		}
	}
	else
	{
		if ((i >= 0) && (i < 2))
		{
			turn(i + 1, j, x0 + l + z, y, x0 + l - x, x0 + l, y0, h, w, l);
		}
		if ((j >= 0) && (j < 2))
		{
			turn(i, j + 1, x, y0 + w + z, y0 + w - y, x0, y0 + w, l, h, w);
		}
		if ((i <= 0) && (i > -2))
		{
			turn(i - 1, j, x0 - z, y, x - x0, x0 - h, y0, h, w, l);
		}
		if ((j <= 0) && (j > -2))
		{
			turn(i, j - 1, x, y0 - z, y - y0, x0, y0 - h, l, h, w);
		}
	}
}

int main()
{
	while (cin >> l >> w >> h >> x1 >> y1_ >> z1 >> x2 >> y2 >> z2)
	{
		if ((z1 != 0) && (z1 != h))
		{
			if ((y1_ == 0) || (y1_ == w))
			{
				swap(y1_, z1);
				swap(y2, z2);
				swap(w, h);
			}
			else
			{
				swap(x1, z1);
				swap(x2, z2);
				swap(l, h);
			}
		}
		if (z1 == h)
		{
			z1 = 0;
			z2 = h - z2;
		}
		r = 2147483647;
		turn(0, 0, x2 - x1, y2 - y1_, z2, -x1, -y1_, l, w, h);
		cout << r << endl;
	}
	return 0;
}
