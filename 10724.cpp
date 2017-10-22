#include <bits/stdc++.h>

using namespace std;

#define maxn 55
#define INF 2147483647
#define MIN(a, b) (a > b ? b : a)

typedef long SS;

char links[maxn][maxn];
double Cost[maxn][maxn];
SS N, M;

struct ss
{
	SS x, y;
};
ss Point[maxn];

double Dis(SS x1, SS y1, SS x2, SS y2)
{
	double p, q;
	p = (double)(x1 - x2);
	p *= p;
	q = (double)(y1 - y2);
	q *= q;
	return sqrt(p + q);
}
void Ini()
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = i + 1; j <= N; j++)
		{
			Cost[i][j] = Cost[j][i] = INF;
		}
		Cost[i][i] = 0;
	}
}
void Floyd()
{
	SS i, j, k;
	for (k = 1; k <= N; k++)
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				Cost[i][j] = MIN(Cost[i][j], Cost[i][k] + Cost[k][j]);
}
double UpDate(SS u, SS v, double dis)
{
	SS i, j;
	double d1, d2, k = 0, d;
	for (i = 1; i <= N; i++)
	{
		for (j = i + 1; j <= N; j++)
		{
			d1 = Cost[i][u] + dis + Cost[v][j];
			d2 = Cost[i][v] + dis + Cost[u][j];
			d1 = MIN(d2, d1);
			d = Cost[i][j] - d1;
			if (d > 0)
				k += d;
		}
	}
	return k;
}
void Cal()
{
	SS i, u, v, f = 1, j;
	double maxDis = 0, minDis = INF, dis, upd;
	Floyd();
	for (i = 1; i <= N; i++)
	{
		for (j = i + 1; j <= N; j++)
		{
			if (links[i][j] == 1)
				continue;
			dis = Dis(Point[i].x, Point[i].y, Point[j].x, Point[j].y);
			upd = UpDate(i, j, dis);
			if (upd <= 1)
				continue;
			if (upd > maxDis)
			{
				maxDis = upd;
				minDis = dis;
				u = i;
				v = j;
				f = 0;
			}
			else if (upd == maxDis && dis < minDis)
			{
				u = i;
				v = j;
				minDis = dis;
				f = 0;
			}
		}
	}
	if (f)
		cout << "No road required\n";
	else
		cout << u << " " << v << endl;
}
void Free()
{
	int i, j;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			links[i][j] = 0;
}

int main()
{
	SS i, u, v;
	ss t;
	double d;
	while (cin >> N >> M)
	{
		if (!N && !M)
			break;
		for (i = 1; i <= N; i++)
		{
			cin >> t.x >> t.y;
			Point[i] = t;
		}
		Ini();
		for (i = 1; i <= M; i++)
		{
			cin >> u >> v;
			d = Dis(Point[u].x, Point[u].y, Point[v].x, Point[v].y);
			links[u][v] = links[v][u] = 1;
			Cost[u][v] = Cost[v][u] = d;
		}
		Cal();
		Free();
	}
	return 0;
}
