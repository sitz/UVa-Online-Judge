#include <bits/stdc++.h>

using namespace std;

/****
10404
****/
#define MAXN 1000005
char F[MAXN];
int N, T[12], S;
void Cal()
{
	int i, j, diff, best;
	F[0] = 2;
	for (i = 1; i <= N; i++)
	{
		best = 1;
		for (j = 0; j < S; j++)
		{
			diff = i - T[j];
			if (diff >= 0)
			{
				if (F[diff] == 2)
				{
					best = 2;
					break;
				}
				else if (F[diff] == 3 && best != 2)
				{
					best = 3;
				}
			}
		}
		if (best == 2)
		{
			F[i] = 3;
		}
		else if (best == 3)
		{
			F[i] = 2;
		}
	}
	if (F[N] == 3)
	{
		printf("Stan wins\n");
	}
	else
	{
		printf("Ollie wins\n");
	}
}
int main()
{
	int i;
	while (scanf("%d", &N) == 1)
	{
		scanf("%d", &S);
		for (i = 0; i < S; i++)
		{
			scanf("%d", &T[i]);
		}
		for (i = 0; i <= N; i++)
		{
			F[i] = 1;
		}
		Cal();
	}
	return 0;
}
