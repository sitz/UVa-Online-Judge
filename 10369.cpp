#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

template <class T>
string toStr(const T &x)
{
	stringstream s;
	s << x;
	return s.str();
}

template <class T>
int toInt(const T &x)
{
	stringstream s;
	s << x;
	int r;
	s >> r;
	return r;
}

struct Edge
{
	int a, b;
	double w;
	Edge(int A, int B, double W)
			: a(A), b(B), w(W)
	{
	}

	bool operator<(const Edge &other) const
	{
		return w < other.w;
	}
};

struct Point
{
	int x, y;
	Point(int X, int Y)
			: x(X), y(Y)
	{
	}
};

double dist(const Point &a, const Point &b)
{
	return hypot(a.x - b.x, a.y - b.y);
}

const int MAXN = 505;

int T, s, n, p[MAXN];
vector<Edge> edges;
vector<Point> points;

void init()
{
	for (int i = 0; i <= n; i++)
	{
		p[i] = i;
	}
}

int find_(int u)
{
	if (p[u] == u)
	{
		return u;
	}
	return p[u] = find_(p[u]);
}

void join(int u, int v)
{
	int a = find_(u), b = find_(v);
	if (a == b)
	{
		return;
	}
	p[a] = b;
}

double kruskal()
{
	init();
	sort(edges.begin(), edges.end());
	int times = 0;
	double ans = 0.0f;
	for (int i = 0; i < edges.size() && times < n - s; i++)
	{
		int u = edges[i].a, v = edges[i].b;
		double w = edges[i].w;
		if (find_(u) != find_(v))
		{
			ans = w;
			times++;
			join(u, v);
		}
	}
	return ans;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &s,&n);
		edges.clear();
		points.clear();
		for (int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x,&y);
			points.push_back(Point(x, y));
			for (int j = 0; j < i; j++)
			{
				edges.push_back(Edge(j, i, dist(points[j], points[i])));
			}
		}
		printf("%.2lf\n", kruskal());
	}
	return 0;
}
