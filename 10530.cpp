#include <bits/stdc++.h>

using namespace std;

int num;
char cmd[30];
int MIN, MAX;
bool cheat;

void Input()
{
	cin.get();
	while (cin.getline(cmd, 30))
	{
		if (!strcmp(cmd, "right on"))
		{
			break;
		}
		if (!strcmp(cmd, "too high"))
		{
			if (num <= MAX)
			{
				MAX = num - 1;
			}
		}
		if (!strcmp(cmd, "too low"))
		{
			if (num >= MIN)
			{
				MIN = num + 1;
			}
		}
		if (MIN > MAX)
		{
			cheat = true;
		}
		if (num > MAX && !strcmp(cmd, "too low"))
		{
			cheat = true;
		}
		if (num < MIN && !strcmp(cmd, "too high"))
		{
			cheat = true;
		}
		//        cout<<"["<<MIN<<","<<MAX<<"]"<<endl;
		cin >> num;
		cin.get();
	}
	if (MIN > MAX)
	{
		cheat = true;
	}
	if (num < MIN || num > MAX)
	{
		cheat = true;
	}
}

int main()
{
	while (cin >> num && num)
	{
		cheat = false;
		MIN = 0;
		MAX = 11;
		Input();
		if (cheat)
		{
			cout << "Stan is dishonest" << endl;
		}
		else
		{
			cout << "Stan may be honest" << endl;
		}
	}
	return 0;
}
