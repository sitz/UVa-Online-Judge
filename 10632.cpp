#include <bits/stdc++.h>

using namespace std;

const int Maxn = 55;
int n;
int col[Maxn][Maxn];
int dirx[] = {-1, 1, -1, 1};
int diry[] = {-1, 0, 0, 1};
int dir[] = {7, 1, 9, 3};
vector<int> vec;
void dfs(int r, int c)
{
	//cout << r << " " << c << endl;
	if (r == n && c == n)
	{
		return;
	}
	if (r == c)
	{
		int x = r + 1, y = c + 1;
		while (col[r][c] != 2)
		{
			vec.push_back(3);
			vec.push_back(7);
			col[x][y]++;
			col[x][y] %= 3;
			col[r][c]++;
		}
		if (col[x][y] == 2 && r == n - 1 && c == n - 1)
		{
			return;
		}
		vec.push_back(3);
		col[x][y]++;
		col[x][y] %= 3;
		while (x < n)
		{
			vec.push_back(1);
			x++;
			col[x][y]++;
			col[x][y] %= 3;
		}
		dfs(n, c + 1);
		return;
	}
	else
	{
		int x = r - 1, y = c;
		while (col[r][c] != 2)
		{
			vec.push_back(9);
			vec.push_back(1);
			col[x][y]++;
			col[x][y] %= 3;
			col[r][c]++;
		}
		vec.push_back(9);
		col[x][y]++;
		col[x][y] %= 3;
		dfs(x, y);
	}
}
int Col[Maxn][Maxn];
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		for (int i = 1; i <= n; ++i)
		{
			char str[Maxn];
			scanf("%s", str + 1);
			for (int j = 1; j <= i; ++j)
				if (str[j] == 'R')
				{
					Col[i][j] = col[i][j] = 0;
				}
				else if (str[j] == 'G')
				{
					Col[i][j] = col[i][j] = 1;
				}
				else
				{
					Col[i][j] = col[i][j] = 2;
				}
		}
		vec.clear();
		dfs(n, 1);
		if (col[n][n] != 2)
		{
			vec.clear();
			vec.push_back(1);
			Col[n][1]++;
			Col[n][1] %= 3;
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= i; ++j)
				{
					col[i][j] = Col[i][j];
				}
			dfs(n, 1);
			printf("%d 1\n", n - 1);
		}
		else
		{
			printf("%d 1\n", n);
		}
		assert(col[n][n] == 2);
		for (int i = 0; i < vec.size(); ++i)
		{
			printf("%d", vec[i]);
		}
		puts("");
	}
	return 0;
}
