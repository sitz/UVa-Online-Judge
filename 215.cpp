#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define ALL(C) (C).begin(), (C).end()

const int R = 20;
const int C = 10;

string ori[R][C];

int data[R][C];

bool isdecided[R][C];

int getdata(string &now, int &p, bool &canget)
{
	int tmp = 0;
	if (isdigit(now[p]) || now[p] == '-')
	{
		int sign = 1;
		if (now[p] == '-')
		{
			sign = -1;
		}
		while (p < now.size() && isdigit(now[p]))
		{
			tmp = tmp * 10 + now[p] - '0';
			p++;
		}
		tmp *= sign;
	}
	else
	{
		int rdata = now[p] - 'A', cdata = now[p + 1] - '0';
		p += 2;
		if (isdecided[rdata][cdata])
		{
			tmp = data[rdata][cdata];
		}
		else
		{
			canget = false;
		}
	}
	return tmp;
}

bool parse(int r, int c)
{
	int p = 0;
	string now = ori[r][c];
	bool canget = true;
	int tmp = getdata(now, p, canget);
	if (!canget)
	{
		return false;
	}
	while (p < now.size())
	{
		canget = true;
		if (now[p] == '+')
		{
			p++;
			tmp += getdata(now, p, canget);
		}
		else
		{
			p++;
			tmp -= getdata(now, p, canget);
		}
		if (!canget)
		{
			return false;
		}
	}
	data[r][c] = tmp;
	isdecided[r][c] = true;
	return true;
}

void solve(int r, int c)
{
	int total = r * c;
	int k;
	for (k = 0; k < total; k++)
	{
		bool isok = false;
		rep(i, r && !isok)
		{
			rep(j, c && !isok)
			{
				if (!isdecided[i][j] && parse(i, j))
				{
					isok = true;
					break;
				}
			}
		}
		if (!isok)
		{
			break;
		}
	}
	if (k == total)
	{
		putchar(' ');
		rep(i, c)
		{
			printf("%6d", i);
		}
		printf("\n");
		rep(i, r)
		{
			cout << (char)('A' + i);
			rep(j, c)
			{
				printf("%6d", data[i][j]);
			}
			cout << endl;
		}
	}
	else
	{
		rep(i, r)
		{
			rep(j, c)
			{
				if (!isdecided[i][j])
				{
					cout << (char)('A' + i) << j << ": " << ori[i][j] << endl;
				}
			}
		}
	}
}

main()
{
	int r, c;
	while (cin >> r >> c && r)
	{
		rep(i, r)
		{
			rep(j, c)
			{
				isdecided[i][j] = false;
				cin >> ori[i][j];
			}
		}
		solve(r, c);
		cout << endl;
	}
}
