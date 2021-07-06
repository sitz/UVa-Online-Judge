#include <bits/stdc++.h>

using namespace std;

#define eps 1e-8
#define EPS 1e-8
#define inf 1e99
double dist(double ax, double ay, double bx, double by)
{
	return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

double distToLine(
		double ax, double ay,
		double bx, double by,
		double px, double py,
		double *cpx, double *cpy)
{
	//Formula: cp = a + (p-a).(b-a) / |b-a| * (b-a)
	double proj = ((px - ax) * (bx - ax) + (py - ay) * (by - ay)) /
								((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
	*cpx = ax + proj * (bx - ax);
	*cpy = ay + proj * (by - ay);
	return dist(px, py, *cpx, *cpy);
}

double distToLineSegment(
		double ax, double ay,
		double bx, double by,
		double px, double py,
		double *cpx, double *cpy)
{
	if ((bx - ax) * (px - ax) + (by - ay) * (py - ay) < EPS)
	{
		*cpx = ax;
		*cpy = ay;
		return dist(ax, ay, px, py);
	}
	if ((ax - bx) * (px - bx) + (ay - by) * (py - by) < EPS)
	{
		*cpx = bx;
		*cpy = by;
		return dist(bx, by, px, py);
	}
	return distToLine(ax, ay, bx, by, px, py, cpx, cpy);
}

double polygonArea(int n, double x[], double y[])
{
	double a = 0;
	for (int i = 1; i <= n; i++)
	{
		a += (x[i - 1] * y[i % n] - x[i % n] * y[i - 1]);
	}
	return fabs(a / 2);
}

double PolygonDistance(int n1, double x1[], double y1[], int n2, double x2[], double y2[])
{
	double result = 1e99;
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
		{
			double a, b;
			result = min(result, distToLineSegment(x2[j], y2[j], x2[(j + 1) % n2], y2[(j + 1) % n2], x1[i], y1[i], &a, &b));
			result = min(result, distToLineSegment(x1[i], y1[i], x1[(i + 1) % n1], y1[(i + 1) % n1], x2[j], y2[j], &a, &b));
		}
	return result;
}

int main()
{
	ofstream fout1("test.in");
	double PolygonX[101][101];
	double PolygonY[101][101];
	double Areas[101];
	bool Graph[101][101];
	int count[101];
	int m, p, c, N;
	cin >> N;
	for (; N--;)
	{
		cin >> m;
		if (m > 100)
		{
			cout << "Oh my god" << endl;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> count[i];
			if (count[i] > 33)
			{
				cout << "What?!" << endl;
			}
			for (int j = 0; j < count[i]; j++)
			{
				cin >> PolygonX[i][j] >> PolygonY[i][j];
			}
		}
		cin >> p >> c;
		//cout << "Read Input" << endl;
		memset(Graph, 0, sizeof Graph);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
			{
				Graph[i][j] = (PolygonDistance(count[i], PolygonX[i], PolygonY[i], count[j], PolygonX[j], PolygonY[j]) < 30.0);
			}
		//cout << "Graph made" << endl;
		for (int i = 0; i < m; i++)
		{
			Areas[i] = polygonArea(count[i], PolygonX[i], PolygonY[i]);
		}
		//cout << "Areas calculated" << endl;
		bool Fired[102];
		int FireTime[102];
		for (int i = 0; i < m; i++)
		{
			FireTime[i] = 400;
		}
		memset(Fired, 0, sizeof Fired);
		Fired[p] = true;
		FireTime[p] = 0;
		for (int I = 0; I < m; I++)
		{
			//cout << "Step " << I << endl;
			//cout << m << endl;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < m; j++)
				{
					//cout << i << " " << j << endl;
					if (Graph[i][j])
					{
						FireTime[j] = min(FireTime[j], FireTime[i] + (int)(ceil(10.0 * Areas[j] / Areas[i]) + eps));
					}
				}
		}
		//cout << "Finalizing" << endl;
		for (int i = 0; i < m; i++)
		{
			//          cerr << i << " " << Areas[i] << " " <<FireTime[i] << endl;
			Fired[i] = (FireTime[i] <= c);
		}
		bool f = true;
		for (int i = 0; i < m; i++)
			if (Fired[i])
			{
				if (!f)
				{
					cout << " ";
				}
				f = false;
				cout << i;
			}
		cout << endl;
	}
	return 0;
}
