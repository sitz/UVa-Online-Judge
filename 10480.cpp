#include <bits/stdc++.h>

using namespace std;

/*
10480
Sabotage
*/
/*
Multiple Input
*/
#define maxn 52

#define MIN(a, b) (a > b ? b : a)
list<int> Edge[maxn];
struct ss
{
	int u;
	int cost;
};
class comp
{
public:
	bool operator()(const ss &a, const ss &b)
	{
		return a.cost < b.cost;
	}
};
priority_queue<ss, vector<ss>, comp> Q;
char Color[maxn];
int MaxF[maxn][maxn];
int Org[maxn][maxn];
int P[maxn];
int N, M;
void Updates(int v, int c)
{
	int u;
	if (v == 1)
	{
		return;
	}
	u = P[v];
	MaxF[u][v] -= c;
	MaxF[v][u] += c;
	Updates(P[v], c);
}
int BFS()
{
	ss t, d;
	list<int>::iterator p;
	int c, v;
	t.u = 1;
	t.cost = 1000000000;
	Q.push(t);
	Color[1] = 1;
	while (!Q.empty())
	{
		t = Q.top();
		Q.pop();
		for (p = Edge[t.u].begin(); p != Edge[t.u].end(); p++)
		{
			v = *p;
			if (Color[v] || !MaxF[t.u][v])
			{
				continue;
			}
			Color[v] = 1;
			P[v] = t.u;
			c = MIN(t.cost, MaxF[t.u][v]);
			if (v == 2)
			{
				Updates(v, c);
				return 1;
			}
			d.cost = c;
			d.u = v;
			Q.push(d);
		}
	}
	return 0;
}
void Reset()
{
	int i;
	for (i = 1; i <= N; i++)
	{
		Color[i] = 0;
	}
	while (!Q.empty())
	{
		Q.pop();
	}
}
void Cal()
{
	int i, v;
	list<int>::iterator p;
	while (BFS())
	{
		Reset();
	}
	for (i = 1; i <= N; i++)
	{
		if (Color[i])
		{
			for (p = Edge[i].begin(); p != Edge[i].end(); p++)
			{
				v = *p;
				if (Color[v])
				{
					continue;
				}
				cout << i << " " << v << endl;
			}
		}
	}
	cout << endl;
}
void Free()
{
	int i;
	for (i = 1; i <= N; i++)
	{
		Edge[i].clear();
		Color[i] = 0;
	}
}
int main()
{
	int i, u, v, c;
	while (cin >> N >> M)
	{
		if (!N && !M)
		{
			break;
		}
		for (i = 0; i < M; i++)
		{
			cin >> u >> v >> c;
			Org[u][v] = Org[v][u] = c;
			MaxF[u][v] = MaxF[v][u] = c;
			Edge[u].push_back(v);
			Edge[v].push_back(u);
		}
		Cal();
		Free();
	}
	return 0;
}
