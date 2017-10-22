#include <bits/stdc++.h>

using namespace std;

int S[300][300] = {0}, I[300][300], X[300] = {100}, U[300], p, l, n;
int cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}
int stick(int lv, int len, int sum, int st, int less)
{
	int i, j, pr, nless;
	if (lv == p)
	{
		return 1;
	}
	if (len == 0)
	{
		for (i = lv; i <= n; i++)
		{
			if (!U[i])
			{
				break;
			}
		}
		S[lv][1] = i;
		U[i] = 1;
		if (X[i] == l)
		{
			if (stick(lv + 1, 0, 0, 1, 0))
			{
				return 1;
			}
		}
		else
		{
			if (X[i] < X[S[lv - 1][1]])
			{
				nless = 1;
			}
			else
			{
				nless = 0;
			}
			if (stick(lv, len + 1, X[i], i + 1, nless))
			{
				return 1;
			}
		}
		U[i] = 0;
		S[lv][1] = 0;
		return 0;
	}
	for (i = st; i <= n; i++)
	{
		if (U[i] || (X[i - 1] == X[i] && !U[i - 1]) || sum + X[i] > l)
		{
			continue;
		}
		pr = S[lv - 1][len + 1];
		if (!less && X[i] > X[pr])
		{
			continue;
		}
		S[lv][len + 1] = i;
		U[i] = 1;
		if (sum + X[i] == l)
		{
			if (stick(lv + 1, 0, 0, 1, 0))
			{
				return 1;
			}
		}
		else
		{
			if (less || X[i] < X[pr])
			{
				nless = 1;
			}
			else
			{
				nless = 0;
			}
			if (stick(lv, len + 1, sum + X[i], i + 1, nless))
			{
				return 1;
			}
		}
		U[i] = 0;
		S[lv][len + 1] = 0;
	}
	return 0;
}
int main()
{
	int i, j, max, sum;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i = 1, max = sum = 0; i <= n; i++)
		{
			scanf("%d", X + i);
			if (X[i] > max)
			{
				max = X[i];
			}
			sum += X[i];
			U[i] = 0;
		}
		qsort(X + 1, n, sizeof(int), cmp);
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				S[i][j] = 0;
			}
		}
		for (l = max; l < sum; l++)
		{
			if (sum % l)
			{
				continue;
			}
			p = sum / l;
			if (stick(1, 0, 0, 1, 0))
			{
				break;
			}
		}
		printf("%d\n", l);
	}
	return 0;
}
