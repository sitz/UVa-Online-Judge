#include <bits/stdc++.h>

using namespace std;

/*
 Name: Mohamed Mayla
 Problem Name: 11664 - Langton's Ant
 Problem Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2711
 */

#define cnt(x, n) count(x.begin(), x.end(), n)
#define so(x) sort(x.begin(), x.end())
#define rso(x) sort(x.rbegin(), x.rend())
#define mx(x) *max_element(x.begin(), x.end())
#define mn(x) *min_element(x.begin(), x.end())
#define al(n) (n).begin(), (n).end()
#define ral(n) (n).rbegin(), (n).rend()
#define mp make_pair
#define REP(i, a, n) for (int i = int(a); i < int(n); i++)
#define rREP(i, a, n) for (int i = int(a); i >= int(n); --i)
#define RE(s) freopen(s, "r", stdin)
#define WR(s) freopen(s, "w", stdout)

int grid[20][20];
int x, y;
int n, len;
string c;
string bin;
int bb[105];

void init_grid()
{
	bin = string(bin.rbegin(), bin.rend());
	//cout<<bin<<endl;
	int cnt = 0;
	REP(row, 0, n)
	{
		REP(col, 0, n)
		{
			grid[row][col] = bin[cnt++] - '0';
		}
	}
}

void print_grid()
{
	for (int row = n - 1; row >= 0; row--)
	{
		REP(col, 0, n)
		{
			cout << grid[row][col] << " ";
		}
		cout << endl;
	}
}

bool simulate(int y, int x)
{
	int dir = 0;//0 up, 1 right, 2 down, 3 left
	while (true)
	{
		if (x >= n || y >= n || x < 0 || y < 0)
			return false;

		if (x == n - 1 && y == n - 1)
			return true;

		if (grid[x][y] == 0)
		{
			dir--;
			grid[x][y] = 1;
		}
		else
		{
			dir++;
			grid[x][y] = 0;
		}

		if (dir > 3)
			dir = 0;
		else if (dir < 0)
			dir = 3;

		switch (dir)
		{
		case 0:
			x++;
			break;
		case 1:
			y++;
			break;
		case 2:
			x--;
			break;
		case 3:
			y--;
			break;
		}
	}
}

int getBit()
{
	int ret = 0;
	for (int i = len; i >= 0; i--)
	{
		ret = ret * 10 + bb[i];
		bb[i] = ret / 2;
		ret %= 2;
	}
	while (len >= 0 && bb[len] == 0)
		len--;
	return ret;
}

void init_bin()
{
	len = c.length();
	memset(bb, 0, sizeof(bb));
	for (int i = 0, j = len - 1; i < len; i++, j--)
		bb[i] = c[j] - '0';
	REP(i, 0, n * n)
	{
		bin.push_back(getBit() + '0');
	}
}

int main()
{
	//RE("in.txt");

	while (cin >> n >> c >> x >> y && n)
	{
		bin.clear();
		init_bin();
		init_grid();
		//print_grid();

		if (simulate(x - 1, y - 1))
			cout << "Yes\n";
		else
			cout << "Kaputt!\n";
	}

	return 0;
}
