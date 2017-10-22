#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

typedef int Node;
struct RBST
{
	Node v;
	RBST *l;
	RBST *r;
	int size;
	RBST() : l(NULL), r(NULL), size(0)
	{
		;
	}
	RBST(Node v) : v(v), l(NULL), r(NULL), size(1)
	{
		;
	}
	RBST *Update()
	{
		size = 1 + (l ? l->size : 0) + (r ? r->size : 0);
		return this;
	}
};
RBST _pool[1000000];
RBST *pool = NULL;

int Count(RBST *t)
{
	return t ? t->size : 0;
}

RBST *Merge(RBST *l, RBST *r)
{
	if (!l)
	{
		return r;
	}
	if (!r)
	{
		return l;
	}
	if (rand() % (Count(l) + Count(r)) < Count(l))
	{
		l->r = Merge(l->r, r);
		return l->Update();
	}
	else
	{
		r->l = Merge(l, r->l);
		return r->Update();
	}
	assert(false);
	return NULL;
}

// [0, k), [k, n)
pair<RBST *, RBST *> Split(RBST *t, int k)
{
	if (t == NULL)
	{
		return pair<RBST *, RBST *>(NULL, NULL);
	}
	if (k <= Count(t->l))
	{
		pair<RBST *, RBST *> s = Split(t->l, k);
		t->l = s.second;
		return make_pair(s.first, t->Update());
	}
	else
	{
		pair<RBST *, RBST *> s = Split(t->r, k - Count(t->l) - 1);
		t->r = s.first;
		return make_pair(t->Update(), s.second);
	}
}

RBST *Insert(RBST *t, int k, Node v)
{
	pair<RBST *, RBST *> s = Split(t, k);
	RBST *val = pool++;
	*val = RBST(v);
	return Merge(s.first, Merge(val, s.second));
}

RBST *Erase(RBST *t, int k)
{
	pair<RBST *, RBST *> s1 = Split(t, k);
	pair<RBST *, RBST *> s2 = Split(s1.first, k - 1);
	return Merge(s2.first, s1.second);
}

RBST *At(RBST *t, int index)
{
	assert(t != NULL);
	if (index < Count(t->l))
	{
		return At(t->l, index);
	}
	else
	{
		index -= Count(t->l);
	}
	if (index == 0)
	{
		return t;
	}
	index--;
	return At(t->r, index);
}

int n, m;
int main()
{
	while (scanf("%d %d", &n, &m) > 0)
	{
		RBST *tree = NULL;
		RBST *rev = NULL;
		pool = _pool;
		REP(i, n)
		{
			tree = Insert(tree, i, i + 1);
			rev = Insert(rev, i, n - i);
		}
		REP(i, m)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			a--;
			pair<RBST *, RBST *> temp;
			temp = Split(tree, b);
			RBST *right = temp.second;
			temp = Split(temp.first, a);
			RBST *mid = temp.second;
			RBST *left = temp.first;
			temp = Split(rev, n - a);
			RBST *rright = temp.second;
			temp = Split(temp.first, n - b);
			RBST *rmid = temp.second;
			RBST *rleft = temp.first;
			tree = Merge(left, Merge(right, rmid));
			rev = Merge(mid, Merge(rleft, rright));
		}
		REP(i, n)
		{
			printf("%d\n", At(tree, i)->v);
		}
	}
}
