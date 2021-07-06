#include <bits/stdc++.h>

using namespace std;

#define maxn 102

int Fre[maxn];

struct ss
{
	int cost;
	int node;
};
class comp
{
	int x;

public:
	bool operator()(const ss &a, const ss &b)
	{
		return a.cost > b.cost;
	}
};
priority_queue<ss, vector<ss>, comp> Q;
list<ss> Link[maxn];
int N, M, X, Y, K;
int BFS()
{
	int v;
	list<ss>::iterator i;
	ss t, d;
	t.node = X;
	t.cost = 0;
	Q.push(t);
	while (!Q.empty())
	{
		t = Q.top();
		Q.pop();
		Fre[t.node]++;
		if (Fre[t.node] >= K)
		{
			if (Fre[t.node] == K && t.node == Y)
				return t.cost;
			if (Fre[t.node] > K)
				continue;
		}
		for (i = Link[t.node].begin(); i != Link[t.node].end(); i++)
		{
			v = i->node;
			d.cost = t.cost + i->cost;
			d.node = v;
			Q.push(d);
		}
	}
	return -1;
}
void Cal()
{
	int d;
	d = BFS();
	if (d == -1)
		cout << "-1\n";
	else
		cout << d << endl;
}
void Free()
{
	int i;
	for (i = 1; i <= N; i++)
	{
		Link[i].clear();
		Fre[i] = 0;
	}
	while (!Q.empty())
		Q.pop();
}

int main()
{
	int i, u, v, c;
	ss t;
	while (cin >> N >> M)
	{
		if (!N && !M)
			break;
		cin >> X >> Y >> K;
		for (i = 0; i < M; i++)
		{
			cin >> u >> v >> c;
			t.node = v;
			t.cost = c;
			Link[u].push_back(t);
		}
		Cal();
		Free();
	}
	return 0;
}
