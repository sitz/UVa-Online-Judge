#include <bits/stdc++.h>

using namespace std;

typedef long long ss;

struct node
{
	ss info;
	node *parent, *left, *right;
};
node *root;

void insert(int info)
{
	node *p = (node *)malloc(sizeof(node));
	p->left = p->right = NULL;
	p->info = info;
	if (root == NULL)
	{
		root = p;
		p->parent = NULL;
		return;
	}
	node *x = root;
	while (1)
	{
		if (x->info < info)
		{
			if (x->right == NULL)
			{
				x->right = p;
				p->parent = x;
				break;
			}
			else
			{
				x = x->right;
			}
		}
		else
		{
			if (x->left == NULL)
			{
				x->left = p;
				p->parent = x;
				break;
			}
			else
			{
				x = x->left;
			}
		}
	}
}
node *search(node *r, int info)
{
	node *x = r;
	while (x != NULL)
	{
		if (x->info == info)
		{
			return x;
		}
		if (x->info < info)
		{
			x = x->right;
		}
		else
		{
			x = x->left;
		}
	}
	return x;
}
int com(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}
void Rev(char *str)
{
	char temp[100];
	int i, n = 0;
	for (i = strlen(str) - 1; i >= 0; i--)
	{
		temp[n++] = str[i];
	}
	temp[n] =  '\0';
	strcpy(str, temp);
}
void Cal(ss n)
{
	char dummy[100];
	root = NULL;
	ss b, m, pre, temp, length = 0;
	while (1)
	{
		sprintf(dummy, "%lld", n);
		qsort(dummy, strlen(dummy), sizeof(char), com);
		sscanf(dummy, "%lld", &b);
		Rev(dummy);
		sscanf(dummy, "%lld", &m);
		temp = m - b;
		printf("%lld - %lld = %lld\n", m, b, temp);
		if (search(root, temp))
		{
			break;
		}
		insert(temp);
		n = temp;
		length++;
	}
	printf("Chain length %lld\n\n", length + 1);
}

int main()
{
	ss n;
	while (scanf("%lld", &n) && n)
	{
		if (!n)
		{
			break;
		}
		printf("Original number was %lld\n", n);
		Cal(n);
	}
	return 0;
}
