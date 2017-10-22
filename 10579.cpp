#include <bits/stdc++.h>

using namespace std;

#define limit 1000000000
int F[5000][120] = {0}, len[5000] = {1, 1};
int main()
{
	int n, i;
	F[1][0] = 1;
	for (n = 2; n < 5000; n++)
	{
		len[n] = len[n - 1];
		for (i = 0; i < len[n]; i++)
		{
			F[n][i] = F[n - 1][i] + F[n - 2][i];
		}
		for (i = 0; i < len[n]; i++)
		{
			F[n][i + 1] += F[n][i] / limit;
			F[n][i] %= limit;
		}
		if (F[n][len[n]])
		{
			len[n]++;
		}
	}
	while (scanf("%d", &n) == 1)
	{
		printf("%d", F[n][len[n] - 1]);
		for (i = len[n] - 2; i >= 0; i--)
		{
			printf("%09d", F[n][i]);
		}
		printf("\n");
	}
	return 0;
}
