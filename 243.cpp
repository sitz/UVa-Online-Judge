#include <bits/stdc++.h>

using namespace std;

typedef struct dnode
{
	int point;
	int flag1;
	int flag2;
	dnode *left;
	dnode *right;
} dlink;
dlink Node[2000];
dlink *Head[30];

int d_size;

void dlink_inital(void)
{
	d_size = 0;
	for (int i = 0; i < 26; ++i)
	{
		Head[i] = NULL;
	}
}

void dlink_add(int a, int b)
{
	if (!Head[a])
	{
		Node[d_size].left = &Node[d_size];
		Node[d_size].right = &Node[d_size];
		Head[a] = &Node[d_size];
	}
	else
	{
		Node[d_size].right = Head[a];
		Node[d_size].left = Head[a]->left;
		Head[a]->left->right = &Node[d_size];
		Head[a]->left = &Node[d_size];
	}
	Node[d_size].flag1 = 0;
	Node[d_size].flag2 = 0;
	Node[d_size].point = b;
	d_size++;
}

dlink *dlink_next(dlink *p, int id, int forword)
{
	dlink *t = Head[p->point];
	while (t->point != id)
	{
		t = t->right;
	}
	return (forword ? t->right : t->left);
}

dlink *dlink_last(dlink *p)
{
	dlink *t = p, *m = p, *q;
	for (q = t->right; t != q; q = q->right)
		if (m->flag2 < q->flag2)
		{
			m = q;
		}
	return m;
}

int visit[30];

int main()
{
	char a, b, c, d;
	while ((a = getchar()) != '#')
	{
		dlink_inital();
		while (a != '@')
		{
			getchar();
			while ((b = getchar()) != '\n')
			{
				dlink_add(a - 'A', b - 'A');
			}
			a = getchar();
		}
		a = getchar();
		b = getchar();
		c = getchar();
		d = getchar();
		getchar();
		if ((a == c && b == d) || (a == d && b == c))
		{
			printf("Theseus is killed between %c and %c\n", a, b);
			continue;
		}
		for (int i = 0; i < 26; ++i)
		{
			visit[i] = 0;
		}
		int T = a - 'A', M = c - 'A', S;
		dlink *p = Head[a - 'A'];
		while (p->point != b - 'A')
		{
			p = p->right;
		}
		dlink *q = Head[c - 'A'];
		while (q->point != d - 'A')
		{
			q = q->right;
		}
		int flagp = 1, flagq = 1, Mmark = 1;
		while (1)
		{
			//Minotaur into cavern
			S = M;
			M = q->point;
			q = dlink_next(q, S, 0);
			if (visit[M] == 1)
			{
				q = dlink_next(q->right, M, 0);
				M = S;
			}
			else
			{
				visit[M] = 2;
			}
			//Thseus into cavern
			S = T;
			T = p->point;
			p = dlink_next(p, S, 1);
			if (T == M)//meet in cavern
			{
				printf("The Minotaur is slain in %c\n", M + 'A');
				break;
			}
			//Thseus into passage
			if (visit[T] == 2)
			{
				visit[T] = 1;
				p = dlink_last(p);
			}
			else
				while (p->flag1)
				{
					p = p->right;
				}
			p->flag1 = 1;
			//Minotaur into passage
			while (q->flag2)
			{
				q = q->left;
			}
			if (M == p->point && T == q->point)//meet in passage
			{
				printf("Theseus is killed between %c and %c\n", 'A' + T, 'A' + M);
				break;
			}
			q->flag2 = Mmark++;
		}
	}
	return 0;
}
