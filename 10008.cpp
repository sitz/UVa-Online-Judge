#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int(i) = int(a); (i) < int(b); (i)++)
#define FOREQ(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define FOREACH(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)

#define ALL(a) (a).begin(), (a).end()
#define SZ(a) ((int)(a).size())

#define fst first
#define snd second
#define pb push_back

inline bool by_val_desc(const pair<char, int> &a, const pair<char, int> &b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second > b.second;
	}
}

static int n;
static string input;
static map<char, int> m;
static vector<pair<char, int>> v;

int main()
{
	cin >> n;
	getline(cin, input); // fetch $'\n'
	while (n--)
	{
		getline(cin, input);
		int y = SZ(input);
		FOR(i, 0, y)
		{
			if (isalpha(input[i]))
			{
				if (m.find(toupper(input[i])) != m.end())
				{
					m[toupper(input[i])]++;
				}
				else
				{
					m[toupper(input[i])] = 1;
				}
			}
		}
	}
	FOREACH(m, it)
	{
		v.pb(pair<char, int>(it->fst, it->snd));
	}
	sort(ALL(v), by_val_desc);
	int y = SZ(v);
	FOR(i, 0, y)
	{
		printf("%c %d\n", v[i].fst, v[i].snd);
	}
	return 0;
}
