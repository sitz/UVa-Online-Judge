#include <bits/stdc++.h>

using namespace std;

#define MAXLINES 12
#define MAXCELLS 48
#define MAXINT 10
#define EMPTY (-1)
#define MAXTYPES (1 << 12)

int maxValue[MAXLINES];
int cells[MAXCELLS];
string belongs[MAXCELLS] =
		{
				"EL",
				"EK", "EL", "FL",
				"AI", "AI", "AJ", "AEJ", "AEK", "AFK", "AFL", "AGL", "AG", "AH", "AH",
				"BI", "BEI", "BEJ", "BFJ", "BFK", "BGK", "BGL", "BHL", "BH",
				"CE", "CEI", "CFI", "CFJ", "CGJ", "CGK", "CHK", "CHL", "CL",
				"DE", "DE", "DF", "DFI", "DGI", "DGJ", "DHJ", "DHK", "DK", "DL", "DL",
				"GI", "HI", "HJ",
				"HI"};
int lines[MAXLINES][MAXLINES - 1] =
		{
				{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
				{15, 16, 17, 18, 19, 20, 21, 22, 23, EMPTY, EMPTY},
				{24, 25, 26, 27, 28, 29, 30, 31, 32, EMPTY, EMPTY},
				{33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43},
				{0, 1, 2, 7, 8, 16, 17, 24, 25, 33, 34},
				{3, 9, 10, 18, 19, 26, 27, 35, 36, EMPTY, EMPTY},
				{11, 12, 20, 21, 28, 29, 37, 38, 44, EMPTY, EMPTY},
				{13, 14, 22, 23, 30, 31, 39, 40, 45, 46, 47},
				{4, 5, 15, 16, 25, 26, 36, 37, 44, 45, 47},
				{6, 7, 17, 18, 27, 28, 38, 39, 46, EMPTY, EMPTY},
				{1, 8, 9, 19, 20, 29, 30, 40, 41, EMPTY, EMPTY},
				{0, 2, 3, 10, 11, 21, 22, 31, 32, 42, 43}};
int dp()
{
	int sum[MAXTYPES], tmp[MAXTYPES];
	memset(sum, EMPTY, sizeof(sum));
	sum[0] = 0;
	for (int i = 0; i < MAXLINES; i++)
	{
		memcpy(tmp, sum, sizeof(sum));
		for (int j = 0; j < MAXTYPES; j++)
			if (sum[j] > EMPTY)
			{
				for (int k = 0; k < MAXLINES - 1; k++)
				{
					if (lines[i][k] == EMPTY)
					{
						break;
					}
					if (cells[lines[i][k]] == maxValue[i])
					{
						int t = j;
						string cell = belongs[lines[i][k]];
						for (int c = 0; c < cell.length(); c++)
							if (cells[lines[i][k]] == maxValue[cell[c] - 'A'])
							{
								t = t | (1 << (cell[c] - 'A'));
							}
						if (tmp[t] > EMPTY)
						{
							tmp[t] = min(tmp[t], sum[j] + maxValue[i]);
						}
						else
						{
							tmp[t] = sum[j] + maxValue[i];
						}
					}
				}
			}
		memcpy(sum, tmp, sizeof(tmp));
	}
	return sum[MAXTYPES - 1];
}

int main()
{
	string line;
	while (getline(cin, line))
	{
		istringstream iss(line);
		for (int i = 0; i < MAXLINES; i++)
		{
			iss >> maxValue[i];
		}
		memset(cells, 0, sizeof(cells));
		for (int i = 0; i < MAXCELLS; i++)
		{
			int value = MAXINT;
			for (int j = 0; j < belongs[i].length(); j++)
				value = min(value,
										maxValue[belongs[i][j] - 'A']);
			cells[i] = value;
		}
		bool noSolution = false;
		for (int i = 0; i < MAXLINES; i++)
		{
			int tmp = 0;
			for (int j = 0; j < MAXLINES - 1; j++)
			{
				if (lines[i][j] == EMPTY)
				{
					break;
				}
				tmp = max(tmp, cells[lines[i][j]]);
			}
			if (tmp != maxValue[i])
			{
				noSolution = true;
				break;
			}
		}
		if (noSolution)
		{
			cout << "NO SOLUTION" << endl;
		}
		else
		{
			int maxSum = 0;
			for (int i = 0; i < MAXCELLS; i++)
			{
				maxSum += cells[i];
			}
			int minSum = dp();
			cout << minSum << " " << maxSum << endl;
		}
	}
	return 0;
}
