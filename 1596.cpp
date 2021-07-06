#include <bits/stdc++.h>

using namespace std;

int testBug;
map<string, int> dsz;
map<string, map<int, int> > dr;

void declara(char exp[])
{
	string name = "";
	int sz = 0, i;
	for (i = 0; exp[i] != '['; i++)
	{
		name += exp[i];
	}
	for (i++; exp[i] != ']'; i++)
	{
		sz = sz * 10 + exp[i] - '0';
	}
	dsz[name] = sz;
	dr[name].clear();
}

int get_val(char exp[])
{
	if (isdigit(exp[0]))
	{
		int val = 0;
		for (int i = 0; isdigit(exp[i]); i++)
		{
			val = val * 10 + exp[i] - '0';
		}
		return val;
	}
	string name = "";
	int i;
	for (i = 0; exp[i] != '['; i++)
	{
		name += exp[i];
	}
	int idx = get_val(exp + i + 1);
	if (dsz.count(name) == 0 || idx >= dsz[name] || dr[name].count(idx) == 0)
	{
		testBug = 1;
		return 0;
	}
	return dr[name][idx];
}

void assign(char exp[])
{
	string name = "";
	int i;
	for (i = 0; exp[i] != '['; i++)
	{
		name += exp[i];
	}
	int idx = get_val(exp + i + 1);
	for (i = 0; exp[i] != '='; i++)
		;
	int val = get_val(exp + i + 1);
	if (testBug)
	{
		return;
	}
	if (dsz.count(name) == 0 || idx >= dsz[name])
	{
		testBug = 1;
		return;
	}
	dr[name][idx] = val;
}

int main()
{
	char c;
	while ((c = getchar()) != '.')
	{
		ungetc(c, stdin);
		dsz.clear();
		dr.clear();
		char exp[32767];
		int bug_line = 0, lines = 0;
		testBug = 0;
		while (gets(exp) && exp[0] != '.')
		{
			lines++;
			int f = 0;
			for (int i = 0; exp[i]; i++)
			{
				f |= exp[i] == '=';
			}
			if (!f)
			{
				declara(exp);
			}
			else
			{
				assign(exp);
			}
			if (testBug && bug_line == 0)
			{
				bug_line = lines;
			}
		}
		printf("%d\n", bug_line);
	}
	return 0;
}
