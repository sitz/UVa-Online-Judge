#include <bits/stdc++.h>

using namespace std;

struct Date
{
	int _day, _month, _days; // days from Jan 1

	void calcDays(int _Year)
	{
		_days = _day;
		if (_month > 1)
		{
			_days += 31;
		}
		if (_month > 2)
		{
			_days += _Year % 4 ? 28 : 29;
		}
		if (_month > 3)
		{
			_days += 31;
		}
		if (_month > 4)
		{
			_days += 30;
		}
		if (_month > 5)
		{
			_days += 31;
		}
		if (_month > 6)
		{
			_days += 30;
		}
		if (_month > 7)
		{
			_days += 31;
		}
		if (_month > 8)
		{
			_days += 31;
		}
		if (_month > 9)
		{
			_days += 30;
		}
		if (_month > 10)
		{
			_days += 31;
		}
		if (_month > 11)
		{
			_days += 30;
		}
	}
};
struct Event : public Date
{
	int _priority;
	string _desc;
};
struct EventPointer
{
	const Event *_event;
	int _rest;

	int priority() const
	{
		return _event->_priority;
	}
	bool operator<(const EventPointer &_Rhs) const
	{
		if (_rest < _Rhs._rest)
		{
			return true;
		}
		if (_rest > _Rhs._rest)
		{
			return false;
		}
		if (_rest > 0)
		{
			if (priority() > _Rhs.priority())
			{
				return true;
			}
			if (priority() < _Rhs.priority())
			{
				return false;
			}
		}
		return _event < _Rhs._event;
	}
};

int main()
{
	int year;
	scanf("%d", &year);
	vector<Event> events;
	vector<Date> dates;
	while (true)
	{
		char type[2];
		scanf("%s", type);
		if (type[0] == 'A')
		{
			Event event;
			scanf("%d %d %d", &event._day, &event._month, &event._priority);
			char ch;
			do
			{
				ch = getchar();
			} while (ch == ' ' || ch == '\t');
			do
			{
				event._desc.insert(event._desc.end(), ch);
				ch = getchar();
			} while (ch != '\n' && ch != '\r');
			event.calcDays(year);
			events.push_back(event);
			if (event._days <= 7)
			{
				event._days += year % 4 ? 365 : 366;
				events.push_back(event);
			}
		}
		else if (type[0] == 'D')
		{
			Date date;
			scanf("%d %d", &date._day, &date._month);
			date.calcDays(year);
			dates.push_back(date);
		}
		else
		{
			break;
		}
	}
	int i, j;
	for (i = 0; i < dates.size(); ++i)
	{
		const Date &date = dates[i];
		set<EventPointer> pointers;
		for (j = 0; j < events.size(); ++j)
		{
			const Event &event = events[j];
			EventPointer pointer;
			pointer._event = &event;
			pointer._rest = event._days - date._days;
			if (date._days <= event._days && pointer._rest <= event._priority)
			{
				pointers.insert(pointer);
			}
		}
		if (i > 0)
		{
			printf("\n");
		}
		printf("Today is:%3d%3d\n", date._day, date._month);
		set<EventPointer>::iterator itr;
		for (itr = pointers.begin(); itr != pointers.end(); ++itr)
		{
			const Event &event = *itr->_event;
			printf("%3d%3d ", event._day, event._month);
			if (itr->_rest == 0)
			{
				printf("*TODAY* ");
			}
			else
			{
				int importance = event._priority - itr->_rest + 1;
				// ASSERT(1 <= importance && importance <= 7);
				for (j = 0; j < importance; ++j)
				{
					printf("*");
				}
				for (; j < 8; ++j)
				{
					printf(" ");
				}
			}
			printf("%s\n", event._desc.c_str());
		}
	}
	return 0;
}
