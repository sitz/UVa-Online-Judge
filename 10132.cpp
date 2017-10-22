#include <bits/stdc++.h>

using namespace std;

vector<string> files, sshort, slong;
string temp;

bool check();

int main()
{
	bool first = true;
	int N;
	scanf("%d", &N);
	scanf("\n");
	for (int i = 0; i < N; i++)
	{
		files.clear();
		sshort.clear();
		slong.clear();
		while (true)
		{
			if (!getline(cin, temp, '\n'))
			{
				break;
			}
			if (temp == "")
			{
				break;
			}
			files.push_back(temp);
		}
		int min = 1000, max = 0;
		for (int j = 0; j < files.size(); j++)
		{
			if (files[j].size() < min)
			{
				min = files[j].size();
			}
			if (files[j].size() > max)
			{
				max = files[j].size();
			}
		}
		for (int j = 0; j < files.size(); j++)
		{
			if (files[j].size() == min)
			{
				bool exist = false;
				for (int k = 0; k < sshort.size(); k++)
					if (files[j] == sshort[k])
					{
						exist = true;
					}
				if (!exist)
				{
					sshort.push_back(files[j]);
				}
			}
			if (files[j].size() == max)
			{
				bool exist = false;
				for (int k = 0; k < slong.size(); k++)
					if (files[j] == slong[k])
					{
						exist = true;
					}
				if (!exist)
				{
					slong.push_back(files[j]);
				}
			}
		}
		bool found = false;
		for (int j = 0; !found && j < sshort.size(); j++)
			for (int k = 0; !found && k < slong.size(); k++)
			{
				temp = sshort[j] + slong[k];
				found = check();
			}
		for (int j = 0; !found && j < sshort.size(); j++)
			for (int k = 0; !found && k < slong.size(); k++)
			{
				temp = slong[k] + sshort[j];
				found = check();
			}
		if (first)
		{
			first = false;
		}
		else
		{
			putchar(10);
		}
		cout << temp << endl;
	}
	return 0;
}

bool check()
{
	int loc1, loc2;
	int len = temp.size();
	for (int i = 0; i < files.size(); i++)
	{
		loc1 = temp.find(files[i]);
		loc2 = temp.rfind(files[i]);
		if (loc1 != 0 && loc2 != len - files[i].size())
		{
			return false;
		}
	}
	return true;
}
