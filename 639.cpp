#include <bits/stdc++.h>

using namespace std;

/**
639
**/
char B[5][5];
int N, MAX, K;
int Ilegal(int n)
{
	int r, c, i;
	r = n / N;
	c = n % N;
	for (i = r + 1; i < N; i++)
	{
		if (B[i][c] == 'X')
		{
			break;
		}
		if (B[i][c] == 'P')
		{
			return 0;
		}
	}
	for (i = r - 1; i >= 0; i--)
	{
		if (B[i][c] == 'X')
		{
			break;
		}
		if (B[i][c] == 'P')
		{
			return 0;
		}
	}
	for (i = c + 1; i < N; i++)
	{
		if (B[r][i] == 'X')
		{
			break;
		}
		if (B[r][i] == 'P')
		{
			return 0;
		}
	}
	for (i = c - 1; i >= 0; i--)
	{
		if (B[r][i] == 'X')
		{
			break;
		}
		if (B[r][i] == 'P')
		{
			return 0;
		}
	}
	return 1;
}
void Recur(int index, int level)
{
	int i, temp, r, c;
	if (level)
	{
		temp = index - 1;
		if (!Ilegal(index - 1))
		{
			return;
		}
		r = temp / N;
		c = temp % N;
		if (B[r][c] != 'X')
		{
			B[r][c] = 'P';
			K++;
			if (K > MAX)
			{
				MAX = K;
			}
		}
	}
	if (level == N * N)
	{
		return;
	}
	for (i = index; i < N * N; i++)
	{
		Recur(i + 1, level + 1);
	}
	if (r < N && r >= 0 && c < N && c >= 0)
	{
		if (B[r][c] == 'P')
		{
			B[r][c] = '.';
			K--;
		}
	}
}
int main()
{
	int i;
	while (scanf("%d", &N) == 1)
	{
		if (!N)
		{
			break;
		}
		for (i = 0; i < N; i++)
		{
			scanf("%s", B[i]);
		}
		MAX = K = 0;
		Recur(0, 0);
		printf("%d\n", MAX);
	}
	return 0;
}
