#include <bits/stdc++.h>

using namespace std;

int nextn[10][15] =
{
	{14, 29, 44, 43, 42, 41, 40, 126, 143, 144, 145, 146, 147, 148, 149},
	{1, 2, 3, 4, 5, 6, 22, 23, 114, 8, 9, 10, 11, 12, 13},
	{16, 17, 18, 19, 20, 55, 112, 96, 50, 85, 24, 25, 26, 27, 28},
	{104, 103, 102, 101, 35, 36, 97, 81, 65, 38, 39, 141, 140, 139, 138},
	{45, 46, 47, 48, 111, 51, 67, 82, 66, 53, 79, 56, 57, 58, 59},
	{60, 61, 62, 63, 64, 98, 83, -1, 68, 69, 70, 71, 72, 73, 74},
	{75, 76, 77, 78, 49, 113, 80, 52, 84, 54, 110, 86, 87, 88, 89},
	{30, 31, 32, 33, 34, 94, 95, 37, 99, 100, 142, 93, 92, 91, 90},
	{15, 105, 106, 107, 108, 109, 127, 128, 21, 115, 116, 117, 118, 119, 137},
	{0, 120, 121, 122, 123, 124, 125, 7, 129, 130, 131, 132, 133, 134, 136}
};
int diag[10][15] =
{
	{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
	{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
	{2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16},
	{3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17},
	{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18},
	{5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19},
	{6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
	{7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21},
	{8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22},
	{9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23}
};
int udiag[10][15] =
{
	{9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23},
	{8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22},
	{7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21},
	{6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
	{5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19},
	{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18},
	{3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17},
	{2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16},
	{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
	{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}
};

char ans[10][15], find_, tmp[10][15];
int hori[10], ver[15], topright[24], topleft[24];
int numhori[10], numver[15], numtopright[24], numtopleft[24];

int print()
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 15; j++)
		{
			putchar((tmp[i][j] ? '#' : '.'));
		}
		putchar('\n');
	}
	return 0;
}
int DFS(int x, int y)
{
	int f, i, j;
	if (find_ == 2)
	{
		return 1;
	}
	if (x == -1 && y == -1)
	{
		find_++;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 15; j++)
			{
				tmp[i][j] = ans[i][j];
			}
		}
		return 1;
	}
	if (hori[x] > 0 && ver[y] > 0 && topright[diag[x][y]] > 0 && topleft[udiag[x][y]] > 0)
	{
		hori[x]--, ver[y]--, topright[diag[x][y]]--, topleft[udiag[x][y]]--;
		ans[x][y] = 1;
		if (nextn[x][y] == -1)
		{
			f = DFS(-1, -1);
		}
		else
		{
			f = DFS(nextn[x][y] / 15, nextn[x][y] % 15);
		}
		if (find_ == 2)
		{
			return 1;
		}
		hori[x]++, ver[y]++, topright[diag[x][y]]++, topleft[udiag[x][y]]++;
	}
	if (numhori[x] > 0 && numver[y] > 0 && numtopright[diag[x][y]] > 0 && numtopleft[udiag[x][y]] > 0)
	{
		numhori[x]--, numver[y]--, numtopright[diag[x][y]]--, numtopleft[udiag[x][y]]--;
		ans[x][y] = 0;
		if (nextn[x][y] == -1)
		{
			f = DFS(-1, -1);
		}
		else
		{
			f = DFS(nextn[x][y] / 15, nextn[x][y] % 15);
		}
		if (find_ == 2)
		{
			return 1;
		}
		numhori[x]++, numver[y]++, numtopright[diag[x][y]]++, numtopleft[udiag[x][y]]++;
	}
	return 0;
}

int main()
{
	int c, i, j;
	scanf("%d", &c);
	for (; c; c--)
	{
		find_ = 0;
		for (i = 0, j = 1; i < 10; i++, j++)
		{
			numtopright[i] = numtopleft[i] = j;
		}
		for (; i < 15; i++)
		{
			numtopright[i] = numtopleft[i] = 10;
		}
		for (j = 9; i < 24; j--, i++)
		{
			numtopright[i] = numtopleft[i] = j;
		}
		for (i = 0; i < 10; i++)
		{
			scanf("%d", &hori[i]);
			numhori[i] = 15 - hori[i];
		}
		for (i = 0; i < 24; i++)
		{
			scanf("%d", &topright[i]);
			numtopright[i] -= topright[i];
		}
		for (i = 0; i < 15; i++)
		{
			scanf("%d", &ver[i]);
			numver[i] = 10 - ver[i];
		}
		for (i = 0; i < 24; i++)
		{
			scanf("%d", &topleft[i]);
			numtopleft[i] -= topleft[i];
		}
		DFS(9, 0);
		if (find_ == 1)
		{
			print();
		}
		else
		{
			for (i = 0; i < 10; i++)
			{
				for (j = 0; j < 15; j++)
				{
					tmp[i][j] = 0;
				}
			}
			print();
		}
		if (c > 1)
		{
			putchar('\n');
		}
	}
	return 0;
}
