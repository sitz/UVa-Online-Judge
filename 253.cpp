#include <bits/stdc++.h>

using namespace std;

//HKUST - ZHANG Xiongqi
//Using C++

void check(char fc[], char sc[], bool &over);
void exam(char fc[], char sc[]);
int main()
{
	while (true)
	{
		char fc[6], sc[6];
		for (int i = 0; i < 6; i++)
		{
			cin >> fc[i];
			if (cin.eof())
			{
				return 0;
			}
		}
		for (int i = 0; i < 6; i++)
		{
			cin >> sc[i];
		}
		exam(fc, sc);
	}
}
void check(char fc[], char sc[], bool &over)
{
	if (sc[0] == fc[0])
	{
		if (sc[5] == fc[5])
		{
			if (sc[1] == fc[1] && sc[2] == fc[2] && sc[3] == fc[3] && sc[4] == fc[4])
			{
				cout << "TRUE" << endl;
				over = !over;
				return;
			}
			if (sc[1] == fc[2] && sc[2] == fc[4] && sc[3] == fc[1] && sc[4] == fc[3])
			{
				cout << "TRUE" << endl;
				over = !over;
				return;
			}
			if (sc[1] == fc[3] && sc[2] == fc[1] && sc[3] == fc[4] && sc[4] == fc[2])
			{
				cout << "TRUE" << endl;
				over = !over;
				return;
			}
			if (sc[1] == fc[4] && sc[2] == fc[3] && sc[3] == fc[2] && sc[4] == fc[1])
			{
				cout << "TRUE" << endl;
				over = !over;
				return;
			}
		}
	}
}
void exam(char fc[], char sc[])
{
	char temp;
	bool over = false;
	check(fc, sc, over);
	for (int i = 0; i < 4; i++)
	{
		if (!over)
		{
			temp = sc[0];
			sc[0] = sc[1];
			sc[1] = sc[5];
			sc[5] = sc[4];
			sc[4] = temp;
			check(fc, sc, over);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (!over)
		{
			temp = sc[0];
			sc[0] = sc[3];
			sc[3] = sc[5];
			sc[5] = sc[2];
			sc[2] = temp;
			check(fc, sc, over);
		}
	}
	if (!over)
	{
		cout << "FALSE" << endl;
	}
	return;
}
