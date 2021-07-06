#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 5010;

//ifstream fin("11131.in");
//#define cin fin

struct TreeNode
{
	char name[35];
	int cntChild;
	int child[10];
} tree[MAXSIZE];

char buffer[1000];
int cntNode = 0;

int findName(char *p)
{
	for (int i = 0; i < cntNode; i++)
		if (!strcmp(p, tree[i].name))
		{
			return i;
		}
	return -1;
}

void init()
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		tree[i].cntChild = 0;
		for (int j = 0; j < 10; j++)
		{
			tree[i].child[j] = -1;
		}
	}
}

void input()
{
	while (cin.getline(buffer, 1000))
	{
		int parent;
		char *cp = strtok(buffer, ",");
		if (cp)
		{
			parent = findName(cp);
			if (parent < 0)
			{
				strcpy(tree[cntNode].name, cp);
				parent = cntNode;
				cntNode++;
			}
		}
		while ((cp = strtok(NULL, ",")) != NULL)
		{
			int son = findName(cp);
			if (son < 0)
			{
				strcpy(tree[cntNode].name, cp);
				son = cntNode;
				cntNode++;
			}
			tree[parent].child[tree[parent].cntChild++] = son;
		}
	}
}

void dfs_left_to_right(int node)
{
	if (tree[node].cntChild == 0)
	{
		cout << tree[node].name << endl;
	}
	else
	{
		for (int i = 0; i < tree[node].cntChild; i++)
		{
			dfs_left_to_right(tree[node].child[i]);
		}
		cout << tree[node].name << endl;
	}
}

void dfs_right_to_left(int node)
{
	if (tree[node].cntChild == 0)
	{
		cout << tree[node].name << endl;
	}
	else
	{
		for (int i = tree[node].cntChild - 1; i >= 0; i--)
		{
			dfs_right_to_left(tree[node].child[i]);
		}
		cout << tree[node].name << endl;
	}
}

void solve()
{
	cout << 2 << endl
			 << endl;
	dfs_left_to_right(0);
	cout << endl;
	dfs_right_to_left(0);
	cout << endl;
}

int main()
{
	init();
	input();
	solve();
	return 0;
}
