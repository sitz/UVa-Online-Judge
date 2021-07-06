#include <bits/stdc++.h>

using namespace std;

#define limit 1000000000
int F[1505][40] = {0}, lf[1505], S[1505][40] = {0}, ls[1505];
int main()
{
	int t, i, j, n;
	F[0][0] = F[1][0] = lf[0] = lf[1] = ls[0] = 1;
	for (i = 2; i < 1505; i++)
	{
		lf[i] = lf[i - 1];
		for (j = 0; j < lf[i]; j++)
		{
			F[i][j] = F[i - 1][j] + F[i - 2][j];
		}
		for (j = 0; j < lf[i]; j++)
		{
			if (F[i][j] >= limit)
			{
				F[i][j + 1]++;
				F[i][j] -= limit;
			}
		}
		if (F[i][lf[i]])
		{
			lf[i]++;
		}
	}
	for (i = 1; i < 1505; i++)
	{
		ls[i] = ls[i - 1];
		for (j = 0; j < ls[i]; j++)
		{
			S[i][j] = S[i - 1][j] + F[i][j];
		}
		for (j = 0; j < ls[i]; j++)
		{
			if (S[i][j] >= limit)
			{
				S[i][j + 1]++;
				S[i][j] -= limit;
			}
		}
		if (S[i][ls[i]])
		{
			ls[i]++;
		}
	}
	for (i = 0; i < 1505; i++)
	{
		F[i][0]++;
		for (j = 0; F[i][j] >= limit; j++)
		{
			F[i][j + 1]++;
			F[i][j] -= limit;
		}
		if (F[i][lf[i]])
		{
			lf[i]++;
		}
		for (j = lf[i] - 1; j > 0; j--)
		{
			if (F[i][j] & 1)
			{
				F[i][j - 1] += limit;
			}
			F[i][j] >>= 1;
		}
		F[i][0] >>= 1;
		if (!F[i][lf[i] - 1])
		{
			lf[i]--;
		}
	}
	for (i = 0; i < 1505; i++)
	{
		for (j = 0; j < ls[i]; j++)
		{
			S[i][j] += F[i + 1][j];
		}
		for (j = 0; j < ls[i]; j++)
		{
			if (S[i][j] >= limit)
			{
				S[i][j + 1]++;
				S[i][j] -= limit;
			}
		}
		if (S[i][ls[i]])
		{
			ls[i]++;
		}
	}
	for (t = 1; scanf("%d", &n) == 1; t++)
	{
		if (n == 0)
		{
			break;
		}
		printf("Set %d:\n", t);
		if (n == 1)
		{
			printf("0\n");
			continue;
		}
		else
		{
			n -= 2;
		}
		printf("%d", S[n][ls[n] - 1]);
		for (i = ls[n] - 2; i >= 0; i--)
		{
			printf("%09d", S[n][i]);
		}
		printf("\n");
	}
	return 0;
}
