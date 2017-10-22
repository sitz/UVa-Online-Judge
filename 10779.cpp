#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

const int N = 1500;
const int inf = (1 << 21);
int cap[N][N];
bool visited[N];
int parent[N];
int flow[N][N];
int layer[N];
void make_layer(int n, int s, int t)
{
	queue<int> Q;
	Q.push(s);
	layer[s] = 0;
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		rep(i, n)
		{
			if (cap[now][i] - flow[now][i] > 0 && layer[i] == -1)
			{
				layer[i] = layer[now] + 1;
				Q.push(i);
			}
		}
	}
}

int augment(int now, int t, int n, int f)
{
	if (now == t || f == 0)
	{
		return f;
	}
	if (visited[now])
	{
		return 0;
	}
	visited[now] = true;
	rep(i, n)
	{
		if (layer[now] < layer[i])
		{
			int tmp = augment(i, t, n, min(f, cap[now][i] - flow[now][i]));
			if (tmp > 0)
			{
				flow[now][i] += tmp;
				flow[i][now] = -flow[now][i];
				visited[now] = false;
				return tmp;
			}
		}
	}
	return 0;
}

int dinic(int n, int s, int t)
{
	int ansflow = 0;
	bool flag = true;
	rep(i, n) rep(j, n) flow[i][j] = 0;
	while (flag)
	{
		fill(layer, layer + n, -1);
		fill(visited, visited + n, false);
		flag = false;
		//make layer
		make_layer(n, s, t);
		if (layer[t] == -1)
		{
			break;//if no such path to go to sink
		}
		//find blocking flow
		for (int f = 1; f; flag = true)
		{
			f = augment(s, t, n, inf);
			if (f == 0)
			{
				break;
			}
			ansflow += f;
		}
	}
	return ansflow;
}

#define FIRST(i, k, m) ((i) * (m)*4 + (k))
#define SECOND(i, k, m) ((i) * (m)*4 + (m) + (k))
#define THIRD(i, k, m) ((i) * (m)*4 + 2 * (m) + (k))
#define FOURTH(i, k, m) ((i) * (m)*4 + 3 * (m) + (k))

main()
{
	int te;
	cin >> te;
	int card[50];
	rep(tc, te)
	{
		int n, m;
		cin >> n >> m;
		int node = n * m * 4 + 2, src = node - 2, dst = node - 1;
		rep(i, node) rep(j, node) cap[i][j] = 0;
		rep(i, n)
		{
			rep(j, m) card[j] = 0;
			int num, t;
			cin >> num;
			rep(j, num)
			{
				cin >> t;
				card[t - 1]++;
			}
			rep(j, m)
			{
				if (i == 0)
				{
					cap[src][FIRST(0, j, m)] = inf;
					cap[FIRST(i, j, m)][SECOND(i, j, m)] = card[j];
					cap[SECOND(i, j, m)][THIRD(i, j, m)] = inf;
					cap[THIRD(i, j, m)][FOURTH(i, j, m)] = 1;
					cap[FOURTH(i, j, m)][dst] = 1;
				}
				else
				{
					if (card[j] > 0)
					{
						cap[THIRD(i, j, m)][FOURTH(i, j, m)] = card[j] - 1;
					}
					if (card[j] == 0)
					{
						cap[FIRST(i, j, m)][SECOND(i, j, m)] = 1;
					}
					cap[FOURTH(i, j, m)][THIRD(0, j, m)] = 1;
				}
			}
		}
		REP(j, 1, n)
		{
			rep(k, m)
			{
				cap[SECOND(0, k, m)][FIRST(j, k, m)] = inf;
			}
		}
		REP(i, 1, n)
		{
			REP(j, 1, n)
			{
				if (i == j)
				{
					continue;
				}
				//trade
				rep(k, m)
				{
					cap[FOURTH(i, k, m)][FIRST(j, k, m)] = inf;
				}
			}
			//self
			rep(j, m)
			{
				rep(k, m)
				{
					if (j != k)
					{
						cap[SECOND(i, j, m)][THIRD(i, k, m)] = inf;
					}
				}
			}
		}
		int ans = dinic(node, src, dst);
		cout << "Case #" << tc + 1 << ": " << ans << endl;
	}
	return false;
}
