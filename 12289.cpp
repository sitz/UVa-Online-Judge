#include <bits/stdc++.h>

using namespace std;

string words[3] = {"one", "two", "three"};

int word_diff(string s1, string s2)
{
	int diff = max(s1.size(), s2.size()) - min(s1.size(), s2.size());
	for (int i = 0; i < min(s1.size(), s2.size()); ++i)
	{
		if (s1[i] != s2[i])
		{
			diff++;
		}
	}
	return diff;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		string word;
		cin >> word;
		for (int i = 0; i < 3; ++i)
		{
			if (word_diff(word, words[i]) <= 1)
			{
				printf("%d\n", i + 1);
				break;
			}
		}
	}
	return 0;
}
