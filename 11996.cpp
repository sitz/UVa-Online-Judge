#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

struct SPLAY
{
	static const int MaxN = 400050;
	static const LL A = 3;
	struct Node
	{
		int sz, ch, rev;
		LL hash[2];
		Node *fa, *c[2];
	} buf[MaxN], *N, *nil, *root;
	LL h[MaxN];
	int n;
	char s[MaxN];

	Node *NewNode(int k, Node *fa)
	{
		Node *x = ++N;
		x->c[0] = x->c[1] = nil;
		x->fa = fa;
		x->ch = k;
		x->sz = 1;
		x->rev = 0;
		return x;
	}
	void Up(Node *x)
	{
		x->sz = x->c[0]->sz + 1 + x->c[1]->sz;
		x->hash[0] = x->c[0]->hash[0] * h[x->c[1]->sz + 1] + x->ch * h[x->c[1]->sz] + x->c[1]->hash[0];
		x->hash[1] = x->c[1]->hash[1] * h[x->c[0]->sz + 1] + x->ch * h[x->c[0]->sz] + x->c[0]->hash[1];
	}
	void Rev(Node *x)
	{
		if (x == nil)
		{
			return;
		}
		x->rev ^= 1;
		swap(x->c[0], x->c[1]);
		swap(x->hash[0], x->hash[1]);
	}
	void Down(Node *x)
	{
		if (x->rev)
		{
			Rev(x->c[0]), Rev(x->c[1]), x->rev = 0;
		}
	}
	Node *build(Node *fa, int L, int R)
	{
		if (L > R)
		{
			return nil;
		}
		int mid = (L + R) / 2;
		Node *x = NewNode(s[mid] - '0', fa);
		x->c[0] = build(x, L, mid - 1);
		x->c[1] = build(x, mid + 1, R);
		Up(x);
		return x;
	}
	void init()
	{
		N = nil = buf;
		nil->sz = nil->ch = nil->rev = 0;
		nil->hash[0] = nil->hash[1] = 0;
		nil->fa = nil->c[0] = nil->c[1] = nil;
		h[0] = 1;
		for (int i = 1; i < MaxN; i++)
		{
			h[i] = h[i - 1] * A;
		}
		scanf("%s", s + 1);
		s[0] = '0';
		s[n + 1] = '0';
		n += 2;
		root = build(nil, 0, n - 1);
	}

	void Rotate(Node *x, int f)
	{
		Node *y = x->fa;
		Down(y);
		Down(x);
		y->c[f ^ 1] = x->c[f];
		if (x->c[f] != nil)
		{
			x->c[f]->fa = y;
		}
		x->fa = y->fa;
		if (y->fa != nil)
		{
			if (y->fa->c[0] == y)
			{
				y->fa->c[0] = x;
			}
			else
			{
				y->fa->c[1] = x;
			}
		}
		y->fa = x;
		x->c[f] = y;
		Up(y);
	}
	void Splay(Node *x, Node *f)
	{
		for (Down(x); x->fa != f;)
		{
			if (x->fa->fa == f)
			{
				if (x->fa->c[0] == x)
				{
					Rotate(x, 1);
				}
				else
				{
					Rotate(x, 0);
				}
			}
			else
			{
				Node *y = x->fa, *z = y->fa;
				if (z->c[0] == y)
				{
					if (y->c[0] == x)
					{
						Rotate(y, 1), Rotate(x, 1);
					}
					else
					{
						Rotate(x, 0), Rotate(x, 1);
					}
				}
				else
				{
					if (y->c[1] == x)
					{
						Rotate(y, 0), Rotate(x, 0);
					}
					else
					{
						Rotate(x, 1), Rotate(x, 0);
					}
				}
			}
		}
		Up(x);
		if (f == nil)
		{
			root = x;
		}
	}

	void Select(int k, Node *f)
	{
		Node *x = root;
		while (x != nil)
		{
			Down(x);
			int tmp = x->c[0]->sz + 1;
			if (k == tmp)
			{
				break;
			}
			else if (k > tmp)
			{
				k -= tmp, x = x->c[1];
			}
			else
			{
				x = x->c[0];
			}
		}
		Splay(x, f);
	}
	void Insert(int p, int c)
	{
		p++;
		n++;
		Select(p, nil);
		Select(p + 1, root);
		root->c[1]->c[0] = NewNode(c, root->c[1]);
		Splay(root->c[1]->c[0], nil);
	}
	void Delete(int p)
	{
		p++;
		n--;
		Select(p - 1, nil);
		Select(p + 1, root);
		root->c[1]->c[0] = nil;
		Splay(root->c[1], nil);
	}
	void Reverse(int L, int R)
	{
		L++;
		R++;
		Select(L - 1, nil);
		Select(R + 1, root);
		Rev(root->c[1]->c[0]);
		Splay(root->c[1], nil);
	}
	LL Hash(int L, int R)
	{
		Select(L - 1, nil);
		Select(R + 1, root);
		return root->c[1]->c[0]->hash[0];
	}
	bool check(int p1, int p2, int L)
	{
		LL x1 = Hash(p1, p1 + L - 1);
		LL x2 = Hash(p2, p2 + L - 1);
		//		printf("%d %d %d %I64u %I64u %d\n",p1,p2,L,x1,x2,n);
		return x1 == x2;
	}
	int LCP(int p1, int p2)
	{
		p1++;
		p2++;
		int lo = 0, hi = min(n - p1, n - p2) + 1;
		while (lo + 1 < hi)
		{
			int mid = (lo + hi) / 2;
			if (check(p1, p2, mid))
			{
				lo = mid;
			}
			else
			{
				hi = mid;
			}
		}
		return lo;
	}
	int ax[MaxN], m;
	void dfs(Node *x)
	{
		if (x == nil)
		{
			return;
		}
		Down(x);
		dfs(x->c[0]);
		ax[m++] = x->ch;
		dfs(x->c[1]);
	}
	void Print()
	{
		m = 0;
		dfs(root);
		for (int i = 0; i < m; i++)
		{
			printf("%d", ax[i]);
		}
		puts("");
	}
} splay;

int main()
{
	int m;
	while (scanf("%d%d", &splay.n, &m) == 2)
	{
		splay.init();
		for (int i = 0; i < m; i++)
		{
			int t, x, y;
			scanf("%d", &t);
			if (t == 1)
			{
				scanf("%d%d", &x, &y);
				splay.Insert(x, y);
			}
			else if (t == 2)
			{
				scanf("%d", &x);
				splay.Delete(x);
			}
			else if (t == 3)
			{
				scanf("%d%d", &x, &y);
				splay.Reverse(x, y);
			}
			else
			{
				scanf("%d%d", &x, &y);
				printf("%d\n", splay.LCP(x, y));
			}
			//			splay.Print();
		}
	}
	return 0;
}
