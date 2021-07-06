#include <bits/stdc++.h>

using namespace std;

char rule[15][2][400];
char editText[500];
int numOfRule;

void input()
{
	cin.get();
	int loop;
	for (loop = 0; loop < numOfRule; loop++)
	{
		cin.getline(rule[loop][0], 400);
		cin.getline(rule[loop][1], 400);
	}
}

//be(ba b)oat  be(hind the g)oat
void replace(int index, char *find, char *by)
{
	char temp[500];
	int i, j;
	for (i = 0; i < index; i++)
	{
		temp[i] = editText[i];
	}
	index += strlen(find);
	for (j = 0; by[j]; j++)
	{
		temp[i++] = by[j];
	}
	for (; editText[index]; index++)
	{
		temp[i++] = editText[index];
	}
	temp[i] = '\0';
	strcpy(editText, temp);
	//  cout<<temp<<endl;
}

void solve()
{
	int loop;
	for (loop = 0; loop < numOfRule; loop++)
	{
		int index;
		for (index = 0; editText[index]; index++)
		{
			if (!strncmp(&editText[index], rule[loop][0], strlen(rule[loop][0])))
			{
				replace(index, rule[loop][0], rule[loop][1]);
				index = 0;
			}
		}
	}
}

int main()
{
	while (cin >> numOfRule && numOfRule)
	{
		input();
		cin.getline(editText, 500);
		solve();
		cout << editText << endl;
	}
	return 0;
}
