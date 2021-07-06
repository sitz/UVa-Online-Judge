#include <bits/stdc++.h>

using namespace std;

int y_board[20] = {0};
int answer = 0;

void backtracking(int n, int y, int x, int slash1, int slash2)
{
	if (y == n)
	{
		answer++;
		return;
	}
	int nowslash1 = slash1 >> y;
	int nowslash2 = slash2 >> (n - y - 1);
	int canputqueen = y_board[y] & x & nowslash1 & nowslash2;
	int xput;
	while (canputqueen)
	{
		xput = canputqueen & (-canputqueen);
		backtracking(n, y + 1, x ^ xput, slash1 ^ (xput << y), slash2 ^ (xput << (n - y - 1)));
		canputqueen ^= xput;
	}
}

int main()
{
	int n;
	int casenumber = 1;
	while (scanf("%d", &n) != EOF && n != 0)
	{
		int i, j;
		char s[20] = {0};
		for (i = 0; i < n; i++)
		{
			scanf("%s", s);
			y_board[i] = (1 << n) - 1;
			for (j = 0; j < n; j++)
				if (s[j] == '*')
				{
					y_board[i] ^= (1 << j);
				}
		}
		answer = 0;
		backtracking(n, 0, (1 << n) - 1, (1 << (2 * n - 1)) - 1, (1 << (2 * n - 1)) - 1);
		printf("Case %d: %d\n", casenumber, answer);
		casenumber++;
	}
	return 0;
}
