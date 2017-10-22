#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;
const double INF = 1e30;

int dcmp(double x)
{
	if (x < -eps)
		return -1;
	return x > eps;
}

struct point
{
	double x, y;
	point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
	double len()
	{
		return sqrt(x * x + y * y);
	}
	point nor()
	{
		double L = len();
		return point(x / L, y / L);
	}
	bool operator<(const point r) const
	{
		if (dcmp(x - r.x))
			return x < r.x;
		return y < r.y;
	}
} p[1000], O;

int N;
double v1, v2;

double cross(point &k, point &a, point &b)
{
	return (a.x - k.x) * (b.y - k.y) - (a.y - k.y) * (b.x - k.x);
}

double dot(point &k, point &a, point &b)
{
	return (a.x - k.x) * (b.x - k.x) + (a.y - k.y) * (b.y - k.y);
}

bool onSeg(point k, point p1, point p2)
{
	return dcmp(cross(k, p1, p2)) == 0 &&
				 dcmp(dot(k, p1, p2)) <= 0;
}

bool inPoly(point cp)
{
	int i, j, k, d1, d2, w = 0;
	for (i = 0; i < N; ++i)
	{
		if (onSeg(cp, p[i], p[i + 1]))
			return 0;
		k = dcmp(cross(p[i], p[i + 1], cp));
		d1 = dcmp(p[i].y - cp.y);
		d2 = dcmp(p[i + 1].y - cp.y);
		if (k > 0 && d1 <= 0 && d2 > 0)
			w++;
		if (k < 0 && d2 <= 0 && d1 > 0)
			w--;
	}
	return w != 0;
}

int inter(point &a1, point &a2, point &b1, point &b2, point &k)
{
	double u = cross(a1, a2, b1), v = cross(a2, a1, b2);
	if (dcmp(u + v))
	{
		k = point((b1.x * v + b2.x * u) / (v + u), (b1.y * v + b2.y * u) / (v + u));
		return 1;
	}
	if (dcmp(u) || dcmp(cross(b1, b2, a1)))
		return 0;
	return -1;
}

double dis(point &a, point &b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

point tmp[1000];
bool ok(point a, point b)
{
	point k;
	int i, d, e = 0;
	tmp[e++] = a, tmp[e++] = b;
	for (i = 0; i < N; ++i)
	{
		d = inter(a, b, p[i], p[i + 1], k);
		if (d == 1 && dcmp(dot(k, a, b)) <= 0)
			tmp[e++] = k;
	}
	sort(tmp, tmp + e);
	for (i = 1; i < e; ++i)
		if (inPoly(point((tmp[i - 1].x + tmp[i].x) / 2, (tmp[i - 1].y + tmp[i].y) / 2)))
			return 0;

	return 1;
}

double d[200][200];
double len[1000], per;
void init()
{
	per = 0;
	p[N] = p[0];
	p[N + 1] = O;
	for (int i = 0; i < N; ++i)
	{
		len[i] = dis(p[i], p[i + 1]);
		per += len[i];
	}
	for (int i = 1; i <= N + 1; ++i)
	{
		d[i][i] = 0;
		for (int j = i + 1; j <= N + 1; ++j)
		{
			if (ok(p[i], p[j]))
				d[i][j] = d[j][i] = dis(p[i], p[j]);
			else
				d[i][j] = d[j][i] = INF;
		}
	}
}

bool vis[200];
double h[200];
bool chk(double tim)
{
	double S = fmod(tim * v1, per);
	point t;
	int i, j, k;

	for (i = 0; i < N; ++i)
	{
		if (len[i] < S)
			S -= len[i];
		else
		{
			t = point(p[i + 1].x - p[i].x, p[i + 1].y - p[i].y).nor();
			p[N + 2] = point(p[i].x + t.x * S, p[i].y + t.y * S);
			break;
		}
	}

	d[N + 2][N + 2] = 0;
	for (i = 1; i <= N + 1; ++i)
	{
		if (ok(p[i], p[N + 2]))
			d[i][N + 2] = d[N + 2][i] = dis(p[i], p[N + 2]);
		else
			d[i][N + 2] = d[N + 2][i] = INF;
	}

	if (d[N + 2][N + 1] > 1e28)
	{
		for (i = 1; i <= N + 2; ++i)
		{
			vis[i] = 0;
			h[i] = INF;
		}
		h[N + 2] = 0;

		while (1)
		{
			S = INF, j = -1;
			for (i = 1; i <= N + 2; ++i)
				if (!vis[i])
				{
					if (h[i] < S)
						S = h[i], j = i;
				}

			if (j == N + 1)
				break;

			vis[j] = 1;
			for (i = 1; i <= N + 2; ++i)
				if (!vis[i])
					h[i] = min(h[i], h[j] + d[j][i]);
		}
	}
	else
		h[N + 1] = d[N + 2][N + 1];

	return h[N + 1] / v2 <= tim;
}

int main()
{
	int cases = 1;
	int i, j, k;
	double ll, rr, mid, t;

	while (scanf("%d", &N), N)
	{
		for (i = 0; i < N; ++i)
			scanf("%lf %lf", &p[i].x, &p[i].y);
		scanf("%lf %lf", &O.x, &O.y);
		scanf("%lf %lf", &v1, &v2);

		init();

		ll = 0, rr = 1e8;
		while (rr - ll > eps)
		{
			mid = (ll + rr) / 2;
			if (chk(mid))
				rr = mid;
			else
				ll = mid;
		}

		chk(5);
		mid = (ll + rr) * 30;
		k = (int)(mid + 0.5 + eps);
		printf("Case %d: Time = %d:%02d\n", cases++, k / 60, k % 60);
	}

	return 0;
}
