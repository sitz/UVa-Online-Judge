#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int Max = 1024;
const int MaxE = 50010;
struct box
{
	int from, to;
	box *s;
} edge[MaxE], *hd[Max], *h2[Max], *cp;
void addEdge(int x, int y, box *h[])
{
	cp->from = x, cp->to = y;
	cp->s = h[x], h[x] = cp++;
}
int pre[Max], low[Max], id[Max];
int s[Max], node[Max];
int cnt, sNum, pCnt;
void SCDfs(int x)
{
	int min, y;
	min = pre[x] = low[x] = cnt++;
	s[sNum++] = x;
	for (box *p = hd[x]; p; p = p->s)
		if (id[y = p->to] == -1)
		{
			if (pre[y] == -1)
			{
				SCDfs(y);
			}
			if (low[y] < min)
			{
				min = low[y];
			}
		}
	if (min < low[x])
	{
		low[x] = min;
		return;
	}
	node[pCnt] = 0;
	do
	{
		id[s[--sNum]] = pCnt;
		++node[pCnt];
	} while (s[sNum] != x);
	pCnt++;
}
void rdfs(int x)
{
	id[x] = 0;
	for (box *p = h2[x]; p; p = p->s)
		if (id[p->to] == -1)
		{
			rdfs(p->to);
		}
	s[sNum++] = x;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int ct = 1; ct <= T; ct++)
	{
		int N, M;
		scanf("%d%d", &N, &M);
		memset(hd + 1, 0, sizeof(hd[0]) * N);
		cp = edge;
		for (int i = 0; i < M; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			addEdge(x, y, hd);
		}
		memset(id + 1, -1, sizeof(id[0]) * N);
		memset(pre + 1, -1, sizeof(pre[0]) * N);
		sNum = 0, cnt = 0, pCnt = 0;
		for (int i = 1; i <= N; i++)
			if (id[i] == -1)
			{
				SCDfs(i);
			}
		//for (int i = 1;i <= N;i++)printf("%d ",id[i]);puts("");
		//for (int i = 0;i < pCnt;i++)printf("%d ",node[i]);puts("");
		memset(h2, 0, sizeof(h2[0]) * pCnt);
		for (box *p = edge, *np = cp; p < np; p++)
			if (id[p->from] != id[p->to])
			{
				addEdge(id[p->to], id[p->from], h2);
				//printf("%d to %d\n",id[p->from],id[p->to]);
			}
		memset(id, -1, sizeof(id[0]) * pCnt);
		sNum = 0;
		for (int i = 0; i < pCnt; i++)
			if (id[i] == -1)
			{
				rdfs(i);
			}
		//for (int i = 0;i < pCnt;i++)printf("%d ",s[i]);puts("");
		int R1 = 0, R2 = 0;
		for (int i = pCnt - 1; i >= 0; i--)
		{
			int x = s[i];
			memset(low, -1, sizeof(low[0]) * pCnt);
			low[x] = 0;
			int cnt = 0;
			for (int j = i; j >= 0; j--)
			{
				int y = s[j];
				if (low[y] == -1)
				{
					continue;
				}
				for (box *p = h2[y]; p; p = p->s)
					if (low[y] + 1 > low[p->to])
					{
						low[p->to] = low[y] + 1;
					}
				if (low[y] == 1)
				{
					++R1;
				}
				cnt += node[y];
			}
			if (node[x] > 1)
			{
				R1 += node[x];
				R2 += node[x] * (node[x] - 1);
			}
			R2 += (cnt - node[x]) * node[x];
			//printf("%d : %d %d | %d %d\n",x,node[x],cnt,R1,R2);
			//for (int j = 0;j < pCnt;j++)printf("%d ",low[j]);puts("");
		}
		printf("Case #%d: %d %d\n", ct, R1, R2);
	}
	return 0;
}
