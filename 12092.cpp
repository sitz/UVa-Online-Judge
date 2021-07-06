#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

const int maxn = 200;
const int maxm = 10010;

struct node
{
	int from;
	int to;
	int next;
	int c;
	int f;
} egde[maxm];
int ls;

int box[maxn];
int n;
int dis[maxn], load[maxn], p[maxn], ans_flow, ans_cost;

bool flag[maxn];
bool spfa(int start, int end)
{
	queue<int> q;
	memset(flag, false, sizeof(flag));
	memset(load, -1, sizeof(load));
	memset(dis, 0x3f, sizeof(dis));
	q.push(start);
	dis[start] = 0;
	flag[start] = true;
	while (!q.empty())
	{
		int e = q.front();
		q.pop();
		for (int i = box[e]; i != -1; i = egde[i].next)
		{
			if (egde[i].c)
			{
				int ne = egde[i].to;
				if (dis[ne] - dis[e] > egde[i].f)
				{
					dis[ne] = dis[e] + egde[i].f;
					load[ne] = i;
					if (!flag[ne])
					{
						flag[ne] = true;
						q.push(ne);
					}
				}
			}
		}
		flag[e] = false;
	}
	if (dis[end] == INF)
	{
		return false;
	}
	return true;
}

void Min_Cost_Flow(int start, int end)
{
	int u, mn;
	ans_flow = 0, ans_cost = 0;
	while (spfa(start, end))
	{
		mn = INF;
		for (u = load[end]; u != -1; u = load[egde[u].from])
		{
			mn = min(egde[u].c, mn);
		}
		for (u = load[end]; u != -1; u = load[egde[u].from])
		{
			egde[u].c -= mn;
			egde[u ^ 1].c += mn;
		}
		ans_cost += dis[end] * mn;
		ans_flow += mn;
	}
	return;
}

void add(int t1, int t2, int t3, int c)
{
	egde[ls].from = t1;
	egde[ls].to = t2;
	egde[ls].f = t3;
	egde[ls].c = c;
	egde[ls].next = box[t1];
	box[t1] = ls++;
}

int main()
{
	int index;
	scanf("%d", &index);
	while (index--)
	{
		int t, m, k;
		memset(box, 0xff, sizeof(box));
		scanf("%d%d%d", &n, &m, &k);
		t = n;
		ls = 0;
		for (int i = 0; i < m; i++)
		{
			int t1, t2, t3;
			scanf("%d%d%d", &t1, &t2, &t3);
			add(t1, t2 + n, t3, 1);
			add(t2 + n, t1, -t3, 0);
		}
		for (int i = 0; i < n; i++)
		{
			add(2 * n, i, 0, k);
			add(i, 2 * n, 0, 0);
			add(i + n, 2 * n + 1, 0, k);
			add(2 * n + 1, i + n, 0, 0);
		}
		n = n * 2 + 2;
		Min_Cost_Flow(n - 2, n - 1);
		printf("%d\n", ans_flow == t * k ? ans_cost : -1);
	}
	return 0;
}
