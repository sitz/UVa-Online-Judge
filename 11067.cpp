#include <bits/stdc++.h>

using namespace std;

#define maxn 102

int R, C, Path[maxn][maxn];
char Fg[maxn][maxn];

void Count()
{
	int i, j;
	Path[0][C] = 1;
	for (i = C - 1; i >= 0; i--)
		if (Fg[0][i])
			Path[0][i] = 0;
		else
			Path[0][i] = Path[0][i + 1];
	for (i = 1; i <= R; i++)
		if (Fg[i][C])
			Path[i][C] = 0;
		else
			Path[i][C] = Path[i - 1][C];
	for (i = 1; i <= R; i++)
		for (j = C - 1; j >= 0; j--)
			if (Fg[i][j])
				Path[i][j] = 0;
			else
				Path[i][j] = Path[i][j + 1] + Path[i - 1][j];
	if (Path[R][0] == 0)
		cout << "There is no path.";
	else if (Path[R][0] == 1)
	{
		cout << "There is one path"
				 << " from Little Red Riding Hood's house to her grandmother's house.";
	}
	else
	{
		cout << "There are " << Path[R][0] << " paths from Little Red Riding"
				 << " Hood's house to her grandmother's house.";
	}
}

void Free()
{
	int i, j;
	for (i = 0; i <= R; i++)
		for (j = 0; j <= C; j++)
			Fg[i][j] = Path[i][j] = 0;
}

int main()
{
	int n, r, c;
	while (cin >> C >> R)
	{
		if (!R || !C)
			break;
		cin >> n;
		while (n--)
		{
			cin >> c >> r;
			r = R - r;
			Fg[r][c] = 1;
		}
		Count();
		cout << endl;
		Free();
	}
	return 0;
}
