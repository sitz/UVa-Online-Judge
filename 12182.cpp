#include <bits/stdc++.h>

using namespace std;

// method : divide-and-conquer
// runtime: O(n)

typedef pair<int, int> pi;
vector<pi> adj[200001];
int mss;

// maximum sum of a subtree with root x and predecessor y
int dfs(int x, int y)
{
	int p = 0;
	// process and destruct subtrees of x
	for (; !adj[x].empty(); adj[x].pop_back())
		// do not return to y
		if (adj[x].back().first != y)
		// take only positive subtrees
		{
			p += max(0, adj[x].back().second + dfs(adj[x].back().first, x));
		}
	// keep the maximum over all subtrees
	mss = max(mss, p);
	return p;
}

int main()
{
	int n, a, b, p;
	while (cin >> n && n)
	{
		// build adjacency lists of graph
		while (n--)
		{
			cin >> a >> b >> p;
			adj[a].push_back(pi(b, p));
			adj[b].push_back(pi(a, p));
		}
		// global maximum
		mss = 0;
		// start at arbitrary node
		dfs(b, b);
		cout << mss << endl;
	}
	return 0;
}
