#include <bits/stdc++.h>

using namespace std;

int Illegal, Req, B[10][10], Col[9][10], Row[9][10], Sub[3][3][10];

void ReadCase()
{
	int i, j, n, sr, sc, pos;
	Illegal = Req = 0;
	for (i = 0; i < 9; i++)
	{
		sr = i / 3;
		for (j = 0; j < 9; j++)
		{
			if (i == 0 && j == 0)
				continue;
			cin >> n;
			B[i][j] = n;
			if (!n)
			{
				Req++;
				continue;
			}
			sc = j / 3;
			if (Row[i][n] || Col[j][n] || Sub[sr][sc][n])
				Illegal = 1;
			Row[i][n] = 1;
			Col[j][n] = 1;
			Sub[sr][sc][n] = 1;
		}
	}
}

int Recur(int r, int c, int n, int level)
{
	int sr, sc, i, j, f = 0, k, count = 0, g = 0;
	if (Row[r][n] || Col[c][n])
		return 0;
	sr = r / 3;
	sc = c / 3;
	if (Sub[sr][sc][n])
		return 0;
	if (level == Req)
		return 1;
	Row[r][n] = Col[c][n] = 1;
	Sub[sr][sc][n] = 1;
	B[r][c] = n;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
			if (B[i][j] == 0)
			{
				f = 1;
				break;
			}
		if (f)
			break;
	}
	for (k = 1; k <= 9; k++)
	{
		count += Recur(i, j, k, level + 1);
		if (count > 1)
			break;
	}
	B[r][c] = 0;
	Sub[sr][sc][n] = 0;
	Col[c][n] = Row[r][n] = 0;
	return count;
}

void Cal()
{
	int i, j, sr, sc, f = 0, count = 0;
	if (Illegal)
	{
		cout << "Illegal.\n";
		return;
	}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
			if (B[i][j] == 0)
			{
				f = 1;
				break;
			}
		if (f)
			break;
	}
	for (int k = 1; k <= 9; k++)
	{
		count += Recur(i, j, k, 1);
		if (count > 1)
			break;
	}
	if (count == 0)
		cout << "Impossible.\n";
	else if (count == 1)
		cout << "Unique.\n";
	else
		cout << "Ambiguous.\n";
}

void Free()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			Row[i][j] = Col[i][j] = 0;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 10; k++)
				Sub[i][j][k] = 0;
}

int main()
{
	int n, k = 1;
	while (cin >> n)
	{
		B[0][0] = n;
		Row[0][n] = 1;
		Col[0][n] = 1;
		Sub[0][0][n] = 1;
		ReadCase();
		cout << "Case " << k++ << ": ";
		Cal();
		Free();
	}
	return 0;
}
