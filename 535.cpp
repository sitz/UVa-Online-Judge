#include <bits/stdc++.h>

using namespace std;

#define RADIO 6378.0
#define MAXCITIES 100

double PIx = 3.141592653589793;

string cities[MAXCITIES];
double latphi[MAXCITIES], lontheta[MAXCITIES];
int n = 0;

struct Point
{
	double x, y, z;
};

// dot product (pk-pi)°(pj-pi)
// =0 if perpendicular segments
double PointProduct(Point p1, Point p2)
{
	return (p1.x * p2.x + p1.y * p2.y + p1.z * p2.z);
}

// norm of a vector, not used in the solution of this problem
float Norm(Point p)
{
	return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

int myRound(double x)
{
	return (int)(x + 0.5f);
}

double radianes(double x)
{
	return x * PIx / 180;
}

void solve(string temp1, string temp2)
{
	int i, j;
	for (i = 0; i < n; i++)
		if (cities[i] == temp1)
			break;
	for (j = 0; j < n; j++)
		if (cities[j] == temp2)
			break;
	if (i == n || j == n)
	{
		cout << temp1 << " - " << temp2 << endl;
		cout << "Unknown" << endl;
		return;
	}
	/*
	Point a,b;
	a.x = cos(radianes(lontheta[i])) * sin(radianes(latphi[i]));
	a.y = sin(radianes(lontheta[i])) * sin(radianes(latphi[i]));
	a.z = cos(radianes(latphi[i]));
	b.x = cos(radianes(lontheta[j])) * sin(radianes(latphi[j]));
	b.y = sin(radianes(lontheta[j])) * sin(radianes(latphi[j]));
	b.z = cos(radianes(latphi[j]));
	double angulo = acos(PointProduct(a,b)/(Norm(a)*Norm(b)));

	But the rule of a and b is always 1! hence:
	double angle = acos(PointProduct (a, b));

	But there was no AC (apparently due to errors with coordinates
	points very very close) so I tried to use arc-sine ...
	double angle = 2 * asin (sqrt (((1-PointProduct (a, b)) / 2)));

	...which is even worse, finally used the formula Haversine.
	@ http://mathforum.org/library/drmath/view/51879.html
*/
	double lon2 = radianes(lontheta[i]);
	double lon1 = radianes(lontheta[j]);
	double lat2 = radianes(latphi[i]);
	double lat1 = radianes(latphi[j]);
	double dlon = lon2 - lon1;
	double dlat = lat2 - lat1;
	double a = (sin(dlat / 2) * sin(dlat / 2)) + cos(lat1) * cos(lat2) * (sin(dlon / 2) * sin(dlon / 2));
	double angulo = 2 * atan2(sqrt(a), sqrt(1 - a));
	cout << temp1 << " - " << temp2 << endl;
	cout << myRound(angulo * RADIO) << " km" << endl;
}

int main()
{
	string temp1, temp2;
	while (true)
	{
		cin >> temp1;
		if (temp1 == "#")
			break;
		cities[n] = temp1;
		cin >> latphi[n] >> lontheta[n];
		/*
Polar coordinates: theta angle no matter you go from -180 to 180
but beware of the phi angle, it should go from 0 to 180 to
correctly represent the position on the surface of the sphere
latphi[n] += 90;
However, haversine angles always will range from -90 to 90 degrees
*/
		n++;
	}
	while (true)
	{
		cin >> temp1;
		cin >> temp2;
		if (temp1 == "#" && temp2 == "#")
		{
			break;
		}
		solve(temp1, temp2);
	}
	return 0;
}
