#include <bits/stdc++.h>

using namespace std;

const string mths[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static char c;
static int t, date, diff, m, d, y;
static string input;

inline bool is_leap(int year)
{
	return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

inline int mth2int(const string &m)
{
	for (int i = 0; i < 12; i++)
	{
		if (m == mths[i])
		{
			return i + 1;
		}
	}
}

inline string int2mth(int m)
{
	return mths[m - 1];
}

int main()
{
	scanf("%d", &t);
	for (int casenum = 0; casenum < t; casenum++)
	{
		scanf("%d%c", &y, &c);
		getline(cin, input, '-');
		m = mth2int(input);
		scanf("%d%d", &d, &diff);

		if (is_leap(y))
			days[1] = 29;
		else
			days[1] = 28;

		for (int i = 0; i < diff; i++)
		{
			d++;
			if (d > days[m - 1])
			{
				d = 1;
				m++;
				if (m > 12)
				{
					y++;
					m = 1;
					if (is_leap(y))
					{
						days[1] = 29;
					}
					else
					{
						days[1] = 28;
					}
				}
			}
		}
		printf("Case %d: %0004d-%s-%02d\n", casenum + 1, y, int2mth(m).c_str(), d);
	}
	return 0;
}
