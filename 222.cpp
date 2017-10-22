#include <bits/stdc++.h>

using namespace std;

double DIST, CAP, MPG, D[52], P[52], COST, LOWEST;
int N;
void recurse(int n, double fuel, double cost)
{
	double need, spend;
	if (n == N + 1)
	{
		if (LOWEST < COST || cost < LOWEST)
		{
			LOWEST = cost;
		}
		return;
	}
	fuel -= (D[n] - D[n - 1]) / MPG;
	need = (D[n + 1] - D[n]) / MPG;
	if (!(fuel > CAP / 2 && fuel > need))
	{
		spend = (((CAP - fuel) * P[n] + 200.0)) / 100.0;
		recurse(n + 1, CAP, cost + spend);
	}
	if (fuel > need)
	{
		recurse(n + 1, fuel, cost);
	}
}
int main()
{
	int i, j, n = 0;
	while (1)
	{
		scanf("%lf", &DIST);
		if (DIST < 0)
		{
			break;
		}
		scanf("%lf %lf %lf %i", &CAP, &MPG, &COST, &N);
		D[0] = P[0] = 0;
		for (i = 1; i <= N; i++)
		{
			scanf("%lf %lf", &D[i], &P[i]);
		}
		D[N + 1] = DIST;
		P[N + 1] = 0;
		LOWEST = 0;
		recurse(1, CAP, COST);
		printf("Data Set #%d\n", ++n);
		printf("minimum cost = $%.2f\n", LOWEST);
	}
}
