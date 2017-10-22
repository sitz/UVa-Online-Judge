#include <bits/stdc++.h>

using namespace std;

//bool v[500][500];
int s[500][500];
int n, m, col;
bool flag;
void DFS(int r, int c, int len, int cycle)
{
	if (r == n - 1 && len == cycle)
	{
		if (!flag)
		{
			col = c;
		}
		else if (col > c)
		{
			col = c;
		}
		flag = true;
	}
	int nextlen = len, nextcycle = cycle + 1;
	if (cycle == len)
	{
		nextcycle = 1;
		nextlen++;
	}
	if (r - 1 >= 0 && s[r - 1][c] == nextcycle)
	{
		DFS(r - 1, c, nextlen, nextcycle);
	}
	if (r + 1 < n && s[r + 1][c] == nextcycle)
	{
		DFS(r + 1, c, nextlen, nextcycle);
	}
	if (c - 1 >= 0 && s[r][c - 1] == nextcycle)
	{
		DFS(r, c - 1, nextlen, nextcycle);
	}
	if (c + 1 < m && s[r][c + 1] == nextcycle)
	{
		DFS(r, c + 1, nextlen, nextcycle);
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int x = 0; x < t; x++)
	{
		if (x)
		{
			puts("");
		}
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &s[i][j]);
			}
		for (int i = 0; i < m; i++)
			if (s[0][i] == 1)
			{
				flag = false;
				DFS(0, i, 1, 1);
				if (flag)
				{
					printf("%d %d\n", 1, i + 1);
					printf("%d %d\n", n, col + 1);
					break;
				}
			}
	}
}
