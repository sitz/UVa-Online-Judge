#include <bits/stdc++.h>

using namespace std;

int main()
{
	int Amplitude, Frequency;
	int m;
	cin >> m;
	int f = 0;
	for (int z = 0; z < m; z++)
	{
		cin >> Amplitude >> Frequency;
		for (int cnt = 0; cnt < Frequency; cnt++)
		{
			if (f)
			{
				cout << endl;
			}
			f = 1;
			int i;
			for (i = 1; i <= Amplitude; i++)
			{
				int j = 0;
				while (j < i)
				{
					cout << i;
					j++;
				}
				cout << endl;
			}
			for (i = Amplitude - 1; i > 0; i--)
			{
				int j = 0;
				while (j < i)
				{
					cout << i;
					j++;
				}
				cout << endl;
			}
		}
	}
	return 0;
}
