#include <bits/stdc++.h>

using namespace std;

#define MAX 41
#define EPS (1.0e-10)
#define PI (acos(-1.0))

typedef double elem;
typedef complex<elem> point, vec;

inline bool eq(const elem &a, const elem &b)
{
	return fabs(a - b) < EPS;
}
inline elem dist(const point &a, const point &b)
{
	return std::abs(a - b);
}
inline elem cross(const vec &a, const vec &b)
{
	return (a.real() * b.imag() - a.imag() * b.real());
}
inline point intersection(const point &a1, const point &a2, const point &b1, const point &b2)
{
	vec b = b2 - b1;
	vec a = a2 - a1;
	return a1 + (cross(b, b1 - a1) / cross(b, a)) * a;
}
inline point rotp(const point &p, elem theta)
{
	return p * exp(point(0, theta));
}
void DivideCircle(elem r, int n, point *v)
{
	for (int i = 0; i < n; ++i)
	{
		v[i] = rotp(point(0, r), (i * PI) / (n / 2));
	}
	return;
}
inline elem AreaOfRegularPolygon(elem r, int n_even)
{
	return (n_even / 2) * (r * r * sin(PI / (n_even / 2)));
}

inline elem AreaOfRoseWindow(elem *r, int n, int k)
{
	if (n / 2 == k)
	{
		return PI * r[k] * r[k] - AreaOfRegularPolygon(r[k - 1], n);
	}
	else
	{
		return AreaOfRegularPolygon(r[k], n) - AreaOfRegularPolygon(r[k - 1], n);
	}
}
int main()
{
	int m;
	scanf("%d", &m);
	for (int tc = 0; tc < m; ++tc)
	{
		elem r;
		int n, k;
		point p[MAX];							 // 円周のn分割点(時計回り)
		elem kr[MAX];							 // 円内部からk番目の正n角形の径
		pair<point, point> v0[MAX];// 円真上の頂点からの対角線
		pair<point, point> v1[MAX];// 上記右隣からの対角線
		scanf("%lf%d%d", &r, &n, &k);
		DivideCircle(r, n, p);
		for (int i = 0; i < n / 2; ++i)
		{
			v0[i].first = p[0];
			v0[i].second = p[n / 2 + i];
			v1[i].first = p[1];
			v1[i].second = p[(n / 2 + i + 1) % n];
		}
		for (int i = 1; i < n / 2; ++i)
		{
			point q = intersection(v0[i].first, v0[i].second, v1[i].first, v1[i].second);
			kr[i] = std::abs(q);
		}
		kr[0] = 0.0;
		kr[n / 2] = r;
		printf("%.4lf\n", AreaOfRoseWindow(kr, n, k));
	}
	return 0;
}
