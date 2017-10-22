#include <bits/stdc++.h>

using namespace std;

#define fr(a, b, c) for (int a = b; a < c; a++)
#define rp(a, b) fr(a, 0, b)
#define add(a, b, c) to[z] = b, cost[z] = c, ant[z] = adj[a], adj[a] = z++
#define maxn 300
#define maxm 300000

int to[maxm], cost[maxm], ant[maxm], adj[maxn], gas[maxn], totalcost[maxn][105];
int z, N, R, Q, a, b, w;
char gb[10];

struct st
{
	int no, driven, cost;
	st() {}
	st(int no, int driven, int cost) : no(no), driven(driven), cost(cost) {}

	bool operator<(const st &lhs) const
	{
		return cost > lhs.cost;
	}
} aux;

priority_queue<st> pq;

int main()
{
	int cas = 1;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(adj, -1, sizeof adj);
		z = 0;
		scanf("%d%d%d", &N, &R, &Q);
		rp(i, N)
		{
			scanf("%s", gb);
			gas[i] = (gb[0] == 'G');
		}
		rp(i, R)
		{
			scanf("%d%d%d", &a, &b, &w);
			if (w <= 100)
				add(a - 1, b - 1, w), add(b - 1, a - 1, w);
		}
		printf("CASE %d\n", cas++);
		rp(i, Q)
		{
			scanf("%d%d", &a, &b);
			a--, b--;
			while (!pq.empty())
				pq.pop();
			pq.push(st(a, 0, 0));
			memset(totalcost, 0x3f, sizeof totalcost);
			totalcost[a][0] = 0;
			while (!pq.empty())
			{
				aux = pq.top();
				pq.pop();
				if (aux.no == b)
				{
					printf("%d\n", aux.cost);
					goto fim;
				}
				int newdriven = (gas[aux.no] ? 0 : aux.driven);
				for (int i = adj[aux.no]; ~i; i = ant[i])
				{
					if (newdriven + cost[i] <= 100 && aux.cost + cost[i] < totalcost[to[i]][newdriven + cost[i]])
					{
						totalcost[to[i]][newdriven + cost[i]] = aux.cost + cost[i];
						pq.push(st(to[i], newdriven + cost[i], aux.cost + cost[i]));
					}
				}
			}
			printf("NO GAS PATH\n");
		fim:;
		}
	}
	return 0;
}
