#include <bits/stdc++.h>

using namespace std;

double s[100][3], a, b, c;
int num;
void calc(double x, double y, double z)
{
	double t;
	if (x > y)
	{
		t = x;
		x = y;
		y = t;
	}
	if (y > z)
	{
		t = y;
		y = z;
		z = t;
	}
	if (x > y)
	{
		t = x;
		x = y;
		y = t;
	}
	for (int i = 0; i < num; i++)
	{
		double t1 = x / s[i][0], t2 = y / s[i][1], t3 = z / s[i][2];
		if (fabs(t1 - t2) < 1e-6 && fabs(t2 - t3) < 1e-6)
		{
			return;
		}
	}
	s[num][0] = x;
	s[num][1] = y;
	s[num][2] = z;
	num++;
	double cosxz = (x * x + z * z - y * y) / (2 * x * z);
	double mid = sqrt((x * x + (z * z) / 4 - x * z * cosxz));
	calc(x, mid, z / 2);
	calc(y, mid, z / 2);
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int cases = 1; cases <= t; cases++)
	{
		printf("Triangle %d: ", cases);
		scanf("%lf %lf %lf", &a, &b, &c);
		num = 0;
		calc(a, b, c);
		printf("%d\n", num);
	}
}
