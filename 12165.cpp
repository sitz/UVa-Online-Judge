#include <bits/stdc++.h>

using namespace std;

struct point
{
	double x, y;
} a, b, c, p, q, r;

int mm[10], tot;
double m[10], k[10];

int main()
{
	scanf("%d", &tot);
	while (tot--)
	{
		scanf("%lf%lf", &p.x, &p.y);
		scanf("%lf%lf", &q.x, &q.y);
		scanf("%lf%lf", &r.x, &r.y);
		for (int i = 1; i <= 6; ++i)
		{
			scanf("%d", &mm[i]);
		}
		m[1] = mm[1] * 1.0 / (mm[1] + mm[2]);
		m[2] = mm[2] * 1.0 / (mm[1] + mm[2]);
		m[3] = mm[3] * 1.0 / (mm[3] + mm[4]);
		m[4] = mm[4] * 1.0 / (mm[3] + mm[4]);
		m[5] = mm[5] * 1.0 / (mm[5] + mm[6]);
		m[6] = mm[6] * 1.0 / (mm[5] + mm[6]);
		k[1] = m[1] / (m[1] + m[2] * m[4]);
		k[2] = m[6] / (m[6] + m[5] * m[3]);
		k[3] = m[3] / (m[3] + m[4] * m[6]);
		k[4] = m[2] / (m[2] + m[1] * m[5]);
		k[5] = m[5] / (m[5] + m[6] * m[2]);
		k[6] = m[4] / (m[4] + m[3] * m[1]);
		b.x = (k[2] * p.x - k[1] * q.x) / (k[2] - k[1]);
		c.x = (k[4] * q.x - k[3] * r.x) / (k[4] - k[3]);
		a.x = (k[6] * r.x - k[5] * p.x) / (k[6] - k[5]);
		b.y = (k[2] * p.y - k[1] * q.y) / (k[2] - k[1]);
		c.y = (k[4] * q.y - k[3] * r.y) / (k[4] - k[3]);
		a.y = (k[6] * r.y - k[5] * p.y) / (k[6] - k[5]);
		printf("%.8lf %.8lf %.8lf %.8lf %.8lf %.8lf\n", a.x, a.y, b.x, b.y, c.x, c.y);
	}
	return 0;
}
