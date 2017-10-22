#include <bits/stdc++.h>

using namespace std;

#define y1 Y1
#define _USE_MATH_DEFINES
double lat1, long1, lat2, long2, x1, y1, z1, x2, y2, z2;
double alpha, delta, x, y, z, norm, bestx, besty, bestz;
struct Vector
{
	double x, y, z;
	Vector(){};
	Vector(double lat, double lon)
	{
		x = sin(lat * M_PI / 180);
		y = sin(lon * M_PI / 180) * cos(lat * M_PI / 180);
		z = cos(lon * M_PI / 180) * cos(lat * M_PI / 180);
	}
	Vector operator*(double scale)
	{
		Vector ans = *this;
		ans.x *= scale;
		ans.y *= scale;
		ans.z *= scale;
		return ans;
	}
	Vector operator+(Vector s)
	{
		Vector ans = *this;
		ans.x += s.x;
		ans.y += s.y;
		ans.z += s.z;
		return ans;
	}
	void Normalize()
	{
		double len = sqrt(x * x + y * y + z * z);
		x /= len;
		y /= len;
		z /= len;
	}
} a, b, c;
void run(double s)
{
	if (s < 0 || s > 1)
	{
		return;
	}
	c = a * s + b * (1 - s);
	c.Normalize();
	if (c.x > bestx)
	{
		bestx = c.x;
		besty = c.y;
		bestz = c.z;
		alpha = s;
	}
}
int main()
{
	int i, j, k, m, n, N;
	int deg, sec;
	char dir;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d,%d%c", &deg, &sec, &dir);
		lat1 = deg + sec / 60.0;
		if (dir == 'S')
		{
			lat1 = -lat1;
		}
		scanf("%d,%d%c", &deg, &sec, &dir);
		long1 = deg + sec / 60.0;
		if (dir == 'W')
		{
			long1 = -long1;
		}
		scanf("%d,%d%c", &deg, &sec, &dir);
		lat2 = deg + sec / 60.0;
		if (dir == 'S')
		{
			lat2 = -lat2;
		}
		scanf("%d,%d%c", &deg, &sec, &dir);
		long2 = deg + sec / 60.0;
		if (dir == 'W')
		{
			long2 = -long2;
		}
		if (lat1 == -lat2 && fabs(long1 - long2) == 180)
		{
			printf("undefined\n");
			continue;
		}
		a = Vector(lat1, long1);
		b = Vector(lat2, long2);
		bestx = -2;
		run(0);
		run(.5);
		run(1);
		for (delta = .5; delta > .000000000001; delta *= .5)
		{
			run(alpha + delta);
			run(alpha - delta);
		}
		if (bestx >= 0)
		{
			i = (int)floor(asin(bestx) * 180 / M_PI * 60 + .5);
			printf("%d,%dN\n", i / 60, i % 60);
		}
		else
		{
			i = (int)floor(asin(-bestx) * 180 / M_PI * 60 + .5);
			printf("%d,%dS\n", i / 60, i % 60);
		}
	}
	return 0;
}
