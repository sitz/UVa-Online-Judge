#include <bits/stdc++.h>

using namespace std;

int *T[32][32], PID = 0, min_[32][32], max_[32][32], X[32][32];

int main()
{
	int n, i, j, k;
	for (i = 0; i < 32; i++)
	{
		for (j = 0; j < 32; j++)
		{
			T[i][j] = (int *)malloc(6001 * sizeof(short));
			memset(T[i][j], 0, sizeof(short));
			T[i][j] = T[i][j] + 3000;
		}
	}
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i = 2 * n - 2; i >= n; i--)
		{
			for (j = i - n + 1; j < n; j++)
			{
				scanf("%d", &X[i - j][j]);
			}
		}
		for (i = n - 1; i >= 0; i--)
		{
			for (j = 0; j <= i; j++)
			{
				scanf("%d", &X[i - j][j]);
			}
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				min_[i][j] = 0x7fffffff;
				max_[i][j] = -0x7fffffff;
			}
		}
		T[0][0][min_[0][0] = max_[0][0] = X[0][0]] = ++PID;
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < n - 1; j++)
			{
				for (k = min_[i][j]; k <= max_[i][j]; k++)
				{
					if (T[i][j][k] != PID)
					{
						continue;
					}
					T[i + 1][j][k + X[i + 1][j]] = PID;
					T[i + 1][j][k - X[i + 1][j]] = PID;
					T[i][j + 1][k + X[i][j + 1]] = PID;
					T[i][j + 1][k - X[i][j + 1]] = PID;
				}
				if (max_[i][j] + X[i + 1][j] > max_[i + 1][j])
				{
					max_[i + 1][j] = max_[i][j] + X[i + 1][j];
				}
				if (max_[i][j] - X[i + 1][j] > max_[i + 1][j])
				{
					max_[i + 1][j] = max_[i][j] - X[i + 1][j];
				}
				if (min_[i][j] + X[i + 1][j] < min_[i + 1][j])
				{
					min_[i + 1][j] = min_[i][j] + X[i + 1][j];
				}
				if (min_[i][j] - X[i + 1][j] < min_[i + 1][j])
				{
					min_[i + 1][j] = min_[i][j] - X[i + 1][j];
				}
				if (max_[i][j] + X[i][j + 1] > max_[i][j + 1])
				{
					max_[i][j + 1] = max_[i][j] + X[i][j + 1];
				}
				if (max_[i][j] - X[i][j + 1] > max_[i][j + 1])
				{
					max_[i][j + 1] = max_[i][j] - X[i][j + 1];
				}
				if (min_[i][j] + X[i][j + 1] < min_[i][j + 1])
				{
					min_[i][j + 1] = min_[i][j] + X[i][j + 1];
				}
				if (min_[i][j] - X[i][j + 1] < min_[i][j + 1])
				{
					min_[i][j + 1] = min_[i][j] - X[i][j + 1];
				}
			}
			for (k = min_[i][j]; k <= max_[i][j]; k++)
			{
				if (T[i][j][k] != PID)
				{
					continue;
				}
				T[i + 1][j][k + X[i + 1][j]] = PID;
				T[i + 1][j][k - X[i + 1][j]] = PID;
			}
			if (max_[i][j] + X[i + 1][j] > max_[i + 1][j])
			{
				max_[i + 1][j] = max_[i][j] + X[i + 1][j];
			}
			if (max_[i][j] - X[i + 1][j] > max_[i + 1][j])
			{
				max_[i + 1][j] = max_[i][j] - X[i + 1][j];
			}
			if (min_[i][j] + X[i + 1][j] < min_[i + 1][j])
			{
				min_[i + 1][j] = min_[i][j] + X[i + 1][j];
			}
			if (min_[i][j] - X[i + 1][j] < min_[i + 1][j])
			{
				min_[i + 1][j] = min_[i][j] - X[i + 1][j];
			}
		}
		for (j = 0; j < n - 1; j++)
		{
			for (k = min_[i][j]; k <= max_[i][j]; k++)
			{
				if (T[i][j][k] != PID)
				{
					continue;
				}
				T[i][j + 1][k + X[i][j + 1]] = PID;
				T[i][j + 1][k - X[i][j + 1]] = PID;
			}
			if (max_[i][j] + X[i][j + 1] > max_[i][j + 1])
			{
				max_[i][j + 1] = max_[i][j] + X[i][j + 1];
			}
			if (max_[i][j] - X[i][j + 1] > max_[i][j + 1])
			{
				max_[i][j + 1] = max_[i][j] - X[i][j + 1];
			}
			if (min_[i][j] + X[i][j + 1] < min_[i][j + 1])
			{
				min_[i][j + 1] = min_[i][j] + X[i][j + 1];
			}
			if (min_[i][j] - X[i][j + 1] < min_[i][j + 1])
			{
				min_[i][j + 1] = min_[i][j] - X[i][j + 1];
			}
		}
		i = j = n - 1;
		for (k = 0; k <= 3000; k++)
		{
			if (T[i][j][k] == PID || T[i][j][-k] == PID)
			{
				break;
			}
		}
		printf("%d\n", k);
	}
	return 0;
}
