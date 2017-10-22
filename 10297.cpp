#include <bits/stdc++.h>

using namespace std;

const double pi = 3.1415926;

int main()
{
	double D, V;
	while (cin >> D >> V)
	{
		if (D == 0.0f && V == 0.0f)
		{
			break;
		}
		printf("%.3lf\n", pow((D * D * D - 6 * V / pi), (1 / 3.0)));
	}
	return 0;
}
