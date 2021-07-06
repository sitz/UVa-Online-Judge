#include <bits/stdc++.h>

using namespace std;

int maxpoints = 10000, n;
double eps = 1e-7;

struct Point
{
	double x, y, z;
} p[10000], t[4], res, q[3];
double r, m[3][3], sol[3], l[3], det;
double d()
{
	return m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] +
				 m[0][2] * m[1][0] * m[2][1] - m[0][2] * m[1][1] * m[2][0] -
				 m[0][1] * m[1][0] * m[2][2] - m[0][0] * m[1][2] * m[2][1];
}
double dot(Point a, Point b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
void ball(int tt)
{
	if (tt == 0)
	{
		r = 0;
	}
	else if (tt == 1)
	{
		res = t[0];
		r = 0;
	}
	else if (tt == 2)
	{
		res.x = (t[0].x + t[1].x) / 2;
		res.y = (t[0].y + t[1].y) / 2;
		res.z = (t[0].z + t[1].z) / 2;
		r = ((t[0].x - t[1].x) * (t[0].x - t[1].x) +
				 (t[0].y - t[1].y) * (t[0].y - t[1].y) +
				 (t[0].z - t[1].z) * (t[0].z - t[1].z)) /
				4;
	}
	else if (tt == 3)
	{
		for (int i = 0; i < 2; i++)
		{
			q[i].x = t[i + 1].x - t[0].x;
			q[i].y = t[i + 1].y - t[0].y;
			q[i].z = t[i + 1].z - t[0].z;
		}
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
			{
				m[i][j] = 2 * dot(q[i], q[j]);
			}
		for (int i = 0; i < 2; i++)
		{
			sol[i] = dot(q[i], q[i]);
		}
		double det = m[0][0] * m[1][1] - m[0][1] * m[1][0];
		//         if abs(det) < eps then exit;
		l[0] = (sol[0] * m[1][1] - m[0][1] * sol[1]) / det;
		l[1] = (m[0][0] * sol[1] - sol[0] * m[1][0]) / det;
		res.x = t[0].x + q[0].x * l[0] + q[1].x * l[1];
		res.y = t[0].y + q[0].y * l[0] + q[1].y * l[1];
		res.z = t[0].z + q[0].z * l[0] + q[1].z * l[1];
		r = (res.x - t[0].x) * (res.x - t[0].x) +
				(res.y - t[0].y) * (res.y - t[0].y) +
				(res.z - t[0].z) * (res.z - t[0].z);
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			q[i].x = t[i + 1].x - t[0].x;
			q[i].y = t[i + 1].y - t[0].y;
			q[i].z = t[i + 1].z - t[0].z;
		}
		for (int i = 0; i < 3; i++)
		{
			sol[i] = dot(q[i], q[i]);
		}
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				m[i][j] = 2 * dot(q[i], q[j]);
			}
		double det = d();
		//        if abs(det) < eps then exit;
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				m[i][j] = sol[i];
			}
			l[j] = d() / det;
			for (int i = 0; i < 3; i++)
			{
				m[i][j] = 2 * dot(q[i], q[j]);
			}
		}
		res = t[0];
		for (int i = 0; i < 3; i++)
		{
			res.x += q[i].x * l[i];
			res.y += q[i].y * l[i];
			res.z += q[i].z * l[i];
		}
		r = (res.x - t[0].x) * (res.x - t[0].x) +
				(res.y - t[0].y) * (res.y - t[0].y) +
				(res.z - t[0].z) * (res.z - t[0].z);
	}
}

void minball(int tt, int n)
{
	Point tmp;
	ball(tt);
	if (tt == 4)
	{
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if ((res.x - p[i].x) * (res.x - p[i].x) +
						(res.y - p[i].y) * (res.y - p[i].y) +
						(res.z - p[i].z) * (res.z - p[i].z) >
				r)
		{
			t[tt] = p[i];
			minball(tt + 1, i);
			tmp = p[i];
			for (int j = i - 1; j >= 0; j--)
			{
				p[j + 1] = p[j];
			}
			p[0] = tmp;
		}
	}
}

int main()
{
	while (true)
	{
		scanf("%d", &n);
		if (!n)
		{
			break;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z);
		}
		r = 0;
		minball(0, n);
		printf("%.4lf %.4lf %.4lf %.4lf\n", sqrt(r), res.x, res.y, res.z);
	}
	return 0;
}
