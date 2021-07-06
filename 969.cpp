#include <bits/stdc++.h>

using namespace std;

typedef struct node
{
	struct node *left, *parent, *right;
	char op;
} node;

node *mkNode(char op)
{
	node *ptr = (node *)malloc(sizeof(node));
	ptr->op = op;
	ptr->left = ptr->right = ptr->parent = 0;
	return ptr;
}

void clearTree(node *tree)
{
	if (tree->left != 0)
	{
		clearTree(tree->left);
	}
	if (tree->right != 0)
	{
		clearTree(tree->right);
	}
	free(tree);
}

node *root;

void optimizeTree(node *tree)
{
	node *ptr;
	if (tree->left)
	{
		optimizeTree(tree->left);
	}
	if (tree->right)
	{
		optimizeTree(tree->right);
	}
	if (tree->op == 'i')
	{
		if ((tree->left->parent = tree->parent) != 0)
		{
			if (tree == tree->parent->right)
			{
				tree->parent->right = tree->left;
			}
			else
			{
				tree->parent->left = tree->left;
			}
		}
		if (root == tree)
		{
			root = tree->left;
		}
		free(tree);
	}
	else if (tree->op == 't' && tree->right->op == 't' && tree->right->right->op == '0')
	{
		ptr = mkNode('k');
		ptr->left = tree->right->left;
		ptr->right = tree->left;
		ptr->left->parent = ptr->right->parent = ptr;
		if ((ptr->parent = tree->parent) != 0)
		{
			if (ptr->parent->left == tree)
			{
				ptr->parent->left = ptr;
			}
			else
			{
				ptr->parent->right = ptr;
			}
		}
		if (root == tree)
		{
			root = ptr;
		}
		free(tree->right->right);
		free(tree->right);
		free(tree);
	}
}

void printExpression(char *dump, node *tree)
{
	int len;
	if (tree == 0)
	{
		return;
	}
	len = strlen(dump);
	dump[len++] = tree->op;
	dump[len] = 0;
	switch (tree->op)
	{
	case 'k':
	case 't':
		strcat(dump, "(");
		printExpression(dump, tree->left);
		strcat(dump, ", ");
		printExpression(dump, tree->right);
		strcat(dump, ")");
		return;
	case 'i':
		strcat(dump, "(");
		printExpression(dump, tree->left);
		strcat(dump, ")");
		return;
	}
}

char *now, token;

char nextToken()
{
	token = *now;
	if (*now)
	{
		now++;
	}
	return token;
}

node *parse()
{
	node *ptr = 0;
	nextToken();
	if (token == '0')
	{
		ptr = mkNode('0');
		return ptr;
	}
	else if (token == 't' || token == 'k')
	{
		ptr = mkNode(token);
		nextToken();
		ptr->left = parse();
		if (ptr->left)
		{
			ptr->left->parent = ptr;
		}
		nextToken();
		ptr->right = parse();
		if (ptr->right)
		{
			ptr->right->parent = ptr;
		}
		nextToken();
		return ptr;
	}
	else if (token == 'i')
	{
		ptr = mkNode(token);
		nextToken();
		ptr->left = parse();
		if (ptr->left)
		{
			ptr->left->parent = ptr;
		}
		nextToken();
		return ptr;
	}
	return 0;
}

void SpGets(char *input)
{
	char ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n' || ch == '\r')
		{
			break;
		}
		else if (ch == '\t' || ch == ' ')
		{
			continue;
		}
		*input++ = ch;
	}
	*input = 0;
	return;
}

char dump1[1000000], dump2[1000000];
int main()
{
	int count = 1000;
	char input[10000];
	node *exp1, *exp2;
	scanf("%d", &count);
	getchar();
	while (count--)
	{
		dump1[0] = dump2[0] = 0;
		SpGets(input);
		now = input;
		exp1 = parse();
		root = exp1;
		optimizeTree(exp1);
		exp1 = root;
		printExpression(dump1, exp1);
		SpGets(input);
		now = input;
		exp2 = parse();
		root = exp2;
		optimizeTree(exp2);
		exp2 = root;
		printExpression(dump2, exp2);
		printf("%s\n", strcmp(dump1, dump2) ? "false" : "true");
		clearTree(exp1);
		clearTree(exp2);
	}
	return 0;
}
