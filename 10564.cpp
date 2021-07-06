#include <bits/stdc++.h>

using namespace std;

#define MAXN 42
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)

typedef long long Long;

struct ss
{
	int u;
} Size[MAXN];
struct bd
{
	int max, min, val;
};
bd B[MAXN][MAXN];
char Fg[MAXN][MAXN][355];
Long C[MAXN][MAXN][355];
int N, S, O;

void Set()
{
	int i, l = N;
	O = N;
	for (i = 1; i <= N; i++)
		Size[i].u = l--;
	l = 2;
	for (i = N + 1; i < 2 * N; i++)
		Size[i].u = l++;
	N = N * 2 - 1;
}
void Dynamic()
{
	int i, j;
	for (i = 1; i <= Size[N].u; i++)
		B[N][i].max = B[N][i].min = B[N][i].val;
	for (i = N - 1; i >= 1; i--)
	{
		for (j = 1; j <= Size[i].u; j++)
		{
			if (i >= O)
			{
				B[i][j].max = max(B[i][j].val + B[i + 1][j].max,
													B[i][j].val + B[i + 1][j + 1].max);
				B[i][j].min = min(B[i][j].val + B[i + 1][j].min,
													B[i][j].val + B[i + 1][j + 1].min);
			}
			else
			{
				if (j == 1)
				{
					B[i][j].max = B[i][j].val + B[i + 1][j].max;
					B[i][j].min = B[i][j].val + B[i + 1][j].min;
				}
				else if (j == Size[i].u)
				{
					B[i][j].max = B[i][j].val + B[i + 1][j - 1].max;
					B[i][j].min = B[i][j].val + B[i + 1][j - 1].min;
				}
				else
				{
					B[i][j].max = max(B[i][j].val + B[i + 1][j].max,
														B[i][j].val + B[i + 1][j - 1].max);
					B[i][j].min = min(B[i][j].val + B[i + 1][j].min,
														B[i][j].val + B[i + 1][j - 1].min);
				}
			}
		}
	}
}
char Path[45];
int done;
Long Recur(int sum, int r, int c, int dir)
{
	Long temp = 0;
	if (Fg[r][c][sum] == 1)
		return C[r][c][sum];
	if (r > 1 && done)
	{
		if (dir == 1)
			Path[r - 2] = 'L';
		else
			Path[r - 2] = 'R';
	}
	if (r == N)
	{
		if (sum + B[r][c].val == S)
		{
			if (done)
			{
				Path[r - 1] = NULL;
				done = 0;
			}
			return 1;
		}
		return 0;
	}
	if (B[r][c].max + sum < S)
		return 0;
	if (B[r][c].min + sum > S)
		return 0;
	Fg[r][c][sum] = 1;
	if (r < O)
	{
		if (c == Size[r].u)
			temp += Recur(sum + B[r][c].val, r + 1, c - 1, 1);
		else if (c == 1)
			temp += Recur(sum + B[r][c].val, r + 1, c, 2);
		else
		{
			temp += Recur(sum + B[r][c].val, r + 1, c - 1, 1);
			temp += Recur(sum + B[r][c].val, r + 1, c, 2);
		}
	}
	else
	{
		temp += Recur(sum + B[r][c].val, r + 1, c, 1);
		temp += Recur(sum + B[r][c].val, r + 1, c + 1, 2);
	}
	C[r][c][sum] = temp;
	return C[r][c][sum];
}
void Cal()
{
	int i, c, d = 0;
	Long count = 0;
	Dynamic();
	done = 1;
	for (i = 1; i <= O; i++)
	{
		if (B[1][i].min <= S && S <= B[1][i].max)
			count += Recur(0, 1, i, 0);
		if (count > 0 && d == 0)
		{
			c = i;
			d = 1;
		}
	}
	printf("%lld\n", count);
	if (count)
	{
		printf("%d ", c - 1);
		puts(Path);
	}
	else
		puts("");
}
void Free()
{
	int i, j, max = 0;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= Size[i].u; j++)
			for (int k = 0; k <= 352; k++)
				Fg[i][j][k] = 0;
	}
}

int main()
{
	int i, j;
	while (scanf("%d%d", &N, &S) && (N || S))
	{
		Set();
		for (i = 1; i <= N; i++)
			for (j = 1; j <= Size[i].u; j++)
				scanf("%d", &B[i][j].val);
		Cal();
		Free();
	}
	return 0;
}
