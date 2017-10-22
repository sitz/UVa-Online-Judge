#include <bits/stdc++.h>

using namespace std;

double a, b, c, d, e, f, dx, dy, dz, x, y, z, r, A, B, C, D, t1, t2, total, sum;
int n;
double dist(double x, double y, double z)
{
	return sqrt(x * x + y * y + z * z);
}
bool valid(double t)
{
	if (t >= 0 && t <= 1)
	{
		return true;
	}
	return false;
}
int main()
{
	char str[200];
	int flag;
	while (scanf("%s", str) == 1)
	{
		flag = 0;
		puts(str);
		scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);
		dx = d - a;
		dy = e - b;
		dz = f - c;
		scanf("%d", &n);
		total = dist(dx, dy, dz);
		sum = 0;
		A = dx * dx + dy * dy + dz * dz;
		for (int i = 0; i < n; i++)
		{
			scanf("%lf %lf %lf %lf", &x, &y, &z, &r);
			if (flag)
			{
				continue;
			}
			if (dist(a - x, b - y, c - z) <= r && dist(d - x, e - y, f - z) <= r)
			{
				flag = 1;
			}
			B = 2 * (dx * (a - x) + dy * (b - y) + dz * (c - z));
			C = (a - x) * (a - x) + (b - y) * (b - y) + (c - z) * (c - z) - r * r;
			D = B * B - 4 * A * C;
			if (D <= 0)
			{
				continue;
			}
			D = sqrt(D);
			t1 = (-B - D) / (2 * A);
			t2 = (-B + D) / (2 * A);
			if (valid(t1) && valid(t2))
			{
				sum += dist((t2 - t1) * dx, (t2 - t1) * dy, (t2 - t1) * dz);
			}
			else if (valid(t1))
			{
				double tempx = a + dx * t1, tempy = b + dy * t1, tempz = c + dz * t1;
				if (dist(a - x, b - y, c - z) < r)
				{
					sum += dist(t1 * dx, t1 * dy, t1 * dz);
				}
				else if (dist(d - x, e - y, f - z) < r)
				{
					sum += dist(tempx - d, tempy - e, tempz - f);
				}
			}
			else if (valid(t2))
			{
				double tempx = a + dx * t2, tempy = b + dy * t2, tempz = c + dz * t2;
				if (dist(a - x, b - y, c - z) < r)
				{
					sum += dist(t2 * dx, t2 * dy, t2 * dz);
				}
				else if (dist(d - x, e - y, f - z) < r)
				{
					sum += dist(tempx - d, tempy - e, tempz - f);
				}
			}
		}
		if (sum > total)
		{
			sum = total;
		}
		if (flag == 1)
		{
			printf("100.00\n");
		}
		else
		{
			printf("%.2lf\n", sum * 100 / total);
		}
	}
	return 0;
}
