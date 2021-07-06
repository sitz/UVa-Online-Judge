#include <bits/stdc++.h>

using namespace std;

typedef struct
{
	int x, y;
} point;
typedef point polygon[20010];

polygon p[2];
int n, m, casenum = 0;

void readin(int num, int i)
{
	int j;
	for (j = 0; j < num; j++)
	{
		cin >> p[i][j].x >> p[i][j].y;
	}
	for (j = num; j < num + num; j++)
	{
		p[i][j] = p[i][j - num];
	}
}

void init()
{
	memset(p, 0, sizeof(p));
	readin(n, 0);
	readin(m, 1);
}

void out(point a, point b)
{
	if (a.x == b.x)
	{
		printf("VERTICAL\n");
	}
	else if (a.y == b.y)
	{
		printf("0.000\n");
	}
	else
	{
		double d = (a.y - b.y + 0.00) / (a.x - b.x + 0.00);
		if (fabs(d) < 1e-3)
		{
			d = 0;
		}
		printf("%.3f\n", d);
	}
}

int cross(point a, point b, point c, point d)
{
	double x1, y1, x2, y2;
	x1 = b.x - a.x;
	y1 = b.y - a.y;
	x2 = d.x - c.x;
	y2 = d.y - c.y;
	return x1 * y2 - x2 * y1;
}

int stdz(double d)
{
	if (fabs(d) < 1e-4)
	{
		return 0;
	}
	if (d > 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

double dot(point a, point b, point c)
{
	double x1, y1, x2, y2;
	x1 = b.x - a.x;
	x2 = c.x - a.x;
	y1 = b.y - a.y;
	y2 = c.y - a.y;
	return x1 * x2 + y1 * y2;
}

void getslope(point pp, int &tp1, int &tp2)
{
	int j, dir, newdir;
	int mini, maxi;
	double k;
	dir = stdz(cross(pp, p[0][0], pp, p[0][1]));
	mini = maxi = 0;
	for (j = 1; j < n; j++)
	{
		dir = stdz(cross(pp, p[0][mini], pp, p[0][j]));
		if (dir > 0 || dir == 0 && dot(p[0][mini], pp, p[0][j]) < 0)
		{
			mini = j;
		}
		dir = stdz(cross(pp, p[0][maxi], pp, p[0][j]));
		if (dir < 0 || dir == 0 && dot(p[0][maxi], pp, p[0][j]) < 0)
		{
			maxi = j;
		}
	}
	tp1 = mini;
	tp2 = maxi;
}

void process()
{
	int i, j, k;
	double k1, k2, tk1, tk2;
	int p1, p2, tp1, tp2;
	int besti = -1, bestj = -1;
	for (i = 0; i < m; i++)
	{
		getslope(p[1][i], tp1, tp2);
		if (besti < 0 || stdz(cross(p[1][i], p[0][tp1], p[1][besti], p[0][p1])) < 0)
		{
			besti = i;
			p1 = tp1;
		}
		if (bestj < 0 || stdz(cross(p[1][i], p[0][tp2], p[1][bestj], p[0][p2])) > 0)
		{
			bestj = i;
			p2 = tp2;
		}
	}
	out(p[1][besti], p[0][p1]);
	for (i = p1; i <= ((p1 < p2) ? p2 : p2 + n); i++)
	{
		printf("%d %d\n", p[0][i].x, p[0][i].y);
	}
	out(p[1][bestj], p[0][p2]);
}

int main()
{
	while (cin >> n, n)
	{
		if (casenum++)
			;
		printf("Instance %d:\n", casenum);
		cin >> m;
		init();
		process();
	}
	return 0;
}
