#include <bits/stdc++.h>

using namespace std;

#define sq(a) ((a) * (a))
#define cq(a) (sq(a) * (a))

const double PI = 2 * acos(0);

typedef double elem;
typedef complex<elem> point, vec;

vec uvec(vec a)
{
	return a / abs(a);
}
vec normr(vec a)
{
	return a * vec(0, -1);
}
vec unormr(vec a)
{
	return uvec(normr(a));
}

inline elem CircleCrossX(elem x2, elem r1, elem r2)
{
	vec ab = point(x2, 0);
	elem k = (sq(r1) - sq(r2) + sq(x2)) / (2 * sq(x2));
	point t = k * ab;
	elem x = sqrt(sq(r1) - sq(x2 * k));
	vec abr = unormr(ab);
	vec vp1 = x * abr;
	return (vp1 + t).real();
}

inline elem SphereSurface(elem r, elem x)
{
	return 2 * PI * r * (x + r);
}
inline elem SphereVolume(elem r, elem x)
{
	return PI * ((2 / 3.0) * cq(r) + sq(r) * x - cq(x) / 3.0);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		elem dr1, dr2, dd, dw, ds;
		elem X, V, A;
		scanf("%lf%lf%lf%lf%lf", &dr1, &dr2, &dd, &dw, &ds);
		X = CircleCrossX(dd, dr1, dr2);
		V = SphereVolume(dr1, X);
		A = SphereSurface(dr1, X);
		X = CircleCrossX(dd, dr2, dr1);
		V += SphereVolume(dr2, X);
		A += SphereSurface(dr2, X);
		printf("%.4lf %.4lf\n", V, A);
		if (dw - ds * V < 0)
		{
			puts("The Paired-Sphere Floats.");
		}
		else if (dw - ds * V > 0)
		{
			puts("The Paired-Sphere Sinks.");
		}
	}
	return 0;
}
