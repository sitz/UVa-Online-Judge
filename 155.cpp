#include <bits/stdc++.h>

using namespace std;

int inside, px, py;
struct point
{
	int x;
	int y;
};
struct square
{
	point p1;
	point p2;
	point p3;
	point p4;
};

void func(int k, int x, int y)
{
	square mySqr;
	mySqr.p1.x = x - k;
	mySqr.p1.y = y - k;
	mySqr.p2.x = x + k;
	mySqr.p2.y = y - k;
	mySqr.p3.x = x + k;
	mySqr.p3.y = y + k;
	mySqr.p4.x = x - k;
	mySqr.p4.y = y + k;
	if ((px >= mySqr.p1.x && px <= mySqr.p2.x) && (py >= mySqr.p2.y && py <= mySqr.p3.y))
	{
		inside++;
	}
	if (k > 1)
	{
		func(k / 2, mySqr.p1.x, mySqr.p1.y);
		func(k / 2, mySqr.p2.x, mySqr.p2.y);
		func(k / 2, mySqr.p3.x, mySqr.p3.y);
		func(k / 2, mySqr.p4.x, mySqr.p4.y);
	}
}

int main()
{
	int k;
	while (1)
	{
		scanf("%d%d%d", &k, &px, &py);
		if (k == 0 && px == 0 && py == 0)
		{
			break;
		}
		inside = 0;
		func(k, 1024, 1024);
		printf("%3d\n", inside);
	}
	return 0;
}
