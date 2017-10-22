#include <bits/stdc++.h>

using namespace std;

int main()
{
	int i, j, k, c = 6, np, t1, t2, X[78500];
	X[1] = 2;
	X[2] = 3;
	X[3] = 5;
	X[4] = 7;
	X[5] = 11;
	X[6] = 13;
	for (i = 17; i <= 1000000; i += 2)
	{
		for (j = 1; X[j] <= sqrt((double)i); j++)
			if (i % X[j] == 0)
			{
				break;
			}
		if (i % X[j] != 0)
		{
			c++;
			X[c] = i;
		}
	}
	for (;;)
	{
		scanf("%d", &t1);
		if (t1 == 0)
		{
			break;
		}
		t2 = t1;
		np = 0;
		for (k = 1; k <= c && t2 >= X[k]; k++)
		{
			if (t2 % X[k] == 0)
			{
				np++;
			}
		}
		printf("%d : %d\n", t1, np);
	}
	return 0;
}
