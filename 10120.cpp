#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000002

int Jump[2][MAXN], N, T;

int Dynamic()
{
	int i, nth = 2, a1 = 1, a2 = 0, j;
	int inda = 1, indb, forward, backward;
	Jump[a1][0] = 1;
	j = nth * 2 - 1;
	while (inda)
	{
		indb = 0;
		for (i = 0; i < inda; i++)
		{
			forward = Jump[a1][i] + j;
			if (forward <= N)
			{
				Jump[a2][indb++] = forward;
			}
			backward = Jump[a1][i] - j;
			if (backward > 0)
			{
				Jump[a2][indb++] = backward;
			}
			if (forward == T || backward == T)
			{
				return 1;
			}
		}
		inda = indb;
		a1++;
		a2++;
		nth++;
		a1 %= 2;
		a2 %= 2;
		j = nth * 2 - 1;
	}
	return 0;
}

int main()
{
	int g;
	while (scanf("%d%d", &N, &T) && N && T)
	{
		if (N > 48)
		{
			printf("Let me try!\n");
			continue;
		}
		g = int(sqrt(T));
		if (g * g == T)
		{
			printf("Let me try!\n");
			continue;
		}
		if (Dynamic())
		{
			printf("Let me try!\n");
		}
		else
		{
			printf("Don't make fun of me!\n");
		}
	}
	return 0;
}
