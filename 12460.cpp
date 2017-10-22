#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

const ll P1 = 131;
const ll P2 = 1000000007;

ll P1k[100000];// P1^k mod P2

struct hashed
{
	int len;
	ll h;
	hashed() {}
	hashed(const string &s)
	{
		len = s.length();
		h = 0;
		rep(k, len) h += s[k] * P1k[k];
		h %= P2;
	}
	bool operator<(const hashed &H) const
	{
		return len < H.len || len == H.len && h < H.h;
	}
	bool operator==(const hashed &H) const
	{
		return len == H.len && h == H.h;
	}
	bool operator!=(const hashed &H) const
	{
		return !(*this == H);
	}
};

int main()
{
	P1k[0] = 1;
	rep(k, 99999) P1k[k + 1] = P1k[k] * P1 % P2;
	vector<string> dic_s;
	while (1)
	{
		string s;
		cin >> s;
		if (s == "--")
		{
			break;
		}
		dic_s.push_back(s);
	}
	int n = dic_s.size();
	vector<hashed> dic(n);
	rep(i, n) dic[i] = hashed(dic_s[i]);
	vector<pair<hashed, string>> tmp(n);
	rep(i, n) tmp[i] = make_pair(dic[i], dic_s[i]);
	sort(tmp.begin(), tmp.end());
	rep(i, n)
	{
		dic[i] = tmp[i].first;
		dic_s[i] = tmp[i].second;
	}
	while (1)
	{
		string s0, t0;
		if (!(cin >> s0 >> t0))
		{
			break;
		}
		hashed s(s0), t(t0);
		int id_s = lower_bound(dic.begin(), dic.end(), s) - dic.begin();
		int id_t = lower_bound(dic.begin(), dic.end(), t) - dic.begin();
		if (id_s == n || dic[id_s] != s || id_t == n || dic[id_t] != t)
		{
			cout << "No" << endl;
			continue;
		}
		vector<bool> vis(n);
		vis[id_s] = true;
		bool ans = false;
		queue<int> Q;
		Q.push(id_s);
		while (!Q.empty())
		{
			int id = Q.front();
			Q.pop();
			if (id == id_t)
			{
				ans = true;
				break;
			}
			rep(c, 128) if (isprint(c)) rep(k, dic[id].len)
			{
				hashed H = dic[id];
				H.h += (c - dic_s[id][k]) * P1k[k];
				H.h %= P2;
				if (H.h < 0)
				{
					H.h += P2;
				}
				int id2 = lower_bound(dic.begin(), dic.end(), H) - dic.begin();
				if (id2 < n && dic[id2] == H && !vis[id2])
				{
					vis[id2] = true;
					Q.push(id2);
				}
			}
		}
		cout << (ans ? "Yes" : "No") << endl;
	}
	return 0;
}
