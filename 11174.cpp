#include <bits/stdc++.h>

using namespace std;

typedef long long int INT64;

const int MOD = 1000000007;

int n, m;
INT64 f[40001], b[40001];

INT64 extgcd(INT64 a, INT64 b, INT64 &x, INT64 &y)
{
	// ax + by = d
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		// b * x' + (a % b) * y' = d
		// b * x' + [a - (a / b) * b] * y' = d
		// a * y' + b * [x' - (a / b) * y' ] = d
		// a * x  + b * y = d
		INT64 tx, ty, d;
		d = extgcd(b, a % b, tx, ty);
		x = ty;
		y = tx - (a / b) * ty;
		return d;
	}
}
void init()
{
	INT64 inv, tmp;
	f[0] = 1;
	f[1] = b[1] = 1;
	for (int i = 2; i <= 40000; i++)
	{
		extgcd(i, MOD, inv, tmp);
		while (inv < 0)
		{
			inv += MOD;
		}
		inv %= MOD;
		f[i] = (f[i - 1] * i) % MOD;
		b[i] = (b[i - 1] * inv) % MOD;
	}
}
struct Node
{
	int childs;
	int count;
	INT64 value;
	Node *father;
	Node *son;
	Node *next;
} Nodes[40001];
void AddSon(int f, int s)
{
	Nodes[s].father = &Nodes[f];
	Nodes[s].next = Nodes[f].son;
	Nodes[f].son = &Nodes[s];
	Nodes[f].childs++;
}
void CulNode(Node *root)
{
	root->count = 0;
	root->value = 1;
	for (Node *p = root->son; p; p = p->next)
	{
		CulNode(p);
		root->count += p->count + 1;
		root->value = (root->value * p->value) % MOD;
		root->value = (root->value * b[p->count + 1]) % MOD;
	}
	root->value = (root->value * f[root->count]) % MOD;
}

int main()
{
	init();
	int t, f, s;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i <= n; i++)
		{
			Nodes[i].childs = 0;
			Nodes[i].father = Nodes[i].son = Nodes[i].next = NULL;
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &s, &f);
			AddSon(f, s);
		}
		for (int i = 1; i <= n; i++)
		{
			if (Nodes[i].father == NULL)
			{
				AddSon(0, i);
			}
		}
		CulNode(&Nodes[0]);
		printf("%lld\n", Nodes[0].value);
	}
}
