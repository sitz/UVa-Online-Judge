#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define N 5000
#define EXPLI 0//meiji
#define IMPLI 1//not meiji
#define UNINSTALLED 2
#define pb push_back

vector<int> dep[N];
vector<int> rev_dep[N];
list<int> install_info;

int state[N];
string name[N];

void remove_from_list(int cur)
{
	list<int>::iterator itr = find(install_info.begin(), install_info.end(), cur);
	install_info.erase(itr);
}

void remove_rec(int cur, bool flag)
{
	if (state[cur] == UNINSTALLED && flag == true)
	{
		cout << "   " << name[cur] << " is not installed." << endl;
		return;
	}
	rep(i, dep[cur].size())//still need?
	{
		if (state[dep[cur][i]] != UNINSTALLED)
		{
			if (flag == true)
			{
				cout << "   " << name[cur] << " is still needed." << endl;
			}
			return;
		}
	}
	if (flag == true)
	{
		state[cur] = UNINSTALLED;//response to command
	}
	state[cur] = UNINSTALLED;
	cout << "   Removing " << name[cur] << endl;
	remove_from_list(cur);
	rep(i, rev_dep[cur].size())
	{
		if (state[rev_dep[cur][i]] == IMPLI)
		{
			remove_rec(rev_dep[cur][i], false);
		}
	}
}

void install_rec(int cur, bool flag)
{
	if (flag == true && state[cur] != UNINSTALLED)//respons to command
	{
		cout << "   " << name[cur] << " is already installed." << endl;
		return;
	}
	rep(i, rev_dep[cur].size())
	{
		if (state[rev_dep[cur][i]] == UNINSTALLED)
		{
			install_rec(rev_dep[cur][i], false);
		}
	}
	if (flag == true)
	{
		state[cur] = EXPLI;
	}
	else
	{
		state[cur] = IMPLI;
	}
	install_info.pb(cur);
	cout << "   Installing " << name[cur] << endl;
}

void list_up()
{
	list<int>::iterator itr = install_info.begin();
	while (itr != install_info.end())
	{
		cout << "   " << name[*(itr++)] << endl;
	}
}

int find_index(string &tar, map<string, int> &M)
{
	int index;
	if (M.find(tar) == M.end())
	{
		index = M[tar] = M.size();
	}
	else
	{
		index = M[tar];
	}
	name[index] = tar;
	return index;
}

main()
{
	string inp;
	map<string, int> M;
	rep(i, N) state[i] = UNINSTALLED;
	while (getline(cin, inp))
	{
		cout << inp << endl;
		string command, tmp;
		vector<string> in;
		stringstream sin(inp);
		sin >> command;
		while (sin >> tmp)
		{
			in.pb(tmp);
		}
		if (command == "DEPEND")
		{
			int from = find_index(in[0], M);
			REP(i, 1, in.size())
			{
				int to = find_index(in[i], M);
				dep[to].pb(from);
				rev_dep[from].pb(to);
			}
		}
		else if (command == "INSTALL")
		{
			int index = find_index(in[0], M);
			install_rec(index, true);
		}
		else if (command == "REMOVE")
		{
			int index = find_index(in[0], M);
			remove_rec(index, true);
		}
		else if (command == "LIST")
		{
			list_up();
		}
		else if (command == "END")
		{
			break;
		}
	}
}
