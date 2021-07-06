#include <bits/stdc++.h>

using namespace std;

/**
	dp[choose a number?][charge of the entire...] - knapsack
	Contact k by simply reversing the direction of the loop
	if you want to limit the number of things you put.
*/

const int MAXN = 11;
const int MAXK = 101;
const int MAXX = 101;

const int DPSIZE1 = 2 * MAXN + 1;
const int DPSIZE2 = MAXN * MAXX + 1;

int N, x, T, K;
int dp[DPSIZE1][DPSIZE2];
int pay[MAXK];
int sum[MAXK];

int main()
{
	while (cin >> N >> x >> T >> K && (N | x | T | K))
	{
		++N;
		for (int k = 0; k < K; ++k)
		{
			cin >> pay[k];
			sum[k] = 0;
			for (int i = 0; i < N; ++i)
			{
				int f;
				cin >> f;
				sum[k] += f;
			}
		}
		fill(dp[0], dp[DPSIZE1], 0);
		for (int k = 0; k < K; ++k)
		{
			for (int i = N * 2; i >= 0; --i)
			{
				for (int j = 0; j <= N * x; ++j)
				{
					for (int m = 1; m <= 2; ++m)
					{
						if (i + m <= N * 2 && j + pay[k] * m <= N * x)
						{
							dp[i + m][j + pay[k] * m] = max(dp[i + m][j + pay[k] * m],
																							dp[i][j] + sum[k] * m);
						}
					}
				}
			}
		}

		double res = 0;
		for (int i = 0; i <= N * 2; ++i)
		{
			for (int j = 0; j <= N * x; j += N)
			{
				int p = (int)ceil((j / N + T) * 1.10);
				if (p <= x)
				{
					res = max(res, (double)dp[i][j] / (double)N);
				}
			}
		}
		printf("%.2f\n", res);
	}
	return 0;
}
