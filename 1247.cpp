#include <bits/stdc++.h>

using namespace std;

const int MAX = 30;
const int INF = 1e9;
typedef pair<int, int> P;

int G[MAX][MAX];
int d[MAX];
int path[MAX];
int N;

void init()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
		{
			G[i][j] = INF;
		}
}

void dijkstra(int s, int g)
{
	for (int i = 0; i < MAX; i++)
	{
		d[i] = INF, path[i] = INF;
	}
	d[s] = 0;
	priority_queue<P, vector<P>, greater<P>> que;
	que.push(P(0, s));
	while (que.size())
	{
		P p = que.top();
		que.pop();
		int v = p.second;
		if (d[v] < p.first)
		{
			continue;
		}
		for (int i = 0; i < MAX; i++)
		{
			if (G[v][i] == INF)
			{
				continue;
			}
			if (d[i] > d[v] + G[v][i])
			{
				d[i] = d[v] + G[v][i];
				que.push(P(d[i], i));
				path[i] = v;
			}
		}
	}
}

int main()
{
	init();
	int N, m;
	cin >> N >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, cost;
		char aa, bb;
		cin >> aa >> bb >> cost;
		a = aa - 'A';
		b = bb - 'A';
		G[a][b] = G[b][a] = cost;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int s, g;
		char aa, bb;
		cin >> aa >> bb;
		s = aa - 'A';
		g = bb - 'A';
		dijkstra(s, g);
		vector<char> res;
		int now = g;
		while (1)
		{
			res.push_back(now + 'A');
			now = path[now];
			if (now == INF)
			{
				break;
			}
		}
		reverse(res.begin(), res.end());
		for (int j = 0; j < res.size(); j++)
		{
			if (j != 0)
			{
				cout << ' ';
			}
			cout << res[j];
		}
		cout << endl;
	}
	return 0;
}
