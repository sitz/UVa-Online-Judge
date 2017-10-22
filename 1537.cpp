#include <bits/stdc++.h>

using namespace std;

#define MAXN 105
#define MAXM 100005
#define INF 1000000000

struct node
{
	int v, w, next;
} edge[MAXM];
struct Edge
{
	int u, v, w;
	Edge() {}
	Edge(int a, int b, int c)
	{
		u = a;
		v = b;
		w = c;
	}
	void init()
	{
		w = 0;
	}
	bool operator>(const Edge &a) const
	{
		return w > a.w;
	}
} mx[MAXN];																							 //ç¨äºå­å¨æ¯ä¸ªç¹å°parkç¹çæå¤§è¾¹
int n, m, k, sum;																				 //sumä¸ºç»æ
int e, head[MAXN], vis[MAXN], dis[MAXN], use[MAXN][MAXN];//headç¨äºé»æ¥è¡¨ visæ¯æ è®°æ°ç» disç¨äºæ±æå°çææ 
//useç¨æ¥æ è®°ä¸¤ç¹ä¹é´æ¯å¦æè¾¹
int blocks, size[MAXN], belong[MAXN], nearvex[MAXN];//blocksè¡¨ç¤ºå»é¤parkåæå ä¸ªè¿éå  sizeæ¯æ¯ä¸ªè¿éåçä¸ªæ°
//belongè¡¨ç¤ºè¯¥ç¹å±äºåªä¸ªè¿éå  nearvexç¨äºå¨çææ ä¸­è®°å½è¾¹
int point[MAXN], link[MAXN];//pointè¡¨ç¤ºæ¯ä¸ªè¿éåä¸­ä¸parkç¹æè¿çç¹  linkåæ¯è¯¥ç¹ä¸parkç¹çè·ç¦»
map<string, int> mp;				//ç¨äºæ å°åå­
void init()
{
	e = 0, n = 1;
	blocks = 0, sum = 0;
	memset(head, -1, sizeof(head));
	memset(vis, 0, sizeof(vis));
	memset(size, 0, sizeof(size));
	memset(use, 0, sizeof(use));
	for (int i = 1; i < MAXN; i++)
	{
		mx[i].init();
	}
	memset(nearvex, 0, sizeof(nearvex));
	mp.clear();
}
void insert(int x, int y, int w)
{
	edge[e].v = y;
	edge[e].w = w;
	edge[e].next = head[x];
	head[x] = e++;
}
int getId(char s[])
{
	if (mp.find(s) == mp.end())
	{
		mp[s] = ++n;
	}
	else
	{
		return mp[s];
	}
	return n;
}
void dfs(int v)//è¯¥dfså°å¾åæäºä¸äºè¿éå
{
	vis[v] = 1;
	size[blocks]++;
	belong[v] = blocks;
	for (int i = head[v]; i != -1; i = edge[i].next)
		if (!vis[edge[i].v])
		{
			dfs(edge[i].v);
		}
}
void prim(int cur)//å¯¹æä¸ªè¿éåæ±æå°çææ 
{
	for (int i = 1; i <= n; i++)
	{
		dis[i] = INF;
	}
	for (int i = 1; i <= n; i++)//è®¾ç½®ååæç¹ä¸ºèµ·ç¹æ¥æ±çææ 
		if (belong[i] == cur)
		{
			dis[i] = 0;
			break;
		}
	for (int i = 1; i <= size[cur]; i++)//å¾ªç¯æ¬¡æ°ä¸ºè¯¥åçé¡¶ç¹æ°ï¼å ä¸ºè¿ä¸ä¸è¬çæ±MSTç¥å¾®ä¸å
	{
		int mi = INF, pos = -1;
		for (int j = 1; j <= n; j++)
			if (nearvex[j] != -1 && mi > dis[j])
			{
				mi = dis[j], pos = j;
			}
		if (pos != -1)
		{
			sum += mi;
			use[pos][nearvex[pos]] = use[nearvex[pos]][pos] = 1;//æ è®°çææ ä¸­æç¨çè¾¹
			nearvex[pos] = -1;
			for (int j = head[pos]; j != -1; j = edge[j].next)
				if (nearvex[edge[j].v] != -1 && dis[edge[j].v] > edge[j].w)
				{
					dis[edge[j].v] = edge[j].w;
					nearvex[edge[j].v] = pos;
				}
		}
	}
}
void getMax(int v, int fa, int w)//è¯¥å½æ°ç¨äºæ´æ°æ°ççææ ä¸­ç¹å°parkç¹çæå¤§è¾¹
{
	nearvex[v] = fa;
	Edge t(v, fa, w);
	if (mx[fa] > t)
	{
		mx[v] = mx[fa];
	}
	else
	{
		mx[v] = t;
	}
	for (int i = head[v]; i != -1; i = edge[i].next)
		if (use[v][edge[i].v] && edge[i].v != fa)
		{
			getMax(edge[i].v, v, edge[i].w);//å¿é¡»æ¯çææ ä¸­çè¾¹å¹¶ä¸ä¸æ¯åè¾¹æå¾ä¸æ
		}
}
void GetMdegreeMST()
{
	vis[1] = 1;
	for (int i = 2; i <= n; i++)//æ±è¿éå
		if (!vis[i])
		{
			blocks++;
			dfs(i);
		}
	nearvex[1] = -1;
	for (int i = 1; i <= blocks; i++)
	{
		prim(i);
	}
	for (int i = 1; i <= n; i++)
	{
		link[i] = INF;
	}
	for (int i = head[1]; i != -1; i = edge[i].next)//çæä¸æ£µmåº¦ççææ 
		if (link[belong[edge[i].v]] > edge[i].w)
		{
			link[belong[edge[i].v]] = edge[i].w;
			point[belong[edge[i].v]] = edge[i].v;
		}
	for (int i = 1; i <= blocks; i++)//å°parkç¹ä¸æ¯ä¸ªè¿éåä¸­ä¸å¶æè¿çç¹ç¸è¿ï¼å¹¶ä¸æ è®°è¾¹
	{
		sum += link[i];
		use[1][point[i]] = use[point[i]][1] = 1;
	}
}
void slove()
{
	int degree = blocks;
	getMax(1, 0, 0);	//é¦åä»parkç¹åºåæ±ä¸éæå¤§è¾¹
	while (degree < k)//å°è¯è¿­ä»£ k - degreeæ¬¡
	{
		int maxval = 0, pos = 0, w;
		for (int i = head[1]; i != -1; i = edge[i].next)//ç¨äºæ¾å°å·®å¼æå¤§çç¹
			if (!use[1][edge[i].v] && mx[edge[i].v].w - edge[i].w > maxval)
			{
				maxval = mx[edge[i].v].w - edge[i].w, pos = edge[i].v;
				w = edge[i].w;
			}
		if (!pos)
		{
			break;
		}
		sum -= maxval;//æ´æ°ç­æ¡
		degree++;
		use[mx[pos].u][mx[pos].v] = use[mx[pos].v][mx[pos].u] = 0;//å°æå¤§è¾¹å é¤
		use[1][pos] = use[pos][1] = 1;
		getMax(pos, 1, w);//æ´æ°æå¤§è¾¹
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char s1[55], s2[55];
		int w;
		scanf("%d", &m);
		init();
		mp["Park"] = 1;
		for (int i = 0; i < m; i++)
		{
			scanf("%s%s%d", s1, s2, &w);
			insert(getId(s1), getId(s2), w);
			insert(getId(s2), getId(s1), w);
		}
		scanf("%d", &k);
		GetMdegreeMST();
		slove();
		printf("Total miles driven: %d\n", sum);
		if (t)
		{
			printf("\n");
		}
	}
	return 0;
}
