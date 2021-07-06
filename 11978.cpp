#include <bits/stdc++.h>

using namespace std;

const int MaxN = 20010;
const double PI = acos(-1.0);

struct point
{
	double x, y;
	point() {}
	point(double x, double y) : x(x), y(y) {}

	void input()
	{
		scanf("%lf %lf", &x, &y);
	}
} p[MaxN], q[MaxN], C;
double R, rat;
int N, pn;

const double eps = 1e-8;

int sgn(double x)
{
	return x < -eps ? -1 : x > eps;
}

point operator-(const point &a, const point &b)
{
	return point(a.x - b.x, a.y - b.y);
}

double operator*(const point &a, const point &b)
{
	return a.x * b.y - a.y * b.x;
}

double operator&(const point &a, const point &b)
{
	return a.x * b.x + a.y * b.y;
}

point operator+(const point &a, const point &b)
{
	return point(a.x + b.x, a.y + b.y);
}

point operator*(double k, const point &a)
{
	return point(k * a.x, k * a.y);
}

void Inter(point s, point t)
{
	point v = t - s;
	double delta = 4 * (s & v) * (s & v) - 4 * (v & v) * ((s & s) - R * R);
	if (sgn(delta) <= 0 || sgn(v & v) == 0)
	{
		return;
	}
	double k = (-2 * (s & v) - sqrt(delta)) / 2 / (v & v);
	if (sgn(k) > 0 && sgn(k - 1.0) < 0)
	{
		p[pn++] = s + k * v;
	}
	k = (-2 * (s & v) + sqrt(delta)) / 2 / (v & v);
	if (sgn(k) > 0 && sgn(k - 1.0) < 0)
	{
		p[pn++] = s + k * v;
	}
}

double cal_area(point s, point t)
{
	if (sgn((0.25 * (s + t) & (s + t)) - R * R) < 0)
	{
		return 0.5 * s * t;
	}
	else
	{
		double ang = atan2(t.y, t.x) - atan2(s.y, s.x);
		while (ang > PI)
		{
			ang -= 2 * PI;
		}
		while (ang < -PI)
		{
			ang += 2 * PI;
		}
		return 0.5 * R * R * ang;
	}
}

double solve()
{
	pn = 0;
	for (int i = 0; i < N; i++)
	{
		p[pn++] = q[i];
		Inter(q[i], q[i + 1]);
	}
	//	puts("debug  --- P");
	//	for(int i=0; i<pn; i++)
	//	{
	//		cout << p[i].x << " " << p[i].y << endl;
	//	}
	//	puts("");
	double ret = 0.0;
	p[pn] = p[0];
	for (int i = 0; i < pn; i++)
	{
		ret += cal_area(p[i], p[i + 1]);
	}
	return ret;
}

int main()
{
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			q[i].input();
		}
		C.input();
		for (int i = 0; i < N; i++)
		{
			q[i] = q[i] - C;
		}
		cin >> rat;
		rat /= 100.0;
		q[N] = q[0];
		double sum = 0.0;
		for (int i = 0; i < N; i++)
		{
			sum += q[i] * q[i + 1];
		}
		sum /= 2.0;
		//		cout << "sum  " << sum << endl;
		//
		//		R = 5.0;
		//		cout << solve() << endl;
		double low = 0.0, high = 1e4;
		for (int tim = 0; tim < 50; tim++)
		{
			R = (low + high) / 2;
			if (sgn(solve() / sum - rat) < 0)
			{
				low = R;
			}
			else
			{
				high = R;
			}
		}
		printf("Case %d: %.0f\n", cas, low);
	}
	return 0;
}
