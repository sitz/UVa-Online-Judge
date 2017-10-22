#include <bits/stdc++.h>

using namespace std;

void check(int loc, int lleft, string now);
vector<string> totalwords, wint, words;
string temp, repeat;
int letter[26], total, ltemp[26];

int main()
{
	while (getline(cin, temp, '\n') && temp.find("#") == string::npos)
	{
		totalwords.push_back(temp);
	}
	while (getline(cin, temp, '\n') && temp.find("#") == string::npos)
	{
		wint.clear();
		words.clear();
		total = 0;
		memset(letter, 0, sizeof(letter));
		for (int i = 0; i < temp.size(); i++)
			if (temp[i] >= 'A' && temp[i] <= 'Z')
			{
				letter[temp[i] - 'A']++;
			}
		for (int i = 0; i < 26; i++)
		{
			total += letter[i];
		}
		for (int i = 0; i < totalwords.size(); i++)
		{
			memset(ltemp, 0, sizeof(ltemp));
			for (int j = 0; j < totalwords[i].size(); j++)
			{
				ltemp[totalwords[i][j] - 'A']++;
			}
			bool ok = true;
			for (int j = 0; ok && j < 26; j++)
				if (ltemp[j] > letter[j])
				{
					ok = false;
				}
			if (ok)
			{
				words.push_back(totalwords[i]);
			}
		}
		stringstream sin(temp);
		while (sin >> repeat)
		{
			wint.push_back(repeat);
		}
		sort(wint.begin(), wint.end());
		repeat = " =";
		for (int i = 0; i < wint.size(); i++)
		{
			repeat += " " + wint[i];
		}
		check(0, total, " =");
	}
	return 0;
}

void check(int loc, int lleft, string now)
{
	if (lleft == 0)
	{
		if (now != repeat)
		{
			cout << temp << now << endl;
		}
		return;
	}
	else if (loc == words.size())
	{
		return;
	}
	bool ok = true;
	for (int i = 0; i < words[loc].size(); i++)
	{
		letter[words[loc][i] - 'A']--;
		if (letter[words[loc][i] - 'A'] < 0)
		{
			ok = false;
		}
	}
	if (ok)
	{
		check(loc + 1, lleft - words[loc].size(), now + " " + words[loc]);
	}
	for (int i = 0; i < words[loc].size(); i++)
	{
		letter[words[loc][i] - 'A']++;
	}
	check(loc + 1, lleft, now);
}
