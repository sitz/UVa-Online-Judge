#include <bits/stdc++.h>

using namespace std;

const int kMaxn = 507;
const int kInf = 0x7f7f7f7f;

struct Edge {int v, w;};
Edge e[kMaxn * 40];

int r[107], fst[kMaxn], nxt[kMaxn * 40], f, n, cnt, ans, value, d[107][kMaxn], near[kMaxn];

void Clear()
{
	cnt = -1;
	memset(fst, -1, sizeof(fst));
}

void AddEdge(int u, int v, int w)
{
	cnt++;
	e[cnt].v = v;
	e[cnt].w = w;
	nxt[cnt] = fst[u];
	fst[u] = cnt;
}

void Input()
{
	scanf("%d%d", &f, &n);
	for (int i = 1; i <= f; i++)
	{
		scanf("%d", &r[i]);
	}
	getchar();
	Clear();
	string in;
	while (getline(cin, in) && !in.empty())
	{
		int u, v, w;
		istringstream(in) >> u >> v >> w;
		AddEdge(u, v, w);
		AddEdge(v, u, w);
	}
}

void SPFA(int start, int *dist)
{
	deque<int> q;
	bool inq[kMaxn];
	memset(inq, false, sizeof(inq));
	for (int i = 1; i <= n; i++)
	{
		dist[i] = kInf;
	}
	dist[start] = 0;
	q.push_back(start);
	while (!q.empty())
	{
		int u = q.front();
		q.pop_front();
		inq[u] = false;
		for (int i = fst[u]; i != -1; i = nxt[i])
		{
			int v = e[i].v;
			if (dist[v] > dist[u] + e[i].w)
			{
				dist[v] = dist[u] + e[i].w;
				if (!inq[v])
				{
					if (!q.empty() && dist[v] < dist[q.front()])
					{
						q.push_front(v);
					}
					else
					{
						q.push_back(v);
					}
					inq[v] = true;
				}
			}
		}
	}
}

void Solve()
{
	for (int i = 1; i <= f; i++)
	{
		SPFA(r[i], d[i]);
	}
	memset(near, 0x7f, sizeof(near));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= f; j++)
		{
			near[i] = min(near[i], d[j][i]);
		}
	}
	value = kInf;
	for (int i = 1; i <= n; i++)
	{
		SPFA(i, d[f + 1]);
		int t = 0;
		for (int j = 1; j <= n; j++)
		{
			t = max(t, min(near[j], d[f + 1][j]));
		}
		if (value > t)
		{
			ans = i;
			value = t;
		}
	}
}

int main()
{
	bool fst_case = true;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		Input();
		Solve();
		if (fst_case)
		{
			fst_case = false;
		}
		else
		{
			printf("\n");
		}
		printf("%d\n", ans);
	}
	return 0;
}
