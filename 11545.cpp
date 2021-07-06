#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

// (pos, time, howMuchContinuous) => is the optimal cost when you enter pos at time 'time' with 'howMuchContinuous' amount of journey.

int arr[1001][25][25];
string str;

int solve(int ind, int time, int howCont)
{
	// finished
	if (ind == (int)str.size() - 1)
	{
		if (howCont > 16)
		{
			return INT_MAX;
		}
		return 0;
	}
	int &ret = arr[ind][time][howCont];
	if (ret != -1)
	{
		return ret;
	}
	int x = 0;
	ret = INT_MAX;
	// cannot travel cont >16h
	if (howCont > 16)
	{
		return ret = INT_MAX;
	}
	if (str[ind] == '*')
	{
		if (time == 0 || time >= 12)
		{
			return ret = INT_MAX;
		}
	}
	int val = solve(ind + 1, (time + 1) % 24, howCont + 1);
	if (val != INT_MAX)
	{
		ret = min(ret, x + 1 + val);
	}
	// just added >enough rest
	for (int i = 0; i < 8; i++)
	{
		if (str[ind] == '*' && (time >= 12 || time == 0))
		{
			break;
		}
		x += 8;
		time = (time + 8) % 24;
		if (str[ind] == '*' && (time >= 12 || time == 0))
		{
			break;
		}
		val = solve(ind + 1, (time + 1) % 24, 1);
		if (val != INT_MAX)
		{
			ret = min(ret, solve(ind + 1, (time + 1) % 24, 1) + x + 1);
		}
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		cin >> str;
		memset(arr, -1, sizeof arr);
		str[0] = '.';
		int ret = solve(0, 0, 0);
		if (ret == INT_MAX)
		{
			ret = -1;
		}
		printf("Case #%d: %d\n", t, ret);
	}
	return 0;
}
