#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define EQ(a, b) (fabs(a - b) < eps)
#define EQV(a, b) (EQ(real(a), real(b)) && EQ(imag(a), imag(b)))
#define ALL(C) (C).begin(), (C).end()
#define pb push_back
#define mp make_pair

typedef complex<double> P;
typedef pair<P, P> Line;

const double eps = 1e-10;
const double pi = acos(-1);

const int N = 1000 * 1000 * 2 * 2;
Line L, U, B, R;
vector<int> edge[N];
bool vis[N];

namespace std
{
	bool operator<(const P &a, const P &b)
	{
		if (!EQ(real(a), real(b)))
		{
			return real(a) < real(b);
		}
		if (!EQ(imag(a), imag(b)))
		{
			return imag(a) < imag(b);
		}
		return false;
	}
	bool operator==(const P &a, const P &b)
	{
		return EQV(a, b);
	}
}

int get_idx(P a, map<P, int> &M, vector<P> &all)
{
	int index = M.size();
	if (M.find(a) == M.end())
	{
		M[a] = index, all.pb(a);
	}
	return M[a];
}

pair<double, double> check(double dx, double dy, double rx, double ry, double r, bool &flag)
{
	double a = (dx * dx + dy * dy), b = -2 * rx * dx - 2 * ry * dy, c = rx * rx + ry * ry - r * r;
	double D = b * b - 4 * a * c;
	if (D < 0)
	{
		flag = false;
	}
	else
	{
		flag = true;
		return mp((-b - sqrt(D)) / (2 * a), (-b + sqrt(D)) / (2 * a));
	}
}

bool isp(P a, P b, P c)
{
	return abs(a - c) + abs(b - c) < abs(a - b) + eps;
}

int is_intersected_circle(P &a, P &b, double r1, double r2)
{
	double d = abs(a - b);
	if (d < eps && abs(r1 - r2) < eps)
	{
		return 3;
	}
	if (d + r2 < r1)
	{
		return 0;
	}
	if (d + r1 < r2)
	{
		return 1;
	}
	if (d > r1 + r2)
	{
		return 4;
	}
	return 2;
}

pair<P, P> CC_intersection(P a, P b, double r1, double r2)
{
	double l, m, n;
	double d = abs(a - b);
	double x, y;
	double p, q;
	l = (d * d - r2 * r2 + r1 * r1) / (2 * d);
	x = a.real() + (b.real() - a.real()) * l / d;
	y = a.imag() + (b.imag() - a.imag()) * l / d;
	n = sqrt(r1 * r1 - l * l);
	p = (b.imag() - a.imag()) / d * n;
	q = (b.real() - a.real()) / d * n;
	return mp(P(x + p, y - q), P(x - p, y + q));
}

void sorting(vector<int> &a, vector<P> &all, map<P, int> &M)
{
	vector<P> tmp(a.size());
	rep(i, tmp.size()) tmp[i] = all[a[i]];
	sort(ALL(tmp));
	rep(i, tmp.size()) a[i] = get_idx(tmp[i], M, all);
}

void proc_line(int n, P *in, double *r, map<P, int> &M,
									vector<P> &all, vector<int> &s, vector<int> &g,
									vector<int> &top, vector<int> &bottom,
									vector<int> *cp)
{
	bottom.pb(get_idx(B.first, M, all));
	bottom.pb(get_idx(B.second, M, all));
	top.pb(get_idx(U.first, M, all));
	top.pb(get_idx(U.second, M, all));
	s.pb(get_idx(L.first, M, all));
	s.pb(get_idx(L.second, M, all));
	g.pb(get_idx(R.first, M, all));
	g.pb(get_idx(R.second, M, all));
	rep(i, n)
	{
		bool flag;
		P ins[2];
		pair<double, double> tmp;
		tmp = check(1, 0, in[i].real() - B.first.real(), in[i].imag() - B.first.imag(), r[i], flag);
		if (flag)
		{
			ins[0] = P(tmp.first, B.first.imag());
			ins[1] = P(tmp.second, B.first.imag());
			rep(j, 2)
			{
				if (isp(B.first, B.second, ins[j]))
				{
					bottom.pb(get_idx(ins[j], M, all));
					cp[i].pb(get_idx(ins[j], M, all));
				}
			}
		}
		tmp = check(1, 0, in[i].real() - U.first.real(), in[i].imag() - U.first.imag(), r[i], flag);
		if (flag)
		{
			ins[0] = P(tmp.first, U.first.imag());
			ins[1] = P(tmp.second, U.first.imag());
			rep(j, 2)
			{
				if (isp(U.first, U.second, ins[j]))
				{
					top.pb(get_idx(ins[j], M, all));
					cp[i].pb(get_idx(ins[j], M, all));
				}
			}
		}
		tmp = check(0, 1, in[i].real() - L.first.real(), in[i].imag() - L.first.imag(), r[i], flag);
		if (flag)
		{
			ins[0] = P(L.first.real(), tmp.first);
			ins[1] = P(L.first.real(), tmp.second);
			rep(j, 2)
			{
				if (isp(L.first, L.second, ins[j]))
				{
					s.pb(get_idx(ins[j], M, all));
					cp[i].pb(get_idx(ins[j], M, all));
				}
			}
		}
		tmp = check(0, 1, in[i].real() - R.first.real(), in[i].imag() - R.first.imag(), r[i], flag);
		if (flag)
		{
			ins[0] = P(R.first.real(), tmp.first);
			ins[1] = P(R.first.real(), tmp.second);
			rep(j, 2)
			{
				if (isp(R.first, R.second, ins[j]))
				{
					g.pb(get_idx(ins[j], M, all));
					cp[i].pb(get_idx(ins[j], M, all));
				}
			}
		}
	}
	sorting(bottom, all, M);
	sorting(top, all, M);
	sorting(s, all, M);
	sorting(g, all, M);
}

void proc_circle(int n, P *in, double *r, vector<int> *cp, map<P, int> &M,
										vector<P> &all)
{
	int ret = 0;
	rep(i, n)
	{
		rep(j, n)
		{
			if (is_intersected_circle(in[i], in[j], r[i], r[j]) == 2)
			{
				pair<P, P> cc = CC_intersection(in[i], in[j], r[i], r[j]);
				P ins[2] = {cc.first, cc.second};
				rep(k, 2)
				{
					if (ins[k].real() > 1000 || ins[k].imag() > 1000 ||
							ins[k].real() < 0 || ins[k].imag() < 0)
					{
						continue;
					}
					cp[i].pb(get_idx(ins[k], M, all));
				}
			}
		}
		vector<double> array(cp[i].size());
		rep(j, cp[i].size())
		{
			array[j] = arg(all[cp[i][j]] - in[i]);
		}
		sort(ALL(array));
		rep(j, array.size())
		{
			cp[i][j] = get_idx(in[i] + polar(r[i], array[j]), M, all);
		}
	}
}

void make_circle(int n, P *in, double *r, vector<int> *cp,
								 vector<P> &all)
{
	rep(i, n)
	{
		rep(j, cp[i].size())
		{
			double tmpa = arg(all[cp[i][j]] - in[i]), tmpb = arg(all[cp[i][(j + 1) % cp[i].size()]] - in[i]);
			if (tmpb < tmpa)
			{
				tmpb += 2 * pi;
			}
			double a = (tmpa + tmpb) / 2.;
			P c = polar(r[i], a) + in[i];
			bool flag = true;
			rep(k, n)
			{
				if (abs(in[k] - c) < r[k] - eps)
				{
					flag = false;
					break;
				}
			}
			if (c.real() > 1000 || c.imag() > 1000 ||
					c.real() < 0 || c.imag() < 0)
			{
				flag = false;
			}
			if (flag)
			{
				edge[cp[i][j]].pb(cp[i][(j + 1) % cp[i].size()]);
				edge[cp[i][(j + 1) % cp[i].size()]].pb(cp[i][j]);
			}
		}
	}
}

void make_line(int n, P *in, double *r, vector<int> &some, vector<P> &all)
{
	rep(i, some.size())
	{
		P a = all[some[i]];
		bool flag = true;
		rep(j, n)
		{
			if (abs(a - in[j]) + eps < r[j])
			{
				flag = false;
				break;
			}
		}
		if (i + 1 == some.size())
		{
			break;
		}
		P b = all[some[i + 1]];
		P mid = (a + b) / (double)2.;
		rep(j, n)
		{
			if (abs(mid - in[j]) + eps < r[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			edge[some[i]].pb(some[i + 1]);
			edge[some[i + 1]].pb(some[i]);
		}
	}
}

bool bfs(int s, vector<int> &g, vector<P> &all)
{
	if (vis[s])
	{
		return false;
	}
	queue<int> Q;
	Q.push(s);
	vis[s] = true;
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		rep(i, edge[now].size())
		{
			if (!vis[edge[now][i]])
			{
				vis[edge[now][i]] = true;
				Q.push(edge[now][i]);
			}
		}
	}
	rep(i, g.size())
	{
		if (vis[g[i]])
		{
			printf("%.2lf %.2lf %.2lf %.2lf\n",
				all[s].real(), all[s].imag(), all[g[i]].real(), all[g[i]].imag());
			return true;
		}
	}
	return false;
}

template <class T>
void op(T a, int n, vector<P> &all)
{
	rep(i, n)
	{
		cout << all[a[i]];
	}
	printf("\n");
}

void solve(int n)
{
	P in[n];
	double r[n];
	map<P, int> M;
	vector<P> all;
	vector<int> s, g, top, bottom;
	vector<int> cp[n];
	rep(i, n)
	{
		double re, im;
		scanf("%lf%lf%lf", &re,&im,&r[i]);
		in[i] = P(re,im);
	}
	proc_line(n, in, r, M, all, s, g, top, bottom, cp);
	proc_circle(n, in, r, cp, M, all);
	int node = M.size();
	rep(i, node)
	{
		vis[i] = false;
		edge[i].clear();
	}
	make_circle(n, in, r, cp, all);
	make_line(n, in, r, top, all);
	make_line(n, in, r, bottom, all);
	make_line(n, in, r, s, all);
	make_line(n, in, r, g, all);
	reverse(ALL(s));
	reverse(ALL(g));
	double anss = -1, ansg = -1;
	rep(i, s.size())
	{
		if (bfs(s[i], g, all))
		{
			return;
		}
	}
	printf("IMPOSSIBLE\n");
}

int main()
{
	U = mp(P(0, 1000), P(1000, 1000));
	B = mp(P(0, 0), P(1000, 0));
	L = mp(P(0, 0), P(0, 1000));
	R = mp(P(1000, 0), P(1000, 1000));
	int n;
	while (scanf("%d", &n) == 1)
	{
		solve(n);
	}
	return 0;
}
