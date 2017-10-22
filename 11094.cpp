#include <bits/stdc++.h>

using namespace std;

#define num 20

char mat[num][num], land;
int mark[num][num];
int n, m, sr, sc;
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int dfs(int x, int y)
{
	int ret = 1;
	mark[x][y] = 1;
	for (int i = 0; i < 4; i++)
		if (x + dir[i][0] >= 0 && x + dir[i][0] < n && !mark[x + dir[i][0]][(y + dir[i][1] + m) % m] && mat[x + dir[i][0]][(y + dir[i][1] + m) % m] == land)
		{
			ret += dfs(x + dir[i][0], (y + dir[i][1] + m) % m);
		}
	return ret;
}

int main()
{
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> mat[i][j];
			}
		cin >> sr >> sc;
		memset(mark, 0, sizeof mark);
		land = mat[sr][sc];
		dfs(sr, sc);
		int mx = 0;
		int x;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!mark[i][j] && mat[i][j] == land && (x = dfs(i, j)) > mx)
				{
					mx = x;
				}
		cout << mx << endl;
	}
	return 0;
}
