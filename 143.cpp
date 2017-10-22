#include <bits/stdc++.h>

using namespace std;

struct POINT
{
	int x, y;
};

int main()
{
	for (POINT Coord[3], Tree;;)
	{
		POINT Min = {10000, 10000}, Max = {0, 0};
		for (int i = 0; i < 3; ++i)
		{
			float fX, fY;
			if (scanf("%f%f", &fX,&fY) == 0)
			{
				return 0;
			}
			Coord[i].x = (int)(fX * 100 + 0.5);
			Coord[i].y = (int)(fY * 100 + 0.5);

			if (Coord[i].x < Min.x)
			{
				Min.x = Coord[i].x;
			}
			if (Coord[i].y < Min.y)
			{
				Min.y = Coord[i].y;
			}
			if (Coord[i].x > Max.x)
			{
				Max.x = Coord[i].x;
			}
			if (Coord[i].y > Max.y)
			{
				Max.y = Coord[i].y;
			}
		}

		if (Min.x > Max.x || Min.y > Max.y)
		{
			printf("   0\n");
		}

		if (Coord[0].x == 0 && Coord[0].y == 0 &&
				Coord[1].x == 0 && Coord[1].y == 0 &&
				Coord[2].x == 0 && Coord[2].y == 0)
		{
			break;
		}
		POINT Vec[3] =
				{
						{Coord[1].x - Coord[0].x, Coord[1].y - Coord[0].y},
						{Coord[2].x - Coord[1].x, Coord[2].y - Coord[1].y},
						{Coord[0].x - Coord[2].x, Coord[0].y - Coord[2].y},
				};

		if (Vec[0].x * Vec[1].y - Vec[1].x * Vec[0].y > 0)
		{
			swap(Coord[0], Coord[1]);
			Vec[0].x = Coord[1].x - Coord[0].x;
			Vec[0].y = Coord[1].y - Coord[0].y;
			Vec[1].x = Coord[2].x - Coord[1].x;
			Vec[1].y = Coord[2].y - Coord[1].y;
			Vec[2].x = Coord[0].x - Coord[2].x;
			Vec[2].y = Coord[0].y - Coord[2].y;
		}

		if (Min.x % 100 != 0)
		{
			Min.x = (Min.x / 100 + 1) * 100;
		}
		if (Min.y % 100 != 0)
		{
			Min.y = (Min.y / 100 + 1) * 100;
		}
		if (Max.x % 100 != 0)
		{
			Max.x = Max.x / 100 * 100;
		}
		if (Max.y % 100 != 0)
		{
			Max.y = Max.y / 100 * 100;
		}

		if (Min.x < 100)
		{
			Min.x = 100;
		}
		if (Min.y < 100)
		{
			Min.y = 100;
		}
		if (Max.x > 9900)
		{
			Max.x = 9900;
		}
		if (Max.y > 9900)
		{
			Max.y = 9900;
		}
		int nCnt = 0, i;

		for (Tree.y = Min.y; Tree.y <= Max.y; Tree.y += 100)
		{
			for (Tree.x = Min.x; Tree.x <= Max.x; Tree.x += 100)
			{
				for (i = 0; i < 3; ++i)
				{
					POINT VecT = {Coord[i].x - Tree.x, Coord[i].y - Tree.y};
					if (VecT.x * Vec[i].y - VecT.y * Vec[i].x > 0)
					{
						break;
					}
				}
				nCnt += (i == 3);
			}
		}

		printf("%4d\n", nCnt);
	}
	return 0;
}
