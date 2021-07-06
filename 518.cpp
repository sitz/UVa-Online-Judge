#include <bits/stdc++.h>

using namespace std;

int isLeap(int);

char *str[] = {"year", "month", "day", "hour", "minute", "second"};

int dayinmonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Time
{
public:
	int value[6];
	Time(void){};

	void increase(int index)
	{
		switch (index)
		{
		case 5:
			if (value[5] == 59)
			{
				value[5] = 0;
				increase(4);
			}
			value[5]++;
			return;
		case 4:
			if (value[4] == 59)
			{
				value[4] = 0;
				increase(3);
			}
			value[4]++;
			return;
		case 3:
			if (value[3] == 23)
			{
				value[3] = -1;
				increase(2);
			}
			value[3]++;
			return;
		case 2:
			if (value[2] == dayinmonth[value[1]] + (value[1] == 2 ? (isLeap(value[0])) : 0))
			{
				value[2] = 0;
				increase(1);
			}
			value[2]++;
			return;
		case 1:
			if (value[1] == 12)
			{
				value[1] = 0;
				increase(0);
			}
			value[1]++;
			return;
		case 0:
			value[0]++;
		}
	}

	void ceil(int index)
	{
		int i;
		int x = 0;
		for (i = index + 1; i < 6; i++)
		{
			if (value[i])
			{
				x = 1;
				value[i] = 0;
			}
		}
		if (x)
		{
			increase(index);
		}
	}

	void floor(int index)
	{
		int i;
		for (i = index + 1; i < 6; i++)
		{
			value[i] = 0;
		}
	}
};
int isLeap(int year)
{
	if (year % 400 == 0)
	{
		return 1;
	}
	if (year % 100 == 0)
	{
		return 0;
	}
	if (year % 4 == 0)
	{
		return 1;
	}
	return 0;
}

long sub(Time &t1, Time &t2, int index)
{
	int day = 0;
	switch (index)
	{
	case 0:
		return (t2.value[0] - t1.value[0]);
	case 1:
		return (t2.value[0] - t1.value[0]) * 12 + t2.value[1] - t1.value[1];
	default:
		while (1)
		{
			if (t1.value[1] == t2.value[1] && t1.value[0] == t2.value[0])
			{
				break;
			}
			day += (dayinmonth[t1.value[1] - 1] + ((t1.value[1] == 2) ? isLeap(t1.value[0]) : 0));
			t1.increase(1);
		}
		t1.value[0] = 0;
		t2.value[0] = 0;
		t1.value[1] = 0;
		t2.value[1] = 0;
		t2.value[2] += day;
	}
	switch (index)
	{
	case 2:
		return (t2.value[2] - t1.value[2]);
	case 3:
		return (t2.value[2] - t1.value[2]) * 24 + t2.value[3] - t1.value[3];
	case 4:
		return (t2.value[2] - t1.value[2]) * 24 * 60 + (t2.value[3] - t1.value[3]) * 60 + t2.value[4] - t1.value[4];
	case 5:
		return (t2.value[2] - t1.value[2]) * 24 * 60 * 60 + (t2.value[3] - t1.value[3]) * 60 * 60 + (t2.value[4] - t1.value[4]) * 60 + t2.value[5] - t1.value[5];
	}
	return -1;
}

void show(const Time &t)
{
	for (int i = 0; i < 6; i++)
	{
		cout << t.value[i] << " ";
	}
	cout << endl;
}

int main()
{
	Time t1, t2;
	int i;
	int x;
	char s[20];
	int y;
	while (1)
	{
		for (i = 0; i < 6; i++)
		{
			cin >> t1.value[i];
			if (!cin)
			{
				return 0;
			}
		}
		for (i = 0; i < 6; i++)
		{
			cin >> t2.value[i];
		}
		cin >> x;
		cin >> s;
		for (i = 0; i < 6; i++)
		{
			if (!strcmp(s, str[i]))
			{
				y = i;
				break;
			}
		}
		assert(i < 6);
		t1.ceil(y);
		t2.floor(y);
		//show(t1);
		//show(t2);
		cout << (sub(t1, t2, y)) / x << endl;
	}
	return 0;
}
