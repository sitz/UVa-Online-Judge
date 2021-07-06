#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef complex<double> P;

const double eps = 1e-8;
const int RIGHT = 1, LEFT = -1;

double cross(P a, P b)
{
	return (a.real() * b.imag() - a.imag() * b.real());
}

double dot(P a, P b)
{
	return (a.real() * b.real() + a.imag() * b.imag());
}

bool isp(P a, P b, P c)
{
	return (abs(a - c) + abs(b - c) < abs(a - b) + eps);
}

double distance_l_p(P a, P b, P c)
{
	return abs(cross(b - a, c - a)) / abs(b - a);
}

double distance_ls_p(P a, P b, P c)
{
	if (dot(b - a, c - a) < 0)
	{
		return abs(c - a);
	}
	if (dot(a - b, c - b) < 0)
	{
		return abs(c - b);
	}
	return abs(cross(b - a, c - a)) / abs(b - a);
}

P intersection_ll(P a1, P a2, P b1, P b2)
{
	P a = a2 - a1, b = b2 - b1;
	return a1 + a * cross(b, b1 - a1) / cross(b, a);
}

int ccw(P a, P b)
{
	if (cross(a, b) < eps)
	{
		return RIGHT;
	}
	else if (cross(a, b) > -eps)
	{
		return LEFT;
	}
	return 2;
}

vector<P> ConvexCut(vector<P> &in, P a1, P a2)
{
	int n = in.size();
	vector<P> ret;
	rep(i, n)
	{
		P now = in[i], nxt = in[(i + 1) % n];
		if (ccw(a1 - a2, now - a2) == RIGHT)
		{
			ret.push_back(now);
		}
		if (ccw(a1 - a2, now - a2) * ccw(a1 - a2, nxt - a2) < 0)
		{
			ret.push_back(intersection_ll(a1, a2, now, nxt));
		}
	}
	return ret;
}

bool is_in(vector<P> &in, P a)
{
	int n = in.size();
	int cnt = 0;
	rep(i, n)
	{
		P cur = in[i] - a, nxt = in[(i + 1) % n] - a;
		if (cur.imag() > nxt.imag())
		{
			swap(cur, nxt);
		}
		if (cur.imag() < 0 && 0 <= nxt.imag() &&
				cross(nxt, cur) >= 0)
		{
			cnt++;
		}
		if (isp(in[i], in[(i + 1) % n], a))
		{
			return false;
		}
	}
	if (cnt % 2 == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

P symmetricPoint(P o, P p, P q)
{
	P N = p - o, L = q - o;
	double t = abs(L);
	N /= abs(N);
	L /= abs(L);
	double prepL = dot(N, L);//theta element of vector L against N (|L|=|N|=1
	double d = 2 * prepL;
	P r(d * N - L);//R vector symmetric point of L
	return o + t * r;
}

int main()
{
	int T;
	scanf("%d", &T);
	rep(t, T)
	{
		if (t)
		{
			printf("\n");
		}
		vector<vector<P>> all;
		vector<P> a;
		a.push_back(P(0, 0));
		a.push_back(P(100, 0));
		a.push_back(P(100, 100));
		a.push_back(P(0, 100));
		all.push_back(a);
		int step;
		scanf("%d", &step);
		rep(loop, step)
		{
			double re, im;
			scanf("%lf%lf", &re,&im);
			P p(re,im);
			scanf("%lf%lf", &re,&im);
			P q(re,im);
			vector<vector<P>> nxt;
			rep(i, all.size())
			{
				vector<P> tmp;
				tmp = ConvexCut(all[i], p, q);
				if (tmp.size() > 0)
				{
					nxt.push_back(tmp);
				}
				tmp = ConvexCut(all[i], q, p);
				rep(k, tmp.size())
				{
					if (distance_l_p(p, q, tmp[k]) < eps)
					{
						continue;
					}
					P tmp2 = symmetricPoint(p, q, tmp[k]);
					if (isnan(tmp2.real()) || isnan(tmp2.imag()))
					{
						assert(false);
					}
					tmp[k] = tmp2;
				}
				if (tmp.size() > 0)
				{
					nxt.push_back(tmp);
				}
			}
			all = nxt;
		}

		int q;
		scanf("%d", &q);
		rep(i, q)
		{
			double re, im;
			scanf("%lf%lf", &re,&im);
			P t(re,im);
			int cnt = 0;
			rep(j, all.size())
			{
				int n = all[j].size();
				bool isok = true;
				rep(k, all[j].size())
				{
					if (distance_l_p(all[j][k], all[j][(k + 1) % n], t) <= 0.000001)
					{
						isok = false;
						break;
					}
				}
				if (isok && is_in(all[j], t))
				{
					cnt++;
				}
			}
			printf("%d\n", cnt);
		}
	}
	return 0;
}
