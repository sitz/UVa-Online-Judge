#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, i, j1, k1, j2, k2, j3, k3, j4, k4;
	int X[10][10];
	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		for (j1 = 1; j1 <= 9; j1 += 2)
		{
			for (k1 = 1; k1 <= j1; k1 += 2)
			{
				scanf("%d", &X[j1][k1]);
			}
		}
		for (j2 = 3; j2 <= 9; j2 += 2)
		{
			for (k2 = 2; k2 <= j2 - 1; k2 += 2)
			{
				X[j2][k2] = (X[j2 - 2][k2 - 1] - X[j2][k2 + 1] - X[j2][k2 - 1]) / 2;
			}
		}
		for (j3 = 2; j3 <= 8; j3 += 2)
		{
			for (k3 = 1; k3 <= j3; k3++)
			{
				X[j3][k3] = X[j3 + 1][k3] + X[j3 + 1][k3 + 1];
			}
		}
		for (j4 = 1; j4 <= 9; j4++)
		{
			for (k4 = 1; k4 < j4; k4++)
			{
				printf("%d ", X[j4][k4]);
			}
			printf("%d\n", X[j4][k4]);
		}
	}
	return 0;
}
