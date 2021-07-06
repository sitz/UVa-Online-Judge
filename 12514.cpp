#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-6;
const double pi = acos(-1.);

inline int dcmp(double x)
{
	if (x < -eps)
		return -1;
	return x > eps;
}

struct point
{
	double x, y;
	bool operator<(const point rgh) const
	{
		if (dcmp(y - rgh.y))
			return y < rgh.y;
		return x < rgh.x;
	}
	bool operator==(const point rgh) const
	{
		return !dcmp(x - rgh.x) && !dcmp(y - rgh.y);
	}
	point(){};
	point(double _x, double _y) : x(_x), y(_y) {}
} L[100][2], p[3000], q[3000];

int hea[3000], nxt[3000000], vv[3000000], c, M;

double cross(point &k, point &a, point &b)
{
	return (a.x - k.x) * (b.y - k.y) - (a.y - k.y) * (b.x - k.x);
}

bool chk(point &k)
{
	if (dcmp(k.x) < 0 || dcmp(k.x - M) > 0)
		return 0;
	if (dcmp(k.y) < 0 || dcmp(k.y - M) > 0)
		return 0;
	return 1;
}

int inter(point &a1, point &a2, point &b1, point &b2, point &k)
{
	double u = cross(a1, a2, b1), v = cross(a2, a1, b2);
	if (dcmp(u + v))
	{
		k = point((b1.x * v + b2.x * u) / (v + u), (b1.y * v + b2.y * u) / (v + u));
		if (chk(k))
			return 1;
	}
	return 0;
}

int chip[505][505];
bool vis[5000];
double ans;

double cal(point &k, point &a, point &b)
{
	double x = atan2(b.y - k.y, b.x - k.x) - atan2(a.y - k.y, a.x - k.x);
	if (x < 0)
		x += 2 * pi;
	return x;
}

int sta[3000], top;
double ya[1000], yb[1000];

int tongji()
{
	int i, j, k, xa = 10000, xb = -10000;
	int xx, yy, cnt = 0;
	double t, xie;

	for (i = 0; i < top; ++i)
	{
		xa = min(xa, (int)(ceil(p[sta[i]].x) + eps));
		xb = max(xb, (int)(floor(p[sta[i]].x) + eps));
	}

	for (i = xa; i <= xb; ++i)
		ya[i] = 1e30, yb[i] = -1e30;

	for (i = 0; i < top; ++i)
		if (dcmp(p[sta[i]].x - p[sta[i + 1]].x))
		{
			xie = (p[sta[i + 1]].y - p[sta[i]].y) / (p[sta[i + 1]].x - p[sta[i]].x + 0.);
			xx = ceil(min(p[sta[i]].x, p[sta[i + 1]].x)) + eps;
			yy = floor(max(p[sta[i]].x, p[sta[i + 1]].x)) + eps;
			for (j = xx; j <= yy; ++j)
			{
				t = p[sta[i + 1]].y - xie * (p[sta[i + 1]].x - j);
				ya[j] = min(ya[j], t);
				yb[j] = max(yb[j], t);
			}
		}

	for (i = xa; i <= xb; ++i)
	{
		xx = ceil(ya[i]) + eps;
		yy = floor(yb[i]) + eps;
		for (j = xx; j <= yy; ++j)
			cnt += chip[i][j];
	}

	return cnt;
}

void solve(int x)
{
	int i, j, k;
	int a, b, c;
	double t, v;
	bool r;

	for (i = hea[x]; i >= 0; i = nxt[i])
	{
		r = 0;
		top = 0;
		a = x, b = vv[i];
		if (vis[b])
			continue;
		sta[top++] = a, sta[top++] = b;
		while (1)
		{
			v = -1e30;
			for (j = hea[b]; j >= 0; j = nxt[j])
				if (vv[j] != a)
				{
					c = vv[j];
					t = cal(p[b], p[a], p[c]);
					if (t > v)
						v = t, k = c;
				}

			if (dcmp(v - pi) <= 0)
				break;

			if (k == x)
			{
				r = 1;
				break;
			}
			if (vis[k])
				break;

			a = b, b = k;
			sta[top++] = k;
		}

		if (r)
		{
			sta[top] = sta[0];
			k = tongji();
			v = 0;
			for (j = 0; j < top; ++j)
				v += cross(p[sta[0]], p[sta[j]], p[sta[j + 1]]);
			v = fabs(v) * 0.5;
			ans = max(ans, k / v);
		}
	}

	vis[x] = 1;
}

int main()
{
	int C, N;
	int i, j, k, e;
	int a, b;
	point t;

	while (scanf("%d %d %d", &M, &C, &N), M)
	{
		c = 0;
		ans = 0;
		memset(hea, -1, sizeof(hea));
		memset(vis, 0, sizeof(vis));
		memset(chip, 0, sizeof(chip));

		for (i = 0; i < C; ++i)
		{
			scanf("%d %d", &a, &b);
			chip[a][b]++;
		}

		L[0][0] = point(0, 0), L[0][1] = point(M, 0);
		L[1][0] = point(M, 0), L[1][1] = point(M, M);
		L[2][0] = point(M, M), L[2][1] = point(0, M);
		L[3][0] = point(0, M), L[3][1] = point(0, 0);

		N += 4;
		for (i = 4; i < N; ++i)
			scanf("%lf %lf %lf %lf", &L[i][0].x, &L[i][0].y, &L[i][1].x, &L[i][1].y);

		for (i = 0; i <= M; ++i)
			for (j = 0; j <= M; ++j)
				if (chip[i][j])
				{
					t = point(i, j);
					for (k = 0; k < N; ++k)
					{
						if (dcmp(cross(t, L[k][0], L[k][1])))
							continue;
						chip[i][j] = 0;
						break;
					}
				}

		e = 0;
		for (i = 0; i < N; ++i)
			for (j = i + 1; j < N; ++j)
				if (inter(L[i][0], L[i][1], L[j][0], L[j][1], t))
					p[e++] = t;

		if (e >= 2800)
		{
			while (1)
				puts("x");
		}

		sort(p, p + e);
		e = unique(p, p + e) - p;

		for (i = 0; i < N; ++i)
		{
			k = 0;
			for (j = 0; j < N; ++j)
				if (i != j && inter(L[i][0], L[i][1], L[j][0], L[j][1], t))
					q[k++] = t;
			sort(q, q + k);
			k = unique(q, q + k) - q;

			for (j = 1; j < k; ++j)
			{
				a = lower_bound(p, p + e, q[j - 1]) - p;
				b = lower_bound(p, p + e, q[j]) - p;
				vv[c] = b, nxt[c] = hea[a], hea[a] = c++;
				vv[c] = a, nxt[c] = hea[b], hea[b] = c++;

				if (c >= 3000000)
				{
					while (1)
						puts("x");
				}
			}
		}

		for (i = 0; i < e; ++i)
			solve(i);

		printf("%.3lf\n", ans);
	}

	return 0;
}
