#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

const int N = 50;
const int M = 26;
const int K = 255;

int vis[M][N][N];
vector<string> edge[M];
char cangene[M][K];

int solve(int ch, int l, int r, string &in)
{
	if (r == l)
	{
		return cangene[ch][in[l]];
	}
	int &ret = vis[ch][l][r];
	if (ret == -1)
	{
		ret = 0;
		rep(i, (int)edge[ch].size())
		{
			int fir = edge[ch][i][0] - 'A', sec = edge[ch][i][1] - 'A';
			REP(i, l, r)
			{
				int a = solve(fir, l, i, in), b = solve(sec, i + 1, r, in);
				if (a + b == 2)
				{
					ret = 1;
					return ret;
				}
			}
		}
	}
	return ret;
}

int main()
{
	string in;
	while (cin >> in && in != "#")
	{
		int st = in[0] - 'A';
		rep(i, M) rep(j, K) cangene[i][j] = false;
		rep(i, M) edge[i].clear();
		string a, b;
		cin >> a >> b;
		string f, t, mid;
		while (cin >> f >> mid >> t && f != "#")
		{
			if (t.size() == 1)
			{
				cangene[f[0] - 'A'][t[0]] = true;
			}
			else
			{
				edge[f[0] - 'A'].push_back(t);
			}
		}
		string tar;
		while (cin >> tar && tar != "#")
		{
			rep(i, M) rep(j, N) rep(k, N) vis[i][j][k] = -1;
			int ans = solve(st, 0, tar.size() - 1, tar);
			cout << tar;
			if (ans == 0)
			{
				cout << " is not in L(G)" << endl;
			}
			else
			{
				cout << " is in L(G)" << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
