#include <bits/stdc++.h>

using namespace std;

vector<string> symbol;

int input()
{
	symbol.clear();
	string s;
	while (cin >> s)
	{
		if (s[0] == '9')
		{
			return 1;
		}
		symbol.push_back(s);
	}
	return 0;
}

int main()
{
	int kase = 1;
	while (input())
	{
		sort(symbol.begin(), symbol.end());
		bool yes = true;
		for (int i = 1; i < symbol.size(); i++)
		{
			int len = min(symbol[i - 1].size(), symbol[i].size());
			if (symbol[i - 1].compare(0, len, symbol[i], 0, len) == 0)
			{
				yes = false;
				break;
			}
		}
		if (yes)
		{
			cout << "Set " << kase++ << " is immediately decodable" << endl;
		}
		else
		{
			cout << "Set " << kase++ << " is not immediately decodable" << endl;
		}
	}
	return 0;
}
