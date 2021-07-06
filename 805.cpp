#include <bits/stdc++.h>

using namespace std;

#define eps 1e-10

struct Pt
{
	double x, y;
	Pt(double a = 0, double b = 0) : x(a), y(b) {}
	Pt operator-(const Pt &a) const
	{
		return Pt(x - a.x, y - a.y);
	}
	Pt operator+(const Pt &a) const
	{
		return Pt(x + a.x, y + a.y);
	}
	Pt operator*(const double a) const
	{
		return Pt(x * a, y * a);
	}
	bool operator==(const Pt &a) const
	{
		return fabs(x - a.x) < eps && fabs(y - a.y) < eps;
	}
	bool operator<(const Pt &a) const
	{
		if (fabs(x - a.x) > eps)
			return x < a.x;
		if (fabs(y - a.y) > eps)
			return y < a.y;
		return false;
	}
	double length()
	{
		return hypot(x, y);
	}
	void read()
	{
		scanf("%lf %lf", &x, &y);
	}
};
const double pi = acos(-1);
int cmpZero(double v)
{
	if (fabs(v) > eps)
		return v > 0 ? 1 : -1;
	return 0;
}
double dot(Pt a, Pt b)
{
	return a.x * b.x + a.y * b.y;
}
double cross(Pt o, Pt a, Pt b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
double cross2(Pt a, Pt b)
{
	return a.x * b.y - a.y * b.x;
}
int between(Pt a, Pt b, Pt c)
{
	return dot(c - a, b - a) >= -eps && dot(c - b, a - b) >= -eps;
}
int on_seg(Pt a, Pt b, Pt c)
{
	return between(a, b, c) && fabs(cross(a, b, c)) < eps;
}
struct Seg
{
	Pt s, e;
	int label;
	Seg(Pt a = Pt(), Pt b = Pt(), int l = 0) : s(a), e(b), label(l)
	{
	}
	bool operator!=(const Seg &other) const
	{
		return !((s == other.s && e == other.e) || (e == other.s && s == other.e));
	}
};
int intersection(Pt as, Pt at, Pt bs, Pt bt)
{
	if (cmpZero(cross(as, at, bs) * cross(as, at, bt)) <= 0 &&
			cmpZero(cross(bs, bt, as) * cross(bs, bt, at)) <= 0)
		return 1;
	return 0;
}
Pt getIntersect(Seg a, Seg b)
{
	Pt u = a.s - b.s;
	double t = cross2(b.e - b.s, u) / cross2(a.e - a.s, b.e - b.s);
	return a.s + (a.e - a.s) * t;
}
double getAngle(Pt va, Pt vb)
{// segment, not vector
	return acos(dot(va, vb) / va.length() / vb.length());
}
Pt rotateRadian(Pt a, double radian)
{
	double x, y;
	x = a.x * cos(radian) - a.y * sin(radian);
	y = a.x * sin(radian) + a.y * cos(radian);
	return Pt(x, y);
}
int in_poly(Pt p[], int n, Pt q)
{
	int i, j, cnt = 0;
	for (i = 0, j = n - 1; i < n; j = i++)
	{
		if (on_seg(p[i], p[j], q))
			return 1;
		if (p[i].y > q.y != p[j].y > q.y &&
				q.x < (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y) + p[i].x)
			cnt++;
	}
	return cnt & 1;
}
void formal_ord(vector<Pt> &A)
{// to counter-clockwise
	int s = 0, n = (int)A.size();
	for (int i = 0; i < A.size(); i++)
		if (A[i] < A[s])
			s = i;
	if (cmpZero(cross(A[(s + n - 1) % n], A[s], A[(s + 1) % n])) < 0)
		reverse(A.begin(), A.end());
}
vector<pair<double, Pt>> get_divide_poly(vector<Pt> A, vector<Pt> B)
{
	vector<pair<double, Pt>> ret;
	Pt p;
	double s = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (i)
			s += (A[i] - A[i - 1]).length();
		ret.push_back(make_pair(s, A[i]));
	}
	A.push_back(A[0]);
	for (int i = 0; i + 1 < A.size(); i++)
	{
		for (int j = 0, k = B.size() - 1; j < B.size(); k = j++)
		{
			if (intersection(B[j], B[k], A[i], A[i + 1]))
			{
				if (cmpZero(cross(A[i], A[i + 1], B[j])) || cmpZero(cross(A[i], A[i + 1], B[k])))
				{
					p = getIntersect(Seg(B[j], B[k]), Seg(A[i], A[i + 1]));
					ret.push_back(make_pair(ret[i].first + (A[i] - p).length(), p));
				}
				else
				{
					if (between(A[i], A[i + 1], B[j]))
					{
						p = B[j];
						ret.push_back(make_pair(ret[i].first + (A[i] - p).length(), p));
					}
					if (between(A[i], A[i + 1], B[k]))
					{
						p = B[k];
						ret.push_back(make_pair(ret[i].first + (A[i] - p).length(), p));
					}
				}
			}
		}
	}
	sort(ret.begin(), ret.end());
	int n = 1;
	for (int i = 1; i < ret.size(); i++)
	{
		if (cmpZero(ret[i].first - ret[n - 1].first))
			ret[n++] = ret[i];
	}
	ret.resize(n);
	return ret;
}

#define MAXM 131072
#define MAXN 512

int g[MAXN][MAXN], ban[MAXN], used[MAXN], fromAB[MAXN], nA, nB;
Pt D[MAXN], path[MAXN], arrA[MAXN], arrB[MAXN];
vector<vector<Pt>> ret;

void ans(Pt A[], int n)
{
	int update;
	do
	{
		update = 0;
		for (int i = 0; i < n; i++)
		{
			if (on_seg(A[i], A[(i + 2) % n], A[(i + 1) % n]))
			{
				update = 1;
				int ridx = (i + 1) % n;
				for (int j = ridx; j < n; j++)
				{
					A[j] = A[j + 1];
				}
				n--;
				break;
			}
		}
	} while (update);
	if (n <= 2)
	{
		return;
	}
	vector<Pt> vA, minExp;
	for (int i = 0; i < n; i++)
	{
		vA.push_back(A[i]);
	}
	formal_ord(vA);
	int st = 0;
	for (int i = 0; i < n; i++)
	{
		if (vA[i] < vA[st])
		{
			st = i;
		}
	}
	for (int i = st; i >= 0; i--)
	{
		minExp.push_back(vA[i]);
	}
	for (int i = n - 1; i > st; i--)
	{
		minExp.push_back(vA[i]);
	}
	for (int i = 0; i < ret.size(); i++)
	{
		if (ret[i].size() != minExp.size())
		{
			continue;
		}
		int same = 1;
		for (int j = 0; j < minExp.size(); j++)
		{
			same &= minExp[j] == ret[i][j];
		}
		if (same)
		{
			return;
		}
	}
	ret.push_back(minExp);
}
void build_edge(vector<pair<double, Pt>> pA, map<Pt, int> &Rlabel, int f)
{
	for (int i = 0, j = pA.size() - 1; i < pA.size(); j = i++)
	{
		int from = Rlabel[pA[j].second];
		int to = Rlabel[pA[i].second];
		g[from][to] |= f;
	}
}
void dfs(int u, int idx, int N, int st)
{
	path[idx] = D[u], used[u] = 1;
	for (int i = 0; i < N; i++)
	{
		if (g[u][i] && i == st)
		{
			int ok = 1;
			for (int j = 0; j < N && ok; j++)
			{
				if (used[j] == 0)
					ok &= !in_poly(path, idx + 1, D[j]);
			}
			for (int j = 0, k = idx; j <= idx; k = j++)
			{
				Pt mid = (path[j] + path[k]) * 0.5;
				ok &= in_poly(arrA, nA, mid);
				ok &= in_poly(arrB, nB, mid);
			}
			if (ok)
			{
				ans(path, idx + 1);
			}
		}
		if (g[u][i] && !used[i] && !ban[i])
		{
			dfs(i, idx + 1, N, st);
		}
	}
	used[u] = 0;
}
bool cmp(vector<Pt> A, vector<Pt> B)
{
	for (int i = 0; i < A.size() && i < B.size(); i++)
	{
		if (!(A[i] == B[i]))
			return A[i] < B[i];
	}
	return A.size() < B.size();
}
void solve(vector<Pt> A, vector<Pt> B)
{
	ret.clear();

	for (int i = 0; i < A.size(); i++)
	{
		arrA[i] = A[i];
	}
	for (int i = 0; i < B.size(); i++)
	{
		arrB[i] = B[i];
	}
	nA = A.size();
	nB = B.size();
	formal_ord(A);
	formal_ord(B);

	vector<pair<double, Pt>> pA, pB;
	map<Pt, int> Rlabel;
	int label = 0;

	pA = get_divide_poly(A, B);
	pB = get_divide_poly(B, A);

	for (int i = 0; i < pA.size(); i++)
	{
		if (!Rlabel.count(pA[i].second))
		{
			D[label] = pA[i].second, fromAB[label] = 1;
			Rlabel[pA[i].second] = label++;
		}
	}
	for (int i = 0; i < pB.size(); i++)
	{
		if (!Rlabel.count(pB[i].second))
		{
			D[label] = pB[i].second, fromAB[label] = 2;
			Rlabel[pB[i].second] = label++;
		}
	}

	int N = (int)Rlabel.size();
	memset(g, 0, sizeof(g));
	memset(ban, 0, sizeof(ban));
	build_edge(pA, Rlabel, 1);
	build_edge(pB, Rlabel, 2);
	for (int i = 0; i < N; i++)
	{
		int ok = in_poly(arrA, A.size(), D[i]) && in_poly(arrB, B.size(), D[i]);
		if (!ok)
		{
			ban[i] = 1;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (!ban[i])
		{
			memset(used, 0, sizeof(used));
			dfs(i, 0, N, i);
		}
	}
	printf("Number of intersection regions: %d\n", ret.size());
	sort(ret.begin(), ret.end(), cmp);
	for (int i = 0; i < ret.size(); i++)
	{
		printf("Region %d:", i + 1);
		for (int j = 0; j < ret[i].size(); j++)
		{
			printf("(%.2lf,%.2lf)", ret[i][j].x, ret[i][j].y);
		}
		printf("\n");
	}
}

int main()
{
	int N, M, cases = 0;
	double x, y;
	while (scanf("%d", &N) == 1 && N)
	{
		vector<Pt> A, B;
		for (int i = 0; i < N; i++)
		{
			scanf("%lf%lf", &x, &y);
			A.push_back(Pt(x, y));
		}
		scanf("%d", &M);
		for (int i = 0; i < M; i++)
		{
			scanf("%lf%lf", &x, &y);
			B.push_back(Pt(x, y));
		}
		printf("Data Set %d\n", ++cases);
		for (int i = 0; i < A.size(); i++)
		{
			// assert(!on_seg(A[i], A[(i + 2) % A.size()], A[(i + 1) % A.size()]));
		}
		for (int i = 0; i < B.size(); i++)
		{
			// assert(!on_seg(B[i], B[(i + 2) % B.size()], B[(i + 1) % B.size()]));
		}
		solve(A, B);
	}
	return 0;
}
