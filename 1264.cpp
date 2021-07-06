#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int M = 9999991;
int c[20][20];
class node
{
public:
	int key, num;
	ll value;
	node *left, *right;
	node()
	{
		left = right = 0;
		value = 1;
		num = 0;
		key = 0;
	}
	node(int el)
	{
		left = right = 0;
		value = 1;
		num = 0;
		key = el;
	}
};
node *root;
void insert(int el)
{
	node *p = root, *pre = 0;
	while (p)
	{
		pre = p;
		if (p->key < el)
		{
			p = p->right;
		}
		else
		{
			p = p->left;
		}
	}
	if (root == 0)
	{
		root = new node(el);
	}
	else if (pre->key < el)
	{
		p = pre->right = new node(el);
	}
	else
	{
		p = pre->left = new node(el);
	}
}
void cal(node *p)
{
	if (!p->key)
	{
		return;
	}
	if (p->left == 0)
	{
		p->left = new node();
	}
	if (p->right == 0)
	{
		p->right = new node();
	}
	cal(p->left);
	cal(p->right);
	p->num = p->left->num + p->right->num + 1;
	p->value = (p->left->value * p->right->value) % M * c[p->left->num + p->right->num][p->left->num] % M;
}
int main()
{
	int t, n, a, i, j;
	c[0][0] = 1;
	for (i = 1; i < 20; i++)
	{
		c[i][0] = c[i][i] = 1;
		for (j = 1; j < i; j++)
		{
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	scanf("%d", &t);
	while (t--)
	{
		root = 0;
		scanf("%d", &n);
		while (n--)
		{
			scanf("%d", &a);
			insert(a);
		}
		cal(root);
		printf("%lld\n", root->value);
	}
	return 0;
}
