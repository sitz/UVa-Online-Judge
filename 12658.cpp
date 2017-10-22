#include <bits/stdc++.h>

using namespace std;

int n;
string s[5];

int main()
{
	cin >> n;
	for (int i = 0; i < 5; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		string sub = s[3].substr(4 * i, 3);
		if (sub == ".*.")
		{
			cout << 1;
		}
		else if (sub == "*..")
		{
			cout << 2;
		}
		else
		{
			cout << 3;
		}
	}
	cout << endl;
	return 0;
}
