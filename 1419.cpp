#include <bits/stdc++.h>

using namespace std;

const int COL = 100;
const int ROW = 100;
const int INF = 1 << 30;
char win[COL][ROW];
int c, r, X, Y;
int a[30];

void out()
{
	int i, j;
	for (i = 0; i < c; i++)
	{
		for (j = 0; j < r; j++)
		{
			cout << win[i][j];
		}
		cout << endl;
	}
	for (i = 0; i < 26; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int IsWin(int x)
{
	int lx, ly, rx, ry;
	lx = ly = INF;
	rx = ry = -1;
	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
		{
			if (win[i][j] == x + 'A')
			{
				lx = min(lx, i);
				ly = min(ly, j);
				rx = max(rx, i);
				ry = max(ry, j);
			}
		}
	if (lx == INF || ly == INF || rx == -1 || ry == -1 || rx - lx < 2 || ry - ly < 2)
	{
		return false;
	}
	for (int i = lx; i <= rx; i++)
		if (win[i][ly] != x + 'A' || win[i][ry] != x + 'A')
		{
			return false;
		}
	for (int i = ly; i <= ry; i++)
		if (win[lx][i] != x + 'A' || win[rx][i] != x + 'A')
		{
			return false;
		}
	for (int i = lx + 1; i < rx; i++)
		for (int j = ly + 1; j < ry; j++)
			if (win[i][j] != '.')
			{
				return false;
			}
	return true;
}
void solve()
{
	char ch;
	int i, j;
	for (i = 0; i < c; i++)
		for (j = 0; j < r; j++)
			if (win[i][j] != '.')
			{
				a[win[i][j] - 'A']++;
			}
	for (i = 0; i < 26; i++)
	{
		if (!a[i])
		{
			continue;
		}
		if (IsWin(i))
		{
			ch = i + 'A';
			cout << ch;
		}
	}
}

int main()
{
	int i, j;
	while (cin >> c >> r)
	{
		if (!c && !r)
		{
			break;
		}
		for (i = 0; i < c; i++)
			for (j = 0; j < r; j++)
			{
				cin >> win[i][j];
			}
		memset(a, 0, sizeof(a));
		solve();
		cout << endl;
	}
	return 0;
}
