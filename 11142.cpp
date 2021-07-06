#include <bits/stdc++.h>

using namespace std;

#define swap(a, b) (a) ^= (b) ^= (a) ^= (b)
int m, n, c, t, cnt, rem[11][11], order[35][2], em[11][11], hadi;
char grid[11][11];
bool forced[35], arr[35], found;
bool prob[35][2];
bool isvalid(int x, int y)
{
	return x >= 0 && x < m && y >= 0 && y < n;
}
bool check(int x, int y)
{
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (isvalid(x + i, y + j) && rem[x + i][y + j] == 0 && isdigit(grid[x + i][y + j]))
			{
				return false;
			}
	return true;
}
bool bt(int s, int consider, int state)
{
	//cout << s << " " << c << " " << cnt  << endl;
	if (c == 0 && s == cnt)
	{
		for (int i = 0; i < cnt; i++)
		{
			prob[i][1] = prob[i][1] || arr[i];
		}
		return true;
	}
	if (s == cnt)
	{
		return false;
	}
	if (c > cnt - s)
	{
		return false;
	}
	int x = order[s][0], y = order[s][1];
	bool valid = true;
	bool canBeEmpty = true;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (isvalid(i + x, y + j) && isdigit(grid[x + i][y + j]))
			{
				em[x + i][y + j]--;
				if (em[x + i][y + j] < rem[x + i][y + j])
				{
					canBeEmpty = false;
				}
				if (em[x + i][y + j] == 0 && rem[x + i][y + j] > 1)
				{
					valid = false;
				}
				if (em[x + i][y + j] < 0)
				{
					canBeEmpty = valid = false;
				}
			}
	bool result = false;
	if (c == 0)
	{
		valid = false;
	}
	c--;
	arr[s] = true;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (isvalid(i + x, j + y) && isdigit(grid[i + x][j + y]))
			{
				rem[i + x][j + y]--;
				if (rem[i + x][j + y] < 0)
				{
					valid = false;
				}
			}
	if (valid && !(consider == s && state == 0))
		if (!result)
		{
			result = result || bt(s + 1, consider, state);
		}
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (isvalid(i + x, j + y) && isdigit(grid[i + x][j + y]))
			{
				rem[i + x][j + y]++;
			}
	arr[s] = false;
	c++;
	if (canBeEmpty && !(consider == s && state == 1))
	{
		result = result || bt(s + 1, consider, state);
	}
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (isvalid(i + x, j + y) && isdigit(grid[x + i][y + j]))
			{
				em[x + i][y + j]++;
			}
	return result;
}
int main()
{
	cin >> t;
	for (int I = 1; I <= t; I++)
	{
		//      cerr << "Doing " << I << endl;
		cin >> m >> n >> c;
		memset(grid, 0, sizeof grid);
		for (int i = 0; i < m; i++)
		{
			cin >> grid[i];
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (grid[i][j] == 'E')
				{
					grid[i][j] = '0';
				}
		cnt = 0;
		hadi = 0;
		memset(em, 0, sizeof em);
		memset(arr, 0, sizeof arr);
		memset(forced, 0, sizeof forced);
		memset(order, 0, sizeof order);
		memset(rem, 0, sizeof rem);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (isdigit(grid[i][j]))
				{
					rem[i][j] = grid[i][j] - '0';
					for (int x = -1; x <= 1; x++)
						for (int y = -1; y <= 1; y++)
							if (isvalid(i + x, j + y))
							{
								rem[i][j] -= (grid[i + x][j + y] == 'X') ? 1 : 0;
								em[i][j] += (grid[i + x][j + y] == '.') ? 1 : 0;
							}
					//cout << rem[i][j] << " " << em[i][j] << endl;
				}
				else if (grid[i][j] == '.')
				{
					order[cnt][0] = i, order[cnt][1] = j;
					cnt++;
				}
		if (cnt > 35)
		{
			cout << "Sedaye Bozghool" << endl;
		}
		//cout << cnt << endl;
		// a. Do a good ordering of cells
		// b. Do backtrack
		memset(forced, 0, sizeof forced);
		memset(arr, 0, sizeof arr);
		memset(prob, 0, sizeof prob);
		bool hadi = true;
		for (int i = 0; i < cnt; i++)
		{
			//cerr << i << endl;
			if (prob[i][0] == 0 && !check(order[i][0], order[i][1]))
			{
				prob[i][0] = true;
			}
			if (prob[i][0] == 0)
			{
				prob[i][0] = bt(0, i, 0);
			}
			if (prob[i][1] == 0 && check(order[i][0], order[i][1]))
			{
				prob[i][1] = bt(0, i, 1);
			}
			if (prob[i][1] && !prob[i][0])
			{
				forced[i] = true;
			}
			if (prob[i][1] == 0 && prob[i][0] == 0)
			{
				hadi = false;
			}
			/*          if(prob[i][0] == 0)
			                prob[i][0] = bt(0, i, 0);
			            if(prob[i][1] == 0)
			                prob[i][1] = bt(0, i, 1);
			            if(prob[i][1] && !prob[i][0])
			                forced[i] = true;*/
			//cout << i << " : " << (int)prob[i][0] << " " << (int)prob[i][1] << endl;
		}
		if (!hadi)
		{
			cerr << "Sedaye Shombool az " << I << endl;
		}
		//cout << hadi << endl;
		// c. Update grid
		for (int i = 0; i < cnt; i++)
			if (forced[i])
			{
				grid[order[i][0]][order[i][1]] = 'X';
			}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (grid[i][j] == '0')
				{
					grid[i][j] = 'E';
				}
		// d. Print Output
		cout << "Case #" << I << ":" << endl;
		for (int i = 0; i < m; i++)
		{
			cout << grid[i] << endl;
		}
	}
	return 0;
}
