#include <bits/stdc++.h>

using namespace std;

const int MAX = 0x7fffffff;
char chFrom[5], chTo[5];

int min;
int record[8][8][8][8];

struct Position
{
	int row, col;
} from, to;

void init()
{
	from.col = chFrom[0] - 'a';
	from.row = chFrom[1] - '1';
	to.col = chTo[0] - 'a';
	to.row = chTo[1] - '1';
}

void try_it(int r, int c, int cnt)
{
	if (r < 0 || r >= 8 || c < 0 || c >= 8 || cnt >= record[from.row][from.col][r][c])
	{
		return;
	}
	record[from.row][from.col][r][c] = cnt;
	try_it(r - 2, c - 1, cnt + 1);
	try_it(r - 2, c + 1, cnt + 1);
	try_it(r - 1, c - 2, cnt + 1);
	try_it(r - 1, c + 2, cnt + 1);
	try_it(r + 1, c - 2, cnt + 1);
	try_it(r + 1, c + 2, cnt + 1);
	try_it(r + 2, c - 1, cnt + 1);
	try_it(r + 2, c + 1, cnt + 1);
}

int main()
{
	int i, j, k, l;
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			for (k = 0; k < 8; k++)
				for (l = 0; l < 8; l++)
				{
					record[i][j][k][l] = MAX;
				}
	while (cin >> chFrom >> chTo)
	{
		init();
		try_it(from.row, from.col, 0);
		cout << "To get from " << chFrom << " to " << chTo << " takes ";
		cout << record[from.row][from.col][to.row][to.col] << " knight moves." << endl;
	}
	return 0;
}
