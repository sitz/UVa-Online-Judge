#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-6;
const double SQRT3 = sqrt((double)3);
const int dir[7][2] = {{0, 0}, {-1, 1}, {0, 2}, {1, 1}, {1, -1}, {0, -2}, {-1, -1}};

struct Point
{
	double x, y;
};

double r, xa, ya, xb, yb;
double stepx, stepy;

bool input();
Point findFirstSection(double x, double y);
Point find(double x, double y);
void solve();

int main()
{
#ifndef ONLINE_JUDGE
	freopen("d:\\OJ\\uva_in.txt", "r", stdin);
#endif

	while (input())
	{
		solve();
	}
	return 0;
}

bool input()
{
	if (scanf("%lf%lf%lf%lf%lf", &r, &xa, &ya, &xb, &yb) != 5 ||
			!(r || xa || ya || xb || yb))
		return false;

	stepx = 1.5 * r;
	stepy = SQRT3 / 2 * r;

	return true;
}

Point findFirstSection(double x, double y)
{
	int dx = (int)(x / stepx);
	int dy = (int)(y / stepy);
	if (dx & 1)
	{
		if (!(dy & 1))
			dy++;
	}
	else
	{
		if (dy & 1)
			dx++;
	}

	double Min = 0x3f3f3f3f;
	Point ans;

	for (int i = 0; i < 7; i++)
	{
		double tmpx = stepx * (dx + dir[i][0]);
		double tmpy = stepy * (dy + dir[i][1]);
		double tmp = sqrt(pow(tmpx - x, 2) + pow(tmpy - y, 2));

		if (tmp < Min)
		{
			ans.x = tmpx;
			ans.y = tmpy;
			Min = tmp;
		}
	}

	return ans;
}

Point find(double x, double y)
{
	Point ans;

	if (x > 0 && y > 0)
	{
		ans = findFirstSection(x, y);
	}
	else if (x < 0 && y > 0)
	{
		ans = findFirstSection(-x, y);
		ans.x = -ans.x;
	}
	else if (x < 0 && y < 0)
	{
		ans = findFirstSection(-x, -y);
		ans.x = -ans.x;
		ans.y = -ans.y;
	}
	else
	{
		ans = findFirstSection(x, -y);
		ans.y = -ans.y;
	}

	return ans;
}

void solve()
{
	Point a = find(xa, ya);
	Point b = find(xb, yb);
	double dis;

	if (fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS)
	{
		dis = sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));
		printf("%.3lf\n", dis);
		return;
	}

	int x1 = (int)(fabs(a.x - b.x) / stepx + 0.5);
	int x2 = (int)(fabs(a.y - b.y) / stepy + 0.5);
	int d;

	if (x1 >= x2)
	{
		d = x1;
	}
	else
	{
		d = x1 + (x2 - x1) / 2;
	}
	dis = sqrt(pow(a.x - xa, 2) + pow(a.y - ya, 2)) + sqrt(pow(b.x - xb, 2) + pow(b.y - yb, 2)) + d * SQRT3 * r;

	printf("%.3lf\n", dis);
}
