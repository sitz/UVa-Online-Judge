#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T, t;
	double PV, r, M, c;
	scanf("%d", &T);
	for (t = 0; t < T; t++)
	{
		if (t != 0)
		{
			printf("\n");
		}
		scanf("%lf %lf %lf", &PV, &r, &M);
		if (r == 0)
		{
			c = PV / M;
		}
		else
		{
			r /= 1200;
			c = PV * r / (1 - pow((r + 1), -M));
		}
		printf("%.2lf\n", c);
	}
	return 0;
}
