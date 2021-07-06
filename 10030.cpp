#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

class state
{
public:
#define FILE 1
#define EXT 0
	string in;
	int data[2];
	bool is_exist;
};

int check[1000];
void solve(int n, int m, state *in)
{
	int cnt = n;
	rep(k, m)
	{
		fill(check, check + n, 0);
		rep(i, n)
		{
			if (in[i].is_exist == true)
			{
				check[in[i].data[k % 2]]++;
			}
		}
		rep(i, n)
		{
			if (in[i].is_exist == true && check[in[i].data[k % 2]] == 1)
			{
				in[i].is_exist = false, cnt--;
			}
		}
	}
	cout << cnt << endl;
	rep(i, n) if (in[i].is_exist == true)
	{
		cout << in[i].in << endl;
	}
}

int main()
{
	int te, tc = 0;
	cin >> te;
	while (te--)
	{
		if (tc)
		{
			puts("");
		}
		tc++;
		int n, m;
		cin >> n >> m;
		map<string, int> File, Ext;
		state in[n];
		rep(i, n)
		{
			in[i].is_exist = true;
			cin >> in[i].in;
			int p = 0;
			string f = "", e = "";
			while (p < in[i].in.size() && in[i].in[p] != '.')
			{
				f += in[i].in[p++];
			}
			p++;
			while (p < in[i].in.size())
			{
				e += in[i].in[p++];
			}
			if (File.find(f) != File.end())
			{
				in[i].data[FILE] = File[f];
			}
			else
			{
				in[i].data[FILE] = File.size(), File[f] = in[i].data[FILE];
			}
			if (Ext.find(e) != Ext.end())
			{
				in[i].data[EXT] = Ext[e];
			}
			else
			{
				in[i].data[EXT] = Ext.size(), Ext[e] = in[i].data[EXT];
			}
		}
		solve(n, m, in);
	}
	return 0;
}
