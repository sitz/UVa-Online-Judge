#include <bits/stdc++.h>

using namespace std;

/*
10461
Difference
*/

#define mx 500
vector<int> V[mx + 2], U[mx + 2];
int D[mx + 2], tday, Sum;
char col[mx + 2];
int N;
void DFS1(int n)
{
	int i, u;
	col[n] = 1;
	tday += D[n];
	for (i = 0; i < V[n].size(); i++)
	{
		u = V[n][i];
		if (col[u] == 0)
		{
			DFS1(u);
		}
	}
}
void DFS2(int n)
{
	int i, u;
	col[n] = 1;
	tday += D[n];
	for (i = 0; i < U[n].size(); i++)
	{
		u = U[n][i];
		if (col[u] == 0)
		{
			DFS2(u);
		}
	}
}
void Cal(int q)
{
	int n;
	while (q--)
	{
		cin >> n;
		tday = 0;
		DFS1(n);
		DFS2(n);
		tday -= D[n];
		cout << (Sum - tday) << endl;
		memset(col, 0, mx + 2);
	}
}
void Free()
{
	int i;
	for (i = 1; i <= N; i++)
	{
		V[i].clear();
		U[i].clear();
	}
}
int main()
{
	int n, m, u, v, ks = 1;
	while (cin >> N >> m)
	{
		if (!N && !m)
		{
			break;
		}
		Sum = 0;
		for (n = 1; n <= N; n++)
		{
			cin >> D[n];
			Sum += D[n];
		}
		while (m--)
		{
			cin >> u >> v;
			V[v].push_back(u);
			U[u].push_back(v);
		}
		cin >> v;
		cout << "Case #" << ks++ << ":\n";
		Cal(v);
		cout << endl;
		Free();
	}
	return 0;
}
