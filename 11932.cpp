#include <bits/stdc++.h>

using namespace std;

#define MIN_VALUE -1000000000

int n;
int posibles[1 << 16];
int vecinos[16];
int dp[1 << 16][2][2];
int valores[16];

static int *dps(int mascara, bool quien)
{
	if (dp[mascara][quien ? 1 : 0][0] != MIN_VALUE)
	{
		return dp[mascara][quien ? 1 : 0];
	}
	int posibleEsta = posibles[mascara];
	int *mejor = dp[mascara][quien ? 1 : 0];
	mejor[0] = MIN_VALUE;
	mejor[1] = MIN_VALUE;
	for (int i = 0; i < n; i++)
	{
		if (((posibleEsta >> i) & 1) == 1)
		{
			int *posible = dps(mascara | (1 << i), !quien);
			if (quien)
			{
				if (posible[0] + valores[i] > mejor[0])
				{
					mejor[0] = posible[0] + valores[i];
					mejor[1] = posible[1];
				}
			}
			else
			{
				if (posible[1] + valores[i] > mejor[1])
				{
					mejor[0] = posible[0];
					mejor[1] = posible[1] + valores[i];
				}
			}
		}
	}
	return mejor;
}

void imprimir(int *d)
{
	if (d[0] > d[1])
	{
		printf("First player wins! %d to %d.\n", d[0], d[1]);
	}
	else if (d[0] < d[1])
	{
		printf("Second player wins! %d to %d.\n", d[1], d[0]);
	}
	else
	{
		printf("Tie game! %d all.\n", d[0]);
	}
}

int main()
{
	while (true)
	{
		scanf("%d", &n);
		if (n == 0)
		{
			return 0;
		}
		for (int i = 0; i < n; i++)
		{
			vecinos[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &valores[i]);
		}
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			int a;
			scanf("%d", &a);
			a--;
			int b;
			scanf("%d", &b);
			b--;
			vecinos[a] |= 1 << b;
			vecinos[b] |= 1 << a;
		}
		posibles[0] = (1 << n) - 1;
		dp[0][0][0] = MIN_VALUE;
		dp[0][0][1] = MIN_VALUE;
		dp[0][1][0] = MIN_VALUE;
		dp[0][1][1] = MIN_VALUE;
		for (int i = 1; i < 1 << n; i++)
		{
			dp[i][0][0] = MIN_VALUE;
			dp[i][0][1] = MIN_VALUE;
			dp[i][1][0] = MIN_VALUE;
			dp[i][1][1] = MIN_VALUE;
			posibles[i] = 0;
			for (int j = 0; j < n; j++)
			{
				if (((i >> j) & 1) == 1)
				{
					posibles[i] |= ~i & vecinos[j];
				}
			}
		}
		dp[(1 << n) - 1][0][0] = 0;
		dp[(1 << n) - 1][0][1] = 0;
		dp[(1 << n) - 1][1][0] = 0;
		dp[(1 << n) - 1][1][1] = 0;
		imprimir(dps(0, true));
	}
}
