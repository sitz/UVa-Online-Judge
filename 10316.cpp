#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = 0; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define convert(a) ((a)*pi / 180.0)

const double pi = 2 * acos(0.0);
const double eps = 1e-10;
const double inf = 1e10;

double dist(double x, double y, double z)
{
	return sqrt(x * x + y * y + z * z);
}
class Point
{
public:
	double x, y, z;
	void init(double phi, double theta)
	{
		z = sin(phi);
		x = cos(phi) * cos(theta);
		y = cos(phi) * sin(theta);
	}
	double compute_dist(Point &a)
	{
		double theta = (1 + 1 - dist(x - a.x, y - a.y, z - a.z)) / 2;
		return acos(theta);
	}
};
class state
{
public:
	int now;
	double cost;
	bool operator<(const state &a) const
	{
		return cost > a.cost;
	}
};
const int N = 1000;
double edge[N][N];
double cost[N];
double dijkstra(int n, int s)
{
	double maxi = 0;
	rep(i, n)
	{
		maxi = max(maxi, edge[s][i]);
	}
	return maxi;
}
void solve(int n, Point *in, double *phi, double *theta)
{
	int ansindex = -1;
	double ans = 1e10;
	rep(i, n)
	{
		double tmp = dijkstra(n, i);
		if (tmp + eps < ans)
		{
			ans = tmp;
			ansindex = i;
		}
	}
	printf("%.2lf %.2lf\n", phi[ansindex], theta[ansindex]);
}

int main()
{
	Point in[N];
	double phi[N];
	double theta[N];
	int n;
	while (cin >> n)
	{
		rep(i, n)
		{
			cin >> phi[i] >> theta[i];
			in[i].init(convert(phi[i]), convert(theta[i]));
		}
		reverse(phi, phi + n);
		reverse(theta, theta + n);
		reverse(in, in + n);
		rep(i, n)
		{
			edge[i][i] = 0;
			REP(j, i + 1, n)
			{
				edge[i][j] = edge[j][i] = in[i].compute_dist(in[j]);
			}
		}
		solve(n, in, phi, theta);
	}
	return 0;
}
