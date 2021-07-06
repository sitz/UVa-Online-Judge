#include <bits/stdc++.h>

using namespace std;

#define db double
#define rt return
#define cs const

cs db eps = 1e-8, PI = acos(-1.);

inline int sig(db x)
{
	rt(x > eps) - (x < -eps);
}

#define cp const P &
#define op operator

struct P
{
	db x, y, z;
	P(db a = 0, db b = 0, db c = 0) : x(a), y(b), z(c) {}
	void in()
	{
		scanf("%lf%lf%lf", &x, &y, &z);
	}
	P op + (cp a)cs { rt P(x + a.x, y + a.y, z + a.z); }
	P op - (cp a)cs { rt P(x - a.x, y - a.y, z - a.z); }
	P op *(cs db &k)cs { rt P(x * k, y * k, z * k); }
	P op ^ (cp a)cs { rt P(y * a.z - a.y * z, z * a.x - a.z * x, x * a.y - a.x * y); }
	db op *(cp a)cs { rt x *a.x + y *a.y + z *a.z; }
	db dot(P a, P b)
	{
		rt(a - *this) * (b - *this);
	}
	P cross(P a, P b)
	{
		rt a - *this ^ b - *this;
	}
	db L()
	{
		rt sqrt(x * x + y * y + z * z);
	}
	db dis_line(P a, P b)
	{
		rt cross(a, b).L() / (a - b).L();
	}
	db dis_seg(P a, P b)
	{
		if (sig(a.dot(*this, b)) < 0)
		{
			rt(a - *this).L();
		}
		if (sig(b.dot(*this, a)) < 0)
		{
			rt(b - *this).L();
		}
		rt dis_line(a, b);
	}
	void out()
	{
		printf("(%f,%f,%f)\n", x + eps, y + eps, z + eps);
	}
};

P calc(P a, P v, db agl)
{
	agl = agl * PI / 180.;
	db c = cos(agl), s = sin(agl);
	db x = v.x, y = v.y, z = v.z, l = v.L();
	x /= l, y /= l, z /= l;
	db m[3][3];
	m[0][0] = c + x * x * (1. - c);
	m[0][1] = x * y * (1. - c) - z * s;
	m[0][2] = x * z * (1. - c) + y * s;
	m[1][0] = x * y * (1. - c) + z * s;
	m[1][1] = c + y * y * (1. - c);
	m[1][2] = y * z * (1. - c) - x * s;
	m[2][0] = x * z * (1. - c) - y * s;
	m[2][1] = y * z * (1. - c) + x * s;
	m[2][2] = c + z * z * (1. - c);
	P res;
	res.x = a.x * m[0][0] + a.y * m[0][1] + a.z * m[0][2];
	res.y = a.x * m[1][0] + a.y * m[1][1] + a.z * m[1][2];
	res.z = a.x * m[2][0] + a.y * m[2][1] + a.z * m[2][2];
	rt res;
}

void solve(int cas)
{
	P start, goal, cur, dir, X, Y, Z;
	int n;
	scanf("%d", &n);
	start.in(), goal.in();
	dir = P(1., 0, 0);
	X = P(1., 0, 0), Y = P(0, 1., 0), Z = P(0, 0, 1.);
	db mn = (start - goal).L(), mx = mn;
	for (int i = 0; i < n; i++)
	{
		char str[15];
		db d;
		scanf("%s%lf", str, &d);
		switch (str[0])
		{
		case 'F':
		{
			cur = start + dir * d;
			mn = min(mn, goal.dis_seg(start, cur));
			mx = max(mx, (goal - cur).L());
			start = cur;
			break;
		}
		case 'P':
		{
			dir = calc(dir, Y, -d);
			X = calc(X, Y, -d);
			Z = X ^ Y;
			break;
		}
		case 'R':
		{
			dir = calc(dir, X, d);
			Y = calc(Y, X, d);
			Z = X ^ Y;
			break;
		}
		case 'Y':
		{
			dir = calc(dir, Z, -d);
			X = calc(X, Z, -d);
			Y = Z ^ X;
			break;
		}
		}
	}
	printf("Case %d: %.10lf %.10lf\n", cas, mn, mx);
}

int main()
{
	int T, cas = 1;
	scanf("%d", &T);
	while (T--)
	{
		solve(cas++);
	}
	rt 0;
}
