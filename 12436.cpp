#include <bits/stdc++.h>

using namespace std;

const int N = 250005;
typedef long long LL;
struct node
{
	bool flag;
	int left, right;
	LL sum, add1, add2, valu, step;
	LL mid()
	{
		return left + (right - left) / 2;
	}
	LL len()
	{
		return right - left + 1;
	}
	void changeAB(LL a, LL b, LL k)
	{
		add1 += a;
		add2 += b;
		step += k;
		sum += (a + b) * len() / 2;
	}
	void changeC(LL a)
	{
		flag = 1;
		valu = a;
		add1 = 0;
		add2 = 0;
		step = 0;
		sum = valu * len();
	}
};
struct Segtree
{
	node tree[N * 4];
	void down(int ind)
	{
		if (tree[ind].flag)
		{
			tree[ind * 2].changeC(tree[ind].valu);
			tree[ind * 2 + 1].changeC(tree[ind].valu);
			tree[ind].flag = 0;
		}
		if (tree[ind].add1 || tree[ind].add2 || tree[ind].step)
		{
			LL add1 = tree[ind].add1, add2 = tree[ind].add2;
			LL k = tree[ind].step;
			LL mid = add1 + k * (tree[ind * 2].len() - 1);
			tree[ind * 2].changeAB(add1, mid, k);
			tree[ind * 2 + 1].changeAB(mid + k, add2, k);
			tree[ind].add1 = 0;
			tree[ind].add2 = 0;
			tree[ind].step = 0;
		}
	}
	void build(LL left, LL right, LL ind)
	{
		tree[ind].left = left;
		tree[ind].right = right;
		tree[ind].add1 = 0;
		tree[ind].add2 = 0;
		tree[ind].sum = 0;
		tree[ind].valu = 0;
		tree[ind].step = 0;
		if (left != right)
		{
			LL mid = tree[ind].mid();
			build(left, mid, ind * 2);
			build(mid + 1, right, ind * 2 + 1);
		}
	}
	void updataAB(LL be, LL end, LL ind, LL step)
	{
		LL left = tree[ind].left, right = tree[ind].right;
		if (be <= left && right <= end)
		{
			LL st, ed;
			if (step >= 0)
			{
				st = left - be + 1;
				ed = right - be + 1;
			}
			else
			{
				st = end - left + 1;
				ed = end - right + 1;
			}
			tree[ind].changeAB(st, ed, step);
		}
		else
		{
			down(ind);
			LL mid = tree[ind].mid();
			if (be <= mid)
			{
				updataAB(be, end, ind * 2, step);
			}
			if (end > mid)
			{
				updataAB(be, end, ind * 2 + 1, step);
			}
			tree[ind].sum = tree[ind * 2].sum + tree[ind * 2 + 1].sum;
		}
	}
	void updataC(LL be, LL end, LL ind, LL valu)
	{
		LL left = tree[ind].left, right = tree[ind].right;
		if (be <= left && right <= end)
		{
			tree[ind].changeC(valu);
		}
		else
		{
			down(ind);
			LL mid = tree[ind].mid();
			if (be <= mid)
			{
				updataC(be, end, ind * 2, valu);
			}
			if (end > mid)
			{
				updataC(be, end, ind * 2 + 1, valu);
			}
			tree[ind].sum = tree[ind * 2].sum + tree[ind * 2 + 1].sum;
		}
	}
	LL query(LL be, LL end, LL ind)
	{
		LL left = tree[ind].left, right = tree[ind].right;
		if (be <= left && right <= end)
		{
			return tree[ind].sum;
		}
		else
		{
			down(ind);
			LL mid = tree[ind].mid();
			LL sum1 = 0, sum2 = 0;
			if (be <= mid)
			{
				sum1 = query(be, end, ind * 2);
			}
			if (end > mid)
			{
				sum2 = query(be, end, ind * 2 + 1);
			}
			return sum1 + sum2;
		}
	}
} seg;
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		seg.build(1, N - 5, 1);
		for (int i = 0; i < n; i++)
		{
			char str[10];
			LL a, b, c;
			scanf("%s", str);
			if (str[0] == 'A')
			{
				scanf("%lld%lld", &a, &b);
				seg.updataAB(a, b, 1, 1);
			}
			else if (str[0] == 'B')
			{
				scanf("%lld%lld", &a, &b);
				seg.updataAB(a, b, 1, -1);
			}
			else if (str[0] == 'C')
			{
				scanf("%lld%lld%lld", &a, &b, &c);
				seg.updataC(a, b, 1, c);
			}
			else
			{
				scanf("%lld%lld", &a, &b);
				printf("%lld\n", seg.query(a, b, 1));
			}
		}
	}
	return 0;
}
