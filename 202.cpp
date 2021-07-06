#include <bits/stdc++.h>

using namespace std;

//HKUST - ZHANG Xiongqi
//Using C++

vector<int> di;
int main()
{
	unsigned int digits = 0;
	unsigned int fenzi = 1, fenmu = 1;
	while (cin >> fenzi >> fenmu)
	{
		di.clear();
		int *p = new int[fenmu];
		cout << fenzi << "/" << fenmu << " = " << fenzi / fenmu;
		cout << ".";
		fenzi = fenzi % fenmu;
		for (int i = 0; i < fenmu; i++)
		{
			fenzi *= 10;
			*(p + i) = fenzi;
			if (i > 0 && fenzi != 0)
			{
				for (int j = 0; j < i; j++)
				{
					if (*(p + j) == *(p + i))
					{
						digits = i - j;
						break;
					}
				}
			}
			if (fenzi == 0)
			{
				for (int i = 0; i < di.size(); i++)
				{
					cout << di[i];
				}
				cout << "(0)" << endl;
				cout << "   1 = number of digits in repeating cycle" << endl
						 << endl;
				break;
			}
			if (digits != 0)
			{
				int loc = di.size() - digits;
				for (int i = 0; i < loc; i++)
				{
					cout << di[i];
				}
				cout << "(";
				for (int i = loc; i < di.size() && i < loc + 50; i++)
				{
					cout << di[i];
				}
				if (digits > 50)
				{
					cout << "...";
				}
				cout << ")" << endl;
				cout << "   " << digits << " = number of digits in repeating cycle" << endl
						 << endl;
				break;
			}
			di.push_back(fenzi / fenmu);
			fenzi = fenzi % fenmu;
		}
		digits = 0;
		delete[] p;
	}
	return 0;
}
