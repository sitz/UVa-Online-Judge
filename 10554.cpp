#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef vector<pair<int, char>> pic;

pic getdata(string &inp)
{
	pic in;
	stringstream sin(inp);
	pair<int, char> tmp;
	while (sin >> tmp.first >> tmp.second)
	{
		in.push_back(tmp);
	}
	return in;
}

const double caldata[] = {9, 4, 4, 4, 7};

double solve()
{
	string in;
	double cal = 0, fat = 0;
	int n = 0;
	while (getline(cin, in) && in != "-")
	{
		n++;
		pic now = getdata(in);
		double total = 1;
		double left = 0;
		rep(i, 5)
		{
			if (now[i].second == 'C')
			{
				left += now[i].first;
			}
			else if (now[i].second == 'g')
			{
				left += now[i].first * caldata[i];
			}
			else
			{
				total -= 0.01 * now[i].first;
			}
		}
		total = left / total;
		if (now[0].second == 'C')
		{
			fat += now[0].first;
		}
		else if (now[0].second == 'g')
		{
			fat += now[0].first * caldata[0];
		}
		else
		{
			fat += 0.01 * now[0].first * total;
		}
		cal += total;
		//cout << cal <<" " << total << endl;
	}
	if (n == 0)
	{
		return -1;
	}
	return fat / cal;
}

int main()
{
	while (true)
	{
		double ans = solve();
		if (ans < 0)
		{
			break;
		}
		else
		{
			printf("%.0lf%%\n", ans * 100);
		}
	}
	return 0;
}
