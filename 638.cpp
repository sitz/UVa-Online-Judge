#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define ALL(C) (C).begin(), (C).end()
#define pb push_back

const int N = 51;

class state
{
public:
	string name;
	int y;
	bool operator<(const state &a) const
	{
		return y < a.y;
	}
};

vector<state> in[N];
int isexist[N][N];

void solve()
{
	vector<string> ans;
	rep(i, N) sort(ALL(in[i]));
	rep(i, N) rep(j, N) isexist[i][j] = -1;
	rep(i, N)
	{
		rep(j, in[i].size())
		{
			isexist[i][in[i][j].y] = j;
		}
	}
	rep(i, N)
	{
		rep(j, in[i].size())
		{
			REP(k, j + 1, in[i].size())
			{
				REP(l, i + 1, N)
				{
					int index[2] = {isexist[l][in[i][j].y], isexist[l][in[i][k].y]};
					if (index[0] != -1 && index[1] != -1)
					{
						string tmp = "";
						tmp += in[l][index[0]].name[0];
						tmp += in[l][index[1]].name[0];
						tmp += in[i][k].name[0];
						tmp += in[i][j].name[0];
						//tmp = "dummy";
						ans.pb(tmp);
					}
				}
			}
		}
	}
	sort(ALL(ans));
	if (ans.size() == 0)
	{
		cout << " No rectangles" << endl;
	}
	else
	{
		cout << endl;
		rep(i, ans.size())
		{
			if (i > 0 && i % 10 == 0)
			{
				cout << endl;
			}
			cout << ' ' << ans[i];
		}
		cout << endl;
	}
}

main()
{
	int n;
	int tc = 1;
	while (cin >> n && n)
	{
		rep(i, N) in[i].clear();
		rep(i, n)
		{
			string tname;
			int tx, ty;
			cin >> tname >> ty >> tx;
			in[tx].pb((state){
					tname, ty});
		}
		cout << "Point set " << tc++ << ":";
		solve();
	}
}
