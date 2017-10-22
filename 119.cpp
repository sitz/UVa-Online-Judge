#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, money, a;
	string name, friends;
	vector<string> names;
	int cnt = 0;
	while (cin >> n)
	{
		names.clear();
		map<string, int> group;
		for (int i = 0; i < n; i++)
		{
			cin >> name;
			group[name] = 0;
			names.push_back(name);
		}
		for (int i = 0; i < n; i++)
		{
			cin >> name >> money >> a;
			if (a > 0)
			{
				group[name] += money % a;
				group[name] -= money;
				for (int j = 0; j < a; j++)
				{
					cin >> friends;
					group[friends] += money / a;
				}
			}
		}
		if (cnt > 0)
		{
			printf("\n");
		}
		for (int i = 0; i < names.size(); i++)
		{
			cout << names[i] << " " << group[names[i]] << endl;
		}
		cnt++;
	}
	return 0;
}
