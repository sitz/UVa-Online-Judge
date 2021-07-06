#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define pb push_back

void output(int in, int len)
{
	for (int i = len - 1; i >= 0; i--)
	{
		if (in & (1 << i))
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	cout << endl;
}

int getlen(int in)
{
	int len = 31;
	bool isop = false;
	for (int i = 31; i >= 0; i--)
	{
		if (in & (1 << i))
		{
			isop = true;
		}
		if (!isop)
		{
			len = i;
		}
	}
	return len;
}

bool isok(int n, int beg, int len)
{
	rep(i, len)
	{
		bool a = (n & (1 << (beg + i))) == 0, b = (n & (1 << (beg + len + i))) == 0;
		bool c = (n & (1 << (beg + len + len + i))) == 0;
		if (a == b && b == c)
			;
		else
		{
			return false;
		}
	}
	return true;
}
bool isTripleFree(int n, int len)
{
	rep(i, len)//pos
	{
		REP(j, 1, len)
		{
			if (i + j + j + j > len)
			{
				break;
			}
			if (isok(n, i, j))
			{
				return false;
			}
		}
	}
	return true;
}

const int N = 31;
vector<int> trip[N];
void makeall()
{
	int cnt = 0;
	trip[1].pb(0);
	trip[1].pb(1);
	REP(i, 2, 31)
	{
		rep(j, trip[i - 1].size())
		{
			rep(k, 2)
			{
				int now = trip[i - 1][j] * 2 + k;
				if (isTripleFree(now, i))
				{
					cnt++;
					trip[i].pb(now);
				}
			}
		}
	}
}

void solve(string &in)
{
	int n = (int)in.size();
	int cnt = 0;
	rep(i, (int)trip[n].size())
	{
		bool isok = true;
		rep(j, n)
		{
			int val = (trip[n][i] & (1 << j)) == 0;
			if ((val == 0 && in[j] == '1') ||
					(val != 0 && in[j] == '0'))
			{
				isok = false;
				break;
			}
		}
		if (isok)
		{
			cnt++;
		}
	}
	cout << cnt << endl;
}

main()
{
	makeall();
	int tc = 1;
	int n;
	string in;
	while (cin >> n >> in && n)
	{
		cout << "Case " << tc++ << ": ";
		solve(in);
	}
	return false;
}
