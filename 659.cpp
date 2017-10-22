#include <bits/stdc++.h>

using namespace std;

#define X 0
#define Y 1
#define ITERMAX 10
#define EPS 1e-12
typedef double Point[2];
typedef struct Sphere
{
	Point center;
	double radius;
} Sphere;
typedef double Vector[2];
typedef struct Ray
{
	Point origin;
	Vector direction;
} Ray;
double DOTPROD(double *a, double *b)
{
	return (a[0] * b[0] + a[1] * b[1]);
}
void NORMALIZE(double *a)
{
	double LAmag;
	LAmag = 1. / sqrt(a[0] * a[0] + a[1] * a[1]);
	a[0] *= LAmag;
	a[1] *= LAmag;
}
int NOS;
Sphere s[30];
double intersect(Sphere s, Ray r)
{
	double d, l2, m2, q, fRadius2, t1, t2;
	Vector l;
	l[X] = s.center[X] - r.origin[X];
	l[Y] = s.center[Y] - r.origin[Y];
	d = DOTPROD(l, r.direction);
	if (d < 0)
	{
		return -1.0;
	}
	l2 = DOTPROD(l, l);
	m2 = l2 - d * d;
	fRadius2 = s.radius * s.radius;
	if (m2 > fRadius2)
	{
		return -1.0;
	}
	q = sqrt(fRadius2 - m2);
	t1 = d - q;
	t2 = d + q;
	if (t1 > 0)
	{
		return t1;
	}
	if (t2 > 0)
	{
		return t2;
	}
	return 0.0;
}
int intensity(Ray *ray, int depth)
{
	int Intersections = 0;
	double Distances[30];
	int NearestIntersection;
	double NearestDistance;
	int i;
	Point sp;
	Vector Normal;
	Ray Reflect;
	double c;
	double Abstand;
	NORMALIZE(ray->direction);
	for (i = 0; i < NOS; i++)
	{
		Abstand = intersect(s[i], *ray);
		Distances[i] = Abstand;
		if (Abstand > EPS)
		{
			Intersections++;
		}
	}
	if (depth > ITERMAX && Intersections)
	{
		printf("...");
		return 0;
	}
	if (Intersections > 0)
	{
		NearestIntersection = -1;
		NearestDistance = 0;
		for (i = 0; i < NOS; i++)
		{
			if (Distances[i] > EPS)
			{
				if (Distances[i] < NearestDistance || NearestIntersection == -1)
				{
					NearestIntersection = i;
					NearestDistance = Distances[i];
				}
			}
		}
		printf("%d ", NearestIntersection + 1);
		sp[X] = ray->origin[X] + ray->direction[X] * NearestDistance;
		sp[Y] = ray->origin[Y] + ray->direction[Y] * NearestDistance;
		Normal[X] = sp[X] - s[NearestIntersection].center[X];
		Normal[Y] = sp[Y] - s[NearestIntersection].center[Y];
		NORMALIZE(Normal);
		Reflect.origin[X] = sp[X] + Normal[X] * EPS;
		Reflect.origin[Y] = sp[Y] + Normal[Y] * EPS;
		c = -DOTPROD(Normal, ray->direction);
		Reflect.direction[X] = ray->direction[X] + (2.0 * Normal[X] * c);
		Reflect.direction[Y] = ray->direction[Y] + (2.0 * Normal[Y] * c);
		return intensity(&Reflect, depth + 1);
	}
	else
	{
		printf("inf");
		return 0;
	}
	return 0;
}
int main()
{
	int i, x, y, rad, dx, dy;
	int scene = 0;
	Ray r;
	while (scanf("%d\n", &NOS) && NOS)
	{
		scene++;
		printf("Scene %d\n", scene);
		for (i = 0; i < NOS; i++)
		{
			scanf("%d %d %d", &x, &y, &rad);
			s[i].center[X] = x;
			s[i].center[Y] = y;
			s[i].radius = rad;
		}
		scanf("%d %d %d %d", &x, &y, &dx, &dy);
		r.origin[X] = x;
		r.origin[Y] = y;
		r.direction[X] = dx;
		r.direction[Y] = dy;
		intensity(&r, 1);
		printf("\n\n");
	}
	return 0;
}
