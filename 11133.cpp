#include <bits/stdc++.h>

using namespace std;

int E[45][45] = {0};
int main()
{
	int i, j, k;
	for (i = 0; i < 45; i++)
	{
		E[i][i] = 1;
	}
	for (i = 0; i < 45; i++)
	{
		for (j = i + 1; j < 45; j++)
		{
			for (k = i; k < j; k++)
			{
				if (j % (j - k) == 0)
				{
					E[i][j] += E[i][k];
				}
			}
		}
	}
	while (scanf("%d%d", &i, &j) == 2)
	{
		if ((i | j) == 0)
		{
			break;
		}
		printf("%d %d %d\n", i, j, E[i][j]);
	}
	return 0;
}
