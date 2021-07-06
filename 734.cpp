#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

const int mod = 6;

class st
{
public:
	int p;
	vector<int> num[6];
	void set(string a)
	{
		p = 6;
		rep(i, 6)
		{
			rep(j, 6) num[i].push_back(a[j] - '0');
			a = a.substr(1) + a[0];
		}
	}
};

bool solve(int now, vector<int> *ans, int *id, bool *used, st *in)
{
	if (now == 6)
	{
		if (ans[1][4] != ans[6][1])
		{
			return false;
		}
		cout << "PEG   HEX   POSITION" << endl;
		cout << "---   ---   --------" << endl;
		set<int> S;
		rep(i, 7)
		{
			S.insert(id[i]);
			cout << " " << i << "     " << (char)(id[i] + 'A') << "     ";
			rep(j, 6) cout << ans[i][j];
			cout << endl;
		}
		return true;
	}
	rep(i, 7)
	{
		if (used[i])
		{
			continue;
		}
		used[i] = true;
		rep(j, in[i].p)
		{
			vector<int> &check = in[i].num[j];
			if (ans[0][now] == check[(now + 3) % mod] &&
					(now == 0 || check[(now - 2 + mod) % mod] == ans[now][(now + 1) % mod]))
			{
				ans[now + 1] = check;
				id[now + 1] = i;
				if (solve(now + 1, ans, id, used, in))
				{
					return true;
				}
			}
		}
		used[i] = false;
	}
	return false;
}

bool solve(st *in)
{
	vector<int> ans[7];
	int id[7];
	bool used[7] = {false};
	rep(i, 7)
	{
		ans[0] = in[i].num[0];
		id[0] = i;
		used[i] = true;
		if (solve(0, ans, id, used, in))
		{
			return true;
		}
		used[i] = false;
	}
	cout << "No solution possible" << endl;
	return false;
}

main()
{
	string tmp;
	while (cin >> tmp)
	{
		st in[7];
		in[0].set(tmp);
		REP(i, 1, 7)
				cin >> tmp,
				in[i].set(tmp);
		solve(in);
		cout << "************************************" << endl;
		cin >> tmp;
	}
	return false;
}
