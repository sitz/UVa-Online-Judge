#include <bits/stdc++.h>

using namespace std;

struct Vertex
{
	vdata id;
	vector<Vertex *> adj;
	Vertex(vdata id) : id(id) {}
};
typedef map<vdata, Vertex *> vmap;
typedef pair<vdata, Vertex *> vpair;
typedef int vdata;

struct Graph
{
	Graph() {}
	~Graph();
	Vertex *addVertex(vdata v);
	void addEdge(vdata begin, vdata end, bool directed);
	Vertex *firstVertex();
	void solve(int point, int depth);

	Vertex *getVertex(vdata v);
	vmap vertexMap;
	vector<Vertex *> allVertexes;
};

Graph::~Graph()
{
	for (int i = 0; i < allVertexes.size(); i++)
	{
		delete allVertexes[i];
	}
}

Vertex *Graph::addVertex(vdata v)
{
	Vertex *newv = new Vertex(v);
	allVertexes.push_back(newv);
	vertexMap.insert(vpair(v, newv));
	return newv;
}

void Graph::addEdge(vdata begin, vdata end, bool directed = false)
{
	Vertex *v = getVertex(begin);
	Vertex *w = getVertex(end);
	v->adj.push_back(w);
	if (!directed)
	{
		w->adj.push_back(v);
	}
}

Vertex *Graph::getVertex(vdata v)
{
	vmap::iterator it = vertexMap.find(v);
	if (it == vertexMap.end())
	{
		return addVertex(v);
	}
	return (*it).second;
}

Vertex *Graph::firstVertex()
{
	return allVertexes[0];
}

void Graph::solve(int n, int a)
{
	int tmp;
	Vertex *v;
	bool visited[n + 1];
	fill(visited, visited + n + 1, false);
	queue<int> q;
	int count = n;
	q.push(a);
	while (!q.empty())
	{
		tmp = q.front();
		q.pop();
		v = getVertex(tmp);
		for (int i = 0, sz = v->adj.size(); i < sz; i++)
		{
			if (visited[v->adj[i]->id])
			{
				continue;
			}
			visited[v->adj[i]->id] = true;
			count--;
			q.push(v->adj[i]->id);
		}
	}
	cout << count;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			cout << " " << i;
		}
	}
	cout << endl;
}

int main()
{
	int n;
	int a, b;
	while (cin >> n)
	{
		if (!n)
		{
			break;
		}
		Graph g;
		for (int i = 1; i <= n; i++)
		{
			g.addVertex(i);
		}
		while (cin >> a)
		{
			if (!a)
			{
				break;
			}
			while (cin >> b)
			{
				if (!b)
				{
					break;
				}
				g.addEdge(a, b, true);
			}
		}
		cin >> a;
		while (a--)
		{
			cin >> b;
			g.solve(n, b);
		}
	}
	return 0;
}
