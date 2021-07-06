#include <bits/stdc++.h>

using namespace std;

/*
  [NWERC'06] Mountopia's airport
  by: Jan Kuipers
*/

int N, L;
vector<double> x, y;

double area(double xx)
{
	int i = 0;
	while (x[i + 1] < xx)
	{
		i++;
	}
	if (x[i + 1] >= xx + L)
	{
		double y1 = y[i] + (xx - x[i]) / (x[i + 1] - x[i]) * (y[i + 1] - y[i]);
		double y2 = y[i] + (xx + L - x[i]) / (x[i + 1] - x[i]) * (y[i + 1] - y[i]);
		return L * fabs(y2 - y1) / 2;
	}
	double yy = y[i] + (xx - x[i]) / (x[i + 1] - x[i]) * (y[i + 1] - y[i]);
	double low = yy;
	double res = (x[i + 1] - xx) * (y[i + 1] + yy) / 2;
	i++;
	while (x[i + 1] < xx + L)
	{
		low = min(low, y[i]);
		res += (x[i + 1] - x[i]) * (y[i + 1] + y[i]) / 2;
		i++;
	}
	low = min(low, y[i]);
	yy = y[i] + (xx + L - x[i]) / (x[i + 1] - x[i]) * (y[i + 1] - y[i]);
	low = min(low, yy);
	res += (xx + L - x[i]) * (y[i] + yy) / 2;
	return res - low * L;
}

int main()
{
	int runs;
	cin >> runs;
	while (runs--)
	{
		cin >> N >> L;
		x = y = vector<double>(N);
		for (int i = 0; i < N; i++)
		{
			cin >> x[i] >> y[i];
		}
		double res = 1e9;
		for (int fr = 0; fr < N - 1; fr++)
			for (int to = fr; to < N - 1; to++)
			{
				if (x[to] - x[fr + 1] > L)
				{
					continue;
				}
				if (x[to + 1] - x[fr] < L)
				{
					continue;
				}
				double lo = max(x[to] - L, x[fr]);
				double hi = min(x[to + 1] - L, x[fr + 1]);
				for (int go = 0; go < 100; go++)
				{
					double x1 = (2 * lo + hi) / 3;
					double x2 = (lo + 2 * hi) / 3;
					double area1 = area(x1);
					double area2 = area(x2);
					if (area1 < area2)
					{
						hi = x2;
					}
					else
					{
						lo = x1;
					}
				}
				res = min(res, area(lo));
			}
		cout << fixed << res << endl;
	}
	return 0;
}
