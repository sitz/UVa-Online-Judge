#include <bits/stdc++.h>

using namespace std;

/**
1. At first you have to find the smallest grid to have the map. So certainly you have to determine the highest x, lowest x, highest y,lowest y value of the map.
2. Then you have to create each possible rectangle within that smallest grid through 4 nested loops.(I solved this in this way(O(n^5)). There may be other efficient algorithms)
3. Now in each iteration you have to check that if the area of current rectangle is closest to the map than result.
4. If (3) true then check if at least three points of current rectangle lies on the map.
5. If (4) is true save the current rectangle to the result.
*/

#define MAXPOLY 300

struct point
{
	int x;
	int y;
};

struct rect
{
	int left, lower;
	int right, upper;
};

struct polygon
{
	int n;
	int top, left, right, bottom;
	point p[MAXPOLY];
};

int on[MAXPOLY][MAXPOLY];

void rectangle(polygon &contour, double area)
{
	double minDiff = area, currentDiff;
	rect tmp;
	for (int i = 0; i <= (contour.right - contour.left); i++)
		for (int j = 0; j <= (contour.top - contour.bottom); j++)
		{
			on[i][j] = 0;
		}
	for (int i = 0; i < contour.n; i++)
	{
		on[contour.p[i].x - contour.left][contour.p[i].y - contour.bottom] = 1;
	}
	for (int i = 0; i <= contour.right - contour.left; i++)
		for (int j = 0; j <= contour.top - contour.bottom; j++)
			for (int m = i; m <= contour.right - contour.left; m++)
				for (int n = j; n <= contour.top - contour.bottom; n++)
				{
					if (on[i][j] + on[i][n] +
									on[m][j] + on[m][n] <
							3)
					{
						continue;
					}
					currentDiff = fabs((m - i) * (n - j) - area);
					if (currentDiff < minDiff)
					{
						minDiff = currentDiff;
						tmp = (rect){
								contour.left + i,
								contour.bottom + j,
								contour.left + m,
								contour.bottom + n};
					}
				}
	cout << ((int)(area)) << "." << ((int)(area * 10.0) % 10) << " ";
	cout << tmp.left << " " << tmp.lower << " ";
	cout << tmp.right << " " << tmp.upper << endl;
}

double calArea(polygon &contour)
{
	double total = 0.0;
	for (int i = 0; i < contour.n; i++)
	{
		int j = (i + 1) % contour.n;
		total += (contour.p[i].x * contour.p[j].y -
							contour.p[j].x * contour.p[i].y);
	}
	return fabs(total / 2.0);
}

int main(int ac, char *av[])
{
	int cases;
	polygon contour;
	cin >> cases;
	while (cases--)
	{
		cin >> contour.n;
		for (int i = 0; i < contour.n; i++)
		{
			cin >> contour.p[i].x >> contour.p[i].y;
		}
		contour.top = contour.p[0].y;
		contour.left = contour.p[0].x;
		contour.bottom = contour.p[0].y;
		contour.right = contour.p[0].x;
		for (int i = 1; i < contour.n; i++)
		{
			contour.top = max(contour.top, contour.p[i].y);
			contour.left = min(contour.left, contour.p[i].x);
			contour.bottom = min(contour.bottom, contour.p[i].y);
			contour.right = max(contour.right, contour.p[i].x);
		}
		rectangle(contour, calArea(contour));
	}
	return 0;
}
