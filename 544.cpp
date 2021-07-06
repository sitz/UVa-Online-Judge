#include <bits/stdc++.h>

using namespace std;

/*
Heavy Cargo
Algorithm   :   Flyod W. with BST
544
*/
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)
#define MAXN 202
int A[MAXN][MAXN];
struct node
{
	char city[31];
	int index;
	node *next, *left, *right;
};
node *root;
int N, M, IN;
void Insert(node *rt, char city[], int in)
{
	node *p = (node *)malloc(sizeof(node));
	strcpy(p->city, city);
	p->index = in;
	p->left = p->right = NULL;
	if (rt == NULL)
	{
		root = p;
		return;
	}
	node *x = root;
	while (1)
	{
		if (strcmp(x->city, city) < 0)
		{
			if (x->right == NULL)
			{
				x->right = p;
				return;
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
				return;
			}
			else
			{
				x = x->left;
			}
		}
	}
}
int Search(node *rt, char city[])
{
	node *x = root;
	while (x != NULL)
	{
		if (!strcmp(x->city, city))
		{
			return x->index;
		}
		if (strcmp(x->city, city) < 0)
		{
			x = x->right;
		}
		else
		{
			x = x->left;
		}
	}
	return -1;
}
void Set(char city1[], char city2[], int cost)
{
	int s, t;
	s = Search(root, city1);
	t = Search(root, city2);
	if (s == -1)
	{
		Insert(root, city1, IN);
		s = IN++;
	}
	if (t == -1)
	{
		Insert(root, city2, IN);
		t = IN++;
	}
	A[s][t] = A[t][s] = cost;
}
void ReadCase()
{
	int cost;
	IN = 1;
	char city1[32], city2[32];
	while (M--)
	{
		scanf("%s%s%d", city1, city2, &cost);
		Set(city1, city2, cost);
	}
}
void Ini()
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			A[i][j] = 0;
		}
	}
}
void Flyod()
{
	int i, j, k;
	for (k = 1; k <= N; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				A[i][j] = MAX(A[i][j], MIN(A[i][k], A[k][j]));
			}
		}
	}
}
void Cal()
{
	char city1[32], city2[32];
	int p, q;
	scanf("%s%s", city1, city2);
	p = Search(root, city1);
	q = Search(root, city2);
	Flyod();
	printf("%d tons\n\n", A[p][q]);
}
int main()
{
	int kase = 1;
	while (scanf("%d%d", &N, &M) == 2)
	{
		if (!N && !M)
		{
			break;
		}
		Ini();
		root = NULL;
		ReadCase();
		printf("Scenario #%d\n", kase++);
		Cal();
	}
	return 0;
}
