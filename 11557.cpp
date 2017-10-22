#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const ull X = 123;
const int N = 105;

int n, nxt[1000005];
string name[N];
string s;
vector<int> ans;
vector<ull> code[N];

void hash_(string s, int u)
{
	string ss = "";
	int l = 0, r = s.length() - 1, len = s.length();
	;
	while (s[l] == ' ' && l < len)
		l++;
	while (s[r] == ' ' && r >= 0)
		r--;
	for (int i = l; i <= r; i++)
	{
		ss += s[i];
		while (s[i] == ' ' && s[i + 1] == ' ' && i < r)
			i++;
	}
	if (ss == "")
		return;
	ull ans = 0;
	for (int i = ss.length() - 1; i >= 0; i--)
		ans = ans * X + ss[i];
	code[u].push_back(ans);
}

void build(int i)
{
	code[i].clear();
	while (getline(cin, s) && s != "***END***")
	{
		hash_(s, i);
	}
}

vector<ull> T;

void getnxt()
{
	int N = T.size();
	nxt[0] = nxt[1] = 0;
	int j = 0;
	for (int i = 2; i <= N; i++)
	{
		while (j && T[i - 1] != T[j])
			j = nxt[j];
		if (T[i - 1] == T[j])
			j++;
		nxt[i] = j;
	}
}

int find()
{
	int ans = 0;
	int N = code[n].size(), m = T.size(), j = 0;
	for (int i = 0; i < N; i++)
	{
		while (j && code[n][i] != T[j])
			j = nxt[j];
		if (code[n][i] == T[j])
			j++;
		ans = max(ans, j);
		if (j == m)
			return m;
	}
	return ans;
}

int cal(int u)
{
	int ans = 0;
	int sz1 = code[u].size();
	for (int i = 0; i < sz1; i++)
	{
		T.clear();
		for (int j = i; j < sz1; j++)
			T.push_back(code[u][j]);
		getnxt();
		ans = max(ans, find());
	}
	return ans;
}

void solve()
{
	int Max = 0;
	ans.clear();
	for (int i = 0; i < n; i++)
	{
		int tmp = cal(i);
		if (tmp > Max)
		{
			Max = tmp;
			ans.clear();
			ans.push_back(i);
		}
		else if (tmp == Max)
			ans.push_back(i);
	}
	cout << Max;
	if (Max)
	{
		for (int i = 0; i < ans.size(); i++)
			cout << " " << name[ans[i]];
	}
	cout << endl;
}

int main()
{
	while (cin >> n)
	{
		getchar();
		for (int i = 0; i < n; i++)
		{
			getline(cin, name[i]);
			build(i);
		}
		build(n);
		solve();
	}
	return 0;
}
