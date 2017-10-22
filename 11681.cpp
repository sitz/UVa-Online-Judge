#include <bits/stdc++.h>

using namespace std;

#define fr(a, b, c) for (int a = b; a < c; a++)
#define rp(a, b) fr(a, 0, b)

typedef long long ll;

const double eps = 1e-8;
const double pi = acos(-1.0);

int cmp(double a, double b = 0)
{
	if (fabs(a - b) < eps)
		return 0;
	else if (a < b)
		return -1;
	return 1;
}

struct PT
{
	double x, y;

	PT() {}
	PT(double x, double y) : x(x), y(y) {}

	PT operator+(const PT &q) const { return PT(x + q.x, y + q.y); }
	PT operator-(const PT &q) const { return PT(x - q.x, y - q.y); }
	PT operator*(double t) const { return PT(x * t, y * t); }
	PT operator/(double t) const { return PT(x / t, y / t); }
	PT operator-() const { return PT(-x, -y); }
	PT operator[](double t) const { return PT(x * cos(t) - y * sin(t), x * sin(t) + y * cos(t)); }
	double operator*(const PT &q) const { return x * q.x + y * q.y; }
	double operator%(const PT &q) const { return x * q.y - y * q.x; }
	double operator!() const { return sqrt(x * x + y * y); }
	double operator^(const PT &q) const { return atan2(*this % q, *this * q); }
	double operator>(const PT &q) const { return ((*this * q) / (q * q)); }
} p[100];

bool segSegIntersect(PT a, PT b, PT c, PT d, PT &p)
{
	if (cmp((d - c) % (b - a)) == 0)
		return 0;
	p = c + (d - c) * (((b - a) % (c - a)) / ((d - c) % (b - a)));
	return 1;
}

PT circumcenter(PT a, PT b, PT c)
{
	PT a1 = (a + b) / 2.0;
	PT b1 = a1 + ((b - a)[pi / 2.0]);
	PT a2 = (b + c) / 2.0;
	PT b2 = a2 + ((c - b)[pi / 2.0]);
	PT center;
	segSegIntersect(a1, b1, a2, b2, center);
	return center;
}

int n;
PT c;
ll tstMask[70000], mask;
int sz;
double tstRay[70000], r;
double ans;

bool in_circle(PT a, PT c, double r)
{
	return cmp(!(a - c), r) <= 0;
}

void teste()
{
	PT centro;
	double raio = 0.0;
	rp(_, sz)
	{
		mask = tstMask[_];
		centro = PT(0.0, 0.0);
		raio = 0.0;
		fr(i, 0, n) if (((mask >> i) & 1) && !in_circle(p[i], centro, raio))
		{
			centro = p[i];
			fr(j, 0, i) if (((mask >> j) & 1) && !in_circle(p[j], centro, raio))
			{
				centro = (p[i] + p[j]) / 2.0;
				raio = (!(p[i] - p[j])) / 2.0;
				fr(k, 0, j) if (((mask >> k) & 1) && !in_circle(p[k], centro, raio))
				{
					centro = circumcenter(p[i], p[j], p[k]);
					raio = !(p[k] - centro);
				}
			}
		}
		ans = min(ans, max(tstRay[_], raio));
	}
}

int main()
{
	while (scanf("%d", &n) == 1 && n > 0)
	{
		rp(i, n) scanf("%lf%lf", &p[i].x, &p[i].y);
		sz = 0;
		ans = 1e100;

		fr(i, 0, n) fr(j, i + 1, n)
		{
			c = (p[i] + p[j]) / 2.0;
			r = (!(p[i] - p[j])) / 2.0;
			mask = 0;
			fr(l, 0, n) if (!in_circle(p[l], c, r)) mask |= (1LL << l);
			if (__builtin_popcount(mask) <= 1)
				ans = min(ans, r);
			else
				tstMask[sz] = mask, tstRay[sz++] = r;
		}

		fr(i, 0, n) fr(j, i + 1, n) fr(k, j + 1, n)
		{
			if (cmp((p[j] - p[i]) % (p[k] - p[i])) == 0)
				continue;
			c = circumcenter(p[i], p[j], p[k]);
			r = !(p[i] - c);
			mask = 0;
			fr(l, 0, n) if (!in_circle(p[l], c, r)) mask |= (1LL << l);
			if (__builtin_popcount(mask) <= 1)
				ans = min(ans, r);
			else
				tstMask[sz] = mask, tstRay[sz++] = r;
		}
		teste();
		printf("%.2lf\n", ans);
	}
	return 0;
}
