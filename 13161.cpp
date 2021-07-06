#include <bits/stdc++.h>

using namespace std;

int quad_eqn_pos_root(int nA, int nB, int nC)
{
	int n_delta = nB * nB - 4 * nA * nC;
	return (-nB + static_cast<int>(sqrt(static_cast<float>(n_delta)))) / 2 / nA;
}

int main()
{
	int nD, nR, nT;
	while (scanf("%d%d%d", &nD,&nR,&nT) == 3)
	{
		int age = quad_eqn_pos_root(2, 2 - 2 * nD, nD * nD - nD - 18 - 2 * (nT + nR));
		int candles = (age + 4) * (age - 3) / 2;
		printf("%d\n", nR - candles);
	}
	return 0;
}
