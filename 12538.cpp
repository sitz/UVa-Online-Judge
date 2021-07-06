#include <bits/stdc++.h>

using namespace std;

const int N = 50000 + 10;
const int SIZE = 20000000;
const int LEN = 100 + 10;

struct NODE
{
	char ch;
	int size;
	int weight;
	NODE *lch, *rch;
};

NODE *root[N];
NODE mem[SIZE];
int top;
char s[LEN];

inline int get_size(NODE *a)
{
	if (!a)
	{
		return 0;
	}
	else
	{
		return a->size;
	}
}

NODE *new_node(char _ch, int _size, int _weight, NODE *_lch, NODE *_rch)
{
	assert(top < SIZE);
	mem[top].ch = _ch;
	mem[top].size = _size;
	mem[top].weight = _weight;
	mem[top].lch = _lch;
	mem[top].rch = _rch;
	top++;
	return &mem[top - 1];
}

NODE *merge(NODE *a, NODE *b)
{
	if (!a)
	{
		return b;
	}
	if (!b)
	{
		return a;
	}
	if (b->weight > a->weight)
	{
		return new_node(a->ch, a->size + b->size, a->weight, a->lch, merge(a->rch, b));
	}
	else
	{
		return new_node(b->ch, b->size + a->size, b->weight, merge(a, b->lch), b->rch);
	}
}

void split(NODE *a, int size, NODE *&b, NODE *&c)
{
	NODE *tmp;
	if (!a)
	{
		b = c = NULL;
	}
	else if (get_size(a->lch) >= size)
	{
		split(a->lch, size, b, tmp);
		c = new_node(a->ch, a->size - get_size(a->lch) + get_size(tmp), a->weight, tmp, a->rch);
	}
	else
	{
		split(a->rch, size - get_size(a->lch) - 1, tmp, c);
		b = new_node(a->ch, size, a->weight, a->lch, tmp);
	}
}

char find(NODE *root, int p)
{
	int lsize;
	lsize = get_size(root->lch);
	if (lsize > p)
	{
		return find(root->lch, p);
	}
	else if (lsize < p)
	{
		return find(root->rch, p - lsize - 1);
	}
	else
	{
		return root->ch;
	}
}

int main()
{
	int n, cmd, ver, v, p, c, d, len, i;
	NODE *a, *b, *x, *y;
	char ch;
	top = 0;
	root[0] = NULL;
	ver = d = len = 0;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &cmd);
		if (cmd == 1)
		{
			scanf("%d %s", &p, s);
			p -= d;
			split(root[ver], p, a, b);
			for (i = 0; s[i]; i++)
			{
				a = merge(a, new_node(s[i], 1, rand(), NULL, NULL));
			}
			root[++ver] = merge(a, b);
			len += strlen(s);
		}
		else if (cmd == 2)
		{
			scanf("%d %d", &p, &c);
			p -= d;
			c -= d;
			split(root[ver], p - 1, a, b);
			split(b, c, x, y);
			root[++ver] = merge(a, y);
		}
		else
		{
			scanf("%d %d %d", &v, &p, &c);
			v -= d;
			p -= d;
			c -= d;
			for (i = 0; i < c; i++)
			{
				ch = find(root[v], p + i - 1);
				printf("%c", ch);
				if (ch == 'c')
				{
					d++;
				}
			}
			printf("\n");
		}
	}
	return 0;
}
