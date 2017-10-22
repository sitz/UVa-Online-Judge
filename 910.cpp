#include <bits/stdc++.h>

using namespace std;

// dp - baktrack
// state dp[a][b] = c
// 	- current position a
// 	- b moves remaining
// 	- in this situation, can achieve goal in c ways
// m=0: 1 if current pos is special, otherwise 0
// otherwise: 2 options - path 0 || 1
// eg. dp[pos 'C'][3]
// 		= #ways to get the goal, choosing path 0, m=3-1=2
// 		+ #ways to get the goal, choosing path 1, m=3-1=2

int matrix[26 + 3][4 + 3], dp[26 + 3][30 + 3];

int bktk(int pos, int m)
{
	if (m == 0)
	{
		return matrix[pos][2];
	}
	if (dp[pos][m] != -1)
	{
		return dp[pos][m];
	}
	return dp[pos][m] = bktk(matrix[pos][0], m - 1) + bktk(matrix[pos][1], m - 1);
}

void reset()
{
	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 33; j++)
		{
			dp[i][j] = -1;
		}
	}
}

int main()
{
	int nodes;
	while (scanf("%d", &nodes) != EOF)
	{
		reset();
		getchar();
		char a[10];
		for (int i = 0; i < nodes; i++)
		{
			gets(a);
			matrix[a[0] - 'A'][0] = a[2] - 'A';
			matrix[a[0] - 'A'][1] = a[4] - 'A';
			matrix[a[0] - 'A'][2] = a[6] == 'x' ? 1 : 0;
		}
		int m;
		scanf("%d", &m);
		printf("%d\n", bktk(0, m));
	}
	return 0;
}
