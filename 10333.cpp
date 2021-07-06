#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define pb push_back
#define ALL(C) (C).begin(), (C).end()

const int H = 501, NUM = 501;

int dp[H][NUM];
char m[500][1000];

void make_table()
{
	rep(i, H) rep(j, NUM) dp[i][j] = -1;
	REP(i, 1, H)
	dp[i][1] = i;
	REP(k, 2, H)
	{
		rep(i, H)
		{
			REP(j, 1, NUM)
			{
				if (i - k < 0)
				{
					continue;
				}
				if (dp[i - k][j - 1] > -1 && k > dp[i - k][j - 1])
				{
					dp[i][j] = max(dp[i][j], k);
				}
			}
		}
	}
}

void make_seq(vector<int> &a, int h, int num)
{
	while (num > 0)
	{
		a.pb(dp[h][num]);
		h -= dp[h][num];
		num--;
	}
}

void make_tower(vector<int> &l, int h, int base)
{
	int total = 0;
	rep(j, l.size())
	{
		rep(i, l[j])
		{
			m[total + i][base + j * 2] = '#';
		}
		total += l[j];
		m[total - 1][base + j * 2 + 1] = '*';
		m[total - 1][base + j * 2 + 2] = '*';
		REP(i, total, h)
		{
			m[i][base + j * 2] = ' ';
			m[i][base + j * 2 + 1] = ' ';
		}
	}
}

void solve(int h)
{
	int num = 0;
	REP(i, 1, NUM)
	{
		if (dp[h][i] > -1 && dp[h][i - 1] > -1)
		{
			num = i;
		}
	}
	rep(i, 500) rep(j, 1000) m[i][j] = ' ';
	vector<int> l, r;
	int width = 0;
	make_seq(l, h, num);
	make_seq(r, h, num - 1);
	width = 2 + r.size() * 2 + l.size() * 2;
	rep(i, h)
	{
		rep(j, width) m[i][j] = '.';
		m[i][width] = '\0';
	}
	make_tower(l, h, 0);
	make_tower(r, h, 2 + r.size() * 2 + 1);
	rep(i, h)
	{
		reverse(m[i] + 3 + r.size() * 2, m[i] + width);
	}
	rep(i, h)
	{
		for (int j = width - 1; j >= 0; j--)
			if (m[h - i - 1][j] == ' ')
			{
				m[h - i - 1][j] = '\0';
			}
			else
			{
				break;
			}
		cout << m[h - 1 - i] << endl;
	}
}

main()
{
	make_table();
	int h, tc = 1;
	while (cin >> h)
	{
		cout << "Tower #" << tc++ << endl;
		solve(h);
		cout << endl;
	}
}
