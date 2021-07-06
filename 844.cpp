#include <bits/stdc++.h>

using namespace std;

int CaseN;
int N;
char Board[100][100];
bool Tie;

char Str[10];

inline bool StraightRow(int n, char color)
{
	for (int i = 0; i < N; ++i)
		if (Board[n][i] != color)
		{
			return false;
		}
	return true;
}

inline bool StraightCol(int n, char color)
{
	for (int i = 0; i < N; ++i)
		if (Board[i][n] != color)
		{
			return false;
		}
	return true;
}

inline int Straight(char color)
{
	int out = 0;
	for (int i = 0; i < N; ++i)
	{
		if (StraightRow(i, color))
		{
			++out;
		}
		if (StraightCol(i, color))
		{
			++out;
		}
	}
	return out;
}

inline void PutL(int n, char color)
{
	int p = 0;
	while (p < N - 1 && Board[n][p] != ' ')
	{
		++p;
	}
	while (p > 0)
	{
		Board[n][p] = Board[n][p - 1];
		--p;
	}
	Board[n][0] = color;
}

inline void PutR(int n, char color)
{
	int p = N - 1;
	while (p > 0 && Board[n][p] != ' ')
	{
		--p;
	}
	while (p < N - 1)
	{
		Board[n][p] = Board[n][p + 1];
		++p;
	}
	Board[n][N - 1] = color;
}

inline void PutT(int n, char color)
{
	int p = 0;
	while (p < N - 1 && Board[p][n] != ' ')
	{
		++p;
	}
	while (p > 0)
	{
		Board[p][n] = Board[p - 1][n];
		--p;
	}
	Board[0][n] = color;
}

inline void PutB(int n, char color)
{
	int p = N - 1;
	while (p > 0 && Board[p][n] != ' ')
	{
		--p;
	}
	while (p < N - 1)
	{
		Board[p][n] = Board[p + 1][n];
		++p;
	}
	Board[N - 1][n] = color;
}

int main()
{
	cin >> CaseN;
	for (--CaseN; CaseN >= 0; --CaseN)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
			{
				Board[i][j] = ' ';
			}
		Tie = true;
		char color = 'X';
		while (true)
		{
			cin >> Str;
			if (strcmp(Str, "QUIT") == 0)
			{
				if (Tie)
				{
					cout << "TIE GAME" << endl;
				}
				break;
			}
			if (Tie)
			{
				int n = 0;
				for (int p = 1; Str[p]; ++p)
				{
					n = n * 10 + Str[p] - '0';
				}
				--n;
				switch (Str[0])
				{
				case 'L':
					PutL(n, color);
					break;
				case 'R':
					PutR(n, color);
					break;
				case 'T':
					PutT(n, color);
					break;
				case 'B':
					PutB(n, color);
					break;
				}
				int a = Straight('X');
				int b = Straight('O');
				if (a > b)
				{
					Tie = false;
					cout << "X WINS" << endl;
				}
				else if (a < b)
				{
					Tie = false;
					cout << "O WINS" << endl;
				}
				if (color == 'X')
				{
					color = 'O';
				}
				else
				{
					color = 'X';
				}
			}
		}
		if (CaseN > 0)
		{
			cout << endl;
		}
	}
	return 0;
}
