#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define EPS 1e-9

int xa, ya, ha, xb, yb, hb;

int x[51], y[51], h[51], r[51];

bool intersect(int i)
{
	double A, B, C;
	A = ya - yb;
	B = xb - xa;
	C = -(A * xa + B * ya);

	double da = sqrt(double(xa - x[i]) * (xa - x[i]) + (ya - y[i]) * (ya - y[i]));
	double db = sqrt(double(xb - x[i]) * (xb - x[i]) + (yb - y[i]) * (yb - y[i]));
	if ((xa - x[i]) * (xa - x[i]) + (ya - y[i]) * (ya - y[i]) <= r[i] * r[i])
	{
		if (r[i] == 0 || ha < (1 - da / (r[i])) * h[i] + EPS)
			return 1;
	}
	if ((xb - x[i]) * (xb - x[i]) + (yb - y[i]) * (yb - y[i]) <= r[i] * r[i])
	{
		if (r[i] == 0 || hb < (1 - db / (r[i])) * h[i] + EPS)
			return 1;
	}

	double dd = (A * double(x[i]) + B * double(y[i]) + C) / sqrt(A * A + B * B);

	double xx, yy, hh;
	xx = double(x[i]) - A / sqrt(A * A + B * B) * dd;
	yy = double(y[i]) - B / sqrt(A * A + B * B) * dd;
	dd = fabs(dd);
	if (yb != ya)
		hh = double(yy - ya) / (yb - ya) * (hb - ha) + ha;
	else if (xb != xa)
		hh = double(xx - xa) / (xb - xa) * (hb - ha) + ha;
	else
		return 0;

	double a, b, c;
	if (hb != ha)
	{
		a = double((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya)) / (hb - ha) / (hb - ha);
		b = -2 * hh * a;
		c = hh * hh * a + dd * dd;

		a -= double(r[i] * r[i]) / h[i] / h[i];
		b -= -2 * double(r[i] * r[i]) / h[i];
		c -= r[i] * r[i];

		double root1, root2;
		if (abs(b * b - 4 * a * c) < EPS)
		{
			root1 = -b / 2 / a;
			if (root1 > -EPS && root1 < h[i] + EPS && root1 > min(ha, hb) - EPS && root1 < max(ha, hb) + EPS)
				return 1;
			else
				return 0;
		}
		if ((b * b - 4 * a * c) < EPS)
			return 0;//0 root

		root1 = (-b + sqrt(b * b - 4 * a * c)) / 2 / a;
		root2 = (-b - sqrt(b * b - 4 * a * c)) / 2 / a;

		if (root1 > -EPS && root1 < h[i] + EPS && root1 > min(ha, hb) - EPS && root1 < max(ha, hb) + EPS)
			return 1;
		if (root2 > -EPS && root2 < h[i] + EPS && root2 > min(ha, hb) - EPS && root2 < max(ha, hb) + EPS)
			return 1;
		return 0;
	}
	else
	{
		if (ha >= 0 && ha < h[i] && (r[i] - double(r[i]) / h[i] * ha > dd - EPS))
			return 1;
		else
			return 0;
	}
}

int main()
{
	int n;
	cin >> n;

	while (n >= 0)
	{
		bool visible = 1;
		for (int i = 0; i < n; i++)
			scanf("%d %d %d %d", x + i, y + i, h + i, r + i);
		scanf("%d %d %d", &xa, &ya, &ha);
		scanf("%d %d %d", &xb, &yb, &hb);

		if (ha < EPS || hb < EPS)
		{
			visible = 0;
		}
		for (int i = 0; i < n; i++)
		{
			visible &= (!intersect(i));
		}
		cout << (visible ? "Yes" : "No") << endl;
		cin >> n;
	}
	return 0;
}
