#include <bits/stdc++.h>

using namespace std;

const double PI = M_PI, PI_2 = PI * 0.5, EPS = 1e-8;
int x[10240], y[10240], n, thita;
double th, r[10240], a[10240];

bool ok()
{
	if (thita > 0)
	{
		for (int i = 0; i < n; ++i)
		{
			if (x[i] > x[i + 1])
			{
				return false;
			}
		}
	}
	printf("Acceptable as proposed\n");
	return true;
}

int main()
{
	for (int t = 1; cin >> n >> thita, n || thita; ++t)
	{
		th = PI / 180 * thita;
		for (int i = 1; i <= n; ++i)
		{
			cin >> x[i] >> y[i];
		}
		printf("Case %d: ", t);
		if (!ok())
		{
			double ul = 0, ur = PI, dl = 0, dr = PI;
			for (int i = 0; i < n; ++i)
			{
				if (x[i] != x[i + 1] || y[i] != y[i + 1])
				{
					double tmp = atan2(y[i + 1] - y[i], x[i + 1] - x[i]);
					if (fabs(tmp) > PI_2)
					{
						if (tmp > 0)
						{
							ul = max(ul, PI_2 + PI - tmp);
							dl = max(dl, tmp - PI_2);
						}
						else
						{
							ul = max(ul, -tmp - PI_2);
							dl = max(dl, PI_2 + PI + tmp);
						}
					}
					else
					{
						ur = min(ur, PI_2 - tmp);
						dr = min(dr, PI_2 + tmp);
					}
				}
			}
			if (ul > ur + EPS && dl > dr + EPS)
			{
				cout << "Unacceptable" << endl;
			}
			else
			{
				if (ul > ur + EPS)
				{
					ul = 1e10;
				}
				if (dl > dr + EPS)
				{
					dl = 1e10;
				}
				cout << "Acceptable after "
						 << ((ul + EPS < dl) ? "counter" : "")
						 << "clockwise rotation of "
						 << fixed << setprecision(2) << min(ul, dl) * 180 / PI
						 << " degrees" << endl;
			}
		}
		printf("\n");
	}
	return 0;
}
