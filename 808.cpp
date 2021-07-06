#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef map<int, int> mii;

typedef struct Point
{
	int x, y;
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
} Point;

Point get_point(int n)
{
	int p, d, h, x, y;
	p = sqrt((n - 1) / 3);
	if ((p + 1) * p * 3 < (n - 1))
		p++;
	int dif = n - 1 - p * (p - 1) * 3;
	d = (p == 0 ? 0 : (dif / p) % 6);
	h = (p == 0 ? 0 : (dif % p));
	switch (d)
	{
	case 0:
		x = p - h;
		y = h;
		break;
	case 1:
		x = -h;
		y = p;
		break;
	case 2:
		x = -p;
		y = p - h;
		break;
	case 3:
		x = h - p;
		y = -h;
		break;
	case 4:
		x = h;
		y = -p;
		break;
	case 5:
		x = p;
		y = h - p;
		break;
	}
	return Point(x, y);
}

int main()
{
	int a, b;
	while (cin >> a >> b, a || b)
	{
		Point s = get_point(a);
		Point e = get_point(b);
		int res = abs(s.x - e.x) + abs(s.y - e.y);
		if ((s.x - e.x) * (s.y - e.y) < 0)
		{
			res -= min(abs(s.x - e.x), abs(s.y - e.y));
		}
		printf("The distance between cells %d and %d is %d.\n", a, b, res);
	}
	return 0;
}
