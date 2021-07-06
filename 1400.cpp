#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const double eps = 1e-6;
const double offset = 2000;
const double PI = acos(-1.0);
const int MAXN = 500005;
const int MAXM = 1 << 20;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1000000009;

int a[MAXN];
LL sum[MAXN];
int n, m;

struct NODE
{
	int left, right;
	LL val;
	NODE()
	{
		left = right = val = -1;
	}
	NODE(int _left, int _right) : left(_left), right(_right)
	{
		val = sum[_right] - sum[_left - 1];
	}
	bool operator<(const NODE &o) const
	{
		if (val == o.val)
		{
			if (left == o.left)
			{
				return right > o.right;
			}
			return left > o.left;
		}
		return val < o.val;
	}
};

struct TREE
{
	int left, right;
	NODE l, r, m;
} tree[MAXN << 2];

void build(int p, int left, int right)
{
	tree[p].left = left;
	tree[p].right = right;
	if (left == right)
	{
		tree[p].m = tree[p].l = tree[p].r = NODE(left, right);
		return;
	}
	int mid = (left + right) >> 1;
	build(p << 1, left, mid);
	build(p << 1 | 1, mid + 1, right);
	tree[p].m = max(tree[p << 1].m, tree[p << 1 | 1].m);
	tree[p].m = max(tree[p].m, NODE(tree[p << 1].r.left, tree[p << 1 | 1].l.right));
	tree[p].l = max(tree[p << 1].l, NODE(tree[p << 1].left, tree[p << 1 | 1].l.right));
	tree[p].r = max(tree[p << 1 | 1].r, NODE(tree[p << 1].r.left, tree[p << 1 | 1].right));
}

NODE cal(int p, int left, int right, NODE &l, NODE &r)
{
	if (left == tree[p].left && right == tree[p].right)
	{
		l = tree[p].l;
		r = tree[p].r;
		return tree[p].m;
	}
	int mid = (tree[p].left + tree[p].right) >> 1;
	NODE ret;
	ret.val = -INF;
	NODE ll, lr, rl, rr;
	if (right <= mid)
	{
		ret = max(ret, cal(p << 1, left, right, ll, lr));
		if (left <= tree[p].left)
		{
			l = ll;
		}
	}
	else if (left > mid)
	{
		ret = max(ret, cal(p << 1 | 1, left, right, rl, rr));
		if (right >= tree[p].right)
		{
			r = rr;
		}
	}
	else
	{
		ret = max(ret, cal(p << 1, left, mid, ll, lr));
		ret = max(ret, cal(p << 1 | 1, mid + 1, right, rl, rr));
		if (rl.right != -1 && lr.left != -1)
		{
			ret = max(ret, NODE(lr.left, rl.right));
		}
		if (left <= tree[p].left)
		{
			l = max(ll, NODE(tree[p].left, rl.right));
		}
		if (right >= tree[p].right)
		{
			r = max(rr, NODE(lr.left, tree[p].right));
		}
	}
	return ret;
}

void solved(int cas)
{
	//scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	build(1, 1, n);
	printf("Case %d:\n", cas);
	int x, y;
	while (m--)
	{
		scanf("%d %d", &x, &y);
		NODE l, r;
		NODE ans = cal(1, x, y, l, r);
		printf("%d %d\n", ans.left, ans.right);
	}
}

int main()
{
	int cas = 1;
	while (scanf("%d %d", &n, &m) != EOF)
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
