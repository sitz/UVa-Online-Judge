#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, v, A, t, colh, colv;
	double vx, vy, sx, sy, radA;
	scanf("%d %d %d %d %d", &a, &b, &v, &A, &t);
	while (a != 0 || b != 0 || v != 0 || A != 0 || t != 0)
	{
		radA = 4 * A * atan(1) / 180;
		vx = v * cos(radA);
		vy = v * sin(radA);
		sx = 0.5 * vx * t;
		sy = 0.5 * vy * t;
		colh = (sy + b / 2) / b;
		colv = (sx + a / 2) / a;
		printf("%d %d\n", colv, colh);
		scanf("%d %d %d %d %d", &a, &b, &v, &A, &t);
	}
	return 0;
}
