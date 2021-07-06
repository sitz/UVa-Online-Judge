#include <bits/stdc++.h>

using namespace std;

const int MAX = 35 * 2;
const double EPS = 1e-6;

bool dy(double x, double y)
{
	return x > y + EPS; // x > y
}
bool xy(double x, double y)
{
	return x < y - EPS; // x < y
}
bool dyd(double x, double y)
{
	return x > y - EPS; // x >= y
}
bool xyd(double x, double y)
{
	return x < y + EPS; // x <= y
}
bool dd(double x, double y)
{
	return fabs(x - y) < EPS; // x == y
}

double x[MAX], y[MAX];
struct rectangle
{
	double lx, ly, rx, ry;
};
rectangle r[35];
int map_[MAX][MAX];

int find(double a[], int m, double x)
{
	int beg = 0, end = m - 1;
	while (beg <= end)
	{
		int mid = (beg + end) >> 1;
		if (dd(x, a[mid]))
		{
			return mid;
		}
		if (dy(x, a[mid]))
		{
			beg = mid + 1;
		}
		else
		{
			end = mid;
		}
	}
}
double solve(int n, int cnt)
{
	for (int i = 0; i < n; i++)
	{
		int x1 = find(x, cnt, r[i].lx);
		int x2 = find(x, cnt, r[i].rx);
		int y1 = find(y, cnt, r[i].ly);
		int y2 = find(y, cnt, r[i].ry);
		for (int k = x1; k < x2; k++)
		{
			for (int j = y1; j < y2; j++)
			{
				map_[k][j]++;
			}
		}
	}
	double area = 0.0f;
	for (int i = 0; i < cnt - 1; i++)
	{
		for (int k = 0; k < cnt - 1; k++)
		{
			if (map_[i][k] == n)
			{
				area += (x[i + 1] - x[i]) * (y[k + 1] - y[k]);
			}
		}
	}
	return area;
}

int main()
{
	int ncases;
	scanf("%d", &ncases);
	int n, cnt, ind = 1;
	while (ncases--)
	{
		cnt = 0;
		scanf("%d", &n);
		memset(map_, 0, sizeof(map_));
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf%lf%lf", &r[i].lx, &r[i].ly, &r[i].rx, &r[i].ry);
			x[cnt] = r[i].lx;
			y[cnt++] = r[i].ly;
			x[cnt] = r[i].rx;
			y[cnt++] = r[i].ry;
		}
		sort(x, x + cnt);
		sort(y, y + cnt);
		double ans = solve(n, cnt);
		printf("Case %d: %.0lf\n", ind++, ans);
	}
	return 0;
}
