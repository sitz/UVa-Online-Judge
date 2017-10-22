#include <bits/stdc++.h>

using namespace std;

string car[1000];
int day[1000], hour[1000], minute[1000], pos[1000];
bool enter[1000];
int cost[24];
deque<int> rsort[60];
vector<string> charcar, running;
vector<int> charmon, bh, posi;

int main()
{
	int N;
	bool begin = true;
	string record;
	scanf("%d", &N);
	scanf("\n");
	for (int i = 0; i < N; i++)
	{
		charcar.clear();
		running.clear();
		charmon.clear();
		bh.clear();
		posi.clear();
		int count = 0;
		for (int j = 0; j < 24; j++)
		{
			scanf("%d", cost + j);
		}
		bool first = true;
		while (true)
		{
			if (first)
			{
				first = false;
				getline(cin, record, '\n');
			}
			if (!getline(cin, record, '\n'))
			{
				break;
			}
			if (record == "")
			{
				break;
			}
			int loc = record.find(' ');
			car[count] = record.substr(0, loc);
			record = record.substr(loc + 1);
			loc = record.find(':');
			record = record.substr(loc + 1);
			loc = record.find(':');
			day[count] = (record[loc - 2] - '0') * 10 + record[loc - 1] - '0';
			record = record.substr(loc + 1);
			loc = record.find(':');
			hour[count] = (record[loc - 2] - '0') * 10 + record[loc - 1] - '0';
			record = record.substr(loc + 1);
			loc = record.find(' ');
			minute[count] = (record[loc - 2] - '0') * 10 + record[loc - 1] - '0';
			record = record.substr(loc + 1);
			loc = record.find("enter");
			if (loc >= 0)
			{
				enter[count] = true;
				record = record.substr(loc + 6);
			}
			else
			{
				loc = record.find("exit");
				enter[count] = false;
				record = record.substr(loc + 5);
			}
			int temp = 0;
			for (int j = 0; j < record.size(); j++)
			{
				if (record[j] <= '9' && record[j] >= '0')
				{
					temp *= 10;
					temp += record[j] - '0';
				}
			}
			pos[count++] = temp;
		}
		int index[count];
		for (int j = 0; j < count; j++)
		{
			rsort[minute[j]].push_back(j);
		}
		int count2 = 0;
		for (int j = 0; j < 60; j++)
		{
			while (rsort[j].size() != 0)
			{
				index[count2++] = rsort[j].front();
				rsort[j].pop_front();
			}
		}
		for (int j = 0; j < count; j++)
		{
			rsort[hour[index[j]]].push_back(index[j]);
		}
		count2 = 0;
		for (int j = 0; j < 24; j++)
		{
			while (rsort[j].size() != 0)
			{
				index[count2++] = rsort[j].front();
				rsort[j].pop_front();
			}
		}
		for (int j = 0; j < count; j++)
		{
			rsort[day[index[j]]].push_back(index[j]);
		}
		count2 = 0;
		for (int j = 0; j < 32; j++)
		{
			while (rsort[j].size() != 0)
			{
				index[count2++] = rsort[j].front();
				rsort[j].pop_front();
			}
		}
		string carnow;
		bool enow;
		for (int j = 0; j < count; j++)
		{
			carnow = car[index[j]];
			enow = enter[index[j]];
			if (enow)
			{
				bool find = false;
				int loc;
				for (int k = 0; k < running.size(); k++)
				{
					if (running[k] == carnow)
					{
						loc = k;
						find = true;
						break;
					}
				}
				if (find)
				{
					bh[loc] = hour[index[j]];
					posi[loc] = pos[index[j]];
				}
				else
				{
					running.push_back(carnow);
					bh.push_back(hour[index[j]]);
					posi.push_back(pos[index[j]]);
				}
			}
			else
			{
				bool find = false;
				int loc;
				for (int k = 0; k < running.size(); k++)
				{
					if (running[k] == carnow)
					{
						loc = k;
						find = true;
						break;
					}
				}
				if (find)
				{
					find = false;
					int loc2;
					for (int k = 0; k < charcar.size(); k++)
					{
						if (charcar[k] == carnow)
						{
							loc2 = k;
							find = true;
							break;
						}
					}
					if (find)
					{
						charmon[loc2] += fabs((pos[index[j]] - posi[loc]) * cost[bh[loc]]) + 100;
					}
					else
					{
						charcar.push_back(carnow);
						charmon.push_back(fabs((pos[index[j]] - posi[loc]) * cost[bh[loc]]) + 100);
					}
					running.erase(running.begin() + loc);
					bh.erase(bh.begin() + loc);
					posi.erase(posi.begin() + loc);
				}
			}
		}
		if (begin)
		{
			begin = false;
		}
		else
		{
			putchar(10);
		}
		while (charcar.size() > 0)
		{
			int next = 0;
			string ncar = charcar[0];
			for (int k = 1; k < charcar.size(); k++)
			{
				if (charcar[k] < ncar)
				{
					next = k;
					ncar = charcar[k];
				}
			}
			cout << charcar[next];
			printf(" $%.2lf\n", (charmon[next] + 200) / 100.0);
			charcar.erase(charcar.begin() + next);
			charmon.erase(charmon.begin() + next);
		}
	}
	return 0;
}
