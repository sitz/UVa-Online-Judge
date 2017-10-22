#include <bits/stdc++.h>

using namespace std;

#define init(i, a, n)      \
	for (i = 1; i <= n; i++) \
	a[i] = i
#define INF 10000000

typedef struct edge {int f, t, d;} E;
E lst[40000];

char matrix[205][205];
int mark[205], set_[205];

typedef struct dNode
{
	int content;
	struct dNode *next;
	struct dNode *prev;
} node;

typedef struct dLinkedList
{
	node header;
	node trailer;
	int size;
} linkedList;

linkedList *LinkedList()
{
	linkedList *l = (linkedList *)malloc(sizeof(linkedList));
	(l->header).next = &(l->trailer);
	(l->trailer).prev = &(l->header);
	l->size = 0;
	return l;
}
int getParent(int i, int *set_)
{
	if (i == set_[i])
	{
		return i;
	}
	else
	{
		return (set_[i] = getParent(set_[i], set_));
	}
}
int isUnion(int a, int b, int *set_)
{
	return getParent(a, set_) == getParent(b, set_);
}
void makeUnion(int a, int b, int *set_)
{
	set_[getParent(a, set_)] = getParent(b, set_);
}
void push_back(int val, linkedList *l)
{
	node *n = (node *)malloc(sizeof(node));
	n->content = val;
	n->next = &(l->trailer);
	n->prev = l->trailer.prev;
	(l->trailer.prev)->next = n;
	l->trailer.prev = n;
	l->size++;
}
int pop_front(linkedList *l)
{
	int res;
	node *n = l->header.next;
	l->header.next = n->next;
	n->next->prev = &(l->header);
	res = n->content;
	free(n);
	l->size--;
	return res;
}
int cmp(const void *a, const void *b)
{
	return ((E *)a)->d - ((E *)b)->d;
}
int validate(int n)
{
	int i, j, c, ex;
	for (i = 1; i <= n; i++)
	{
		mark[i] = 0;
	}
	linkedList *Q = LinkedList();
	for (j = 1; j <= n; j++)
		if (!mark[j])
		{
			mark[j] = 1;
			push_back(j, Q);
			while (Q->size)
			{
				c = pop_front(Q);
				ex = mark[c] ^ 3;
				for (i = 1; i <= n; i++)
					if (matrix[c][i])
					{
						if (!mark[i])
						{
							mark[i] = ex;
							push_back(i, Q);
						}
						if (mark[i] != ex)
						{
							return 0;
						}
					}
			}
		}
	return 1;
}

int main()
{
	register int i, j, res, d;
	int n, e;
	scanf("%d", &n);
	while (n)
	{
		scanf("%d", &e);
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
			{
				matrix[i][j] = 0;
			}
		for (i = 0; i < e; i++)
		{
			scanf("%d %d %d", &lst[i].f, &lst[i].t, &lst[i].d);
			matrix[lst[i].f][lst[i].t] = matrix[lst[i].t][lst[i].f] = 1;
		}
		if (!validate(n))
		{
			puts("Invalid data, Idiot!");
		}
		else
		{
			init(i, set_, n);
			res = 0;
			d = 0;
			qsort(lst, e, sizeof(E), &cmp);
			for (i = 0; i < e && d < n - 1; i++)
				if (!isUnion(lst[i].f, lst[i].t, set_))
				{
					makeUnion(lst[i].f, lst[i].t, set_);
					res += lst[i].d;
					d++;
				}
				else if (lst[i].d < 0)
				{
					res += lst[i].d;
				}
			for (; i < e && lst[i].d < 0; i++)
			{
				res += lst[i].d;
			}
			printf("%d\n", res);
		}
		scanf("%d", &n);
	}
	return 0;
}
