#include <bits/stdc++.h>

using namespace std;

char table[30] = "01230120022455012623010202";

int main()
{
	char buf[100];
	while (cin >> buf)
	{
		int i;
		for (i = 0; buf[i]; i++)
		{
			if (table[buf[i] - 'A'] != '0')
			{
				if (table[buf[i] - 'A'] != table[buf[i - 1] - 'A'])
				{
					cout << table[buf[i] - 'A'];
				}
			}
		}
		cout << endl;
	}
	return 0;
}
