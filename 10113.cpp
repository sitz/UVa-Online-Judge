#include <bits/stdc++.h>

using namespace std;

#define MAXN 102

struct ss
{
	int a;
	int b;
	char f;
} V[MAXN][MAXN];
struct node
{
	char city[31];
	int index;
	node *next, *left, *right;
};
node *root;
int Q[MAXN], QH, QT, IN, P[MAXN];
int N[MAXN];
char F[MAXN];
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
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
void Set(char city1[], int cost1, char city2[], int cost2)
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
	V[s][t].f = V[t][s].f = 1;
	V[s][t].a = cost1;
	V[s][t].b = cost2;
	V[t][s].a = cost2;
	V[t][s].b = cost1;
}
void Push(int n)
{
	Q[QH++] = n;
	QH %= MAXN;
}
int Pop()
{
	int n = Q[QT++];
	QT %= MAXN;
	return n;
}
int IsEmpty()
{
	return QH == QT;
}
int BFS(int s, int t)
{
	int i, j;
	for (i = 0; i < IN; i++)
	{
		F[i] = 0;
		P[i] = -1;
	}
	QH = QT = 0;
	F[s] = 1;
	Push(s);
	while (!IsEmpty())
	{
		j = Pop();
		for (i = 0; i < IN; i++)
		{
			if (!V[j][i].f || F[i])
			{
				continue;
			}
			if (i == t)
			{
				P[i] = j;
				return 1;
			}
			F[i] = 1;
			P[i] = j;
			Push(i);
		}
	}
	return 0;
}
int T = 0;
void Find(int a, int b)
{
	if (a == b)
	{
		N[T++] = a;
		return;
	}
	Find(a, P[b]);
	N[T++] = b;
}
void Cal(char p1[], char p2[])
{
	int s, t, x, i;
	int n, d;
	n = d = 1;
	s = Search(root, p1);
	t = Search(root, p2);
	x = BFS(s, t);
	if (x == 0)
	{
		printf("? %s = ? %s\n", p1, p2);
		return;
	}
	T = 0;
	Find(s, t);
	for (i = 0; i < T - 1; i++)
	{
		s = N[i];
		t = N[i + 1];
		n *= V[s][t].a;
		d *= V[s][t].b;
		x = gcd(n, d);
		n /= x;
		d /= x;
	}
	printf("%d %s = %d %s\n", n, p1, d, p2);
}

int main()
{
	IN = 0;
	char text[10], pr1[22], pr2[22];
	int co1, co2;
	root = NULL;
	while (1)
	{
		char ch;
		cin >> ch;
		if (ch == '.')
		{
			break;
		}
		if (ch == '!')
		{
			cin >> co1 >> pr1 >> ch >> co2 >> pr2;
			Set(pr1, co1, pr2, co2);
		}
		else
		{
			cin >> pr1 >> ch >> pr2;
			Cal(pr1, pr2);
		}
	}
	return 0;
}
