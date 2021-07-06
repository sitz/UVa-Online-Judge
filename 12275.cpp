#include <bits/stdc++.h>

using namespace std;

// O(VE)

#define infinity 1000000000
#define MAXV 350

struct edge
{
	int a, b, w;
};

class cmp
{
public:
	bool operator()(const edge &e, const edge &f)
	{
		return (e.w < f.w);
	}
};

int n, parent[MAXV], ret, minedge, maxedge, treesize, weight[MAXV][MAXV];
vector<edge> edges;

int commonancestor(int a, int b)
{
	bool vis[MAXV];
	for (int i = 0; i < n; i++)
	{
		vis[i] = false;
	}
	int z = a;
	vis[z] = true;
	do
	{
		z = parent[z];
		if (z >= 0)
		{
			vis[z] = true;
		}
	} while (z >= 0 && parent[z] != z);
	int x = b;
	while (x >= 0 && !vis[x] && x != parent[x])
	{
		x = parent[x];
	}
	if (!vis[x])
	{
		return -1;
	}
	else
	{
		return x;
	}
}

void findremove(int a, int b)
{
	int x = commonancestor(a, b);
	edge light;
	light.w = infinity;
	int y = a;
	while (y != x)
	{
		if (weight[y][parent[y]] < light.w)
		{
			light.a = y;
			light.b = parent[y];
			light.w = weight[y][parent[y]];
		}
		y = parent[y];
	}
	bool inb = false;
	y = b;
	while (y != x)
	{
		if (weight[y][parent[y]] < light.w)
		{
			light.a = y;
			light.b = parent[y];
			light.w = weight[y][parent[y]];
			inb = true;
		}
		y = parent[y];
	}
	//removing the edge
	if (inb)
	{
		y = b;
	}
	else
	{
		y = a;
	}
	vector<int> v;
	v.push_back(y);
	while (y != light.a)
	{
		y = parent[y];
		v.push_back(y);
	}
	for (int i = v.size() - 1; i > 0; i--)
	{
		parent[v[i]] = v[i - 1];
	}
	if (inb)
	{
		parent[b] = a;
	}
	else
	{
		parent[a] = b;
	}
	treesize--;
	//compute the new lightest edge
	minedge = infinity;
	for (int i = 0; i < n; i++)
		if (parent[i] != -1 && parent[i] != i)
		{
			minedge = min(minedge, weight[i][parent[i]]);
		}
	return;
}

void process(edge e)
{
	int x = commonancestor(e.a, e.b);
	if (x != -1)
	{
		findremove(e.a, e.b);
	}
	else if (parent[e.a] >= 0 && parent[e.b] >= 0)
	{
		int y = e.a;
		vector<int> v;
		v.push_back(y);
		while (y != parent[y])
		{
			y = parent[y];
			v.push_back(y);
		}
		for (int i = v.size() - 1; i > 0; i--)
		{
			parent[v[i]] = v[i - 1];
		}
		parent[e.a] = e.b;
	}
	else if (parent[e.a] == -1)
	{
		parent[e.a] = e.b;
		if (parent[e.b] == -1)
		{
			parent[e.b] = e.b;
		}
	}
	else
	{
		parent[e.b] = e.a;
	}
	treesize++;
	maxedge = e.w;
	if (treesize == 1)
	{
		minedge = e.w;
	}
	if (treesize == n - 1)
	{
		ret = min(ret, maxedge - minedge);
	}
	return;
}

int main()
{
	clock_t start, finish;
	start = clock();
	for (;;)
	{
		int nedges;
		cin >> n;
		if (!n)
		{
			break;
		}
		cin >> nedges;
		int x, y, z;
		edge e;
		edges.clear();
		for (int i = 0; i < nedges; i++)
		{
			cin >> x >> y >> z;
			e.a = x;
			e.b = y;
			e.w = z;
			weight[x][y] = z;
			weight[y][x] = z;
			edges.push_back(e);
		}
		sort(edges.begin(), edges.end(), cmp());
		memset(parent, -1, sizeof(parent));
		ret = infinity;
		treesize = 0;
		minedge = -infinity;
		maxedge = infinity;
		for (int i = 0; i < nedges; i++)
		{
			process(edges[i]);
		}
		cout << ret << endl;
	}
	finish = clock();
	cerr << "Time: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
	return 0;
}
