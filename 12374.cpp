#include <bits/stdc++.h>

using namespace std;

#define Fill(a, b) memset(a, b, sizeof(a))
#define Copy(a, b) memcpy(a, b, sizeof(b))
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define erep(j, a) for (Tedge *j = e[a]; j; j = j->next)
#define irep(i, a) for (__typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define pb push_back
#define mp make_pair
#define vec vector
#define sf scanf
#define pf printf
#define sz(x) int(x.size())
#define eps 1e-9
#define bit_cnt(x) __builtin_popcount(x)
#define sqr(a) ((a) * (a))

typedef long double ld;
typedef long long ll;
const ld EPS = 1e-9;
const ld DINF = 1e10;
inline int dcmp(const ld &a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }

const int MAXN = 20;

ld d[MAXN];

struct Tpoint
{
	ld x, y;
	Tpoint() { x = y = 0; }
	Tpoint(ld _x, ld _y) : x(_x), y(_y) {}
	Tpoint operator+(const Tpoint &a) const
	{
		return Tpoint(x + a.x, y + a.y);
	}
	Tpoint operator-(const Tpoint &a) const
	{
		return Tpoint(x - a.x, y - a.y);
	}
	Tpoint operator*(const ld &k) const
	{
		return Tpoint(x * k, y * k);
	}
	Tpoint operator/(const ld &k) const
	{
		return Tpoint(x / k, y / k);
	}
	Tpoint &operator=(const Tpoint &a)
	{
		x = a.x, y = a.y;
		return *this;
	}
	bool operator<(const Tpoint &a) const
	{
		return dcmp(x - a.x) < 0 || (!dcmp(x - a.x) && dcmp(y - a.y) < 0);
	}
	bool operator==(const Tpoint &a) const
	{
		return !dcmp(x - a.x) && !dcmp(y - a.y);
	}
	bool operator!=(const Tpoint &a) const
	{
		return dcmp(x - a.x) || dcmp(y - a.y);
	}
} p[MAXN], np[MAXN], t[MAXN];

ld dist(const Tpoint &a, const Tpoint &b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

ld length(const Tpoint &a)
{
	return sqrt(sqr(a.x) + sqr(a.y));
}

struct Tline
{
	ld a, b, c;
	Tline() {}
	Tline(ld _a, ld _b, ld _c) : a(_a), b(_b), c(_c) {}
	Tline(ld x1, ld y1, ld x2, ld y2) : a(y1 - y2), b(x2 - x1), c(x1 * y2 - x2 * y1) {}
} l[MAXN], e[MAXN];

Tpoint intersect(const Tline &la, const Tline &lb)
{
	ld x = (la.b * lb.c - la.c * lb.b) / (la.a * lb.b - la.b * lb.a);
	ld y = (la.a * lb.c - la.c * lb.a) / (la.b * lb.a - la.a * lb.b);
	return Tpoint(x, y);
}

bool is_parallel(const Tline &la, const Tline &lb)
{
	return !dcmp(la.a * lb.b - la.b * lb.a);
}

bool input()
{
	ld sum = 0.0;
	rep(i, 1, 8)
	{
		cin >> p[i].x >> p[i].y;
		//sf("%Lf %Lf", &p[i].x, &p[i].y);
		//ll a,b;
		//sf("%lld.%lld",&a,&b);
		//p[i].x = (ld)a + (ld)b / 1e12;
		//sf("%lld.%lld",&a,&b);
		//p[i].y = (ld)a + (ld)b / 1e12;
		sum += p[i].x + p[i].y;
	}
	return dcmp(sum);
}

int main()
{
	cout << fixed << setprecision(12);
	while (input())
	{
		Tpoint p1, p0, dp;
		rep(i, 1, 4) p1 = p1 + p[i];
		rep(i, 5, 8) p0 = p0 + p[i];
		p1 = p1 / 4.0;
		p0 = p0 / 4.0;
		dp = p0 - p1;
		ld len = 4.0 * length(dp);
		if (!dcmp(len))
		{
			rep(i, 1, 4) cout << p[i].x << " " << p[i].y << endl;
		}
		else
		{
			rep(i, 1, 4) l[i] = Tline(dp.y, -dp.x, dp.x * p[i].y - p[i].x * dp.y);
			p[9] = p[5];
			rep(i, 5, 8) e[i - 4] = Tline(p[i].x, p[i].y, p[i + 1].x, p[i + 1].y);
			rep(i, 1, 4)
			{
				d[i] = DINF;
				rep(j, 1, 4) if (!is_parallel(l[i], e[j]))
				{
					Tpoint q = intersect(l[i], e[j]);
					if (dcmp((q.x - p[i].x) * dp.x) > 0)
					{
						if (dcmp(d[i] - dist(q, p[i])) > 0)
							d[i] = dist(q, p[i]), t[i] = q;
					}
				}
			}
			//#define debug
			//#ifdef debug
			//rep (i, 1, 4) cout << t[i].x << " " << t[i].y << endl;
			//#endif

			rep(i, 1, 4) np[i] = p[i];
			rep(i, 1, 4)
			{
				if (dcmp(d[i] - len) >= 0)
				{
					np[i] = np[i] + dp / length(dp) * len;
					break;
				}
				else
				{
					np[i] = t[i];
					len -= d[i];
				}
			}
			rep(i, 1, 4) cout << np[i].x << " " << np[i].y << endl;
			//#define debug
			//#ifdef debug
			//ld sum = 0.0;
			//rep (i, 1, 4) sum += dist(np[i], p[i]);
			//cout << sum << " " << 4.0 * length(dp) << endl;
			//#endif
		}
		cout << endl;
	}
	return 0;
}
