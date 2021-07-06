#include <bits/stdc++.h>

using namespace std;

int main()
{
	int M[105], L[105], n, i, j, k, sec, ok;
	while (scanf("%d%d", M, M + 1) == 2)
	{
		L[0] = M[0] - 5, L[1] = M[1] - 5;
		M[0] <<= 1, M[1] <<= 1;
		for (n = 2; scanf("%d", M + n); n++)
		{
			if (!M[n])
			{
				break;
			}
			L[n] = M[n] - 5;
			M[n] <<= 1;
		}
		if (n == 2 && (M[0] | M[1] | M[2]) == 0)
		{
			break;
		}
		for (i = 0, sec = 10000; i < n; i++)
		{
			if (M[i] < sec)
			{
				sec = M[i];
			}
		}
		while (sec <= 18000)
		{
			for (i = 0, ok = 1; i < n; i++)
			{
				if (sec % M[i] >= L[i])
				{
					ok = 0;
					sec = sec - sec % M[i] + M[i];
					break;
				}
			}
			if (ok)
			{
				break;
			}
		}
		if (sec > 18000)
		{
			printf("Signals fail to synchronise in 5 hours\n");
		}
		else
		{
			printf("%02d:%02d:%02d\n", sec / 3600, sec / 60 % 60, sec % 60);
		}
	}
	return 0;
}
