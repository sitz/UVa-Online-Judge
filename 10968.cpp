#include <bits/stdc++.h>

using namespace std;

#define maxn 1001

list<int> L[maxn];
int N, M, Deg[maxn];
char C[maxn];

struct ss
{
	int node;
	int dis;
};
queue<ss> Q;

int BFS(int st, int end)
{
	ss t, d;
	int u, v;
	list<int>::iterator p;
	t.node = st;
	t.dis = 0;
	Q.push(t);
	C[st] = 1;
	while (!Q.empty())
	{
		t = Q.front();
		u = t.node;
		Q.pop();
		for (p = L[u].begin(); p != L[u].end(); p++)
		{
			v = *p;
			if (v == end)
				return t.dis + 1;
			if (C[v] || Deg[v] < 3)
				continue;
			C[v] = 1;
			d.node = v;
			d.dis = t.dis + 1;
			Q.push(d);
		}
	}
	return 0;
}

void Cal()
{
	int i, u, v, f = 0;
	for (i = 1; i <= N; i++)
	{
		if (Deg[i] == 0)
		{
			cout << "Poor Koorosh\n";
			return;
		}
		if (Deg[i] % 2)
		{
			if (Deg[i] == 1)
			{
				cout << "Poor Koorosh\n";
				return;
			}
			if (!f)
				u = i;
			else
				v = i;
			f++;
			if (f == 2)
				break;
		}
	}
	if (f < 2)
	{
		cout << 0 << endl;
		return;
	}
	f = BFS(u, v);
	if (!f)
		cout << "Poor Koorosh\n";
	else
		cout << f << endl;
}

void Clear()
{
	int i;
	for (i = 1; i <= N; i++)
	{
		L[i].clear();
		Deg[i] = 0;
		C[i] = 0;
	}
	while (!Q.empty())
		Q.pop();
}

int main()
{
	int i, u, v;
	while (cin >> N >> M)
	{
		if (!N && !M)
			break;
		for (i = 0; i < M; i++)
		{
			cin >> u >> v;
			Deg[u]++;
			Deg[v]++;
			L[u].push_back(v);
			L[v].push_back(u);
		}
		Cal();
		Clear();
	}
	return 0;
}
