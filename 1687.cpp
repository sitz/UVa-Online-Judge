#include <bits/stdc++.h>

using namespace std;

#define MAXN 1024
#define MAXM 32767
#define INF 1LL << 60

struct Node
{
	Node *l, *r;
	vector<pair<long long, long long> > v;
	int kind;
	Node(Node *a = NULL, Node *b = NULL, int k = 0)
	{
		l = a;
		r = b;
		kind = k;
		v.clear();
	}
} nodes[MAXM];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second != b.second)
	{
		return a.second < b.second;
	}
	return a.first < b.first;
}

void dfs(Node *u)
{
	if (u->l == NULL && u->r == NULL)
	{
		return;
	}
	dfs(u->l);
	dfs(u->r);
	Node *lson = u->l, *rson = u->r;
	long long w, h, rmin = INF, lmin = INF;
	if (u->kind)
	{
		sort(lson->v.begin(), lson->v.end());
		sort(rson->v.begin(), rson->v.end());
		for (int i = 0, j = 0; i < lson->v.size(); i++)
		{
			while (j < rson->v.size() && rson->v[j].first <= lson->v[i].first)
			{
				rmin = min(rmin, rson->v[j].second);
				j++;
			}
			if (rmin == INF)
			{
				continue;
			}
			w = lson->v[i].first;
			h = lson->v[i].second + rmin;
			u->v.push_back(make_pair(w, h));
		}
		for (int i = 0, j = 0; i < rson->v.size(); i++)
		{
			while (j < lson->v.size() && lson->v[j].first <= rson->v[i].first)
			{
				lmin = min(lmin, lson->v[j].second);
				j++;
			}
			if (lmin == INF)
			{
				continue;
			}
			w = rson->v[i].first;
			h = rson->v[i].second + lmin;
			u->v.push_back(make_pair(w, h));
		}
	}
	else
	{
		sort(lson->v.begin(), lson->v.end(), cmp);
		sort(rson->v.begin(), rson->v.end(), cmp);
		for (int i = 0, j = 0; i < lson->v.size(); i++)
		{
			while (j < rson->v.size() && rson->v[j].second <= lson->v[i].second)
			{
				rmin = min(rmin, rson->v[j].first);
				j++;
			}
			if (rmin == INF)
			{
				continue;
			}
			w = lson->v[i].first + rmin;
			h = lson->v[i].second;
			u->v.push_back(make_pair(w, h));
		}
		for (int i = 0, j = 0; i < rson->v.size(); i++)
		{
			while (j < lson->v.size() && lson->v[j].second <= rson->v[i].second)
			{
				lmin = min(lmin, lson->v[j].first);
				j++;
			}
			if (lmin == INF)
			{
				continue;
			}
			w = rson->v[i].first + lmin;
			h = rson->v[i].second;
			u->v.push_back(make_pair(w, h));
		}
	}
	sort(u->v.begin(), u->v.end());
	u->v.resize(unique(u->v.begin(), u->v.end()) - u->v.begin());
}

int main()
{
	char s[MAXN];
	int T, n, H[MAXN], W[MAXN], x;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &H[i], &W[i]);
		}
		stack<Node *> stk;
		Node *p, *a, *b, *root;
		int size = 0;
		for (int i = 1; i < 2 * n; i++)
		{
			scanf("%s", s);
			if (s[0] == 'V' || s[0] == 'H')
			{
				p = &nodes[size++];
				b = stk.top(), stk.pop();
				a = stk.top(), stk.pop();
				*p = Node(a, b, s[0] == 'V');
				stk.push(p);
			}
			else
			{
				sscanf(s, "%d", &x);
				p = &nodes[size++];
				*p = Node(NULL, NULL);
				p->v.push_back(make_pair(H[x], W[x]));
				p->v.push_back(make_pair(W[x], H[x]));
				stk.push(p);
			}
		}
		root = stk.top();
		dfs(root);
		long long ret = INF;
		for (int i = 0; i < root->v.size(); i++)
		{
			ret = min(ret, (long long)root->v[i].first * root->v[i].second);
		}
		printf("%lld\n", ret);
	}
	return 0;
}
