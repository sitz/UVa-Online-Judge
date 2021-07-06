#include <bits/stdc++.h>

using namespace std;

const int MAXNODE = 35;

struct Node
{
	int id, ttl;
};

bool adj[MAXNODE][MAXNODE];
int NC, kase = 1;
int nodeID[MAXNODE], cntNode;

int getIndex(int id)
{
	for (int i = 0; i < cntNode; i++)
		if (nodeID[i] == id)
		{
			return i;
		}
	return -1;
}

void input()
{
	cntNode = 0;
	memset(adj, 0, sizeof(adj));
	int x, y;
	for (int i = 0; i < NC; i++)
	{
		cin >> x >> y;
		int xID = getIndex(x);
		if (xID < 0)
		{
			xID = cntNode;
			nodeID[cntNode++] = x;
		}
		int yID = getIndex(y);
		if (yID < 0)
		{
			yID = cntNode;
			nodeID[cntNode++] = y;
		}
		adj[xID][yID] = adj[yID][xID] = true;
	}
}

int bfs(int start, int ttl)
{
	bool vis[MAXNODE] = {false};
	Node node;
	queue<Node> q;
	node.id = start;
	node.ttl = 0;
	q.push(node);
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		if (node.ttl > ttl || vis[node.id])
		{
			continue;
		}
		vis[node.id] = true;
		for (int i = 0; i < cntNode; i++)
		{
			if (adj[node.id][i] && node.ttl < ttl && !vis[i])
			{
				Node p;
				p.id = i;
				p.ttl = node.ttl + 1;
				q.push(p);
			}
		}
	}
	int res = 0;
	for (int i = 0; i < cntNode; i++)
		if (!vis[i])
		{
			res++;
		}
	return res;
}

int main()
{
	while (cin >> NC && NC)
	{
		input();
		int start, ttl;
		while (cin >> start >> ttl && start)
		{
			int s = getIndex(start);
			cout << "Case " << kase++ << ": " << bfs(s, ttl) << " nodes not reachable from node ";
			cout << start << " with TTL = " << ttl << "." << endl;
		}
	}
	return 0;
}
