#include <bits/stdc++.h>

using namespace std;

struct Node
{
	Node *ch[2];
	int r, v, s;//sè¡¨ç¤ºèç¹æ°
	Node(int v) : v(v)
	{
		ch[0] = ch[1] = NULL;
		r = rand();
		s = 1;
	}
	bool operator<(const Node &b) const
	{
		return r < b.r;
	}
	int cmp(int x)
	{
		if (x == v)
		{
			return -1;
		}
		return x < v ? 0 : 1;
	}
	void maintain()
	{
		s = 1;
		if (ch[0] != NULL)
		{
			s += ch[0]->s;
		}
		if (ch[1] != NULL)
		{
			s += ch[1]->s;
		}
	}
};
void rotate(Node *&o, int d)
{
	Node *k = o->ch[d ^ 1];
	o->ch[d ^ 1] = k->ch[d];
	k->ch[d] = o;
	o->maintain();
	k->maintain();
	o = k;
}
void insert(Node *&o, int x)//oå­æ ä¸­äºåä¸å­å¨x
{
	if (o == NULL)
	{
		o = new Node(x);
	}
	else
	{
		int d = (x < o->v) ? 0 : 1;//åè®¸ç¸åçvå¼å¨Treapä¸­,æä»¥æ³¨æè¿éçåæ³,ä¸è½ç¨cmp
		insert(o->ch[d], x);
		if (o->ch[d] > o)
		{
			rotate(o, d ^ 1);
		}
	}
	o->maintain();
}
void remove(Node *&o, int x)//oå­æ ä¸­å®ç°å¿é¡»å­å¨x
{
	int d = o->cmp(x);
	if (d == -1)
	{
		Node *u = o;
		if (o->ch[0] && o->ch[1])
		{
			int d2 = (o->ch[0] > o->ch[1]) ? 1 : 0;
			rotate(o, d2);
			remove(o->ch[d2], x);
		}
		else
		{
			if (o->ch[0] == NULL)
			{
				o = o->ch[1];
			}
			else
			{
				o = o->ch[0];
			}
			delete u;
		}
	}
	else
	{
		remove(o->ch[d], x);
	}
	if (o)
	{
		o->maintain();//ä¹åoå­å¨,ä½æ¯å é¤èç¹åoå¯è½å°±æ¯ç©ºNULLäº,æä»¥éè¦åå¤æ­oæ¯å¦ä¸ºç©º
	}
}
const int maxn = 20000 + 100;
const int maxm = 60000 + 100;
int weight[maxn];
struct edge
{
	int u, v;
} edges[maxm];
struct command
{
	int type;//0,1,2,å¯¹äºD,Q,C
	int x, p;
} coms[600000 + 1000];
int cnt;//å½ä»¤æ¡æ°
bool removed[maxm];
int F[maxn];
int findset(int i)
{
	if (F[i] == -1)
	{
		return i;
	}
	return F[i] = findset(F[i]);
}
Node *nodes[maxn];
int kth(Node *o, int k)
{
	if (o == NULL || k <= 0 || k > o->s)
	{
		return 0;
	}
	int s = (o->ch[1] == NULL) ? 0 : o->ch[1]->s;
	if (k == s + 1)
	{
		return o->v;
	}
	else if (k <= s)
	{
		return kth(o->ch[1], k);
	}
	else
	{
		return kth(o->ch[0], k - s - 1);
	}
}
void merge(Node *&a, Node *&b)
{
	if (a->ch[0])
	{
		merge(a->ch[0], b);
	}
	if (a->ch[1])
	{
		merge(a->ch[1], b);
	}
	insert(b, a->v);
	delete a;
	a = NULL;
}
void removetree(Node *&a)
{
	if (a->ch[0])
	{
		removetree(a->ch[0]);
	}
	if (a->ch[1])
	{
		removetree(a->ch[1]);
	}
	delete a;
	a = NULL;
}
void add_edge(int e)
{
	int x = findset(edges[e].u), y = findset(edges[e].v);
	if (x != y)
	{
		if (nodes[x]->s < nodes[y]->s)
		{
			F[x] = y;
			merge(nodes[x], nodes[y]);
		}
		else
		{
			F[y] = x;
			merge(nodes[y], nodes[x]);
		}
	}
}
int query_cnt;
long long query_tot;
void query(int x, int k)
{
	int fx = findset(x);
	query_tot += kth(nodes[fx], k);
	query_cnt++;
}
void change_weight(int x, int v)
{
	int u = findset(x);
	remove(nodes[u], weight[x]);
	insert(nodes[u], v);
	weight[x] = v;
}
int main()
{
	int n, m, kase = 0;
	while (scanf("%d%d", &n, &m) == 2 && n)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		memset(removed, 0, sizeof(removed));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &weight[i]);
		}
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d", &edges[i].u, &edges[i].v);
		}
		char str[100];
		int x, p;
		cnt = 0;
		while (scanf("%s", str) == 1)
		{
			if (str[0] == 'E')
			{
				break;
			}
			scanf("%d", &x);
			if (str[0] == 'D')
			{
				coms[cnt++] = (command){
						0, x, 0};
				removed[x] = true;
			}
			else if (str[0] == 'Q')
			{
				scanf("%d", &p);
				coms[cnt++] = (command){
						1, x, p};
			}
			else if (str[0] == 'C')
			{
				int v;
				scanf("%d", &v);
				p = weight[x];
				weight[x] = v;
				coms[cnt++] = (command){
						2, x, p};
			}
		}
		for (int i = 1; i <= n; i++)
		{
			F[i] = -1;
			if (nodes[i])
			{
				removetree(nodes[i]);
			}
			nodes[i] = new Node(weight[i]);
		}
		for (int i = 1; i <= m; i++)
			if (!removed[i])
			{
				add_edge(i);
			}
		query_tot = query_cnt = 0;
		for (int i = cnt - 1; i >= 0; i--)
		{
			if (coms[i].type == 0)
			{
				add_edge(coms[i].x);
			}
			else if (coms[i].type == 1)
			{
				query(coms[i].x, coms[i].p);
			}
			else if (coms[i].type == 2)
			{
				change_weight(coms[i].x, coms[i].p);
			}
		}
		//printf("tot=%I64d, cnt=%d\n",query_tot,query_cnt);
		printf("Case %d: %.6lf\n", ++kase, query_tot / (double)query_cnt);
	}
	return 0;
}
