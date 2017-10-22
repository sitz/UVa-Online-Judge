#include <bits/stdc++.h>

using namespace std;

const int maxn = 50005;
typedef map<string, int>::iterator iter;

struct Tire
{
	int sz;
	map<string, int> g[maxn];

	void init();
	void insert(string s);
	void put(int u, int d);
} tree;

int main()
{
	int n;
	string s;
	while (cin >> n && n)
	{
		tree.init();
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			s += '\\';
			tree.insert(s);
		}
		tree.put(0, 0);
		cout << endl;
	}
	return 0;
}

void Tire::init()
{
	sz = 1;
	g[0].clear();
}

void Tire::insert(string s)
{

	int u = 0;
	string word = "";

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '\\')
		{

			if (!g[u].count(word))
			{
				g[sz].clear();
				g[u][word] = sz++;
			}

			u = g[u][word];
			word = "";
		}
		else
			word += s[i];
	}
}

void Tire::put(int u, int d)
{

	for (iter i = g[u].begin(); i != g[u].end(); i++)
	{
		for (int j = 0; j < d; j++)
			cout << " ";
		cout << i->first << endl;
		put(i->second, d + 1);
	}
}
