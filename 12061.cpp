#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cases;
	double ci, cj, ax, ay, bx, by, cx, cy, dx, dy, sf, angle, den, xden, yden;
	scanf("%d", &cases);
	while (cases--)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &ci, &cj, &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
		sf = sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)) / ci;
		angle = atan2((by - ay), (bx - ax));
		den = (sf * cos(angle) - 1) * (sf * cos(angle) - 1) + (sf * sin(angle)) * (sf * sin(angle));
		den = -1 / den;
		xden = ay * sf * sin(angle) + ax * (sf * cos(angle) - 1);
		yden = -ax * sf * sin(angle) + ay * (sf * cos(angle) - 1);
		printf("%.4lf %.4lf\n", xden * den, yden * den);
	}
	return 0;
}
