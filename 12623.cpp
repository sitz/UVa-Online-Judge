#include <bits/stdc++.h>

using namespace std;

#define fr(a, b, c) for (int a = b; a < c; a++)
#define rp(a, b) fr(a, 0, b)
#define mp make_pair
#define F first
#define S second
#define inf 0x3f3f3f3f

typedef pair<int, int> pii;

int N, P;
int n, c, a;
int size[30];
pii adj[30][30];
int mark[30], TOTAL, resp[30], temp[30];

void bt(int v, int cost)
{
	if (v == N)
	{
		TOTAL = cost;
		rp(i, N) resp[i] = temp[i];
		return;
	}

	rp(i, size[v])
	{
		if (!mark[adj[v][i].F] && cost + adj[v][i].S < TOTAL)
		{
			mark[adj[v][i].F] = 1;
			temp[v] = adj[v][i].F;
			bt(v + 1, cost + adj[v][i].S);
			mark[adj[v][i].F] = 0;
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &P);
		memset(size, 0, sizeof size);
		rp(i, P)
		{
			scanf("%d%d", &c, &n);
			rp(j, n)
			{
				scanf("%d", &a);
				adj[a][size[a]++] = mp(i, c);
			}
		}
		memset(mark, 0, sizeof mark);
		TOTAL = inf;
		bt(0, 0);
		if (TOTAL == inf)
			printf("No solution.\n");
		else
		{
			printf("%d", TOTAL);
			rp(i, N) printf(" %d", resp[i]);
			printf("\n");
		}
	}
	return 0;
}
