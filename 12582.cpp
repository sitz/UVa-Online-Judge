#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sc scanf
#define pf printf
#define Pi 2 * acos(0.0)

static map<char, int> mp;
static stack<char> stk;
static int t, no = 0;
static string s;

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> s;
		stk.push(s[0]);
		for (int i = 1; i < s.size(); i++)
		{
			if (stk.top() == s[i])
				stk.pop();
			else
			{
				mp[stk.top()]++;
				stk.push(s[i]);
				mp[stk.top()]++;
			}
		}
		sort(s.begin(), s.end());
		s.erase(unique(s.begin(), s.end()), s.end());
		pf("Case %d\n", ++no);
		for (int i = 0; i < s.size(); i++)
			pf("%c = %d\n", s[i], mp[s[i]]);
		mp.clear();
	}
	return 0;
}
