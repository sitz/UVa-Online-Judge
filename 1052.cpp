#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 40;

enum {NO, UNIQUE, NOT_UNIQUE};

int l, n, tc;
map<int, map<int, int>> dp[N];
string s;

int solve(int i, int ones, int zeroes)
{
	if (ones < 0 || zeroes < 0)
	{
		return NO;
	}
	if (i == s.length())
	{
		return ones == 0 && zeroes == 0 ? UNIQUE : NO;
	}
	if (dp[i][ones].count(zeroes))
	{
		return dp[i][ones][zeroes];
	}
	if (s[i] == '0')
	{
		return dp[i][ones][zeroes] = solve(i + 1, ones, zeroes - 1);
	}
	ll def = 0;
	int ans = 0;
	for (int j = i; j < s.length(); j++)
	{
		def = (def << 1) | (s[j] == '1');
		if (def != 2 && (j + 1 >= s.length() || s[j + 1] == '0'))
		{
			ans += solve(j + 1, ones - def, zeroes);
			if (def == 3)
			{
				ans += solve(j + 1, ones - 2, zeroes); // special case
			}
		}
		if (def > ones)
		{
			break;
		}
		if (ans >= NOT_UNIQUE)
		{
			return dp[i][ones][zeroes] = NOT_UNIQUE;
		}
	}
	return dp[i][ones][zeroes] = ans;
}

string outp[] = {"NO", "YES", "NOT UNIQUE"};

int main()
{
	while (cin >> l >> n && (n || l))
	{
		cin >> s;
		for (int i = 0; i < s.length(); i++)
		{
			dp[i].clear();
		}
		int ans = solve(0, n, l - n);
		cout << "Case #" << ++tc << ": " << outp[ans] << endl;
	}
	return 0;
}
