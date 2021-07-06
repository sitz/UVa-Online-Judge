#include <bits/stdc++.h>

using namespace std;

#define FR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR(i, n) FR(i, 0, n)
#define CLR(x, a) memset(x, a, sizeof(x))
#define setmax(a, b) a = max(a, b)
#define PB push_back
#define BEND(v) (v).begin(), (v).end()
#define MP make_pair
#define A first
#define B second
#define FORALL(i, v) for (typeof((v).end()) i = (v).begin(); i != (v).end(); ++i)
#define X real()
#define Y imag()
typedef long long ll;
typedef complex<ll> cpx;

int n, m;
int as[1000], bs[1000], cs[1000], xs[1000], ys[1000], zs[1000];
bool known[1000];
cpx pts[1000];
void put(int i, int x, int y)
{
	assert(!known[i]);
	known[i] = 1;
	pts[i] = cpx(x, y);
}
void doit()
{
	scanf("%d%d", &n, &m);
	if (n == 0)
	{
		exit(0);
	}
	FOR(i, n)
	{
		scanf("%d%d%d%d%d%d", &as[i], &bs[i], &cs[i], &xs[i], &ys[i], &zs[i]);
		--as[i];
		--bs[i];
		--cs[i];
	}
	CLR(known, 0);
	put(0, 0, 0);
	put(1, 0, 1);
	put(2, 1, 0);
	while (1)
	{
		bool done = 1;
		FOR(i, n)
		{
			int nk = known[as[i]] + known[bs[i]] + known[cs[i]];
			if (nk == 2)
			{
				done = 0;
				while (known[bs[i]])
				{
					swap(as[i], cs[i]);
					swap(as[i], bs[i]);
					swap(xs[i], zs[i]);
					swap(xs[i], ys[i]);
				}
				int a = as[i], b = bs[i], c = cs[i];
				cpx p = pts[a], q = pts[c];
				for (ll dx = 0; dx * dx <= xs[i]; ++dx)
				{
					ll dy = ll(sqrt(xs[i] - dx * dx) + 0.5);
					if (dx * dx + dy * dy != xs[i])
					{
						continue;
					}
					FOR(zz, 2)
					{
						dx *= -1;
						FOR(zzz, 2)
						{
							dy *= -1;
							cpx r = p + cpx(dx, dy);
							assert(xs[i] == norm(p - r));
							if (ys[i] == norm(q - r) && (conj(q - r) * (r - p)).Y < 0)
							{
								put(b, r.X, r.Y);
							}
						}
					}
				}
				assert(known[b]);
			}
		}
		if (done)
		{
			break;
		}
	}
	FOR(i, m)
	{
		printf("%lld %lld\n", pts[i].X, pts[i].Y);
	}
}

const int MULTICASE = 1;
int main()
{
	do
	{
		doit();
	} while (MULTICASE);
	return 0;
}
