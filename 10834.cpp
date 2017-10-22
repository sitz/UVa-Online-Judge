#include <bits/stdc++.h>

using namespace std;

struct vector2d
{
	double x,y;
};

typedef pair<vector2d, vector2d> vect_p;

vect_p solve(double R, double r, double x, double y)
{
	vect_p soln;
	soln.first.x = 0.0f;
	soln.first.y = 0.0f;
	soln.second.x = 0.0f;
	soln.second.y = 0.0f;

	// intersect btw {c=(0, 0), r=|r + r|} & {c=(t.x, t.y), r=r}
	double D = sqrt(x * x + y * y);
	double r0 = r + R;
	double r1 = r;
	if (r0 + r1 > D && D > abs(r0 - r1))
	{
		double delta = 0.25f * sqrt((D + r0 + r1) * (D + r0 - r1) * (D - r0 + r1) * (-D + r0 + r1));
		double pxa = (x / 2) + (x * (r0 * r0 - r1 * r1)) / (2 * D * D);
		double pxb = (-2 * y * delta) / (D * D);
		double cx1 = pxa + pxb;
		double cx2 = pxa - pxb;

		double pya = (y / 2) + (y * (r0 * r0 - r1 * r1)) / (2 * D * D);
		double pyb = (-2 * x * delta) / (D * D);
		double cy1 = pya - pyb;
		double cy2 = pya + pyb;

		// angle btw (cx, cy) & (R + r, 0)
		double alpha1 = atan2(cy1, cx1);
		double alpha2 = atan2(cy2, cx2);

		if (alpha1 < 0)
		{
			alpha1 += 2 * M_PI;
		}
		if (alpha2 < 0)
		{
			alpha2 += 2 * M_PI;
		}

		// calc angle small circle has rot
		double beta1 = (alpha1 * R) / r;
		double beta2 = (alpha2 * R) / r;

		// calc pos of p1 + p2 (finally!) from (cx, cy) w/ beta angle
		if (alpha1 < alpha2)
		{
			soln.first.x = cx1 - sin(alpha1 + beta1) * r;
			soln.first.y = cy1 + cos(alpha1 + beta1) * r;
			soln.second.x = cx2 - sin(alpha2 + beta2) * r;
			soln.second.y = cy2 + cos(alpha2 + beta2) * r;
		}
		else
		{
			soln.second.x = cx1 - sin(alpha1 + beta1) * r;
			soln.second.y = cy1 + cos(alpha1 + beta1) * r;
			soln.first.x = cx2 - sin(alpha2 + beta2) * r;
			soln.first.y = cy2 + cos(alpha2 + beta2) * r;
		}
	}

	return soln;
}

int main()
{
	double R, r, x, y;
	int t = 1;
	while (scanf("%lf%lf%lf%lf", &R,&r,&x,&y), R, r)
	{
		vect_p soln = solve(R, r, x, y);
		printf("Case %d:\n", t);
		if (soln.first.x == 0 && soln.first.y == 0 && soln.second.x == 0 && soln.second.y == 0)
		{
			printf("IMPOSSIBLE\n");
		}
		else
		{
			printf("%.3lf %.3lf\n%.3lf %.3lf\n", soln.first.x,soln.first.y,soln.second.x,soln.second.y);
		}
		t++;
	}
	return 0;
}
