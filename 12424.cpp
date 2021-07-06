#include <bits/stdc++.h>

using namespace std;

#define MAXN 100001
struct node
{
	int num;
	node *next;
};
struct number
{
	int left, right;
	bool mark;
	int sum[11];
};
int ans[11];
int father[MAXN];
int Log[2 * MAXN];
int n, m, T;
int d[MAXN];
int euler[2 * MAXN];
int low[MAXN], high[MAXN];
int color[MAXN][11];
int c[MAXN];
number tree[4 * MAXN];
node *graph[MAXN];
node memo[2 * MAXN];
int home[MAXN];
int sparse_table[2 * MAXN][20];
int sparse_table_num[2 * MAXN][20];
int top, label;
void LOG()
{
	Log[1] = 0;
	for (int i = 2; i < 2 * MAXN; i++)
	{
		Log[i] = Log[i / 2] + 1;
	}
}
void add(int x, int y)
{
	node *p = &memo[top++];
	p->num = y;
	p->next = graph[x];
	graph[x] = p;
	p = &memo[top++];
	p->num = x;
	p->next = graph[y];
	graph[y] = p;
}
void dfs(int i)
{
	low[i] = ++label;
	for (int j = 1; j <= 10; j++)
	{
		color[low[i]][j] += color[low[father[i]]][j];
	}
	color[low[i]][c[i]]++;
	euler[++top] = i;
	home[i] = top;
	for (node *p = graph[i]; p; p = p->next)
	{
		if (!low[p->num])
		{
			father[p->num] = i;
			d[p->num] = d[i] + 1;
			dfs(p->num);
			euler[++top] = i;
		}
	}
	high[i] = label;
}
void segment(int i)
{
	if (tree[i].left == tree[i].right)
	{
		for (int j = 1; j <= 10; j++)
		{
			tree[i].sum[j] = color[tree[i].left][j];
		}
		return;
	}
	int mid = (tree[i].left + tree[i].right) / 2;
	tree[2 * i].left = tree[i].left;
	tree[2 * i].right = mid;
	tree[2 * i + 1].left = mid + 1;
	tree[2 * i + 1].right = tree[i].right;
	segment(2 * i);
	segment(2 * i + 1);
}
void push_down(int i)
{
	for (int j = 1; j <= 10; j++)
	{
		if (tree[i].sum[j] != 0 && tree[i].left != tree[i].right)
		{
			tree[2 * i].mark = tree[2 * i + 1].mark = 1;
			tree[2 * i].sum[j] += tree[i].sum[j];
			tree[2 * i + 1].sum[j] += tree[i].sum[j];
		}
		tree[i].sum[j] = 0;
	}
	tree[i].mark = 0;
}
void change(int i, int x, int y, int k_add, int k_minus)
{
	if (tree[i].left == x && tree[i].right == y)
	{
		tree[i].mark = 1;
		tree[i].sum[k_add]++;
		tree[i].sum[k_minus]--;
		return;
	}
	if (tree[i].mark)
	{
		push_down(i);
	}
	int mid = (tree[i].left + tree[i].right) / 2;
	if (y <= mid)
	{
		change(2 * i, x, y, k_add, k_minus);
	}
	else if (x > mid)
	{
		change(2 * i + 1, x, y, k_add, k_minus);
	}
	else
	{
		change(2 * i, x, mid, k_add, k_minus);
		change(2 * i + 1, mid + 1, y, k_add, k_minus);
	}
}
void search(int i, int x, int multi)
{
	if (tree[i].left == tree[i].right)
	{
		for (int j = 1; j <= 10; j++)
		{
			ans[j] += multi * tree[i].sum[j];
		}
		return;
	}
	if (tree[i].mark)
	{
		push_down(i);
	}
	int mid = (tree[i].left + tree[i].right) / 2;
	if (x <= mid)
	{
		search(2 * i, x, multi);
	}
	else
	{
		search(2 * i + 1, x, multi);
	}
}
void build_sparse_table()
{
	int i, j;
	for (i = 1; i <= top; i++)
	{
		sparse_table[i][0] = d[euler[i]];
		sparse_table_num[i][0] = euler[i];
	}
	for (j = 1; (1 << j) <= top; j++)
	{
		for (i = 1; i <= top - (1 << j) + 1; i++)
		{
			if (sparse_table[i][j - 1] < sparse_table[i + (1 << (j - 1))][j - 1])
			{
				sparse_table[i][j] = sparse_table[i][j - 1];
				sparse_table_num[i][j] = sparse_table_num[i][j - 1];
			}
			else
			{
				sparse_table[i][j] = sparse_table[i + (1 << (j - 1))][j - 1];
				sparse_table_num[i][j] = sparse_table_num[i + (1 << (j - 1))][j - 1];
			}
		}
	}
}
int LCA(int x, int y)
{
	if (x > y)
	{
		int t;
		t = x;
		x = y;
		y = t;
	}
	int z = Log[y - x + 1];
	if (sparse_table[x][z] < sparse_table[y - (1 << z) + 1][z])
	{
		return sparse_table_num[x][z];
	}
	else
	{
		return sparse_table_num[y - (1 << z) + 1][z];
	}
}
int main()
{
	scanf("%d", &T);
	int i, j, k;
	int x, y, z;
	LOG();
	for (k = 1; k <= T; k++)
	{
		top = label = 0;
		memset(low, 0, sizeof(low));
		memset(graph, 0, sizeof(graph));
		memset(tree, 0, sizeof(tree));
		memset(color, 0, sizeof(color));
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			c[i] = x;
		}
		for (i = 1; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			add(x, y);
		}
		father[1] = 0;
		d[1] = 0;
		top = 0;
		dfs(1);
		tree[1].left = 1;
		tree[1].right = n;
		segment(1);
		build_sparse_table();
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &z, &x, &y);
			if (z == 0)
			{
				change(1, low[x], high[x], y, c[x]);
				c[x] = y;
			}
			else
			{
				int fa = LCA(home[x], home[y]);
				int MAX = 0;
				memset(ans, 0, sizeof(ans));
				search(1, low[x], 1);
				search(1, low[y], 1);
				search(1, low[fa], -2);
				for (j = 1; j <= 10; j++)
				{
					if (c[fa] == j)
					{
						ans[j]++;
					}
					if (ans[j] > MAX)
					{
						MAX = ans[j];
					}
				}
				printf("%d\n", MAX);
			}
		}
	}
	return 0;
}
