#include <bits/stdc++.h>

using namespace std;

const int MAXPERSON = 25;

int nPerson, nAction, kase = 1;
char person[MAXPERSON][50];

struct Account
{
	int amount;
	int iPerson;
} pAccount[MAXPERSON];

int findPerson(char *name)
{
	int rtn = -1;
	for (int i = 0; i < nPerson; i++)
		if (!strcmp(name, person[i]))
		{
			rtn = i;
			break;
		}
	return rtn;
}

void input()
{
	for (int i = 0; i < nPerson; i++)
	{
		cin >> person[i];
		pAccount[i].amount = 0;
	}
	int amount, id1, id2;
	char name1[50], name2[50];
	for (int i = 0; i < nAction; i++)
	{
		cin >> name1 >> name2 >> amount;
		id1 = findPerson(name1);
		id2 = findPerson(name2);
		if (id1 >= 0 && id2 >= 0)
		{
			pAccount[id1].amount -= amount;
			pAccount[id2].amount += amount;
			pAccount[id1].iPerson = id1;
			pAccount[id2].iPerson = id2;
		}
	}
}

void solve()
{
	int i, j;
	while (1)
	{
		for (i = 0; i < nPerson; i++)
			if (pAccount[i].amount > 0)
			{
				break;
			}
		for (j = 0; j < nPerson; j++)
			if (pAccount[j].amount < 0)
			{
				break;
			}
		if (i == nPerson || j == nPerson)
		{
			break;
		}
		int temp = pAccount[i].amount < (-pAccount[j].amount) ? pAccount[i].amount : (-pAccount[j].amount);
		pAccount[i].amount -= temp;
		pAccount[j].amount += temp;
		cout << person[i] << " " << person[j] << " " << temp << endl;
	}
}

int main()
{
	while (cin >> nPerson >> nAction && nPerson)
	{
		input();
		cout << "Case #" << kase++ << endl;
		solve();
		cout << endl;
	}
	return 0;
}
