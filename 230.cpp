#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define ALL(C) (C).begin(), (C).end()

class Book
{
public:
	string t, a;
	bool operator<(const Book &b) const
	{
		if (a != b.a)
		{
			return a < b.a;
		}
		else
		{
			return t < b.t;
		}
	}
};

void shelve(set<Book> &S, map<string, string> &M, vector<Book> &ret)
{
	sort(ALL(ret));
	rep(i, ret.size())
	{
		string tar = ret[i].t;
		Book ins = {tar, M[tar]};
		S.insert(ins);
		set<Book>::iterator itr = S.find(ins);
		if (itr == S.begin())
		{
			cout << "Put \"" << tar << "\" first" << endl;
		}
		else
		{
			itr--;
			cout << "Put \"" << tar << "\" after \"" << (*itr).t << "\"" << endl;
		}
	}
	puts("END");
	ret.clear();
	return;
}

main()
{
	set<Book> S;
	map<string, string> M;
	vector<Book> ret;
	string in;
	while (getline(cin, in) && in != "END")
	{
		string title = "", author;
		int p = 0;
		while (p < in.size())
		{
			if (in[p++] == '"')
			{
				break;
			}
		}
		while (p < in.size())
		{
			if (in[p] == '"')
			{
				p++;
				break;
			}
			title += in[p++];
		}
		p += 4;
		author = in.substr(p);
		S.insert((Book){
				title, author});
		M[title] = author;
	}
	while (getline(cin, in) && in != "END")
	{
		if (in[0] == 'B' || in[0] == 'R')
		{
			string title;
			int p = 0;
			while (p < in.size())
			{
				if (in[p++] == '"')
				{
					break;
				}
			}
			while (p < in.size())
			{
				if (in[p] == '"')
				{
					p++;
					break;
				}
				title += in[p++];
			}
			if (in[0] == 'B')
				S.erase((Book){
						title, M[title]});
			else if (in[0] == 'R')
				ret.push_back((Book){
						title, M[title]});
		}
		else if (in == "SHELVE")
		{
			shelve(S, M, ret);
		}
	}
}
