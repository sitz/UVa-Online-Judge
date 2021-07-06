#include <bits/stdc++.h>

using namespace std;

double x1, y1_, x2, y2, x3, y3, x4, y4, x, y;

int main()
{
	while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1,&y1_,&x2,&y2,&x3,&y3,&x4,&y4) != EOF)
	{
		if (x1 == x3 && y1_ == y3)
		{
			x = x2 + x4 - x3;
			y = y2 + y4 - y3;
		}
		else if (x1 == x4 && y1_ == y4)
		{
			x = x2 + x3 - x4;
			y = y2 + y3 - y4;
		}
		else if (x2 == x3 && y2 == y3)
		{
			x = x1 + x4 - x3;
			y = y1_ + y4 - y3;
		}
		else
		{
			x = x1 + x3 - x4;
			y = y1_ + y3 - y4;
		}
		printf("%.3lf %.3lf\n", x, y);
	}
	return 0;
}
