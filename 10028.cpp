#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

#define OFFENCE false
#define AWARD true
#define pb push_back
bool year_check(int y1, int m1, int d1, int y2, int m2, int d2)
{
	if (y1 < y2)
	{
		return AWARD;
	}
	else if (y1 > y2)
	{
		return OFFENCE;
	}
	else
	{
		if (m1 < m2)
		{
			return AWARD;
		}
		else if (m1 > m2)
		{
			return OFFENCE;
		}
		else
		{
			if (d1 < d2)
			{
				return AWARD;
			}
			else if (d1 > d2)
			{
				return OFFENCE;
			}
			else
			{
				return AWARD;
			}
		}
	}
	return false;
}

void solve(int f_year, int f_month, int f_day, int n,
					 vector<int> &year, vector<int> &month, vector<int> &day,
					 vector<int> &point)
{
	int dem = 0, me = 0, p = 0;
	int cyear = f_year, cmonth = f_month, cday = f_day;
	printf("%04d-%02d-%02d No merit or demerit points.\n",
				 cyear, cmonth, cday);
	cyear += 2;
	while (true)
	{
		if (p == n && me == 5)
		{
			break;
		}
		if (p != n && year_check(cyear, cmonth, cday, year[p], month[p], day[p]) == OFFENCE)
		{
			dem += point[p];
			if (me * 2 < dem)
			{
				dem -= me * 2;
				me = 0;
				printf("%04d-%02d-%02d %d demerit point(s).\n",
							 year[p], month[p], day[p], dem);
				cyear = year[p] + 1;
				cmonth = month[p];
				cday = day[p];
			}
			else if (me * 2 >= dem)
			{
				dem = 0;
				me = me - dem / 2;
				if (me == 0)
					printf("%04d-%02d-%02d No merit or demerit points.\n",
								 cyear, cmonth, cday);
				else
					printf("%04d-%02d-%02d %d merit point(s).\n",
								 cyear, cmonth, cday, me);
				cyear = year[p] + 2;
				cmonth = month[p];
				cday = day[p];
			}
			p++;
		}
		else
		{
			if (dem > 2)
			{
				dem /= 2;
				printf("%04d-%02d-%02d %d demerit point(s).\n",
							 cyear, cmonth, cday, dem);
				cyear++;
			}
			else if (dem > 0)
			{
				dem = 0;
				me = 0;
				printf("%04d-%02d-%02d No merit or demerit points.\n",
							 cyear, cmonth, cday);
				cyear += 2;
			}
			else
			{
				me++;
				printf("%04d-%02d-%02d %d merit point(s).\n",
							 cyear, cmonth, cday, me);
				cyear += 2;
			}
		}
	}
	return;
}

int main()
{
	string in;
	int te, tc = 0;
	cin >> te;
	while (te--)
	{
		if (tc)
		{
			puts("");
		}
		tc++;
		cin >> in;
		int fyear, fmonth, fday;
		fyear = (in[0] - '0') * 1000 + (in[1] - '0') * 100 + (in[2] - '0') * 10 + (in[3] - '0');
		fmonth = (in[4] - '0') * 10 + (in[5] - '0');
		fday = (in[6] - '0') * 10 + (in[7] - '0');
		getline(cin, in);
		vector<int> year, month, day, point;
		while (getline(cin, in) && in.size() > 0)
		{
			int ty, tm, td, tp;
			ty = (in[0] - '0') * 1000 + (in[1] - '0') * 100 + (in[2] - '0') * 10 + (in[3] - '0');
			tm = (in[4] - '0') * 10 + (in[5] - '0');
			td = (in[6] - '0') * 10 + (in[7] - '0');
			year.pb(ty);
			month.pb(tm);
			day.pb(td);
			stringstream sin(in);
			sin >> ty >> tp;
			point.pb(tp);
		}
		solve(fyear, fmonth, fday, year.size(), year, month, day, point);
	}
	return 0;
}
