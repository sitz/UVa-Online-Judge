#include <bits/stdc++.h>

using namespace std;

struct node
{
	int l, m, r, v;
} tree[1000100];
int res[200100];

void make(int l, int r, int i = 1)
{
	tree[i].l = l;
	tree[i].r = r;
	tree[i].m = (l + r) / 2;
	if (l == r)
	{
		tree[i].v = res[l];
		return;
	}
	else
	{
		make(l, tree[i].m, 2 * i);
		make(tree[i].m + 1, r, 2 * i + 1);
		tree[i].v = tree[2 * i].v + tree[2 * i + 1].v;
	}
}

void insert(int n, int v, int i = 1)
{
	if (tree[i].l == tree[i].r && tree[i].l == n)
	{
		tree[i].v = v;
	}
	else
	{
		if (n <= tree[i].m)
		{
			insert(n, v, 2 * i);
		}
		else
		{
			insert(n, v, 2 * i + 1);
		}
		tree[i].v = tree[2 * i].v + tree[2 * i + 1].v;
	}
}

int count(int l, int r, int i = 1)
{
	if (tree[i].l == l && tree[i].r == r)
	{
		return tree[i].v;
	}
	else
	{
		if (r <= tree[i].m)
		{
			return count(l, r, 2 * i);
		}
		else if (l > tree[i].m)
		{
			return count(l, r, 2 * i + 1);
		}
		else
		{
			return count(l, tree[i].m, 2 * i) + count(tree[i].m + 1, r, 2 * i + 1);
		}
	}
}

void setv()
{
	int n, v;
	scanf("%d%d", &n, &v);
	insert(n, v);
}

void measure()
{
	int l, r;
	scanf("%d%d", &l, &r);
	printf("%d\n", count(l, r));
}

int main()
{
	int casec = 1, N, first = 1;
	char t;
	while (scanf("%d", &N), N != 0)
	{
		if (first)
		{
			first = 0;
		}
		else
		{
			putchar('\n');
		}
		for (int i = 1; i <= N; ++i)
		{
			scanf("%d", res + i);
		}
		getchar();
		printf("Case %d:\n", casec++);
		make(1, N);
		while (true)
		{
			t = getchar();
			if (t == 'M')
			{
				measure();
			}
			else if (t == 'S')
			{
				setv();
			}
			else if (t == 'E')
			{
				while (t = getchar(), t != '\n' && t != EOF)
					;
				break;
			}
			while (t = getchar(), t != '\n' && t != EOF)
				;
		}
	}
	return 0;
}
