#include <bits/stdc++.h>

using namespace std;

double UP, D, L, B, P, DOWN, V, pi = 3.1415926535897932384626433832795;
int main()
{
	int caseno = 0;
	while (scanf("%lf", &UP) == 1, UP >= 1)
	{
		scanf("%lf%lf%lf%lf%lf%lf", &D, &L, &B, &P, &DOWN, &V);
		if (caseno++)
		{
			puts("");
		}
		printf("Scenario %d:\n", caseno);
		printf("     up hill         %10.2lf sec\n", UP);
		printf("     well diameter   %10.2lf in\n", D);
		printf("     water level     %10.2lf in\n", L);
		printf("     bucket volume   %10.2lf cu ft\n", B);
		printf("     bucket ascent rate %7.2lf in/sec\n", P);
		printf("     down hill       %10.2lf sec\n", DOWN);
		printf("     required volume %10.2lf cu ft\n", V);
		double time = 0, v = 0;
		D /= 12;
		L /= 12;
		P /= 12;
		double r = D / 2;
		do
		{
			time += UP + DOWN;
			time += (double)sqrt(2 * L / (32.2)) + (L / P);
			v += B;
			L += B / (pi * r * r);
		} while (v < V && V - v > 1e-7);
		printf("     TIME REQUIRED   %10.2lf sec\n", time);
	}
	return 0;
}
