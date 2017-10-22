#include <bits/stdc++.h>

using namespace std;

#define maxn 100
#define INF 999999

map<string, int> M;
int N, MX, Cost[maxn][maxn], Path[maxn][maxn];
string City[maxn];

void Ini()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			Path[i][j] = i;
			if (Cost[i][j] < 0)
			{
				Cost[i][j] = INF;
				Path[i][j] == -1;
			}
		}
		Path[i][i] = i;
	}
}

void Floyd()
{
	int i, j, k;
	int dum;
	for (k = 0; k < N; k++)
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
			{
				dum = Cost[i][k] + Cost[k][j];
				if (dum < Cost[i][j])
				{
					Cost[i][j] = dum;
					Path[i][j] = Path[k][j];
				}
			}
}

void PrintPath(int u, int v, int level)
{
	if (level > MX)
		MX = level;
	if (u == v)
	{
		if (Path[u][v] == u)
		{
			cout << City[u];
			return;
		}
		else if (level > 0)
		{
			cout << City[u];
			return;
		}
	}
	PrintPath(u, Path[u][v], level + 1);
	cout << " " << City[v];
}

void Cal()
{
	int q, u, v;
	string empName, first, second;
	Ini();
	Floyd();
	cin >> q;
	while (q--)
	{
		cin >> empName >> first >> second;
		u = M[first];
		v = M[second];
		MX = 0;
		if (Cost[u][v] == INF)
		{
			cout << "Sorry Mr " << empName;
			cout << " you can not go from " << first << " to " << second << endl;
		}
		else
		{
			cout << "Mr " << empName << " to go from ";
			cout << first << " to " << second << ", you will receive ";
			cout << Cost[u][v] << " euros\n";
			cout << "Path:";
			PrintPath(u, v, 0);
			if (MX == 0)
				cout << " " << City[u];
			cout << endl;
		}
	}
}

int main()
{
	int k, i, j;
	cin >> k;
	while (k--)
	{
		cin >> N;
		for (i = 0; i < N; i++)
		{
			cin >> City[i];
			M[City[i]] = i;
		}
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				cin >> Cost[i][j];
		Cal();
		M.clear();
	}
	return 0;
}
