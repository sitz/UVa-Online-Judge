#include <bits/stdc++.h>

using namespace std;

//ifstream fin( "10514.in" );
//#define cin fin

const double PI = acos(-1.0);
const int MAX_POLYGON = 15;
const double INF = 1e100;

struct MPoint
{
	double x, y;
};

vector<MPoint> polygon[MAX_POLYGON];
double graph[MAX_POLYGON][MAX_POLYGON];
int nIsland;

void init()
{
	for (int i = 0; i < MAX_POLYGON; i++)
	{
		polygon[i].clear();
	}
	for (int i = 0; i < MAX_POLYGON; i++)
		for (int j = 0; j < MAX_POLYGON; j++)
		{
			graph[i][j] = INF;
		}
}

void input()
{
	int r1, r2;
	cin >> r1 >> r2 >> nIsland;
	double x, y;
	for (int i = 0; i < r1; i++)
	{
		cin >> x >> y;
		MPoint p = {x, y};
		polygon[0].push_back(p);
	}
	for (int i = 0; i < r2; i++)
	{
		cin >> x >> y;
		MPoint p = {x, y};
		polygon[nIsland + 1].push_back(p);
	}
	for (int i = 1; i <= nIsland; i++)
	{
		int m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> x >> y;
			MPoint p = {x, y};
			polygon[i].push_back(p);
		}
		MPoint p = polygon[i][0];
		polygon[i].push_back(p);
	}
}

inline double dist(MPoint A, MPoint B)
{
	double xx = A.x - B.x;
	double yy = A.y - B.y;
	return sqrt(xx * xx + yy * yy);
}

double minDistanceDot2Segment(MPoint A, MPoint B, MPoint C)
{
	double a = dist(B, C);
	double b = dist(A, C);
	double c = dist(A, B);
	double BB = acos((a * a + c * c - b * b) / (2.0 * a * c));
	double CC = acos((a * a + b * b - c * c) / (2.0 * a * b));
	if (BB > PI / 2)
	{
		return c;
	}
	else if (CC > PI / 2)
	{
		return b;
	}
	else
	{
		return c * sin(BB);
	}
}

double minDistanceBetween2Polygon(int poly1, int poly2)
{
	double minDist = INF;
	for (int i = 0; i < polygon[poly1].size(); i++)
		for (int j = 0; j < polygon[poly2].size() - 1; j++)
		{
			double tmp = minDistanceDot2Segment(polygon[poly1][i], polygon[poly2][j], polygon[poly2][j + 1]);
			if (tmp < minDist)
			{
				minDist = tmp;
			}
		}
	for (int i = 0; i < polygon[poly2].size(); i++)
		for (int j = 0; j < polygon[poly1].size() - 1; j++)
		{
			double tmp = minDistanceDot2Segment(polygon[poly2][i], polygon[poly1][j], polygon[poly1][j + 1]);
			if (tmp < minDist)
			{
				minDist = tmp;
			}
		}
	return minDist;
}

void make_graph()
{
	for (int i = 0; i < nIsland + 2; i++)
		for (int j = i; j < nIsland + 2; j++)
		{
			if (i == j)
			{
				graph[i][j] = graph[j][i] = 0;
			}
			else
			{
				graph[i][j] = graph[j][i] = minDistanceBetween2Polygon(i, j);
			}
		}
}

void dijkstra(int num, double dist[], int s)
{
	bool vis[MAX_POLYGON];
	for (int i = 0; i < num; i++)
	{
		dist[i] = graph[s][i];
		vis[i] = false;
	}
	dist[s] = 0;
	for (int i = 0; i < num; i++)
	{
		double minValue = INF;
		int k = 0;
		for (int j = 0; j < num; j++)
			if (!vis[j] && dist[j] < minValue)
			{
				minValue = dist[j];
				k = j;
			}
		vis[k] = true;
		for (int j = 0; j < num; j++)
			if (!vis[j] && dist[k] + graph[k][j] < dist[j])
			{
				dist[j] = dist[k] + graph[k][j];
			}
	}
}

void solve()
{
	make_graph();
	double dist[MAX_POLYGON];
	dijkstra(nIsland + 2, dist, 0);
	printf("%.3lf\n", dist[nIsland + 1]);
}

int main()
{
	int numOfCase;
	cin >> numOfCase;
	while (numOfCase--)
	{
		init();
		input();
		solve();
	}
	return 0;
}
