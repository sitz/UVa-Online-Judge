#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653589793

int a, b, c, d, e;

bool valid()
{
	if (a + b + c + d + e != 180)
	{
		return true;
	}
	return false;
}

int main()
{
	while (scanf("%d%d%d%d%d", &a, &b, &c, &d, &e) && (a || b || c || d || e))
	{
		if (valid())
		{
			printf("Impossible\n");
			continue;
		}
		double pa = (double)a * PI / 180.0;
		double pb = (double)b * PI / 180.0;
		double pc = (double)c * PI / 180.0;
		double pd = (double)d * PI / 180.0;
		double pe = (double)e * PI / 180.0;
		double la = 10.0;
		double lde = la * sin(pd + pe) / sin(pa);
		double le = la * sin(pe) / sin(pa + pd);
		double ld = lde - le;
		double lbc = la * sin(pb + pc) / sin(pa);
		double lc = la * sin(pc) / sin(pa + pb);
		double lb = lbc - lc;
		double lx = sqrt(lb * lb + ld * ld - 2.0 * lb * ld * cos(pa));
		double sx = le * sin(pb) / lx;
		printf("%.2lf\n", asin(sx) / PI * 180.0);
	}
	return 0;
}
