#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int n, color[MAXN];

struct Point
{
	int x, y;
	Point(int x = 0, int y = 0)
			: x(x), y(y)
	{
	}
	double rad;
	bool operator<(const Point &rhs) const
	{
		return rad < rhs.rad;
	}
} op[MAXN], p[MAXN];

Point operator-(const Point &A, const Point &B)
{
	return Point(A.x - B.x, A.y - B.y);
}

int cross(const Point &A, const Point &B)
{
	return A.x * B.y - A.y * B.x;
}

int solve()
{
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int k = 0;
		for (int j = 0; j < n; ++j)
		{
			if (i != j)
			{
				p[k] = op[j] - op[i];
				if (color[j])
				{
					p[k].x = -p[k].x;
					p[k].y = -p[k].y;
				}
				p[k].rad = atan2(p[k].y, p[k].x);
				k++;
			}
		}
		sort(p, p + k);
		int L = 0, R = 0, cnt = 2;
		for (; L < k; ++L)
		{
			if (L == R)
			{
				R = (R + 1) % k;
				cnt++;
			}
			while (L != R && cross(p[L], p[R]) >= 0)
			{
				R = (R + 1) % k;
				cnt++;
			}
			cnt--;
			ans = max(ans, cnt);
		}
	}
	return ans;
}

int main()
{
	while (scanf("%d", &n) == 1 && n)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d%d", &op[i].x, &op[i].y, &color[i]);
		}
		printf("%d\n", solve());
	}
	return 0;
}
