#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-6;

struct Point
{
	double x, y;
	Point(double X = 0.0, double Y = 0.0) : x(X), y(Y) {}
	Point operator-(const Point &p) const
	{
		return Point(x - p.x, y - p.y);
	}
};

double cross(const Point &a, const Point &b)
{
	return a.x * b.y - a.y * b.x;
}
double dot(const Point &a, const Point &b)
{
	return a.x * b.x + a.y * b.y;
}

double angle(const Point &a, const Point &b)
{
	double cs = dot(a, b) / sqrt(dot(a, a)) / sqrt(dot(b, b));
	return acos(min(max(cs, -1.0), 1.0));
}

double area_intersect(double R, Point P[], int N)
{
	double ans = 0;
	for (int i = 0; i < N; i++)
	{
		Point A = P[i], B = P[(i + 1) % N];
		if (cross(A, B) < 0)
		{
			swap(A, B);
		}
		double a = dot(B - A, B - A), b = 2 * dot(A, B - A), c = dot(A, A) - R * R;
		if (fabs(a) < EPS)
		{
			continue;
		}
		double v[10];
		int k = 0;
		v[k++] = 0;
		v[k++] = 1;
		double det = b * b - 4 * a * c;
		if (det > EPS)
		{
			for (int sgn = -1; sgn <= 1; sgn += 2)
			{
				double t = (-b + sgn * sqrt(det)) / (2 * a);
				if (EPS < t && t < 1 - EPS)
				{
					v[k++] = t;
				}
			}
		}
		sort(v, v + k);
		Point Q[10];
		for (int i = 0; i < k; i++)
		{
			Q[i].x = A.x + v[i] * (B.x - A.x);
			Q[i].y = A.y + v[i] * (B.y - A.y);
		}
		for (int i = 0; i < k - 1; i++)
		{
			if (dot(Q[i], Q[i]) < R * R + EPS && dot(Q[i + 1], Q[i + 1]) < R * R + EPS)
			{
				ans += 0.5 * fabs(cross(Q[i], Q[i + 1]));
			}
			else
			{
				ans += 0.5 * R * R * angle(Q[i], Q[i + 1]);
			}
		}
	}
	return ans;
}

int main()
{
	double area_min;
	Point P[64];
	int N;
	for (int cs = 1; scanf("%d%lf", &N, &area_min) == 2 && N > 0; cs++)
	{
		for (int i = 0; i < N; i++)
		{
			scanf("%lf%lf", &P[i].x, &P[i].y);
		}
		P[N] = P[0];

		double area = 0.0;
		for (int i = 0; i < N; i++)
		{
			area += cross(P[i], P[i + 1]);
		}
		area = fabs(area / 2.0);

		double lo = sqrt(max(0.0, area_min / M_PI)), hi = 0.0;
		for (int i = 0; i < N; i++)
		{
			hi = max(hi, max(fabs(P[i].x), fabs(P[i].y)));
		}
		while (hi - lo > EPS)
		{
			double mid = (lo + hi) / 2.0;
			if (area_intersect(mid, P, N) < area_min)
			{
				lo = mid;
			}
			else
			{
				hi = mid;
			}
		}

		printf("Case %d: %.2lf\n", cs, lo);
	}
	return 0;
}
