#include <bits/stdc++.h>

using namespace std;

char buffer[110];
int kase = 1, R, pRule;
char encode[30];

struct AddtionRule
{
	int p;
	char x, y;
} rule[1010];

void getInitCode()
{
	for (int i = 0; i < 26; i++)
	{
		cin >> encode[i];
	}
}

void getAddtionRule()
{
	cin >> R;
	for (int i = 0; i < R; i++)
	{
		cin >> rule[i].p >> rule[i].x >> rule[i].y;
	}
}

void update(int p)
{
	if (rule[pRule].p > p)
	{
		return;
	}
	while (rule[pRule].p == p && pRule < R)
	{
		encode[rule[pRule].x - 'a'] = rule[pRule].y;
		pRule++;
	}
}

int main()
{
	while (cin >> buffer)
	{
		getInitCode();
		getAddtionRule();
		pRule = 0;
		cout << "Case #" << kase++ << ": The encoding string is ";
		for (int i = 0; i < strlen(buffer); i++)
		{
			update(i);
			cout << encode[buffer[i] - 'a'];
		}
		cout << ".\n"
				 << endl;
	}
	return 0;
}
