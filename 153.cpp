#include <bits/stdc++.h>

using namespace std;

set<char> chars;
int char_count[128];

template <typename T>
inline T gcd(T a, T b)
{
	T c;
	while (b)
	{
		c = b, b = a % b, a = c;
	}
	return a;
}

int perm_cnt(string &s)
{
	vector<int> top, btm;
	int size = 0;
	for (set<char>::iterator it = chars.begin(); it != chars.end(); it++)
	{
		size += char_count[*it];
		if (char_count[*it] > 1)
		{
			for (int i = 2; i <= char_count[*it]; i++)
			{
				btm.push_back(i);
			}
		}
	}
	for (int i = 2; i <= size; i++)
	{
		top.push_back(i);
	}
	for (int i = 0, sz1 = top.size(); i < sz1; i++)
	{
		for (int j = 0, sz2 = btm.size(); j < sz2; j++)
		{
			if (top[i] == 1 || btm[j] == 1)
			{
				continue;
			}
			int tmp = gcd(top[i], btm[j]);
			if (tmp == 1)
			{
				continue;
			}
			top[i] = top[i] / tmp;
			btm[j] = btm[j] / tmp;
		}
	}
	int result = 1;
	for (int i = 0, sz = top.size(); i < sz; i++)
	{
		result *= top[i];
	}
	return result;
}

int solve(string &s, int start)
{
	int result = 0, counter = 0;
	if (start == s.size())
	{
		return 0;
	}
	for (set<char>::iterator it = chars.begin(); it != chars.end(); it++)
	{
		if (*it == s[start])
		{
			break;
		}
		if (char_count[*it] == 0)
		{
			continue;
		}
		char_count[*it]--;
		result += perm_cnt(s);
		char_count[*it]++;
	}
	char_count[s[start]]--;
	return result + solve(s, start + 1);
}

int main()
{
	string input;
	while (getline(cin, input))
	{
		if (input == "#")
		{
			break;
		}
		chars.clear();
		for (int i = 0; i < 128; i++)
		{
			char_count[i] = 0;
		}
		for (int i = 0, sz = input.size(); i < sz; i++)
		{
			chars.insert(input[i]);
			char_count[input[i]]++;
		}
		cout << setw(10) << solve(input, 0) + 1 << endl;
	}
	return 0;
}
