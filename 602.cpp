#include <bits/stdc++.h>

using namespace std;

// @JUDGE_ID: 13345PF 602 C++

inline bool test(int y)
{
	if (y < 1752)
	{
		return y % 4 == 0;
	}
	if (y >= 1752)
	{
		return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
	}
}

int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *month_name[] =
		{
				"January", "February", "March", "April", "May", "June", "July",
				"August", "September", "October", "November", "December"};

char *day_name[] =
		{
				"Monday", "Tuesday", "Wednesday",
				"Thursday", "Friday", "Saturday", "Sunday"};

int cal(int y, int m, int d)
{
	int ret = 0;
	for (int i = 0; i < m - 1; i++)
	{
		ret += month[i];
		if (i == 1)
		{
			ret += test(y);
		}
	}
	ret += d;
	return ret;
}

int day(int y, int m, int d)
{
	int i, ret = 0;
	if (y > 1752)
	{
		for (i = 1752; i < y; i++)
		{
			ret += (365 + test(i)) % 7;
		}
		ret -= cal(1752, 9, 14) % 7;
		ret += cal(y, m, d) % 7;
		ret += 3;
		ret %= 7;
	}
	else if (y < 1752)
	{
		for (i = y; i < 1752; i++)
		{
			ret += (365 + test(i)) % 7;
		}
		ret += cal(1752, 9, 2) % 7;
		ret -= cal(y, m, d) % 7;
		ret = (9 - ret % 7) % 7;
	}
	else
	{
		if (m < 9 || m == 9 && d < 14)
		{
			ret = (9 - (cal(1752, 9, 2) - cal(y, m, d)) % 7) % 7;
		}
		else
		{
			ret = (cal(y, m, d) - cal(1752, 9, 14) + 3) % 7;
		}
	}
	return ret;
}

inline bool illegal(int y, int m, int d)
{
	if (m < 1 || m > 12 || d < 1)
	{
		return true;
	}
	if (m == 2 &&
			(!test(y) && d > 28 || d > 29))
	{
		return true;
	}
	if (m != 2 && d > month[m - 1])
	{
		return true;
	}
	if (y == 1752 && m == 9 && d > 2 && d < 14)
	{
		return true;
	}
	return false;
}

int main()
{
	int y, m, d;
	cin >> m >> d >> y;
	while (y != 0 || m != 0 || d != 0)
	{
		if (illegal(y, m, d))
		{
			printf("%d/%d/%d is an invalid date.\n", m, d, y);
		}
		else
		{
			printf("%s %d, %d is a %s\n", month_name[m - 1], d, y, day_name[day(y, m, d)]);
		}
		cin >> m >> d >> y;
	}
	return 0;
}
