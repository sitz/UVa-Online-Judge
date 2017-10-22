#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const double eps = 1e-6;
const double offset = 2000;
const double PI = acos(-1.0);
const int MAXN = 100005;
const int MAXM = 1 << 20;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000009;

bool zero(double a)
{
	return fabs(a) < eps;
}
int sgn(double x)
{
	return x < -eps ? -1 : x > eps;
}

struct point
{
	int x, y;
	point() {}
	point(int _x, int _y) : x(_x), y(_y) {}
	point operator-(point o) const
	{
		return point(x - o.x, y - o.y);
	}
	point operator+(point o) const
	{
		return point(x + o.x, y + o.y);
	}
	int operator^(point r)
	{
		return x * r.y - y * r.x;
	}
	bool operator<(const point &r) const
	{
		return x == r.x ? y < r.y : x < r.x;
	}
	void input()
	{
		scanf("%d %d", &x, &y);
	}
};

bool intersectIn(point a, point b, point c, point d)
{
	if (min(a.x, b.x) > max(c.x, d.x) ||
			min(a.y, b.y) > max(c.y, d.y) ||
			min(c.x, d.x) > max(a.x, b.x) ||
			min(c.y, d.y) > max(a.y, b.y))
	{
		return false;
	}
	LL h, i, j, k;
	h = (b - a) ^ (c - a);
	i = (b - a) ^ (d - a);
	j = (d - c) ^ (a - c);
	k = (d - c) ^ (b - c);
	return h * i <= 0 && j * k <= 0;
}//判线段相交,包括端点和部分重合

int s, r, w, p;
set<point> se;
vector<pair<point, point>> line;

bool check(const point &a, int x, int y)
{
	if (x * x + y * y > r * r)
	{
		return false;
	}
	point temp = a + point(x, y);
	if (se.find(temp) == se.end())
	{
		return false;
	}
	int cnt = 0;
	for (int i = 0; i < line.size(); i++)
		if (intersectIn(a, temp, line[i].first, line[i].second))
		{
			cnt++;
		}
	if (cnt > r)
	{
		return false;
	}
	if (x * x + y * y <= (r - cnt) * (r - cnt))
	{
		return true;
	}
	return false;
}

void solved(int cas)
{
	se.clear();
	line.clear();
	scanf("%d %d %d %d", &s, &r, &w, &p);
	point p1, p2;
	while (s--)
	{
		p1.input();
		se.insert(p1);
	}
	while (w--)
	{
		p1.input(), p2.input();
		line.push_back(make_pair(p1, p2));
	}
	while (p--)
	{
		p1.input();
		vector<point> vec;
		for (int i = -r; i <= r; i++)
			for (int j = -r; j <= r; j++)
				if (check(p1, i, j))
				{
					vec.push_back(p1 + point(i, j));
				}
		sort(vec.begin(), vec.end());
		printf("%d", vec.size());
		for (int i = 0; i < vec.size(); i++)
		{
			printf(" (%d,%d)", vec[i].x, vec[i].y);
		}
		printf("\n");
	}
}

int main()
{
	int T = 1;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		solved(i);
	}
	return 0;
}
