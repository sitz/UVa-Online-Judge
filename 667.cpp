#include <bits/stdc++.h>

using namespace std;

#define max(a, b) (((a) > (b)) ? a : b)
#define min(a, b) (((a) < (b)) ? a : b)

typedef struct
{
	double x, y;
} point;

int n, multi, i;
double k, h;
point pp[200];
double len[200];

const double Precision = 1e-9;

#define Pi 3.1415926535897931

int init()
{
	int i;
	memset(pp, 0, sizeof(pp));
	cin >> k >> h;
	if (k < 0 && h < 0)
	{
		return 0;
	}
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> pp[i].x >> pp[i].y;
		len[i] = sqrt(pp[i].x * pp[i].x + pp[i].y * pp[i].y);
	}
	pp[n] = pp[0];
	len[n] = len[0];
	return 1;
}

int dblcmp(double d)
{
	return (d > 0) ? 1 : -1;
}

double cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}

double dot(point a, point b)
{
	return a.x * b.x + a.y * b.y;
}

void process()
{
	int i;
	double l, r, m, dir, the, newm, delta;
	l = r = m = 0;
	pp[n] = pp[0];
	for (i = 1; i <= n; i++)
	{
		dir = dblcmp(cross(pp[i], pp[i - 1]));
		the = dot(pp[i], pp[i - 1]) / len[i] / len[i - 1];
		if (fabs(the) > 1)
		{
			the = dblcmp(the);
		}
		the = acos(the);
		newm = m + dir * the;
		l = min(l, newm);
		r = max(r, newm);
		m = newm;
	}
	delta = min(2 * Pi, r - l);
	printf("%.2lf\n", delta * k * h);
}

int main()
{
	cin >> multi;
	for (i = 0; i < multi; i++)
	{
		if (init())
		{
			process();
		}
		else
		{
			i--;
		}
		if (i < multi - 1)
		{
			printf("\n");
		}
	}
	return 0;
}
