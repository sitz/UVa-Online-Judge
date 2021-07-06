#include <bits/stdc++.h>

using namespace std;

// DJWS's code :p

struct Point
{
	int x, y;

	Point(int x = 0, int y = 0) : x(x), y(y) {}

	friend istream &operator>>(istream &in, Point &p)
	{
		return in >> p.x >> p.y;
	}

	friend Point makeDir(const Point &p1, const Point &p2)
	{
		if (p1.x == p2.x)
			if (p1.y < p2.y)
			{
				return Point(0, 1);
			}
			else
			{
				return Point(0, -1);
			}
		else if (p1.x < p2.x)
		{
			return Point(1, 0);
		}
		else
		{
			return Point(-1, 0);
		}
	}

	bool operator==(const Point &p) const
	{
		return x == p.x && y == p.y;
	}

	Point operator+(const Point &p) const
	{
		return Point(x + p.x, y + p.y);
	}

	void operator+=(const Point &p)
	{
		x += p.x, y += p.y;
	}

	void operator=(const Point &p)
	{
		x = p.x, y = p.y;
	}
};

Point aS[101], bS[101];

int main()
{
	int cases;
	cin >> cases;
	while (cases--)
	{
		int i;
		cin >> bS[0] >> aS[0];
		int aN, bN;
		cin >> aN;
		for (i = 1; i <= aN; ++i)
		{
			cin >> aS[i];
		}
		cin >> bN;
		for (i = 1; i <= bN; ++i)
		{
			cin >> bS[i];
		}
		bool ans = true;
		int aI = 0, bI = 0;
		Point a = aS[0], b = bS[0], dira, dirb;
		while (true)
		{
			if (a == aS[aI])
			{
				if (aI == aN)
				{
					break;
				}
				else
				{
					dira = makeDir(aS[aI], aS[aI + 1]), aI++;
				}
			}
			if (b == bS[bI])
			{
				if (bI == bN)
				{
					break;
				}
				else
				{
					dirb = makeDir(bS[bI], bS[bI + 1]), bI++;
				}
			}
			if (a == b)
			{
				ans = false;
				break;
			}
			//          if ((a + dira == b) && (b + dirb == a)) {
			//              ans = false;
			//              break;
			//          }
			a += dira;
			b += dirb;
		}
		if (ans)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
		if (cases)
		{
			cout << endl;
		}
	}
	return 0;
}
