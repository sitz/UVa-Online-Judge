#include <bits/stdc++.h>

using namespace std;

int main()
{
	int use, ps, N[200], pn, i, j, B[128], T[128][2][2];
	char C[200], P[200];
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			T['K'][i][j] = i & j;
			T['A'][i][j] = i | j;
			T['C'][i][j] = i | (1 - j);
			T['E'][i][j] = 1 - (i ^ j);
		}
	}
	while (scanf("%s", C) == 1)
	{
		if (C[0] == '0')
		{
			break;
		}
		for (i = 0; C[i]; i++)
			;
		P[i] = '\0';
		for (i--, j = 0; i >= 0; i--, j++)
		{
			P[j] = C[i];
		}
		for (use = 0; use < 32; use++)
		{
			for (j = 0; j < 5; j++)
			{
				B['p' + j] = (use & (1 << j)) / (1 << j);
			}
			for (i = ps = pn = 0; P[i]; i++)
			{
				if (P[i] > 'Z')
				{
					N[pn++] = B[P[i]];
				}
				else if (P[i] == 'N')
				{
					N[pn - 1] = 1 - N[pn - 1];
				}
				else
				{
					N[pn - 2] = T[P[i]][N[--pn]][N[pn - 1]];
				}
			}
			if (!N[0])
			{
				break;
			}
		}
		if (N[0])
		{
			printf("tautology\n");
		}
		else
		{
			printf("not\n");
		}
	}
	return 0;
}
