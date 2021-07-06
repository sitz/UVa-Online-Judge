#include <bits/stdc++.h>

using namespace std;

const double PI = atan(1) * 4;
int kase = 1;
double px, py, txy;
char str[20];
int main()
{
	int i = 0;
	while (scanf("%lf %lf %lf", &px, &py, &txy) != EOF)
	{
		if (i > 0)
		{
			printf("\n");
		}
		if (fabs(txy) >= 1e-12)
		{
			scanf("%s", str);
			if (!strcmp(str, "CCW"))
			{
				txy *= -1.0;
			}
		}
		double r;
		r = sqrt((px - py) * (px - py) + 4.0 * txy * txy) / 2.0;
		double oc, angle;
		oc = (px + py) / 2.0;
		angle = acos((px - oc) / r) / 2.0;
		angle = angle * 180 / PI;
		printf("Element : %d\n", kase++);
		printf("Position of maximum normal stresses : %.2lf deg\n", angle);
		printf("Maximum normal stresses : %.2lf MPa and %.2lf MPa\n\n", oc + r, oc - r);
		printf("Position of maximum shear stresses : %.2lf deg\n", angle + 45);
		printf("Maximum shear stress (xy plane) : %.2lf MPa\n", r);
		printf("Normal stress at this condition : %.2lf MPa\n", oc);
		i++;
	}
	return 0;
}
