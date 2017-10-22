#include <bits/stdc++.h>

using namespace std;

const int maxn = 55;
const int maxd = 3000;
const double zero = 1e-9;
int n, timer, lenl, ans, tc;
int pos[maxn * maxn], now[maxn], p[maxn];
struct things
{
	double t;
	int num1, num2;
	things() {}
	things(double t, int num1, int num2) : t(t), num1(num1), num2(num2) {}
};
std::vector<things> q;
bool operator<(things a, things b)
{
	return a.t - b.t < -zero;
}
struct points
{
	double x, y, z, dx, dy, dz;
	void scan1()
	{
		scanf("%lf%lf%lf%lf%lf%lf", &x, &y, &z, &dx, &dy, &dz);
	}
} dat[maxn];
struct lines
{
	double a, b, c;
	int x, y;
} l[maxd];
bool operator<(lines x, lines y)
{
	return x.c - y.c < -zero;
}
inline double cfsqr(double x)
{
	return x * x;
}
inline double cfabs(double x)
{
	if (x > zero)
	{
		return x;
	}
	if (x < -zero)
	{
		return -x;
	}
	return 0;
}
inline int getp(int x)
{
	int t = x, t1;
	while (p[t] != t)
	{
		t = p[t];
	}
	while (x != t)
	{
		t1 = p[x];
		p[x] = t;
		x = t1;
	}
	return t;
}
int main()
{
	//	freopen("12a.in", "r", stdin);
	//	freopen("12a.out", "w", stdout);
	tc = 0;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			dat[i].scan1();
		}
		q.clear();
		lenl = 0;
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
			{
				//sigma ((dat[i].dx - dat[j].dx)*t+(dat[i].x-dat[j].x))^2
				lenl++;
				l[lenl].a = cfsqr((dat[i].dx - dat[j].dx)) + cfsqr(dat[i].dy - dat[j].dy) + cfsqr(dat[i].dz - dat[j].dz);
				l[lenl].b = 2 * ((dat[i].dx - dat[j].dx) * (dat[i].x - dat[j].x) + (dat[i].dy - dat[j].dy) * (dat[i].y - dat[j].y) + (dat[i].dz - dat[j].dz) * (dat[i].z - dat[j].z));
				l[lenl].c = cfsqr((dat[i].x - dat[j].x)) + cfsqr(dat[i].y - dat[j].y) + cfsqr(dat[i].z - dat[j].z);
				l[lenl].x = i;
				l[lenl].y = j;
			}
		std::sort(l + 1, l + lenl + 1);
		for (int i = 1; i < lenl; i++)
			for (int j = i + 1; j <= lenl; j++)
			{
				int p1 = i, q1 = j;
				if (l[p1].a - l[q1].a < -zero)
				{
					p1 = j, q1 = i;
				}
				double ta, tb, tc, delta, t1, t2;
				ta = l[p1].a - l[q1].a;
				tb = l[p1].b - l[q1].b;
				tc = l[p1].c - l[q1].c;
				if (cfabs(ta) < zero)
				{
					if (cfabs(tb) < zero)
					{
						continue;
					}
					if (tb > zero)
					{
						p1 ^= q1 ^= p1 ^= q1;
						tb = -tb;
						tc = -tc;
					}
					if (tc > zero)
					{
						q.push_back(things(-tc / tb, p1, q1));
					}
					continue;
				}
				delta = tb * tb - 4 * ta * tc;
				if (delta < zero)
				{
					continue;
				}
				delta = sqrt(delta);
				t1 = -(tb + delta) / (2 * ta);
				t2 = (delta - tb) / (2 * ta);
				if (t1 > zero)
				{
					q.push_back(things(t1, p1, q1));
				}
				if (t2 > zero)
				{
					q.push_back(things(t2, q1, p1));
				}
			}
		for (int i = 1; i <= n; i++)
		{
			p[i] = i;
		}
		for (int i = 1; i <= lenl; i++)
		{
			pos[i] = 0;
		}
		for (int i = 1, j = 0; i <= lenl && j < n - 1; i++)
		{
			int x = getp(l[i].x), y = getp(l[i].y);
			if (x != y)
			{
				now[pos[i] = ++j] = i;
				p[x] = y;
			}
		}
		std::sort(&q[0], &q[q.size()]);
		ans = 1;
		for (int i = 0; i < q.size(); i++)
		{
			//			printf("%.6lf %d %d\n", q[i].t, q[i].num1, q[i].num2);
			if (pos[q[i].num2] && (!pos[q[i].num1]))
			{
				for (int j = 1; j <= n; j++)
				{
					p[j] = j;
				}
				for (int j = 1; j < n; j++)
					if (j != pos[q[i].num2])
					{
						int x = getp(l[now[j]].x), y = getp(l[now[j]].y);
						if (x != y)
						{
							p[x] = y;
						}
					}
				int x = getp(l[q[i].num1].x), y = getp(l[q[i].num1].y);
				if (x != y)
				{
					ans++;
					now[pos[q[i].num1] = pos[q[i].num2]] = q[i].num1;
					pos[q[i].num2] = 0;
				}
				continue;
			}
		}
		printf("Case %d: %d\n", ++tc, ans);
	}
	return 0;
}
