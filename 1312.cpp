#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef pair<int, int> Point;

void max_area(const vector<Point> &v, int xMin, int yMin, int xMax, int yMax, int &P, int &Q, int &L)
{
	if (v.empty())
	{
		int side = xMax - xMin;
		if (yMax - yMin < side)
		{
			side = yMax - yMin;
		}
		if (L >= side)
		{
			return;
		}
		L = side;
		P = xMin;
		Q = yMin;
		return;
	}
	Point pivot = v[0];
	vector<Point> v_top, v_btm, v_left, v_right;
	for (unsigned int i = 1; i < v.size(); ++i)
	{
		Point p = v[i];
		if (p.X > pivot.X)
    {
			v_right.push_back(p);
    }
		else
    {
			v_left.push_back(p);
    }
		if (p.Y > pivot.Y)
    {
			v_top.push_back(p);
    }
		else
    {
			v_btm.push_back(p);
    }
	}
	max_area(v_top, xMin, pivot.Y, xMax, yMax, P, Q, L);
	max_area(v_btm, xMin, yMin, xMax, pivot.Y, P, Q, L);
	max_area(v_left, xMin, yMin, pivot.X, yMax, P, Q, L);
	max_area(v_right, pivot.X, yMin, xMax, yMax, P, Q, L);
}

int main()
{
	int T, N, W, H, x, y, P, Q, L;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		if (t != 0)
		{
			printf("\n");
		}
		scanf("%d%d%d", &N, &W, &H);
		vector<Point> v;
		for (int i = 0; i < N; ++i)
		{
			scanf("%d%d", &x, &y);
			v.push_back(Point(x, y));
		}
		random_shuffle(v.begin(), v.end());
		L = 0;
		max_area(v, 0, 0, W, H, P, Q, L);
		printf("%d %d %d\n", P, Q, L);
	}
	return 0;
}
