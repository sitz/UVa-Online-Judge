#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define pb push_back
#define mp make_pair
#define ALL(C) (C).begin(), (C).end()
int getnum(string &a, map<string, int> &M, vector<string> &in)
{
	int index = M.size();
	if (M.find(a) == M.end())
	{
		M[a] = index, in.pb(a);
	};
	return M[a];
}
const int N = 2000;
vector<int> edge[N];
vector<int> cango[N];
bool vis[N];
bool ispair(int a, int b, vector<int> &va, vector<int> &vb)
{
	return !binary_search(ALL(va), b) && !binary_search(ALL(vb), a);
}
void dfs(int now, vector<int> &a)
{
	if (vis[now])
	{
		return;
	}
	vis[now] = true;
	a.pb(now);
	rep(i, edge[now].size()) dfs(edge[now][i], a);
}
void op(string a, string b)
{
	cout << "(" << a << "," << b << ")";
}
void dfsall(int n)
{
	rep(i, n)
	{
		rep(j, n) vis[j] = false;
		dfs(i, cango[i]);
	}
}
void solve(int n, vector<string> &in)
{
	dfsall(n);
	rep(i, n) sort(ALL(cango[i]));
	/*
	rep(i,n){
	  cout << i <<" " << in[i]<<":";
	  rep(j,cango[i].size())cout << in[cango[i][j]]<<" ";
	  cout << endl;
	}
	*/
	pair<int, int> p1(-1, -1), p2(-1, -1);
	int cnt = 0;
	rep(i, n)
	{
		REP(j, i + 1, n)
		{
			if (ispair(i, j, cango[i], cango[j]))
			{
				//cout  <<in[i]<<" " << in[j] << endl;
				cnt++;
				if (p1.first == -1)
				{
					p1 = mp(i, j);
				}
				else if (p2.first == -1)
				{
					p2 = mp(i, j);
				}
			}
		}
	}
	if (cnt == 0)
	{
		cout << "no concurrent events." << endl;
	}
	else
	{
		cout << cnt << " concurrent events:" << endl;
		if (p1.first != -1)
		{
			op(in[p1.first], in[p1.second]), cout << ' ';
		}
		if (p2.first != -1)
		{
			op(in[p2.first], in[p2.second]), cout << ' ';
		}
		cout << endl;
	}
}
int main()
{
	int n, m;
	int tc = 1;
	while (cin >> n && n)
	{
		map<string, int> M;
		vector<string> in;
		rep(i, N) edge[i].clear(), cango[i].clear();
		rep(i, n)
		{
			int tmp;
			cin >> tmp;
			string a;
			int f, t;
			cin >> a;
			f = getnum(a, M, in);
			rep(j, tmp - 1)
			{
				cin >> a;
				t = getnum(a, M, in);
				edge[f].pb(t);
				f = t;
			}
		}
		cin >> m;
		rep(i, m)
		{
			string a;
			int b[2];
			rep(j, 2) cin >> a, b[j] = getnum(a, M, in);
			edge[b[0]].pb(b[1]);
		}
		cout << "Case " << tc++ << ", ";
		solve(M.size(), in);
	}
	return 0;
}
