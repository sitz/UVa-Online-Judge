#include <bits/stdc++.h>

using namespace std;

/*
Counting Rectangles
10502
*/
#define MAX 105
char Field[MAX][MAX];
int A[MAX][MAX];
int R, C;
int Sum(int n)
{
	int m = n + 1;
	int s = (n * (m)) / 2;
	return s;
}
int Rcount(int n)
{
	int i, j = 0, c, total = 0;
	while (j < R)
	{
		c = 0;
		for (i = j; i < R && Field[i][n] == '1'; i++)
		{
			c++;
		}
		total += Sum(c);
		for (j = i; j < R && Field[j][n] == '0'; j++)
			;
	}
	return total;
}
int Compare(int n, int m)
{
	int i, j = 0, k, l, d = m - n, total = 0, c;
	if (m > C || n > C)
	{
		return 0;
	}
	while (j < R)
	{
		i = j;
		c = 0;
		while (i < R)
		{
			k = A[i][n];
			l = A[i][m];
			if (l - k == d && Field[i][n] == '1' && Field[i][m] == '1')
			{
				c++;
			}
			else
			{
				break;
			}
			i++;
		}
		total += Sum(c);
		j = i;
		while (j < R)
		{
			k = A[j][n];
			l = A[j][m];
			if (l - k == d && Field[j][n] == '1' && Field[j][m] == '1')
			{
				break;
			};
			j++;
		}
	}
	return total;
}
void Cal()
{
	int i, j, total = 0;
	for (i = 1; i <= C; i++)
	{
		total += Rcount(i);
		for (j = i + 1; j <= C; j++)
		{
			total += Compare(i, j);
		}
	}
	printf("%d\n", total);
}
void Free()
{
	int i, j;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j <= C; j++)
		{
			A[i][j] = 0;
		}
	}
}
int main()
{
	int i, j;
	while (scanf("%d", &R) == 1)
	{
		if (!R)
		{
			break;
		}
		scanf("%d", &C);
		for (i = 0; i < R; i++)
		{
			scanf("%s", &(Field[i][1]));
			A[i][1] = Field[i][1] - '0';
			for (j = 2; Field[i][j]; j++)
			{
				A[i][j] += (A[i][j - 1] + Field[i][j] - '0');
			}
		}
		Cal();
		Free();
	}
	return 0;
}
