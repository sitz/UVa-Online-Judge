#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

int main()
{
	int T;
	cin >> T;
	cin.ignore();
	while (T--)
	{
		string str;
		getline(cin, str);
		int counter = 0;
		stack<char> S;
		bool stat = true;
		while (counter < str.length())
		{
			if (str[counter] == '(' || str[counter] == '[')
			{
				S.push(str[counter]);
			}
			else if (str[counter] == ')')
			{
				if (S.empty() || S.top() != '(')
				{
					stat = false;
					break;
				}
				else if (S.top() == '(')
				{
					S.pop();
				}
			}
			else if (str[counter] == ']')
			{
				if (S.empty() || S.top() != '[')
				{
					stat = false;
					break;
				}
				else if (S.top() == '[')
				{
					S.pop();
				}
			}
			counter++;
		}
		if (stat && S.empty())
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}
