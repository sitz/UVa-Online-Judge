#include <bits/stdc++.h>

using namespace std;

// geom + bruteforce all perm+arrangement

bool inter(double x, double y, double r, double x2, double y2, double r2)
{
	double dx = x - x2, dy = y - y2;
	double d = dx * dx + dy * dy;
	return d < (r + r2) * (r + r2);
}

void rotate(double x, double y, double a, double &x2, double &y2)
{
	x2 = x * cos(a) - y * sin(a);
	y2 = x * sin(a) + y * cos(a);
}

int check1(int a, int b, int c,
					 double tr[3], double br[3])
{ // top and bottom radii
	/*
    Assume triangle is :
        /\
     a /  \ c
      /____\
         b
    */
	int peri = a + b + c;
	double p = peri / 2.0;
	double area = sqrt(p * (p - a) * (p - b) * (p - c));
	double incircleR = area / p;

	int i, j;
	double mr[3];
	for (i = 0; i < 3; i++)
	{
		if (tr[i] > incircleR || br[i] > incircleR)
			return 0;
		mr[i] = max(tr[i], br[i]);
	}

	double an[3], x[3], y[3];
	an[0] = .5 * acos((a * a + b * b - c * c) / (2.0 * a * b));
	x[0] = mr[0] / tan(an[0]); // (x,y) of circle@(a,b)
	y[0] = mr[0];

	an[1] = .5 * acos((a * a + c * c - b * b) / (2.0 * a * c));
	double tx = a - mr[1] / tan(an[1]);
	double ty = -mr[1];
	rotate(tx, ty, 2 * an[0], x[1], y[1]);

	an[2] = .5 * acos((c * c + b * b - a * a) / (2.0 * c * b));
	x[2] = b - mr[2] / tan(an[2]);
	y[2] = mr[2];

	for (i = 0; i < 3; i++)
	{
		for (j = i + 1; j < 3; j++)
		{
			if (inter(x[i], y[i], tr[i], x[j], y[j], tr[j]))
				return 0;
			if (inter(x[i], y[i], br[i], x[j], y[j], br[j]))
				return 0;
		}
	}

	return 1;
}

int perm[6][3] = {
		{0, 1, 2},
		{0, 2, 1},
		{1, 2, 0},
		{1, 0, 2},
		{2, 0, 1},
		{2, 1, 0}};

int main()
{
	int i, j, a, b, c, cc = 1;
	while (1)
	{
		cin >> a >> b >> c;
		if (a == 0)
			break;
		if (cc > 1)
			cout << endl;
		double d[3][2];
		for (i = 0; i < 3; i++)
			cin >> d[i][0] >> d[i][1];
		int found = 0;
		for (j = 0; j < 6; j++)
		{
			for (i = 0; i < 8; i++)
			{
				double tr[3], br[3];
				for (int k = 0; k < 3; k++)
				{
					int bit = 1 << k;
					tr[k] = d[perm[j][k]][!(i & bit)] / 2;
					br[k] = d[perm[j][k]][!!(i & bit)] / 2;
				}
				if (check1(a, b, c, tr, br))
				{
					found = 1;
					break;
				}
				if (check1(b, c, a, tr, br))
				{
					found = 1;
					break;
				}
				if (check1(c, a, b, tr, br))
				{
					found = 1;
					break;
				}
			}
		}
		printf("Triangle number %d:\n", cc++);
		if (found)
		{
			printf("All three stoppers will fit in the triangular space\n");
		}
		else
		{
			printf("Stoppers will not fit in the triangular space\n");
		}
	}
	return 0;
}
