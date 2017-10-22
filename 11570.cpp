#include <bits/stdc++.h>

using namespace std;

char D[17][17];
int T[9][9];
bool UR[9][10];// use j at row i
bool UC[9][10];// use j at col i
bool UB[9][10];// use j at box i

void init()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			UR[i][j] = UC[i][j] = UB[i][j] = false;
		}
	}
}

bool checkHorizontal(int left, char op, int right)
{
	if (op == '<')
		return (left < right);
	else
		return (left > right);
}

bool checkVertical(int top, char op, int bottom)
{
	if (op == '^')
		return (top < bottom);
	else
		return (top > bottom);
}

bool recursive(int pos)
{
	if (pos == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (j)
					cout << " ";
				cout << T[i][j];
			}
			cout << endl;
		}
		return true;
	}

	int i = pos / 9;
	int j = pos % 9;

	for (int n = 1; n <= 9; n++)
	{
		if (UR[i][n] || UC[j][n] || UB[(i / 3) * 3 + (j / 3)][n])
			continue;

		if (j > 0 && j % 3 != 0 && !checkHorizontal(T[i][j - 1], D[i * 2][j * 2 - 1], n))
			continue;
		if (i > 0 && i % 3 != 0 && !checkVertical(T[i - 1][j], D[i * 2 - 1][j * 2], n))
			continue;

		UR[i][n] = UC[j][n] = UB[(i / 3) * 3 + (j / 3)][n] = true;
		T[i][j] = n;
		if (recursive(pos + 1))
			return true;
		UR[i][n] = UC[j][n] = UB[(i / 3) * 3 + (j / 3)][n] = false;
	}

	return false;
}

int main()
{
	int tcase = 0;
	while (cin >> D[0][1])
	{
		for (int j = 3; j <= 15; j += 2)
		{
			if (!(j == 5 || j == 11))
				cin >> D[0][j];
		}
		for (int i = 1; i <= 16; i++)
		{
			if (i == 5 || i == 11)
				continue;
			if (i % 2 == 0)
			{
				for (int j = 1; j <= 15; j += 2)
				{
					if (!(j == 5 || j == 11))
						cin >> D[i][j];
				}
			}
			else
			{
				for (int j = 0; j <= 16; j += 2)
					cin >> D[i][j];
			}
		}
		if (tcase++)
			cout << endl;
		init();
		recursive(0);
	}

	return 0;
}
