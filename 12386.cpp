#include <bits/stdc++.h>

using namespace std;

#define eps 1e-9
#define ll long long

double f_abs(double x)
{
	return x < 0 ? -x : x;
}
struct Point
{
	double x, y;
	void disp()
	{
		printf("%lf %lf\n", x, y);
	}
};
struct Line
{
	Point s, e;
	void disp()
	{
		s.disp();
		e.disp();
	}
	double area()
	{
		return (s.x * e.y - s.y * e.x) / 2;
	}
	double len()
	{
		return sqrt((s.x - e.x) * (s.x - e.x) + (s.y - e.y) * (s.y - e.y));
	}
};
Point pt[15];
int N;
void get_data()
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%lf%lf", &pt[i].x, &pt[i].y);
	}
}
Line le[15], tl;
bool mk[15];
double minarea, L1, L2;
double xmult(Point a, Line b)
{
	return (b.s.x - a.x) * (b.e.y - a.y) - (b.e.x - a.x) * (b.s.y - a.y);
}
double pmult(Point a, Line b)
{
	return (b.s.x - a.x) * (b.e.x - a.x) + (b.e.y - a.y) * (b.s.y - a.y);
}
bool contra(Line a, Line b)
{
	double x = xmult(a.s, b) * xmult(a.e, b), y = xmult(b.s, a) * xmult(b.e, a);
	return x < eps && y < eps;
}
bool collison(Line a, Line b)
{
	if (f_abs(xmult(a.s, b)) < eps && f_abs(xmult(a.e, b)) < eps && f_abs(xmult(b.s, a)) < eps && f_abs(xmult(b.e, a)) < eps)
	{
		return pmult(a.s, b) < -eps || pmult(a.e, b) < -eps || pmult(b.s, a) < -eps || pmult(b.e, a) < -eps;
	}
	return 0;
}
bool ok(int s, int e)
{
	int i;
	for (i = s; i < e; i++)
	{
		if (contra(tl, le[i]))
		{
			return 0;
		}
	}
	return 1;
}
void disp(int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		le[i].disp();
	}
	printf("----\n");
}
void dfs(int loc, int last, double ar, double len)
{
	if (loc == N - 1)
	{
		tl.s = pt[last];
		tl.e = pt[0];
		if (ok(1, loc - 1) && !collison(tl, le[0]) && !collison(tl, le[loc - 1]))
		{
			le[loc].s = pt[last];
			le[loc].e = pt[0];
			ar += le[loc].area();
			len += le[loc].len();
			if (ar < 0)
			{
				ar = -ar;
			}
			if (minarea < -0.5 || minarea > ar || f_abs(minarea - ar) < eps && len < L1)
			{
				minarea = ar;
				L1 = len;
			}
			if (L2 < -0.5 || L2 > len)
			{
				L2 = len;
			}
		}
		return;
	}
	int i;
	for (i = 1; i < N; i++)
	{
		if (mk[i])
		{
			continue;
		}
		tl.s = pt[last];
		tl.e = pt[i];
		if (!ok(0, loc - 1) || collison(tl, le[loc - 1]))
		{
			continue;
		}
		mk[i] = 1;
		le[loc] = tl;
		dfs(loc + 1, i, ar + tl.area(), len + tl.len());
		mk[i] = 0;
	}
}
void run()
{
	memset(mk, 0, sizeof(mk));
	minarea = L2 = -1;
	dfs(0, 0, 0, 0);
	printf("%.4lf\n", L1 - L2);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		get_data();
		run();
	}
	return 0;
}
