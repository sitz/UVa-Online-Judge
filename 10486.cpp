#include <bits/stdc++.h>

using namespace std;

int n, m, d[50][50], a[50][50];
int mj, ori, cha, retmj, F;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void dodye(int s[][50], int x, int y, int &dyeno)
{
	int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
	int i, x1, y1;
	s[x][y] = dyeno;
	for (i = 0; i < 4; i++)
	{
		x1 = x + dir[i][0], y1 = y + dir[i][1];
		if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && s[x1][y1] != 0 && s[x1][y1] != dyeno)
		{
			dodye(s, x1, y1, dyeno);
		}
	}
}
int graphdye(int s[][50], int w, int h)
{
	int i, j, dyeno = 0;
	for (i = 0; i < w; i++)
		for (j = 0; j < h; j++)
			if (s[i][j] == -1)
			{
				dodye(s, i, j, (++dyeno));
			}
	return dyeno;
}
void done()
{
	int i, j, min;
	int num[1601];
	for (cha = 0; cha < 100; cha++)
	{
		for (min = 0; min < 100; min++)
		{
			memset(a, 0, sizeof(a));
			for (i = 0; i < n; i++)
				for (j = 0; j < m; j++)
					if (d[i][j] >= min && d[i][j] <= min + cha)
					{
						a[i][j] = -1;
					}
			graphdye(a, n, m);
			memset(num, 0, sizeof(num));
			for (i = 0; i < n; i++)
				for (j = 0; j < m; j++)
				{
					num[a[i][j]]++;
					if (a[i][j] && num[a[i][j]] >= mj)
					{
						cout << cha << endl;
						return;
					}
				}
		}
	}
}
int main()
{
	int i, j, k;
	while (cin >> n >> m)
	{
		for (i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> d[i][j];
			}
		cin >> k;
		for (i = 0; i < k; i++)
		{
			cin >> mj;
			done();
		}
		//break;
	}
	return 0;
}
