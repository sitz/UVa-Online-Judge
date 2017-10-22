#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < (int)n; i++)
#define rep(i, n) REP(i, 0, n)
#define FOR(it, o) for (__typeof((o).begin()) it = (o).begin(); it != (o).end(); ++it)

const int V = 1000;
int n;
bool edge[V][V], preUsed[V][V], used[V][V];
int preNum[V], low[V], rootNode, defultID[V];
vector<pair<int, int>> Edge;

int dfs(int nowNode, int &nowNum)
{
	low[nowNode] = preNum[nowNode] = nowNum;
	defultID[nowNum] = nowNode;
	nowNum++;
	rep(i, n)
	{
		if (!edge[nowNode][i])
		{
			continue;
		}
		if (preNum[i] >= 0)
		{
			if (preUsed[i][nowNode])
			{
				continue;
			}
			low[nowNode] = min(low[nowNode], preNum[i]);
			if (used[nowNode][i])
			{
				continue;
			}
			Edge.push_back(make_pair(nowNode, i));
			used[nowNode][i] = used[i][nowNode] = true;
		}
		else
		{
			preUsed[nowNode][i] = true;
			Edge.push_back(make_pair(nowNode, i));
			used[nowNode][i] = used[i][nowNode] = true;
			low[nowNode] = min(dfs(i, nowNum), low[nowNode]);
		}
	}
	return low[nowNode];
}
void getBridge()
{
	rep(i, n)
	{
		rep(j, n)
		{
			if (!preUsed[i][j])
			{
				continue;
			}
			if (low[j] == preNum[j])
			{
				Edge.push_back(make_pair(defultID[max(preNum[i], preNum[j])], defultID[min(preNum[i], preNum[j])]));
			}
		}
	}
}
void setGraph()
{
	rootNode = 0;
	rep(i, n)
	{
		preNum[i] = -1;
		rep(j, n)
		{
			used[i][j] = false;
			preUsed[i][j] = false;
		}
	}
	int id = 0;
	dfs(rootNode, id);
}

int main()
{
	int m;
	int tc = 0;
	while (cin >> n >> m)
	{
		tc++;
		if (n == 0 && m == 0)
		{
			break;
		}
		cout << tc << endl
				 << endl;
		rep(i, n) rep(j, n) edge[i][j] = false;
		rep(i, m)
		{
			int from, to;
			cin >> from >> to;
			from--;
			to--;
			edge[from][to] = edge[to][from] = true;
		}
		Edge.clear();
		setGraph();
		getBridge();
		FOR(it, Edge)
		{
			cout << it->first + 1 << ' ' << it->second + 1 << endl;
		}
		cout << "#" << endl;
	}
	return 0;
}
