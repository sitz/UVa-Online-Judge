#include <bits/stdc++.h>

using namespace std;

int size, mat[100][100], record[100][100];

inline void Input()
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	memset(record, 0, sizeof(record));
}

inline void solve()
{
	int max = -10000, row, col, loop, sum, lsum;
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			sum = 0;
			for (loop = col; loop < size; loop++)
			{
				sum += mat[row][loop];
				lsum = sum + record[col][loop];
				if (lsum > max)
				{
					max = lsum;
				}
				if (lsum < 0)
				{
					lsum = 0;
				}
				record[col][loop] = lsum;
			}
		}
	}
	printf("%d\n", max);
}

int main()
{
	while (scanf("%d", &size) != EOF)
	{
		Input();
		solve();
	}
	return 0;
}
