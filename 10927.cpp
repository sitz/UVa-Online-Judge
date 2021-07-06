#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

const double eps = 1e-10;

inline double dist(double x, double y)
{
	return x * x + y * y;
}

class pt
{
public:
	int x, y;
	int height;
	double ang;
	bool operator<(const pt &a) const
	{
		if (fabs(ang - a.ang) > eps)
		{
			return ang < a.ang;
		}
		return dist(x, y) < dist(a.x, a.y);
	}
};

void solve(vector<pt> &a)
{
	vector<pair<int, int>> cannot;
	sort(a.begin(), a.end());
	double prevang = -1000;
	int prevheight = 0;
	rep(i, a.size())
	{
		if (prevang != a[i].ang)
		{
			prevang = a[i].ang;
			prevheight = a[i].height;
		}
		else if (prevheight >= a[i].height)
		{
			prevang = a[i].ang;
			cannot.push_back(make_pair(a[i].x, a[i].y));
		}
		else
		{
			prevheight = max(prevheight, a[i].height);
		}
	}
	if (cannot.size() == 0)
	{
		cout << "All the lights are visible." << endl;
	}
	else
	{
		sort(cannot.begin(), cannot.end());
		cout << "Some lights are not visible:" << endl;
		rep(i, cannot.size())
		{
			cout << "x = " << cannot[i].first << ", y = " << cannot[i].second;
			if (i + 1 != cannot.size())
			{
				cout << ";" << endl;
			}
			else
			{
				cout << "." << endl;
			}
		}
	}
}

main()
{
	int tc = 1, n;
	while (cin >> n && n)
	{
		vector<pt> a(n);
		cout << "Data set " << tc++ << ":" << endl;
		rep(i, n)
		{
			cin >> a[i].x >> a[i].y >> a[i].height;
			a[i].ang = atan2(a[i].y, a[i].x);
		}
		solve(a);
	}
	return false;
}
