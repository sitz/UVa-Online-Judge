#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-6;
const int MAXN = 510;
int sgn(double x)
{
	return (x > eps) - (x < -eps);
}
double sqr(double x)
{
	return x * x;
}
struct node
{
	double x, y, z;
	node() {}
	node(double a, double b, double c) : x(a), y(b), z(c) {}
	void read()
	{
		scanf("%lf%lf%lf", &x, &y, &z);
	}
	node operator-(node a)
	{
		return node(x - a.x, y - a.y, z - a.z);
	}
	node operator*(node a)
	{
		return node(y * a.z - a.y * z, a.x * z - x * a.z, x * a.y - a.x * y);
	}
	double operator^(node a)
	{
		return x * a.x + y * a.y + z * a.z;
	}
	double dis(node a)
	{
		return sqrt(sqr(x - a.x) + sqr(y - a.y) + sqr(z - a.z));
	}
} zero(0, 0, 0);
int to[MAXN][MAXN];
struct ThreeD
{
	int n;
	node p[MAXN];
	struct Face
	{
		int a, b, c;
		bool ok;
	} F[MAXN * 8];
	int cnt;
	void read()
	{
		for (int i = 0; i < n; i++)
		{
			p[i].read();
		}
	}
	double volume(node p1, node p2, node p3, node p4)
	{
		return ((p2 - p1) * (p3 - p1)) ^ (p4 - p1);
	}
	double get(node p1, Face f)
	{
		return volume(p[f.a], p[f.b], p[f.c], p1);
	}
	void deal(int pos, int a, int b)
	{
		int f = to[a][b];
		Face tmp;
		if (F[f].ok)
		{
			if (sgn(get(p[pos], F[f])) > 0)
			{
				dfs(pos, f);
			}
			else
			{
				to[b][a] = to[a][pos] = to[pos][b] = cnt;
				tmp.a = b, tmp.b = a, tmp.c = pos, tmp.ok = 1;
				F[cnt++] = tmp;
			}
		}
	}
	void dfs(int pos, int f)
	{
		F[f].ok = 0;
		deal(pos, F[f].b, F[f].a);
		deal(pos, F[f].c, F[f].b);
		deal(pos, F[f].a, F[f].c);
	}
	void run()
	{
		cnt = 0;
		if (n <= 3)
		{
			return;
		}
		int i;
		for (i = 1; i < n; i++)
			if (sgn(p[0].dis(p[i])) > 0)
			{
				swap(p[1], p[i]);
				break;
			}
		if (i == n)
		{
			return;
		}
		for (i = 2; i < n; i++)
		{
			if (sgn(zero.dis((p[0] - p[1]) * (p[i] - p[0]))) > 0)
			{
				swap(p[2], p[i]);
				break;
			}
		}
		if (i == n)
		{
			return;
		}
		for (i = 3; i < n; i++)
		{
			if (fabs(volume(p[0], p[1], p[2], p[i])) > eps)
			{
				swap(p[3], p[i]);
				break;
			}
		}
		if (i == n)
		{
			return;
		}
		Face tmp;
		for (i = 0; i <= 3; i++)
		{
			tmp.a = (i + 1) % 4, tmp.b = (i + 2) % 4, tmp.c = (i + 3) % 4, tmp.ok = 1;
			if (sgn(get(p[i], tmp)) > 0)
			{
				swap(tmp.b, tmp.c);
			}
			to[tmp.a][tmp.b] = to[tmp.b][tmp.c] = to[tmp.c][tmp.a] = cnt;
			F[cnt++] = tmp;
		}
		int j;
		for (i = 4; i < n; i++)
			for (j = 0; j < cnt; j++)
			{
				if (F[j].ok && sgn(get(p[i], F[j])) > 0)
				{
					dfs(i, j);
					break;
				}
			}
		int T = cnt;
		cnt = 0;
		for (i = 0; i < T; i++)
			if (F[i].ok)
			{
				F[cnt++] = F[i];
			}
	}
	bool same(Face A, Face B)
	{
		return sgn(get(p[A.a], B)) == 0 &&
					 sgn(get(p[A.b], B)) == 0 &&
					 sgn(get(p[A.c], B)) == 0;
	}
	double area()
	{
		int i;
		double ans = 0;
		for (i = 0; i < cnt; i++)
		{
			ans += zero.dis((p[F[i].b] - p[F[i].a]) * (p[F[i].c] - p[F[i].a])) / 2.0;
		}
		return ans;
	}
	int FaceNum()
	{
		int i, j, ans = 0;
		for (i = 0; i < cnt; i++)
		{
			for (j = i + 1; j < cnt; j++)
			{
				if (same(F[i], F[j]))
				{
					break;
				}
			}
			if (j == cnt)
			{
				ans++;
			}
		}
		return ans;
	}
} H;
int main()
{
	int c = 0;
	while (~scanf("%d", &H.n), H.n)
	{
		H.read();
		H.run();
		printf("Case %d: %.2lf\n", ++c, H.area());
	}
	return 0;
}
