#include <bits/stdc++.h>

using namespace std;

int N;			 // rows
int M;			 // columns
bool V[3][3];// visited
int S;			 // num solutions

// a bit hardcoded here (assumes that the maximum is 3x3)
bool isSelectable(int ci, int cj, int li, int lj)
{
	if (li == ci)
	{
		if (abs(cj - lj) > 1 && !V[li][1])
		{
			return false;
		}
	}
	else if (lj == cj)
	{
		if (abs(ci - li) > 1 && !V[1][lj])
		{
			return false;
		}
	}
	else
	{
		if (abs(ci - li) == 2 && abs(cj - lj) == 2 && !V[1][1])
		{
			return false;
		}
	}

	return true;
}

void findSol(int lasti, int lastj)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (!V[i][j])
			{
				if ((lasti == -1 && lastj == -1) ||
						isSelectable(i, j, lasti, lastj))
				{
					V[i][j] = true;
					findSol(i, j);
					V[i][j] = false;
					++S;
				}
			}
		}
	}
}

int main()
{
	int T = 0;

	while (cin >> N >> M)
	{
		if (N == 0 && M == 0)
		{
			break;
		}

		S = 0;
		findSol(-1, -1);
		cout << "Case #" << ++T << ": " << S << "\n";
	}

	return 0;
}
