#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-12;
const double PI = acos(-1);
int sgn(double x)
{
	return (x < -eps) ? -1 : (x > eps);
}

//2D PT
struct PT
{
	double x, y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}
	PT operator+(const PT o)
	{
		return PT(x + o.x, y + o.y);
	}
	PT operator-(const PT o)
	{
		return PT(x - o.x, y - o.y);
	}
	PT operator*(double s)
	{
		return PT(x * s, y * s);
	}
	PT operator/(double s)
	{
		return PT(x / s, y / s);
	}
	bool operator<(const PT &o) const
	{
		return x < o.x - eps || (x < o.x + eps && y < o.y - eps);
	}
	bool operator==(const PT &o) const
	{
		return !sgn(y - o.y) && !sgn(x - o.x);
	}
	bool operator!=(const PT &o) const
	{
		return sgn(y - o.y) || sgn(x - o.x);
	}
	void rd()
	{
		scanf("%lf %lf", &x, &y);
	}
	double ag()
	{
		return atan2(y, x);
	}
};

double cpr(PT a, PT b)
{
	return a.x * b.y - a.y * b.x;
}
double dpr(PT a, PT b)
{
	return a.x * b.x + a.y * b.y;
}

double cpr(PT a, PT b, PT c)
{
	return cpr(b - a, c - a);
}
double dpr(PT a, PT b, PT c)
{
	return dpr(b - a, c - a);
}

double vlen(PT a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}
double dist(PT a, PT b)
{
	return vlen(a - b);
}

//å¤ä¸¤ç¹abä¸ç´çº¿cdç¸å¯¹ä½ç½®, ç¹å¨ç´çº¿ä¸0, åä¾§1, å¼ä¾§-1
int plside(PT a, PT b, PT c, PT d)
{
	return sgn(cpr(c, a, d) * cpr(c, b, d));
}

//ç¹på°ç´çº¿abè·ç¦»
double disptoline(PT p, PT a, PT b)
{
	return fabs(cpr(p, a, b)) / dist(a, b);
}

//ç¹å°çº¿æ®µè·ç¦»
double disptoseg(PT p, PT a, PT b)
{
	PT t = p + PT(a.y - b.y, b.x - a.x);
	if (plside(a, b, p, t) == 1)
	{
		return min(dist(p, a), dist(p, b));
	}
	return disptoline(p, a, b);
}

//ç¹vç»çç¹péæ¶éæè½¬angleå¹¶æ¾å¤§scaleå
PT protate(PT v, PT p, double ag, double scale)
{
	PT t = PT(cos(ag), sin(ag)) * scale;
	v = v - p;
	p.x += v.x * t.x - v.y * t.y;
	p.y += v.x * t.y + v.y * t.x;
	return p;
}

int check(PT po, PT p[], int n)
{
	double q[5];
	for (int i = 0; i < n; i++)
	{
		q[i] = disptoseg(po, p[i], p[i + 1]);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (sgn(q[i] - q[j]) == 0)
			{
				return -1;
			}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (q[ans] > q[i])
		{
			ans = i;
		}
	return ans;
}

int work(PT p[], PT po)
{
	for (int i = 1; i < 15; i++)
	{
		int mark = check(po, p, i == 1 ? 3 : 4);
		if (mark == -1)
		{
			return 15;
		}
		if (cpr(p[mark], p[mark + 1], po) > eps)
		{
			return i;
		}
		p[0] = p[mark];
		p[4] = p[mark + 1];
		p[1] = p[0] + (p[4] - p[0]) / 3;
		p[3] = p[4] - (p[4] - p[0]) / 3;
		p[2] = protate(p[0], p[1], PI * 2 / 3, 1);
	}
	return 15;
}

int main()
{
	//freopen("1.txt", "r", stdin);
	int cas, T;
	for (cas = scanf("%d", &T); cas <= T; cas++)
	{
		PT p[4];
		for (int i = 0; i < 3; i++)
		{
			p[i].rd();
		}
		PT po;
		po.rd();
		if (cpr(p[0], p[1], p[2]) < eps)
		{
			reverse(p, p + 3);
		}
		p[3] = p[0];
		int ans = work(p, po);
		if (ans < 15)
		{
			printf("The bacterium destroys you within day %d. ESCAPE!!\n", ans);
		}
		else
		{
			puts("You are safe :)");
		}
	}
	return 0;
}
