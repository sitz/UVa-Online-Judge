#include <bits/stdc++.h>

using namespace std;

#define maxn 520

vector<string> Relation;
map<string, int> Map;
list<int> Adj[maxn], Alter[maxn], Adapt[maxn];
char Color[maxn];
int Cost[maxn][maxn], Parent[maxn], Q[maxn * 3];
int Plag, PlgLim, TPlag, Dev, Match, Des;

void Assign(int u, int v)
{
	int n;
	list<int>::iterator p;
	if (u != v)
		Alter[u].push_back(v);
	Color[v] = 1;
	for (p = Adapt[v].begin(); p != Adapt[v].end(); p++)
	{
		n = *p;
		if (Color[n])
			continue;
		Assign(u, n);
	}
}
void MakeAlter()
{
	int i, j;
	for (i = 101; i <= PlgLim; i++)
	{
		Assign(i, i);
		for (j = 101; j <= TPlag; j++)
			Color[j] = 0;
	}
}
void MakeAdj()
{
	int i, u, v, n, lim;
	string st;
	list<int>::iterator p;
	lim = Plag + 100;
	for (i = 0; i < Relation.size(); i++)
	{
		st = Relation[i];
		n = Map[Relation[i]];
		if (n <= lim)
		{
			Adj[i + 1].push_back(n);
			Adj[n].push_back(i + 1);
			Cost[i + 1][n] = 1;
		}
		for (p = Alter[n].begin(); p != Alter[n].end(); p++)
		{
			v = *p;
			if (v > lim)
				continue;
			Adj[i + 1].push_back(v);
			Adj[v].push_back(i + 1);
			Cost[i + 1][v] = 1;
		}
	}
}
void Mark(int v)
{
	int u;
	u = Parent[v];
	if (u < 0)
		return;
	Cost[u][v]--;
	Cost[v][u]++;
	Mark(Parent[v]);
}
int BFS(int n)
{
	int i, u, v;
	int ind = 0;
	char ch[maxn];
	list<int>::iterator p;
	for (i = 1; i <= Dev; i++)
		ch[i] = 0;
	for (i = 101; i <= PlgLim; i++)
		ch[i] = 0;
	ch[Des] = 0;
	Parent[n] = -1;
	Q[ind++] = n;
	for (i = 0; i < ind; i++)
	{
		u = Q[i];
		for (p = Adj[u].begin(); p != Adj[u].end(); p++)
		{
			v = *p;
			if (ch[v] || Cost[u][v] == 0)
				continue;
			Parent[v] = u;
			if (v == Des)
			{
				Match--;
				Mark(v);
				return 1;
			}
			ch[v] = 1;
			Q[ind++] = v;
		}
	}
	return 0;
}
void Cal()
{
	int i;
	MakeAlter();
	MakeAdj();
	Match = Dev;
	Des = 400;
	for (i = 101; i <= PlgLim; i++)
	{
		Adj[i].push_back(Des);
		Cost[i][Des] = 1;
	}
	for (i = 1; i <= Dev && Match; i++)
		BFS(i);
	cout << Match << endl;
}
void ReadCase()
{
	int i, n, d, u, v;
	string str, plg;
	cin >> Plag;
	d = 100 + Plag + 1;
	for (i = 101; i < d; i++)
	{
		cin >> str;
		Map[str] = i;
	}
	cin >> Dev;
	n = Dev;
	while (n--)
	{
		cin >> str >> plg;
		Relation.push_back(plg);
		u = Map[plg];
		if (!u)
			Map[plg] = d++;
	}
	PlgLim = d - 1;
	cin >> n;
	while (n--)
	{
		cin >> str >> plg;
		u = Map[str];
		v = Map[plg];
		if (!u)
		{
			u = d;
			Map[str] = d++;
		}
		if (!v)
		{
			v = d;
			Map[plg] = d++;
		}
		Adapt[u].push_back(v);
	}
	TPlag = d - 1;
}
void Free()
{
	int i, j;
	for (i = 1; i <= Dev; i++)
	{
		for (j = 101; j <= PlgLim; j++)
			Cost[i][j] = Cost[j][i] = 0;
		Adj[i].clear();
		Cost[0][i] = Cost[i][0] = 0;
	}
	Adj[0].clear();
	for (i = 101; i <= TPlag; i++)
	{
		Alter[i].clear();
		Adapt[i].clear();
	}
	Map.clear();
	Relation.clear();
	for (i = 0; i < maxn; i++)
		Color[i] = 0;
}

int main()
{
	int ks;
	cin >> ks;
	while (ks--)
	{
		ReadCase();
		Cal();
		Free();
		if (ks)
			cout << endl;
	}
	return 0;
}
