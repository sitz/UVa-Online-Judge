#include <bits/stdc++.h>

using namespace std;

#define LINESIZE 32

struct Rule
{
	string str1;
	string str2;
};

int calcCount(string &initialStr, vector<Rule> &rules);

int main()
{
	int caseNum = 0;
	char buffer[LINESIZE];
	vector<Rule> ruleList;
	string initialStr;
	char *p1;
	char *p2;
	// get case num
	cin.getline(buffer, LINESIZE);
	caseNum = atoi(buffer);
	// skip blank line
	cin.getline(buffer, 32);
	for (; caseNum != 0; caseNum--)
	{
		// get initial string
		cin.getline(buffer, LINESIZE);
		buffer[strlen(buffer) - 1] = '\0';
		initialStr = buffer + 1;
		// get replace list
		cin.getline(buffer, LINESIZE);
		while (buffer[0] != '\0')
		{
			p1 = strchr(buffer, '\"');
			p1++;
			p2 = strchr(p1, '\"');
			*p2++ = '\0';
			Rule rule;
			rule.str1 = p1;
			p1 = strchr(p2, '\"');
			p1++;
			p2 = strchr(p1, '\"');
			*p2 = '\0';
			rule.str2 = p1;
			ruleList.push_back(rule);
			cin.getline(buffer, LINESIZE);
		}
		int count = calcCount(initialStr, ruleList);
		if (0 == count)
		{
			cout << "Too many." << endl;
		}
		else
		{
			cout << count << endl;
		}
		if (caseNum != 1)
		{
			cout << endl;
		}
		ruleList.clear();
	}
	return 0;
}

int calcCount(string &initialStr, vector<Rule> &rules)
{
	vector<string> strList;
	strList.push_back(initialStr);
	int i = 0;
	int count = 0;
	int maxSize = initialStr.size();
	for (i = 0; i < strList.size(); i++)
	{
		for (int k = 0; k < rules.size(); k++)
		{
			if (rules[k].str1 == "" && rules[k].str2 != "")
			{
				// must over 1000
				return 0;
			}
			if (rules[k].str1 != rules[k].str2 && rules[k].str2.find(rules[k].str1, 0) != string::npos)
			{
				// must over 1000
				return 0;
			}
			int firstPos = -1;
			while ((firstPos = strList[i].find(rules[k].str1, firstPos + 1)) != string::npos)
			{
				string tmpStr = strList[i];
				tmpStr.replace(firstPos, rules[k].str1.size(), rules[k].str2);
				int m = 0;
				if (tmpStr.size() > maxSize)
				{
					if (count == 1000)
					{
						return 0;
					}
					maxSize = tmpStr.size();
					strList.push_back(tmpStr);
					count++;
					continue;
				}
				for (m = 0; m < strList.size(); m++)
				{
					if (strList[m] == tmpStr)
					{
						break;
					}
				}
				if (m == strList.size())
				{
					if (count == 1000)
					{
						return 0;
					}
					strList.push_back(tmpStr);
					count++;
				}
			}
		}
	}
	return i;
}
