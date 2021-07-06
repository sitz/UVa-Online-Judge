#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define keyTree (ch[ch[root][1]][0])
const int maxn = 2100005;
struct splaytree
{
	int size[maxn];
	int ch[maxn][2];
	int pre[maxn];
	int root, top1;

	void Rotate(int x, int f)
	{
		int y = pre[x];
		pushdown(y);
		pushdown(x);
		ch[y][!f] = ch[x][f];
		pre[ch[x][f]] = y;
		pre[x] = pre[y];
		if (pre[x])
		{
			ch[pre[y]][ch[pre[y]][1] == y] = x;
		}
		ch[x][f] = y;
		pre[y] = x;
		pushup(y);
	}
	void splay(int x, int goal)
	{
		pushdown(x);
		while (pre[x] != goal)
		{
			if (pre[pre[x]] == goal)
			{
				Rotate(x, ch[pre[x]][0] == x);
			}
			else
			{
				int y = pre[x], z = pre[y];
				int f = (ch[z][0] == y);
				if (ch[y][f] == x)
				{
					Rotate(x, !f), Rotate(x, f);
				}
				else
				{
					Rotate(y, f), Rotate(x, f);
				}
			}
		}
		pushup(x);
		if (goal == 0)
		{
			root = x;
		}
	}
	void RotateTo(int k, int goal)
	{
		int x = root;
		pushdown(x);
		while (size[ch[x][0]] != k)
		{
			if (k < size[ch[x][0]])
			{
				x = ch[x][0];
			}
			else
			{
				k -= (size[ch[x][0]] + 1);
				x = ch[x][1];
			}
			pushdown(x);
		}
		splay(x, goal);
	}
	void maketree(int &x, int l, int r, int f)
	{
		if (l > r)
		{
			return;
		}
		int m = (l + r) / 2;
		NewNode(x, num[m]);
		maketree(ch[x][0], l, m - 1, x);
		maketree(ch[x][1], m + 1, r, x);
		pushup(x);
		pre[x] = f;
	}

	void NewNode(int &x, int c)
	{
		x = top1++;
		ch[x][0] = ch[x][1] = pre[x] = 0;
		size[x] = 1;
		val[x] = c;
		sum[x] = c;
	}

	void pushdown(int x)
	{
	}
	void pushup(int x)
	{
		size[x] = 1 + size[ch[x][0]] + size[ch[x][1]];
		sum[x] = val[x] + sum[ch[x][0]] + sum[ch[x][1]];
	}

	void init()
	{
		ch[0][0] = ch[0][1] = pre[0] = size[0] = 0;
		sum[0] = 0;
		top1 = 1;
		NewNode(root, 0);
		NewNode(ch[root][1], 0);
		pre[ch[root][1]] = root;
		size[root] = 2;
	}

	void insert()
	{
		int pos;
		scanf("%d", &pos);
		LL n, r, m, a, c;
		scanf("%lld%lld%lld%lld%lld", &n, &r, &m, &a, &c);
		for (int i = 0; i < r; i++)
		{
			scanf("%lld", &num[i]);
		}
		for (int i = r; i < n; i++)
		{
			num[i] = (num[i - r] * a + c) % m;
			c = ((num[i - r] * a + c) / m) % m;
		}
		RotateTo(pos, 0);
		RotateTo(pos + 1, root);
		maketree(keyTree, 0, n - 1, ch[root][1]);
		pushup(ch[root][1]);
		pushup(root);
	}

	void query()
	{
		int l, r;
		scanf("%d%d", &l, &r);
		RotateTo(l, 0);
		RotateTo(r + 2, root);
		printf("%lld\n", sum[keyTree]);
	}

	void del()
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l++;
		r++;
		RotateTo(l - 1, 0);
		RotateTo(r + 1, root);
		keyTree = 0;
		pushup(ch[root][1]);
		pushup(root);
	}
	LL num[maxn];
	LL sum[maxn];
	LL val[maxn];
} spt;

int main()
{
	int C;
	int cas = 1;
	while (scanf("%d", &C) != EOF && C)
	{
		printf("Scenario %d:\n", cas++);
		spt.init();
		for (int i = 1; i <= C; i++)
		{
			char str[25];
			scanf("%s", str);
			if (str[0] == 'i')
			{
				spt.insert();
			}
			else if (str[0] == 'd')
			{
				spt.del();
			}
			else if (str[0] == 's')
			{
				spt.query();
			}
		}
		puts("");
	}
	return 0;
}
