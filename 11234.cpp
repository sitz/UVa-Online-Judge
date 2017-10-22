#include <bits/stdc++.h>

using namespace std;

typedef struct _tree
{
	char v;
	struct _tree *lf, *rt;
} tree;
char in[10005];
int ptr, n, len;
tree *Q[10005];
tree *run()
{
	tree *r = (tree *)malloc(sizeof(tree));
	r->v = in[--ptr];
	if (r->v < 'a')
	{
		r->rt = run();
		r->lf = run();
	}
	return r;
}
void des(tree *x)
{
	if (x->v < 'a')
	{
		des(x->rt);
		des(x->lf);
	}
	free(x);
}
int main()
{
	int t, n;
	char ch;
	tree *root;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", in);
		ptr = n = strlen(in);
		root = run();
		Q[0] = root, len = 1;
		for (ptr = 0; ptr < len; ptr++)
		{
			ch = Q[ptr]->v;
			in[n - 1 - ptr] = ch;
			if (ch < 'a')
			{
				Q[len++] = Q[ptr]->lf;
				Q[len++] = Q[ptr]->rt;
			}
		}
		printf("%s\n", in);
	}
	return 0;
}
