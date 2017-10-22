#include <bits/stdc++.h>

using namespace std;

struct article
{
	article()
	{
		for (char s[99]; gets(s) && strcmp(s, "**********");)
		{
			lines.emplace_back(s);
			transform(s, s + strlen(s), s, ::tolower);
			string S;
			stringstream ss(S = regex_replace(s, regex("[^a-z]"), " "));
			lower.push_back(S);
			while (ss >> s)
				words.push_back(s);
		}
	}
	bool exist(const string &s) { return ::find(words.begin(), words.end(), s) != words.end(); }
	void find(char *term1, char *term2 = "")
	{
		begin = true;
		for (int i = 0; i < lower.size(); ++i)
			if (match(lower[i], term1))
				print(lines[i]);
			else if (*term2 && match(lower[i], term2))
				print(lines[i]);
	}
	bool match(string &s1, char *s2)
	{
		stringstream ss(s1);
		for (char s[99]; ss >> s;)
			if (!strcmp(s, s2))
				return true;
		return false;
	}
	void print(string s)
	{
		if (begin)
		{
			begin = false;
			if (first)
				first = false;
			else
				puts("----------");
		}
		puts(s.c_str());
	}
	vector<string> lines, words, lower;
	static bool first;
	bool begin;
};

bool article::first;

int main()
{
	int n;
	char key[3][99], search[99];
	scanf("%d\n", &n);
	article collection[n];
	for (scanf("%d\n", &n); n--;)
	{
		fgets(search, 99, stdin);
		article::first = true;
		int get = sscanf(search, "%s %s %s", key[0], key[1], key[2]);
		if (get == 1)
		{
			for (auto &c : collection)
			{
				if (c.exist(key[0]))
				{
					c.find(key[0]);
				}
			}
		}
		else if (get == 2)
		{
			for (auto &c : collection)
				if (!c.exist(key[1]))
				{
					if (article::first)
					{
						article::first = false;
					}
					else
					{
						puts("----------");
					}
					for (auto &s : c.lines)
					{
						cout << s << endl;
					}
				}
		}
		else if (strcmp(key[1], "AND") == 0)
		{
			for (auto &c : collection)
			{
				if (c.exist(key[0]) && c.exist(key[2]))
				{
					c.find(key[0], key[2]);
				}
			}
		}
		else
		{
			for (auto &c : collection)
			{
				if (c.exist(key[0]) || c.exist(key[2]))
				{
					c.find(key[0], key[2]);
				}
			}
		}
		if (article::first)
		{
			puts("Sorry, I found nothing.");
		}
		puts("==========");
	}
	return 0;
}
