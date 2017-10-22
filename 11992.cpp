#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const double eps = 1e-6;
const double offset = 2000;
const double PI = acos(-1.0);
const int MAXN = 1000005;
const int MAXM = 1 << 20;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000009;

struct TREE
{
	int left, right;
	int sum, minval, maxval;
	int add, set;
} tree[MAXN << 2];

int n, m, q;

void update(int p)
{
	tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
	tree[p].maxval = max(tree[p << 1].maxval, tree[p << 1 | 1].maxval);
	tree[p].minval = min(tree[p << 1].minval, tree[p << 1 | 1].minval);
}

void down(int p)
{
	if (tree[p].set != INF)
	{
		tree[p << 1].set = tree[p << 1 | 1].set = tree[p].set;
		tree[p << 1].add = tree[p << 1 | 1].add = 0;
		tree[p << 1].sum = (tree[p << 1].right - tree[p << 1].left + 1) * tree[p].set;
		tree[p << 1 | 1].sum = (tree[p << 1 | 1].right - tree[p << 1 | 1].left + 1) * tree[p].set;
		tree[p << 1].minval = tree[p << 1 | 1].minval = tree[p << 1].maxval = tree[p << 1 | 1].maxval = tree[p].set;
		tree[p].set = INF;
	}
	if (tree[p].add != 0)
	{
		tree[p << 1].add += tree[p].add;
		tree[p << 1 | 1].add += tree[p].add;
		tree[p << 1].sum += tree[p].add * (tree[p << 1].right - tree[p << 1].left + 1);
		tree[p << 1 | 1].sum += tree[p].add * (tree[p << 1 | 1].right - tree[p << 1 | 1].left + 1);
		tree[p << 1].minval += tree[p].add;
		tree[p << 1].maxval += tree[p].add;
		tree[p << 1 | 1].minval += tree[p].add;
		tree[p << 1 | 1].maxval += tree[p].add;
		tree[p].add = 0;
	}
}

void build(int p, int left, int right)
{
	tree[p].left = left;
	tree[p].right = right;
	tree[p].add = 0;
	tree[p].set = INF;
	tree[p].sum = tree[p].minval = tree[p].maxval = 0;
	if (left == right)
	{
		return;
	}
	int mid = (left + right) >> 1;
	build(p << 1, left, mid);
	build(p << 1 | 1, mid + 1, right);
}

void add(int p, int left, int right, int val)
{
	if (tree[p].left == left && tree[p].right == right)
	{
		tree[p].add += val;
		tree[p].sum += val * (right - left + 1);
		tree[p].minval += val;
		tree[p].maxval += val;
		return;
	}
	down(p);
	int mid = (tree[p].left + tree[p].right) >> 1;
	if (left > mid)
	{
		add(p << 1 | 1, left, right, val);
	}
	else if (right <= mid)
	{
		add(p << 1, left, right, val);
	}
	else
	{
		add(p << 1, left, mid, val);
		add(p << 1 | 1, mid + 1, right, val);
	}
	update(p);
}

void set_(int p, int left, int right, int val)
{
	if (tree[p].left == left && tree[p].right == right)
	{
		tree[p].add = 0;
		tree[p].set = val;
		tree[p].sum = val * (right - left + 1);
		tree[p].minval = val;
		tree[p].maxval = val;
		return;
	}
	down(p);
	int mid = (tree[p].left + tree[p].right) >> 1;
	if (left > mid)
	{
		set_(p << 1 | 1, left, right, val);
	}
	else if (right <= mid)
	{
		set_(p << 1, left, right, val);
	}
	else
	{
		set_(p << 1, left, mid, val);
		set_(p << 1 | 1, mid + 1, right, val);
	}
	update(p);
}

int Sum(int p, int left, int right)
{
	if (tree[p].left == left && tree[p].right == right)
	{
		return tree[p].sum;
	}
	down(p);
	int mid = (tree[p].left + tree[p].right) >> 1;
	if (right <= mid)
	{
		return Sum(p << 1, left, right);
	}
	else if (left > mid)
	{
		return Sum(p << 1 | 1, left, right);
	}
	else
	{
		return Sum(p << 1, left, mid) + Sum(p << 1 | 1, mid + 1, right);
	}
}

int min(int p, int left, int right)
{
	if (tree[p].left == left && tree[p].right == right)
	{
		return tree[p].minval;
	}
	down(p);
	int mid = (tree[p].left + tree[p].right) >> 1;
	if (right <= mid)
	{
		return min(p << 1, left, right);
	}
	else if (left > mid)
	{
		return min(p << 1 | 1, left, right);
	}
	else
	{
		return min(min(p << 1, left, mid), min(p << 1 | 1, mid + 1, right));
	}
}

int max(int p, int left, int right)
{
	if (tree[p].left == left && tree[p].right == right)
	{
		return tree[p].maxval;
	}
	down(p);
	int mid = (tree[p].left + tree[p].right) >> 1;
	if (right <= mid)
	{
		return max(p << 1, left, right);
	}
	else if (left > mid)
	{
		return max(p << 1 | 1, left, right);
	}
	else
	{
		return max(max(p << 1, left, mid), max(p << 1 | 1, mid + 1, right));
	}
}

void solved(int cas)
{
	//scanf ("%d %d", &n, &m);
	int len = n * m;
	build(1, 1, len);
	int x1, y1, x2, y2, op, val;
	while (q--)
	{
		scanf("%d %d %d %d %d", &op, &x1, &y1, &x2, &y2);
		x1--, y1--, x2--, y2--;
		if (op != 3)
		{
			scanf("%d", &val);
		}
		if (op == 1)
		{
			for (int i = x1; i <= x2; i++)
			{
				add(1, i * m + y1 + 1, i * m + y2 + 1, val);
			}
		}
		else if (op == 2)
		{
			for (int i = x1; i <= x2; i++)
			{
				set_(1, i * m + y1 + 1, i * m + y2 + 1, val);
			}
		}
		else
		{
			int sum = 0, minval = INF, maxval = -INF;
			for (int i = x1; i <= x2; i++)
			{
				sum += Sum(1, i * m + y1 + 1, i * m + y2 + 1);
				minval = min(minval, min(1, i * m + y1 + 1, i * m + y2 + 1));
				maxval = max(maxval, max(1, i * m + y1 + 1, i * m + y2 + 1));
			}
			printf("%d %d %d\n", sum, minval, maxval);
		}
	}
}

int main()
{
	int cas = 1;
	while (scanf("%d %d %d", &n, &m, &q) != EOF)
	{
		solved(cas++);
	}
	return 0;
	int T = 1;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		solved(i);
	}
	return 0;
}
