#include <bits/stdc++.h>

using namespace std;

int S[70000], X[20], Y[20], L[300], len, N[70000] = {0}, C[20][20] = {0}, Q[20], ll;
int main()
{
	int t, tt, first = 1, n, m, i, j, k, l, limit, max, dx, dy, sign;
	for (i = 0, limit = (1 << 16); i < limit; i++)
	{
		for (j = i; j; j >>= 1)
		{
			N[i] += (j & 1);
		}
	}
	scanf("%d", &tt);
	for (t = 1; t <= tt; t++)
	{
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", X + i, Y + i);
		}
		limit = (1 << n), len = 0;
		for (i = 0; i < limit; i++)
		{
			S[i] = (N[i] + 1) / 2;
		}
		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if (C[i][j] == t)
				{
					continue;
				}
				sign = ((1 << i) | (1 << j));
				dx = X[j] - X[i];
				dy = Y[j] - Y[i];
				for (k = j + 1, ll = 0; k < n; k++)
				{
					if ((X[k] - X[i]) * dy != (Y[k] - Y[i]) * dx)
					{
						continue;
					}
					sign |= (1 << k);
					C[i][k] = C[j][k] = t;
					Q[ll++] = k;
				}
				for (k = 0; k < ll; k++)
				{
					for (l = k + 1; l < ll; l++)
					{
						C[Q[k]][Q[l]] = t;
					}
				}
				L[len++] = sign;
			}
		}
		for (i = 0, max = (n + 1) / 2; i < limit; i++)
		{
			for (j = 0; j < len; j++)
			{
				k = L[j];
				sign = (i | k);
				if (S[sign] > S[i] + 1)
				{
					S[sign] = S[i] + 1;
				}
			}
			if (N[i] >= m && S[i] < max)
			{
				max = S[i];
			}
		}
		if (first)
		{
			first = 0;
		}
		else
		{
			printf("\n");
		}
		printf("Case #%d:\n%d\n", t, max);
	}
	return 0;
}
