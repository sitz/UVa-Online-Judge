#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

const double PI = acos(-1);
const double eps = 1e-8;
#define EQ(a, b) (abs((a) - (b)) < eps)

class P
{
public:
	double x, y;
	double rad;
	double r;
	void calc_rad()
	{
		rad = atan2(y, x);
	}
	bool operator<(const P &a) const
	{
		return rad < a.rad;
	}
};

inline double dist(double x, double y)
{
	return sqrt(x * x + y * y);
}

inline double cross(double xa, double ya, double xb, double yb)
{
	return xa * yb - ya * xb;
}

inline double dot(double xa, double ya, double xb, double yb)
{
	return xa * xb + ya * yb;
}

double needr[2001];
int cnt[2001];
int table[2001][2001];
void solve(int n, P *in)
{
	sort(in, in + n);
	rep(i, n + 1) cnt[i] = 0;
	rep(i, n) rep(j, n + 1) table[i][j] = 0;
	rep(i, n) in[i].r = dist(in[i].x, in[i].y);
	rep(i, n)
	{
		int p = n;
		REP(j, 1, n && p > 2)
		{
			int next = (i + j) % n;
			if (cross(in[i].x, in[i].y, in[next].x, in[next].y) < 0)
			{
				break;
			}
			/*
			double tmp =abs(acos(dot(in[i].x,in[i].y,in[next].x,in[next].y)/
			   (dist(in[i].x,in[i].y)*dist(in[next].x,in[next].y))));
			*/
			double tmp = abs(acos(dot(in[i].x, in[i].y, in[next].x, in[next].y) /
														(in[i].r * in[next].r)));
			if (EQ(tmp, needr[p]))
			{
				table[next][p] = table[i][p] + 1;
				if (table[next][p] == p - 1)
				{
					cnt[p]++;
				}
			}
			else if (tmp > needr[p])
			{
				p--, j--;
			}
		}
	}
	rep(i, n + 1) if (cnt[i] != 0)
	{
		printf("%d %d\n", i, cnt[i]);
	}
}

main()
{
	int n, tc = 1;
	P in[2000];
	P tmp[2000];
	REP(i, 3, 2001)
	needr[i] = PI * 2. / i;
	while (scanf("%d", &n) != -1 && n)
	{
		rep(i, n)
				scanf("%lf%lf", &in[i].x, &in[i].y);
		rep(i, n) in[i].calc_rad();
		printf("Case %d:\n", tc++);
		solve(n, in);
	}
	return false;
}
