#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1);

typedef complex<double> point;
typedef point vec;

#define X real()
#define Y imag()

struct line
{
	point s, t;
	double ang;
	line() {}
	line(point a, point b) : s(a), t(b), ang(arg(b - a)) {}
};

// basic
int dcmp(double x)
{
	return x < -eps ? -1 : x > eps;
}
bool zero(vec v)
{
	return !dcmp(v.X) && !dcmp(v.Y);
}

double sqr(double x)
{
	return x * x;
}
double dis(point a, point b)
{
	return abs(a - b);
}

double cross(vec a, vec b)
{
	return a.X * b.Y - a.Y * b.X;
}
double cross(point a, point b, point c)
{
	return cross(b - a, c - a);
}
double dot(vec a, vec b)
{
	return a.X * b.X + a.Y * b.Y;
}
double dot(point a, point b, point c)
{
	return dot(b - a, c - a);
}

vec dir(line ln)
{
	return ln.t - ln.s;
}
vec normal(vec v)
{
	return vec(-v.Y, v.X);
}
vec unit(vec v)
{
	return v / abs(v);
}

vec proj(vec v, vec n)
{
	return n * dot(v, n) / norm(n);
}
point proj(point p, line ln)
{
	return ln.s + proj(p - ln.s, dir(ln));
}
vec reflect(vec v, vec n)
{
	return proj(v, n) * 2.0 - v;
}
point reflect(point p, line ln)
{
	return ln.s + reflect(p - ln.s, dir(ln));
}

vec rotate(vec v, double a)
{
	return v * polar(1.0, a);
}
double angle(vec a, vec b)
{
	return arg(b / a);
}

// line
double len(line ln)
{
	return abs(ln.s - ln.t);
}

bool onseg(point p, line ln)
{
	return dcmp(cross(p, ln.s, ln.t)) == 0 && dcmp(dot(p, ln.s, ln.t)) <= 0;
}

double distoline(point p, line ln)
{
	return fabs(cross(p, ln.s, ln.t)) / len(ln);
}
double distoseg(point p, line ln)
{
	if (dcmp(dot(ln.s, ln.t, p)) <= 0)
	{
		return dis(p, ln.s);
	}
	if (dcmp(dot(ln.t, ln.s, p)) <= 0)
	{
		return dis(p, ln.t);
	}
	return distoline(p, ln);
}

bool inter(line a, line b, point &p)
{
	double s1 = cross(a.s, a.t, b.s);
	double s2 = cross(a.s, a.t, b.t);
	if (!dcmp(s1 - s2))
	{
		return false;
	}
	p = (s1 * b.t - s2 * b.s) / (s1 - s2);
	return true;
}

bool seginter(line a, line b, point &p) // strict
{
	double s1 = cross(a.s, a.t, b.s), s2 = cross(a.s, a.t, b.t);
	if ((dcmp(s1) ^ dcmp(s2)) != -2)
	{
		return false;
	}
	double s3 = cross(b.s, b.t, a.s), s4 = cross(b.s, b.t, a.t);
	if ((dcmp(s3) ^ dcmp(s4)) != -2)
	{
		return false;
	}
	p = (s1 * b.t - s2 * b.s) / (s1 - s2);
	return true;
}

const int maxn = 1000;

bool inhp(point p, line hp)
{
	return dcmp(cross(hp.s, hp.t, p)) > 0;
}

bool cmpang(line a, line b)
{
	return dcmp(a.ang - b.ang) ? a.ang < b.ang : cross(a.s, a.t, b.s) < 0;
}

void hpinter(line *q, int n, point *h, int &m)
{
	int head = 0, tail = 0;
	m = 0;
	sort(q, q + n, cmpang);
	for (int i = 1; i < n; ++i)
	{
		if (!dcmp(q[i].ang - q[i - 1].ang))
		{
			continue;
		}
		while (head < tail && !inhp(h[tail - 1], q[i]))
		{
			--tail;
		}
		while (head < tail && !inhp(h[head], q[i]))
		{
			++head;
		}
		q[++tail] = q[i];
		if (head < tail)
		{
			inter(q[tail - 1], q[tail], h[tail - 1]);
		}
	}
	while (head < tail && !inhp(h[tail - 1], q[head]))
	{
		--tail;
	}
	if (head < tail)
	{
		inter(q[tail], q[head], h[tail]);
	}
	for (int i = head; i <= tail; ++i)
	{
		h[m++] = h[i];
	}
}

line makehp(double a, double b, double c) // ax + by + c > 0
{
	point p1 = fabs(a) > fabs(b) ? point(-c / a, 0) : point(0, -c / b);
	point p2 = p1 + vec(b, -a);
	return line(p1, p2);
}

int u[maxn], v[maxn], w[maxn];
point tmp[maxn];
line q[maxn];
int n;

bool can(int t)
{
	bool ok = true;
	for (int i = 0; i < n; ++i)
		if (i != t && u[i] >= u[t] && v[i] >= v[t] && w[i] >= w[t])
		{
			ok = false;
			break;
		}
	if (!ok)
	{
		return false;
	}
	int cnt = 0, m;
	double k = 10000;
	for (int i = 0; i < n; ++i)
		if (i != t)
		{
			double a = (k / v[i] - k / w[i]) - (k / v[t] - k / w[t]);
			double b = (k / u[i] - k / w[i]) - (k / u[t] - k / w[t]);
			double c = k / w[i] - k / w[t];
			q[cnt++] = makehp(a, b, c);
		}
	q[cnt++] = line(point(0, 0), point(0, -1));
	q[cnt++] = line(point(0, 0), point(1, 0));
	q[cnt++] = line(point(0, 1), point(-1, 2));
	hpinter(q, cnt, tmp, m);
	return m >= 3;
}

int main()
{
	while (scanf("%d", &n) == 1 && n)
	{
		for (int i=0; i<n; ++i)
		{
			scanf("%d%d%d", &v[i], &u[i], &w[i]);
		}
		for (int i=0; i<n; ++i)
		{
			printf("%s\n", can(i) ? "Yes" : "No");
		}
	}
	return 0;
}
