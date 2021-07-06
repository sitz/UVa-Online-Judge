#include <bits/stdc++.h>

using namespace std;

const int maxn = 400000;

int cnttree;

struct node
{
	node *ch[2], *f;
	int key, key2, num;

	void flow()
	{
		num = ch[0]->num + ch[1]->num + 1;
	}
	void rot(node *&rt)
	{
		node *t = f;
		int isr = (t->ch[1] == this);
		t->ch[isr] = ch[!isr], ch[!isr]->f = t;
		f = t->f, t->f = this, ch[!isr] = t;
		f->ch[f->ch[1] == t] = this;
		t->flow(), flow();
		if (!f->num)
		{
			rt = this;
		}
	}
	void ins(node *&rt, node *ff, node *t)
	{
		if (!num)
		{
			t->f = ff;
			if (!ff->num)
			{
				rt = t;
			}
			else
			{
				ff->ch[t->key > ff->key] = t;
			}
			while (t->f->num && t->key2 > t->f->key2)
			{
				t->rot(rt);
			}
			return;
		}
		num++;
		if (t->key <= key)
		{
			ch[0]->ins(rt, this, t);
		}
		else
		{
			ch[1]->ins(rt, this, t);
		}
	}
} nn[maxn];

struct treap
{
	node *rt;

	void ins(int k)
	{
		++cnttree;
		node *t = nn + cnttree;
		t->key = k, t->key2 = rand();
		t->f = t->ch[0] = t->ch[1] = nn;
		t->num = 1;
		rt->ins(rt, nn, t);
	}
	void del(int k)
	{
		if (rt->num == 1)
		{
			rt = nn;
			return;
		}
		node *t = rt;
		while (t->key - k)
		{
			if (k < t->key)
			{
				t = t->ch[0];
			}
			else
			{
				t = t->ch[1];
			}
		}
		while (t->ch[0] - nn || t->ch[1] - nn)
		{
			if (t->ch[0] && (t->ch[1] == nn || t->ch[0]->key2 > t->ch[1]->key2))
			{
				t->ch[0]->rot(rt);
			}
			else
			{
				t->ch[1]->rot(rt);
			}
		}
		t->f->ch[t->f->ch[1] == t] = nn;
		t = t->f;
		while (t - nn)
		{
			t->num--, t = t->f;
		}
	}
	int get()
	{
		int ans = 0;
		node *t = rt;
		while (t->ch[1] - nn)
		{
			t = t->ch[1];
		}
		return t->key;
	}
	int getk(int k)
	{
		node *t = rt;
		while (1)
		{
			if (t->ch[0]->num + 1 == k)
			{
				return t->key;
			}
			if (t->ch[0]->num >= k)
			{
				t = t->ch[0];
			}
			else
			{
				k -= t->ch[0]->num + 1, t = t->ch[1];
			}
		}
	}
} tree[maxn], now;

int M[maxn], siz[maxn], tot;

void del(int c, int k)
{
	if (siz[c] == 1)
	{
		siz[c] = 0;
		tree[c].del(k);
		now.del(M[c]);
		M[c] = -1;
		tot--;
	}
	else
	{
		siz[c]--;
		now.del(M[c]);
		tree[c].del(k);
		now.ins(M[c] = tree[c].get());
	}
}
void ins(int c, int k)
{
	if (siz[c] == 0)
	{
		siz[c] = 1;
		tot++;
		tree[c].ins(k);
		now.ins(M[c] = tree[c].get());
	}
	else
	{
		siz[c]++;
		now.del(M[c]);
		tree[c].ins(k);
		now.ins(M[c] = tree[c].get());
	}
}
int query(int L)
{
	if (tot < L)
	{
		return 0;
	}
	return now.getk(tot - L + 1);
}
struct NN
{
	int l, r, h, c;
} mm[maxn];

int arr[maxn], cnt;
vector<pair<int, int>> V1[maxn];
vector<pair<int, int>> V2[maxn];

int main()
{
	int t, ii = 0;
	int N, n, L, i, j, k;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &N, &n, &L);
		for (i = 1; i <= n; i++)
		{
			scanf("%d%d%d%d", &mm[i].h, &mm[i].l, &mm[i].r, &mm[i].c);
		}
		for (i = 1; i <= n; i++)
		{
			arr[i] = mm[i].l, arr[i + n] = ++mm[i].r;
		}
		sort(arr + 1, arr + 1 + n + n);
		int m = unique(arr + 1, arr + 1 + n + n) - arr - 1;
		for (i = 1; i <= m; i++)
		{
			V1[i].clear(), V2[i].clear();
		}
		for (i = 1; i <= n; i++)
		{
			mm[i].l = lower_bound(arr + 1, arr + 1 + m, mm[i].l) - arr;
			mm[i].r = lower_bound(arr + 1, arr + 1 + m, mm[i].r) - arr;
			V1[mm[i].l].push_back(make_pair(mm[i].h, mm[i].c));
			V2[mm[i].r].push_back(make_pair(mm[i].h, mm[i].c));
		}
		now.rt = nn;
		for (i = 1; i <= 100000; i++)
		{
			siz[i] = 0, tree[i].rt = nn;
		}
		tot = 0, cnttree = 0;
		printf("Case %d: ", ++ii);
		long long ans = 0;
		if (L == 0)
		{
			ans = N;
			ans *= N;
			printf("%lld\n", ans);
			continue;
		}
		for (i = 1; i < m; i++)
		{
			for (j = 0; j < V2[i].size(); j++)
			{
				del(V2[i][j].second, V2[i][j].first);
			}
			for (j = 0; j < V1[i].size(); j++)
			{
				ins(V1[i][j].second, V1[i][j].first);
			}
			ans += query(L) * (arr[i + 1] - arr[i] + 0ll);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
