#include <bits/stdc++.h>

using namespace std;

#define FOREACH(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)

struct draft
{
	string name_fst;
	int qty;
	draft(string name_fst1 = "", int qty1 = 0) : name_fst(name_fst1), qty(qty1) {}
};

string line, capital;
map<string, set<string>> mapa;
set<string> s;
vector<draft> res;

bool cmp(draft a, draft b)
{
	if (a.qty > b.qty)
	{
		return true;
	}
	if (a.qty < b.qty)
	{
		return false;
	}
	if (a.name_fst < b.name_fst)
	{
		return true;
	}
	return false;
}

int main()
{
	while (getline(cin, line))
	{
		if (line == "0")
		{
			break;
		}
		if (line[0] == '1')
		{
			FOREACH(s, it_set)
			{
				int cont = 0;
				FOREACH(mapa, it)
				{
					if (it->second.count(*it_set))
					{
						cont++;
					}
				}
				if (cont > 1)
				{
					FOREACH(mapa, it)
					{
						if (it->second.count(*it_set))
						{
							it->second.erase(it->second.find(*it_set));
						}
					}
				}
			}
			FOREACH(mapa, it)
			{
				res.push_back(draft(it->first, it->second.size()));
			}
			sort(res.begin(), res.end(), cmp);
			FOREACH(res, it)
			{
				printf("%s %d\n", it->name_fst.c_str(), it->qty);
			}
			res.clear();
			mapa.clear();
			s.clear();
			continue;
		}
		if (line[0] < 'A' || line[0] > 'Z')
		{
			mapa[capital].insert(line);
			s.insert(line);
		}
		else
		{
			mapa[line], capital = line;
		}
	}
	return 0;
}
