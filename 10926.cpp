#include <bits/stdc++.h>

using namespace std;

/*
10926
How many Dependecies
*/
#define maxn 102

char Fg[maxn];
int D[maxn];
list<int> L[maxn];
int N;
int DFS(int n)
{
	int x = 0, u;
	Fg[n] = 1;
	list<int>::iterator p;
	for (p = L[n].begin(); p != L[n].end(); p++)
	{
		u = *p;
		if (Fg[u] == 0)
		{
			x += DFS(u);
		}
	}
	D[n] = x;
	return x + 1;
}
void Cal()
{
	int i, max = -1, sel;
	for (i = 1; i <= N; i++)
	{
		if (Fg[i] == 0)
		{
			DFS(i);
			if (D[i] > max)
			{
				max = D[i];
				sel = i;
			}
			for (int j = 1; j <= N; j++)
			{
				Fg[j] = 0;
			}
		}
	}
	cout << sel << endl;
	for (i = 1; i <= N; i++)
	{
		D[i] = 0;
		L[i].clear();
	}
}
int main()
{
	int n, v;
	while (cin >> N && N)
	{
		for (int i = 1; i <= N; i++)
		{
			cin >> n;
			while (n--)
			{
				cin >> v;
				L[i].push_back(v);
			}
		}
		Cal();
	}
	return 0;
}
