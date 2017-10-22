#include <bits/stdc++.h>

using namespace std;

int pow2(int y)
{
	int res = 1;
	for (int i = 0; i < y; i++)
	{
		res *= 2;
	}
	return res;
}

int main()
{
	int m, xin, yin, x, y;
	while (scanf("%d%d%d", &m,&xin,&yin) != EOF)
	{
		x = xin;
		y = yin;
		if (m == 0 && x == 0 && y == 0)
		{
			break;
		}
		if (y > x)
		{
			swap(x,y);
		}
		int yd = y - 1;
		int i = 0, sumy = 0, sumx = 0;
		int cut;
		while ((cut = pow2(i)) <= yd && yd >= cut)
		{
			if (cut > m)
			{
				break;
			}
			i++;
			sumy++;
			yd -= cut;
		}
		int ky;
		if (yd > 0)
		{
			ky = (yd / m);
			if ((ky * m) != yd)
			{
				ky++;
			}
		}
		else
		{
			ky = 0;
		}
		sumy += ky;
		int xd = y * (x - 1);
		int kx;
		if (x > 1)
		{
			i = 0;
			if (m <= y * 1)
			{
				kx = xd / m;
				if ((kx * m) != xd)
				{
					kx++;
				}
				sumx += kx;
			}
			else
			{
				while ((cut = y * pow2(i)) < m && xd >= cut)
				{
					i++;
					sumx++;
					xd -= cut;
				}
				if (xd > 0)
				{
					kx = (xd / m);
					if ((kx * m) != xd)
					{
						kx++;
					}
				}
				else
				{
					kx = 0;
				}
				sumx += kx;
			}
			int sum = sumx + sumy;
			printf("%d by %d takes %d cuts\n\n", xin,yin,sum);
		}
		else
		{
			int sum = 0;
			printf("%d by %d takes %d cuts\n\n", xin,yin,sum);
		}
	}
	return 0;
}
