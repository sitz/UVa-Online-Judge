#include <bits/stdc++.h>

using namespace std;

/*
Aflea on a chessboard
10620
*/
//typedef __int64 ss;
typedef long long ss;
ss S, X, Y, dx, dy;
struct cor
{
	int x, y;
};
int Inside()
{
	ss x, y;
	x = X / S;
	y = Y / S;
	if (X % S && Y % S)
	{
		if ((x + y) % 2)
		{
			return 1;
		}
	}
	return 0;
}
void Cal()
{
	ss i, x, y;
	x = X / S;
	y = Y / S;
	if (X % S && Y % S)
	{
		if ((x + y) % 2)
		{
			printf("After 0 jumps the flea lands at (%lld, %lld).\n", X, Y);
			return;
		}
	}
	for (i = 0; i < 1100; i++)
	{
		X += dx;
		Y += dy;
		if (Inside())
		{
			printf("After %lld jumps the flea lands at (%lld, %lld).\n", i + 1, X, Y);
			return;
		}
	}
	printf("The flea cannot escape from black squares.\n");
}
int main()
{
	while (scanf("%lld%lld%lld%lld%lld", &S, &X, &Y, &dx, &dy) == 5)
	{
		if (!S && !X && !Y && !dx && !dy)
		{
			break;
		}
		Cal();
	}
	return 0;
}
