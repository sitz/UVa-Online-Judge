#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define EPS 1e-8
const double PI = 4.0 * atan(1.0);

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

struct point
{
	double x, y;
};

inline bool comp_x(point a, point b)
{
	return a.x < b.x;
}

inline bool comp_y(point a, point b)
{
	return a.y < b.y;
}

inline double dist(point a, point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double closest_pair(point pt[], int n)
{
	int m = n / 2;

	if (n == 1)
		return 1e99;
	if (n == 2)
		return dist(*pt, *(pt + 1));

	double d1 = closest_pair(pt, m);
	double d2 = closest_pair(pt + m, n - m);
	double d = min(d1, d2);

	vector<point> qt;
	qt.clear();
	for (int i = 0; i < n; i++)
	{
		if (fabs(pt[i].x - pt[m].x) < d + EPS)
			qt.push_back(pt[i]);
	}
	sort(qt.begin(), qt.end(), comp_y);
	for (int i = 0; i < qt.size(); i++)
	{
		for (int j = 1; j < 6; j++)
		{
			if (i + j < qt.size())
				d = min(d, dist(qt[i], qt[i + j]));
		}
	}
	return d;
}

point pt[15005];

int main()
{
	int n;
	double e, theta;

	cin >> n >> e >> theta;

	int cs = 0;
	while (n)
	{
		memset(pt, 0, sizeof(pt));
		cout << "Case " << ++cs << ":\n";
		double x, y;

		double th = double(theta) * PI / 180;
		double k = sqrt(1 - e * e);// k = b/a <1

		for (int i = 0; i < n; i++)
		{
			scanf("%lf %lf", &x, &y);
			pt[i].x = (x * cos(th) + y * sin(th)) * k;
			pt[i].y = -x * sin(th) + y * cos(th);
		}

		sort(pt, pt + n, comp_x);

		double d = closest_pair(pt, n) / 2;

		if (e == 1)
			printf("%f\n", 0);
		else
			printf("%f\n", PI * d * d / k);

		cin >> n >> e >> theta;
	}
}
