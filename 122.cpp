#include <bits/stdc++.h>

using namespace std;

struct node
{
	node *left, *right;
	int val;
};
node *root;
int N, MAX;
struct st
{
	int a[257];
	int index;
} V[257];

int Insert(int n, int ind, char s[], node *rt)
{
	if (strlen(s) == 0)
	{
		if (root->val != -1)
		{
			return 0;
		}
		root->val = n;
		return 1;
	}
	if (ind == strlen(s))
	{
		if (rt->val != -1)
		{
			return 0;
		}
		rt->val = n;
		return 1;
	}
	if (s[ind] == 'L')
	{
		if (rt->left != NULL)
		{
			return Insert(n, ind + 1, s, rt->left);
		}
		node *p = (node *)malloc(sizeof(node));
		p->left = p->right = NULL;
		rt->left = p;
		p->val = -1;
		return Insert(n, ind + 1, s, rt->left);
	}
	if (s[ind] == 'R')
	{
		if (rt->right != NULL)
		{
			return Insert(n, ind + 1, s, rt->right);
		}
		node *p = (node *)malloc(sizeof(node));
		p->left = p->right = NULL;
		rt->right = p;
		p->val = -1;
		return Insert(n, ind + 1, s, rt->right);
	}
	return 1;
}

void Sep(char ss[], char *temp)
{
	int i, j = 0;
	char dummy[100];
	for (i = 1; ss[i]; i++)
	{
		if (ss[i] == ',')
		{
			break;
		}
		dummy[j++] = ss[i];
	}
	dummy[j] = '\0';
	N = atoi(dummy);
	j = 0;
	for (i++; ss[i] != ')'; i++)
	{
		temp[j++] = ss[i];
	}
	temp[j] = '\0';
}

int Traversal(node *r, int index)
{
	if (r->val == -1)
	{
		return 0;
	}
	V[index].a[V[index].index++] = r->val;
	if (index > MAX)
	{
		MAX = index;
	}
	if (r->left != NULL)
		if (!Traversal(r->left, index + 1))
		{
			return 0;
		}
	if (r->right != NULL)
		if (!Traversal(r->right, index + 1))
		{
			return 0;
		}
	return 1;
}

void Cal()
{
	int i, j, k;
	MAX = 0;
	j = Traversal(root, 0);
	if (!j)
	{
		printf("not complete\n");
		return;
	}
	printf("%d", V[0].a[0]);
	k = 1;
	for (i = 0; i <= MAX; i++)
	{
		for (j = k; j < V[i].index; j++)
		{
			printf(" %d", V[i].a[j]);
		}
		V[i].index = 0;
		k = 0;
	}
	putchar('\n');
}

int main()
{
	char ss[100], path[500];
	int f;
	root = NULL;
	while (scanf("%s", ss) != EOF)
	{
		if (!strcmp(ss, "()"))
		{
			continue;
		}
		f = 1;
		node *p = (node *)malloc(sizeof(node));
		p->left = p->right = NULL;
		p->val = -1;
		root = p;
		Sep(ss, path);
		Insert(N, 0, path, root);
		while (1)
		{
			scanf("%s", ss);
			if (!strcmp(ss, "()"))
			{
				break;
			}
			if (!f)
			{
				continue;
			}
			Sep(ss, path);
			f = Insert(N, 0, path, root);
		}
		if (!f)
		{
			printf("not complete\n");
		}
		else
		{
			Cal();
		}
	}
	return 0;
}
