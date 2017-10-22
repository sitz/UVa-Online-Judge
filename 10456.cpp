#include <bits/stdc++.h>

using namespace std;

int x[31], y[31], x1, y1_, n, tx[31], ty[31], len, totalarea;

int GCD(int a, int b)
{
	return (b == 0) ? a : GCD(b, a % b);
}

int main()
{
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", x + i, y + i);
		}
		x[n] = x[0];
		y[n] = y[0];
		totalarea = 0;
		for (int i = 0; i < n; i++)
		{
			totalarea += x[i] * y[i + 1] - x[i + 1] * y[i];
		}
		int k;
		scanf("%d", &k);
		while (k--)
		{
			scanf("%d %d", &x1, &y1_);
			int p = 0;
			len = 0;
			for (int i = n - 1; i >= 0; i--)
				if ((x[i + 1] - x[i]) * (y1_ - y[i]) == (x1 - x[i]) * (y[i + 1] - y[i]))
				{
					p = i;
				}
			tx[len] = x1;
			ty[len++] = y1_;
			tx[len] = x[p + 1];
			ty[len++] = y[p + 1];
			for (int i = (p + 2) % n; i != p; i = (i + 1) % n)
			{
				tx[len] = x[i];
				ty[len++] = y[i];
				tx[len] = x1;
				ty[len] = y1_;
				int temp = 0;
				for (int j = 0; j < len; j++)
				{
					temp += tx[j] * ty[j + 1] - tx[j + 1] * ty[j];
				}
				if (2 * temp < totalarea)
				{
					continue;
				}
				int lx = x[(i + n - 1) % n], ly = y[(i + n - 1) % n];
				int a = x[i] - lx, b = y[i] - ly;
				int la = 0, lb = 0;
				for (int j = 0; j < len; j++)
				{
					if (j < len - 2)
					{
						la += tx[j] * ty[j + 1] - tx[j + 1] * ty[j];
					}
					else if (j == len - 2)
					{
						//la+=lx*ly-ly*lx;
						lb += lx * b - ly * a;
					}
					else
					{
						la += lx * ty[0] - ly * tx[0];
						lb += a * ty[0] - b * tx[0];
					}
				}
				la = (totalarea - 2 * la);
				int nx = lx * 2 * lb + a * la;
				int fx = 2 * lb;
				int d = GCD(nx, fx);
				nx /= d;
				fx /= d;
				if (fx < 0)
				{
					nx *= -1;
					fx *= -1;
				}
				printf("(%d/%d),", nx, fx);
				int ny = ly * 2 * lb + b * la;
				int fy = 2 * lb;
				int dd = GCD(ny, fy);
				ny /= dd;
				fy /= dd;
				if (fy < 0)
				{
					ny *= -1;
					fy *= -1;
				}
				printf("(%d/%d)\n", ny, fy);
				break;
			}
		}
	}
	return 0;
}
