#include <bits/stdc++.h>

using namespace std;

struct ss
{
	int ind;
	char nam[100];
};
struct node
{
	int x;
};
class comp
{
public:
	bool operator()(const node &a, const node &b)
	{
		return a.x > b.x;
	}
};
ss Dr[102];
list<int> V;
vector<int> L[101], W[101];
priority_queue<node, vector<node>, comp> Q;
char Org[101][52];
int N, M, Deg[101];

int com(const void *a, const void *b)
{
	ss *x, *y;
	x = (ss *)a;
	y = (ss *)b;
	return strcmp(x->nam, y->nam);
}

void BFS()
{
	int u, i;
	node t, d;
	for (i = 0; i < N; i++)
		if (Deg[i] == 0)
		{
			t.x = i;
			Q.push(t);
		}
	while (!Q.empty())
	{
		t = Q.top();
		V.push_back(t.x);
		Q.pop();
		for (i = 0; i < W[t.x].size(); i++)
		{
			u = W[t.x][i];
			Deg[u]--;
			if (Deg[u] == 0)
			{
				d.x = u;
				Q.push(d);
			}
		}
	}
}

void Cal()
{
	int u, v;
	ss st;
	ss *p;
	qsort(Dr, N, sizeof(ss), com);
	cin >> M;
	while (M--)
	{
		cin >> st.nam;
		p = (ss *)bsearch(&st, Dr, N, sizeof(ss), com);
		u = p->ind;
		cin >> st.nam;
		p = (ss *)bsearch(&st, Dr, N, sizeof(ss), com);
		v = p->ind;
		L[u].push_back(v);
		W[u].push_back(v);
		Deg[v]++;
	}
	BFS();
	list<int>::iterator it;
	for (it = V.begin(); it != V.end(); it++)
	{
		u = *it;
		cout << " " << Org[u];
	}
	cout << ".\n\n";
}

void Free()
{
	int i;
	for (i = 0; i < 101; i++)
	{
		Deg[i] = 0;
		L[i].clear();
		W[i].clear();
	}
	V.clear();
}

int main()
{
	int i, k = 1;
	while (cin >> N)
	{
		for (i = 0; i < N; i++)
		{
			cin >> Dr[i].nam;
			strcpy(Org[i], Dr[i].nam);
			Dr[i].ind = i;
		}
		cout << "Case #" << k++ << ": Dilbert should drink beverages in this order:";
		Cal();
		Free();
	}
	return 0;
}
