#include <bits/stdc++.h>

using namespace std;

int main()
{
	string word;
	set<string> dict;
	char ch = cin.get();
	while (ch != EOF)
	{
		if (isalpha(ch))
		{
			ch = tolower(ch);
			word += ch;
		}
		else
		{
			dict.insert(word);
			word.clear();
		}
		ch = cin.get();
	}
	bool first = true;
	for (set<string>::iterator iter = dict.begin(); iter != dict.end(); iter++)
	{
		if (!first)
		{
			cout << *iter << endl;
		}
		first = false;
	}
	return 0;
}
