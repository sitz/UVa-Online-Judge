#include <bits/stdc++.h>

using namespace std;

vector<string> sou;
//bool mark1[100][100];//向上是否遍历
bool mark[100][100];//向下是否遍历
int n, m;
int step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//下0 上1 右2 左3
int out = 0;
int nums = 0;
int maxs = 0;
void dfs(int starti, int startj, int i, int j, int direct, int cou, int redir)
{
	int tempi = i + step[direct][0], tempj = j + step[direct][1];
	if (direct == redir && tempi == starti && tempj == startj)
	{
		out = 1;
		nums++;
		if (cou > maxs)
		{
			maxs = cou;
		}
		return;
	}
	if (tempi >= 0 && tempi < n && tempj >= 0 && tempj < m)
	{
		if (direct == 0)
		{
			if (sou[tempi][tempj] == '\\')
			{
				dfs(starti, startj, tempi, tempj, 2, cou + 1, redir);
			}
			else
			{
				dfs(starti, startj, tempi, tempj, 3, cou + 1, redir);
			}
		}
		if (direct == 1)
		{
			mark[tempi][tempj] = false;
			if (sou[tempi][tempj] == '\\')
			{
				dfs(starti, startj, tempi, tempj, 3, cou + 1, redir);
			}
			else
			{
				dfs(starti, startj, tempi, tempj, 2, cou + 1, redir);
			}
		}
		if (direct == 2)
		{
			if (sou[tempi][tempj] == '\\')
			{
				mark[tempi][tempj] = false;
				dfs(starti, startj, tempi, tempj, 0, cou + 1, redir);
			}
			else
			{
				dfs(starti, startj, tempi, tempj, 1, cou + 1, redir);
			}
		}
		if (direct == 3)
		{
			if (sou[tempi][tempj] == '\\')
			{
				dfs(starti, startj, tempi, tempj, 1, cou + 1, redir);
			}
			else
			{
				mark[tempi][tempj] = false;
				dfs(starti, startj, tempi, tempj, 0, cou + 1, redir);
			}
		}
		if (out)
		{
			return;
		}
	}
	else
	{
		return;
	}
}
void print()
{
	for (int i = 0; i < sou.size(); i++)
	{
		cout << sou[i] << endl;
	}
}
void process()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			out = 0;
			if (mark[i][j])
			{
				int redir = (sou[i][j] == '\\' ? 2 : 3);
				dfs(i, j, i, j, 0, 1, redir);
			}
		}
	}
}
int main()
{
	string str;
	int cases = 0;
	while (cin >> m >> n)
	{
		nums = 0, maxs = 0;
		if (m == 0 && n == 0)
		{
			break;
		}
		cases++;
		memset(mark, true, sizeof(mark));
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			sou.push_back(str);
		}
		process();
		cout << "Maze #" << cases << ":" << endl;
		if (nums != 0)
		{
			cout << nums << " Cycles; the longest has length " << maxs << "." << endl
					 << endl;
		}
		else
		{
			cout << "There are no cycles." << endl
					 << endl;
		}
		sou.clear();
	}
	return 0;
}
/*
10 3
/\/\/\\\\/
\\\///\\/\
\\/\/\\\\/
0 0
Maze #1:
4 Cycles; the longest has length 8.
*/
