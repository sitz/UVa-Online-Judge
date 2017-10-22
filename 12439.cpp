#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;

int cnt_leap(int year)
{
	return year / 4 - year / 100 + year / 400;
}

bool check(int year)
{
	if (year % 400 == 0)
	{
		return true;
	}
	if (year % 100 == 0)
	{
		return false;
	}
	if (year % 4 == 0)
	{
		return true;
	}
	return false;
}

void solve()
{
	string tmp;
	int day1, month1, year1, day2, month2, year2;
	char c;
	cin >> tmp >> day1 >> c >> year1;
	month1 = mp[tmp];
	cin >> tmp >> day2 >> c >> year2;
	month2 = mp[tmp];
	int res = cnt_leap(year2 - 1) - cnt_leap(year1);
	if (month1 < 2 && check(year1))
	{
		res++;
	}
	if ((month2 > 1 || (month2 == 1 && day2 == 29)) && check(year2))
	{
		res++;
	}
	cout << res << endl;
}

int main()
{
	mp["January"] = 0;
	mp["February"] = 1;
	mp["March"] = 2;
	mp["April"] = 3;
	mp["May"] = 4;
	mp["June"] = 5;
	mp["July"] = 6;
	mp["August"] = 7;
	mp["September"] = 8;
	mp["October"] = 9;
	mp["November"] = 10;
	mp["December"] = 11;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Case " << i + 1 << ": ";
		solve();
	}
	return 0;
}
