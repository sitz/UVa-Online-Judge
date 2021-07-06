#include <bits/stdc++.h>

using namespace std;

typedef struct
{
	double x, y, z;
} velocity;

int main()
{
	int test_case, data = 0, time;
	double x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
	double a, b, c, t, dis;
	velocity v1, v2;
	scanf("%d", &test_case);
	while (test_case--)
	{
		scanf("%d", &time);
		scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &z1, &x2, &y2, &z2);
		v1.x = (x2 - x1) / time;
		v1.y = (y2 - y1) / time;
		v1.z = (z2 - z1) / time;
		scanf("%lf %lf %lf %lf %lf %lf", &x3, &y3, &z3, &x4, &y4, &z4);
		v2.x = (x4 - x3) / time;
		v2.y = (y4 - y3) / time;
		v2.z = (z4 - z3) / time;
		a = (v2.x - v1.x) * (v2.x - v1.x) + (v2.y - v1.y) * (v2.y - v1.y) + (v2.z - v1.z) * (v2.z - v1.z);
		b = 2 * ((x1 * v1.x + x3 * v2.x - x3 * v1.x - x1 * v2.x) + (y1 * v1.y + y3 * v2.y - y3 * v1.y - y1 * v2.y) + (z1 * v1.z + z3 * v2.z - z3 * v1.z - z1 * v2.z));
		c = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1) + (z3 - z1) * (z3 - z1);
		(a == 0) ? (t = 0) : (t = -b / (2 * a));
		if (t < 0)
		{
			t = 0;
		}
		if (t > 0 && a * t * t + b * t + c < 0)
		{
			dis = 0.0;
		}
		else
		{
			dis = sqrt(a * t * t + b * t + c);
		}
		printf("Case %d: %.4lf\n", ++data, dis);
	}
	return 0;
}
