#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> S;
string s;

void insert(char c)
{
	bool found = false;
	int pos;
	char _min = 'Z' + 1;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].back() >= c)
		{
			if (S[i].back() < _min)
			{
				_min = S[i].back();
				pos = i;
				found = true;
			}
		}
	}
	if (found)
	{
		S[pos].push_back(c);
	}
	else
	{
		S.push_back(vector<char>());
		S.back().push_back(c);
	}
}

int casno = 1;
int main()
{
	while (cin >> s && s != "end")
	{
		S.clear();
		for (int i = 0; i < s.length(); i++)
		{
			insert(s[i]);
		}
		printf("Case %d: %d\n", casno++, S.size());
	}
	return 0;
}
