#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef unsigned long long ll;

const double eps = 1e-6;
const int N = 1010;
inline int sign(double x)
{
	return x < -eps ? -1 : x > eps;
}

struct Point
{
	double x, y;
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	Point operator+(const Point &o) const
	{
		return Point(x + o.x, y + o.y);
	}
	Point operator-(const Point &o) const
	{
		return Point(x - o.x, y - o.y);
	}
	Point operator/(double o)
	{
		return Point(x / o, y / o);
	}
	Point operator*(double o)
	{
		return Point(x * o, y * o);
	}
	double det(const Point &o) const
	{
		return x * o.y - y * o.x;
	}

	void rd()
	{
		scanf("%lf %lf", &x, &y);
	}
	void show()
	{
		cout << x << ' ' << y << endl;
	}
};

struct Range
{
	int l, r, c;
	bool operator<(const Range &o) const
	{
		return r < o.r;
	}
} rg[N];

int n, m;
Point p[N], l[N];
Point o;
int c[N];
bool flag[100];

inline bool check(Point light, Point p1, Point p2)
{
	return sign((light - p1).det(p2 - p1) * (o - p1).det(p2 - p1)) < 0;
}
void DP()
{
	int dp[100];
	int ans = ~0U >> 2;
	sort(rg, rg + m);
	for (int s = 0; s < n; ++s)
	{
		fill(dp, dp + 100, ~0U >> 2);
		vector<Range> cur;
		for (int i = 0; i < m; ++i)
			if (rg[i].r >= s)
			{
				cur.push_back(rg[i]);
			}
		for (int i = 0; i < cur.size(); ++i)
		{
			int l = cur[i].l, r = cur[i].r, c = cur[i].c;
			if (l <= s)
			{
				dp[r] = min(dp[r], c);
			}
			for (int j = max(l - 1, s); j <= r; ++j)
			{
				dp[r] = min(dp[r], dp[j] + c);
			}
		}
		for (int i = s + n - 1; i < n + n; ++i)
		{
			ans = min(ans, dp[i]);
		}
	}
	if (ans == ~0U >> 2)
	{
		puts("Impossible.");
	}
	else
	{
		printf("%d\n", ans);
	}
}
int main()
{
	while (scanf("%d", &n), n)
	{
		o = Point(0, 0);
		for (int i = 0; i < n; ++i)
		{
			p[i].rd(), o = o + p[i];
		}
		o = o / n;
		p[n] = p[0];
		scanf("%d", &m);
		for (int i = 0; i < m; ++i)
		{
			l[i].rd(), scanf("%d", c + i);
		}
		for (int i = 0; i < m; ++i)
		{
			memset(flag, false, sizeof(flag));
			for (int j = 0; j < n; ++j)
			{
				Point a = p[j], b = p[j + 1];
				if (check(l[i], a, b))
				{
					flag[j] = true;
				}
			}
			if (flag[0] && flag[n - 1])
			{
				int l = n - 1, r = n;
				while (flag[l])
				{
					rg[i].l = l, l--;
				}
				while (flag[r - n])
				{
					rg[i].r = r, r++;
				}
			}
			else
			{
				int l = 0, r = n - 1;
				while (!flag[l])
				{
					l++;
				}
				rg[i].l = l;
				while (!flag[r])
				{
					r--;
				}
				rg[i].r = r;
			}
			rg[i].c = c[i];
		}
		DP();
	}
	return 0;
}
