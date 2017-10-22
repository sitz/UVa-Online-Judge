#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, s, m, n;
	double dis, angle;
	cout.precision(2);
	cout.setf(ios::fixed);
	while (true)
	{
		cin >> a >> b >> s >> m >> n;
		if (!a && !b && !s && !m && !n)
		{
			break;
		}
		dis = hypot(b * n, a * m);
		angle = fabs(atan2(b * n, a * m) * 180 / M_PI);
		if (angle > 90)
		{
			angle = 180 - angle;
		}
		dis /= s;
		cout << angle << " " << dis << endl;
	}
}
