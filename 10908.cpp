#include <bits/stdc++.h>

using namespace std;

#define maxn 105

int R, Col, Q, C[maxn][maxn], D[maxn][maxn];
char input[maxn], B[maxn][maxn];

void ReadCase()
{
	int i, j, v;
	for (i = 1; i <= R; i++)
	{
		gets(B[i]);
		for (j = 0; B[i][j]; j++)
		{
			v = B[i][j];
			C[i][j + 1] = C[i - 1][j + 1] + v;
		}
	}
}

int isSquare(int r1, int c1, int r2, int c2, int d)
{
	int i, j;
	if (r1 < 1 || c1 > Col || r2 > R || c2 < 1)
		return 0;
	for (i = c2; i <= c1; i++)
	{
		if (C[r2][i] - C[r1 - 1][i] != d)
			return 0;
	}
	return 1;
}

int Count(int r, int c)
{
	int ct = 1, r1, c1, r2, c2, d;
	r1 = r - 1;
	c1 = c + 1;
	r2 = r + 1;
	c2 = c - 1;
	d = B[r][c - 1] * 3;
	while (isSquare(r1, c1, r2, c2, d))
	{
		ct += 2;
		r1--;
		c1++;
		r2++;
		c2--;
		d += B[r][c - 1] * 2;
	}
	return ct;
}

void Cal()
{
	int r, c;
	printf("%d %d %d\n", R, Col, Q);
	while (Q--)
	{
		gets(input);
		sscanf(input, "%d%d", &r, &c);
		printf("%d\n", Count(r + 1, c + 1));
	}
}

int main()
{
	int kase, i;
	gets(input);
	kase = atoi(input);
	while (kase--)
	{
		gets(input);
		sscanf(input, "%d%d%d", &R, &Col, &Q);
		ReadCase();
		Cal();
	}
	return 0;
}
