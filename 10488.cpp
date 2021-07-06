#include <bits/stdc++.h>

using namespace std;

double D, L;

double getdryno(double x, double y)
{
	return (floor(y / D));
}
double dist(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}
int main()
{
	double x1, y1, x2, y2, ret;
	double d1, d2;
	while (cin >> D >> L >> x1 >> y1 >> x2 >> y2)
	{
		d1 = getdryno(x1, y1);
		d2 = getdryno(x2, y2);
		if (y1 > y2)
		{
			y1 -= labs(d1 - d2) * L * 2;
		}
		else
		{
			y2 -= labs(d1 - d2) * L * 2;
		}
		ret = dist(x1, y1, x2, y2);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "The gopher has to swim ";
		cout << labs(d1 - d2) * L * 2 << " meters and walk ";
		cout << ret << " meters." << endl;
	}
	return 0;
}
