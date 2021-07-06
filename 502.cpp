#include <bits/stdc++.h>

using namespace std;

#define inf 1 << 25

struct node
{
	string name;
	string ext;
};
node pl[1050];
node add[1050];
int n, m;
int ml1, ml2;
node ans;

void read()
{
	int i, j;
	char temp[100];
	string t;
	ml1 = ml2 = inf;
	n = m = 0;
	while (gets(temp) != NULL && temp[0] != 0)
	{
		t = "";
		t += temp;
		if (t[0] == '-')
		{
			int p = t.find('.');
			if (p != -1)
			{
				if (p == t.size() - 1)
				{
					pl[n].name = t.substr(1, t.size() - 2);
					pl[n].ext = "";
				}
				else
				{
					pl[n].ext = t.substr(p + 1, t.size() - p);
					pl[n].name = t.substr(1, p - 1);
				}
			}
			else
			{
				pl[n].name = t.substr(1, t.size() - 1);
				pl[n].ext = "";
			}
			// cout<<pl[n].name<<"***"<<pl[n].ext<<endl;
			int aa = pl[n].name.size();
			ml1 = min(ml1, aa);
			aa = pl[n].ext.size();
			ml2 = min(ml2, aa);
			n++;
		}
		else
		{
			int p = t.find('.');
			if (p != -1)
			{
				if (p == t.size() - 1)
				{
					add[m].name = t.substr(1, t.size() - 2);
					add[m].ext = "";
				}
				else
				{
					add[m].name = t.substr(1, p - 1);
					add[m].ext = t.substr(p + 1, t.size() - p);
				}
			}
			else
			{
				add[m].name = t.substr(1, t.size() - 1);
				add[m].ext = "";
			}
			m++;
		}
	}
}

void solve()
{
	int i, j;
	int flag = 0;
	ans.ext = ans.name = "";
	for (i = 0; i < ml1; i++)
	{
		char c = pl[0].name[i];
		for (j = 0; j < n; j++)
		{
			if (c != pl[j].name[i])
			{
				break;
			}
		}
		if (j == n)
		{
			ans.name += c;
		}
		else
		{
			ans.name += '?';
		}
	}
	for (i = 0; i < n; i++)
	{
		if (pl[0].name.size() != pl[i].name.size())
		{
			break;
		}
	}
	if (i != n)
	{
		ans.name += '*';
	}
	for (i = 0; i < n; i++)
	{
		if (pl[i].ext != "")
		{
			break;
		}
	}
	if (i == n)
	{
		return;
	}
	for (i = 0; i < ml2; i++)
	{
		char c = pl[0].ext[i];
		for (j = 0; j < n; j++)
		{
			if (c != pl[j].ext[i])
			{
				break;
			}
		}
		if (j == n)
		{
			ans.ext += c;
		}
		else
		{
			ans.ext += '?';
		}
	}
	int len = pl[0].ext.size();
	for (i = 0; i < n; i++)
	{
		if (len != pl[i].ext.size())
		{
			break;
		}
	}
	if (i != n)
	{
		ans.ext += '*';
	}
}

bool judge(node &r)
{
	int i;
	int flag = 0;
	for (i = 0; i < r.name.size(); i++)
	{
		char c = r.name[i];
		if (i == ans.name.size())
		{
			return false;
		}
		else if (ans.name[i] == '*')
		{
			flag = 1;
			break;
		}
		else if (ans.name[i] == '?')
		{
			continue;
		}
		else if (ans.name[i] != c)
		{
			return false;
		}
	}
	if (flag != 1)
	{
		if (i == r.name.size() && i < ans.name.size() && ans.name[i] != '*')
		{
			return false;
		}
	}
	if (ans.ext == "")
	{
		if (r.ext == "")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (r.ext == "")
		{
			return false;
		}
		else
		{
			flag = 0;
			for (i = 0; i < r.ext.size(); i++)
			{
				char c = r.ext[i];
				if (i == ans.ext.size())
				{
					return false;
				}
				else if (ans.ext[i] == '*')
				{
					flag = 1;
					break;
				}
				else if (ans.ext[i] == '?')
				{
					continue;
				}
				else if (ans.ext[i] != c)
				{
					return false;
				}
			}
			if (flag != 1)
			{
				if (i == r.ext.size() && i < ans.ext.size() && ans.ext[i] != '*')
				{
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	int i, j;
	int T;
	scanf("%d", &T);
	getchar(), getchar();
	while (T--)
	{
		read();
		solve();
		for (i = 0; i < m; i++)
		{
			if (judge(add[i]))
			{
				puts("IMPOSSIBLE");
				break;
			}
		}
		if (i == m)
		{
			cout << "DEL ";
			cout << ans.name << "." << ans.ext << endl;
		}
		if (T)
		{
			puts("");
		}
	}
	return 0;
}
