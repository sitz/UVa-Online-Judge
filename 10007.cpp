#include <bits/stdc++.h>

using namespace std;

#define limit 1000000000LL

static int T[305][100] = {0}, len[305];

int main()
{
	int i, j, n;
	long long int tmp;
	T[0][0] = 1;
	len[0] = 1;
	for (i = 1; i < 305; i++)
	{
		len[i] = len[i - 1];
		for (j = 0; j < len[i]; j++)
		{
			tmp = (long long int)T[i - 1][j] * (4 * i - 2);
			T[i][j] += tmp % limit;
			T[i][j + 1] = tmp / limit;
		}
		if (T[i][len[i]])
		{
			len[i]++;
		}
	}
	for (i = 1; i < 305; i++)
	{
		tmp = 0LL;
		for (j = len[i] - 1; j >= 0; j--)
		{
			tmp = tmp * limit + T[i][j];
			T[i][j] = (int)(tmp / (i + 1));
			tmp %= (i + 1);
		}
		if (!T[i][len[i] - 1])
		{
			len[i]--;
		}
	}
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		printf("%d", T[n][len[n] - 1]);
		for (i = len[n] - 2; i >= 0; i--)
		{
			printf("%09d", T[n][i]);
		}
		printf("\n");
	}
	return 0;
}
