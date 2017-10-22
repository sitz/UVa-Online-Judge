#include <bits/stdc++.h>

using namespace std;

/*
489
*/
#define MAXN 10000
char Puzzel[MAXN];
char Guess[MAXN];
char F[40], G[40];
void Cal(int n)
{
	int i, j, k, c = 0, w = 0;
	int f;
	printf("Round %d\n", n);
	for (i = 0; Puzzel[i]; i++)
	{
		k = Puzzel[i] - 'a';
		G[k] = 1;
	}
	for (i = 0; Guess[i]; i++)
	{
		k = Guess[i] - 'a';
		f = 0;
		if (F[k])
		{
			continue;
		}
		if (G[k])
		{
			c++;
			G[k] = 0;
			for (j = 0; j < 27; j++)
			{
				if (G[j])
				{
					f = 1;
					break;
				}
			}
		}
		else
		{
			w++;
			f = 1;
		}
		F[k] = 1;
		if (f == 0)
		{
			printf("You win.\n");
			return;
		}
		if (w == 7)
		{
			printf("You lose.\n");
			return;
		}
	}
	printf("You chickened out.\n");
}
int main()
{
	int n;
	while (1)
	{
		scanf("%d", &n);
		if (n == -1)
		{
			break;
		}
		scanf("%s%s", &Puzzel, &Guess);
		Cal(n);
		for (int i = 0; i < 30; i++)
		{
			F[i] = G[i] = 0;
		}
	}
	return 0;
}
