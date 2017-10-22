#include <bits/stdc++.h>

using namespace std;

enum
{
	MAX_REC = 10,
	X1 = 0,
	Y1 = 1,
	X2 = 2,
	Y2 = 3
};
int main()
{
	int numRec = 0;
	double rec[MAX_REC][4];
	char c;
	while (scanf(" %c", &c))
	{
		if (c == '*')
		{
			break;
		}
		scanf("%lf %lf %lf %lf",
					&rec[numRec][X1], &rec[numRec][Y1], &rec[numRec][X2], &rec[numRec][Y2]);
		numRec++;
	}
	double x, y;
	int numPoint = 1;
	int outRec;
	while (scanf(" %lf %lf", &x, &y))
	{
		if (x == 9999.9 && y == 9999.9)
		{
			break;
		}
		outRec = 1;
		for (int i = 0; i < numRec; ++i)
		{
			if (x > rec[i][X1] && y < rec[i][Y1] &&
					x < rec[i][X2] && y > rec[i][Y2])
			{
				printf("Point %d is contained in figure %d\n", numPoint, i + 1);
				outRec = 0;
			}
		}
		if (outRec)
		{
			printf("Point %d is not contained in any figure\n", numPoint);
		}
		numPoint++;
	}
	return 0;
}
