#include <bits/stdc++.h>

using namespace std;

#define dcmp(x) (((x) > -eps) - ((x) < eps))

const double eps = 1e-7;

struct Poi
{
	double x, y;
	Poi(double x = 0, double y = 0) : x(x), y(y) {}
	bool operator<(const Poi &rhs) const
	{
		return dcmp(x - rhs.x) < 0 || (dcmp(x - rhs.x) == 0 && dcmp(y - rhs.y) < 0);
	}
	bool operator==(const Poi &rhs) const
	{
		return dcmp(x - rhs.x) == 0 && dcmp(y - rhs.y) == 0;
	}
	Poi operator+(const Poi &rhs) const
	{
		return Poi(x + rhs.x, y + rhs.y);
	}
	Poi operator-(const Poi &rhs) const
	{
		return Poi(x - rhs.x, y - rhs.y);
	}
	Poi operator*(double p) const
	{
		return Poi(x * p, y * p);
	}
	Poi operator/(double p)
	{
		return Poi(x / p, y / p);
	}
	void out()
	{
		printf("%.4lf %.4lf\n", x, y);
	}
};

typedef Poi Vec;
typedef vector<Poi> Poly;

double cross(const Vec &a, const Vec &b)
{
	return a.x * b.y - a.y * b.x;
}

double dot(const Vec &a, const Vec &b)
{
	return a.x * a.x + a.y * a.y;
}

double length(const Vec &v)
{
	return sqrt(dot(v, v));
}

Poi gPoi()
{
	int x, y;
	scanf("%d%d", &x, &y);
	return Poi(x, y);
}

bool segprointer(const Poi &a1, const Poi &a2, const Poi &b1, const Poi &b2)
{
	Vec vb = b2 - b1, va = a2 - a1;
	int c1 = dcmp(cross(vb, a2 - b1)), c2 = dcmp(cross(vb, a1 - b1));
	int c3 = dcmp(cross(va, b2 - a1)), c4 = dcmp(cross(va, b1 - a1));
	return (c1 ^ c2) == -2 && (c3 ^ c4) == -2;
}

Poi lineinter(const Poi &p, const Vec &v, const Poi &q, const Vec &w)
{
	Vec u = p - q;
	double t = cross(w, u) / cross(v, w);
	return p + v * t;
}

struct Edge
{
	int from, to;
	double ang;
};

double PolyArea(const Poly &poly)
{
	int n = poly.size();
	double area = 0;
	for (int i = 1; i < n - 1; i++)
	{
		area += cross(poly[i] - poly[0], poly[i + 1] - poly[0]);
	}
	return area / 2;
}

bool cmp(int, int);

template <int N>
struct PSLG
{
	vector<Edge> edges;
	vector<Poly> faces;
	vector<int> G[N];
	double x[N], y[N], area[N];
	bool vis[N];
	int left[N], prev[N];
	int n, m, face_cnt;
	void init(int n)
	{
		this->n = n;
		for (int i = 0; i < n; i++)
		{
			G[i].clear();
		}
		edges.clear();
		faces.clear();
	}
	double getAngle(int from, int to)
	{
		return atan2(y[to] - y[from], x[to] - x[from]);
	}
	void AddEdge(int from, int to)
	{
		edges.push_back((Edge){
				from, to, getAngle(from, to)});
		edges.push_back((Edge){
				to, from, getAngle(to, from)});
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}
	void Build()
	{
		for (int i = 0; i < n; i++)
		{
			int sz = G[i].size();
			for (int j = 0; j < sz; j++)
			{
				for (int k = j + 1; k < sz; k++)
				{
					if (edges[G[i][j]].ang > edges[G[i][k]].ang)
					{
						swap(G[i][j], G[i][k]);
					}
				}
			}
			for (int j = 0; j < sz; j++)
			{
				prev[G[i][(j + 1) % sz]] = G[i][j];
			}
		}
		m = edges.size();
		face_cnt = 0;
		memset(vis, 0, sizeof(vis));
		for (int k = 0; k < m; k++)
		{
			if (!vis[k])
			{
				Poly poly;
				int e = k;
				for (;;)
				{
					vis[e] = 1;
					left[e] = face_cnt;
					int from = edges[e].from;
					poly.push_back(Poi(x[from], y[from]));
					e = prev[e ^ 1];
					if (e == k)
					{
						break;
					}
					assert(!vis[e]);
				}
				face_cnt++;
				faces.push_back(poly);
			}
		}
		for (int i = 0; i < face_cnt; i++)
		{
			area[i] = PolyArea(faces[i]);
		}
	}
};

PSLG<20010> g;
const int N = 110;

Poi p[N];
vector<double> dist[N];
vector<Poi> V;

inline int ID(const Poi &a)
{
	return lower_bound(V.begin(), V.end(), a) - V.begin();
}

int n;

Poly simplify(const Poly &poly)
{
	Poly newpoly;
	int n = poly.size();
	for (int i = 0; i < n; i++)
	{
		Poi a = poly[i], b = poly[(i + 1) % n], c = poly[(i + 2) % n];
		if (dcmp(cross(c - b, c - a)))
		{
			newpoly.push_back(b);
		}
	}
	return newpoly;
}

int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++)
		{
			p[i] = gPoi();
			dist[i].clear();
		}
		V.assign(p, p + n);
		p[n] = p[0];
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (segprointer(p[i], p[i + 1], p[j], p[j + 1]))
				{
					Poi a = lineinter(p[i], p[i + 1] - p[i], p[j], p[j + 1] - p[j]);
					dist[i].push_back(length(a - p[i]));
					dist[j].push_back(length(a - p[j]));
					V.push_back(a);
				}
			}
		}
		sort(V.begin(), V.end());
		V.erase(unique(V.begin(), V.end()), V.end());
		g.init(V.size());
		for (int i = 0; i < V.size(); i++)//!!
		{
			g.x[i] = V[i].x;
			g.y[i] = V[i].y;
		}
		for (int i = 0; i < n; i++)
		{
			Vec v = p[i + 1] - p[i];
			double len = length(v);
			v = v / length(v);
			dist[i].push_back(0);
			dist[i].push_back(len);
			sort(dist[i].begin(), dist[i].end());//!!
			for (int j = 1; j < dist[i].size(); j++)
			{
				Poi a = p[i] + v * dist[i][j - 1];
				Poi b = p[i] + v * dist[i][j];
				if (a == b)
				{
					continue;
				}
				g.AddEdge(ID(a), ID(b));
			}
		}
		g.Build();
		for (int i = 0; i < g.face_cnt; i++)
		{
			if (g.area[i] < 0)
			{
				Poly poly = g.faces[i];
				reverse(poly.begin(), poly.end());
				poly = simplify(poly);
				int start = 0;
				for (int i = 1; i < poly.size(); i++)
				{
					if (poly[i] < poly[start])
					{
						start = i;
					}
				}
				printf("%d\n", poly.size());
				for (int i = start; i < poly.size(); i++)
				{
					poly[i].out();
				}
				for (int i = 0; i < start; i++)
				{
					poly[i].out();
				}
				break;
			}
		}
	}
	return 0;
}
