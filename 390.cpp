#include <bits/stdc++.h>

using namespace std;

struct node
{
	char seq[6];
	int freq;
	node *nxt;
};
node *lst = NULL;

char seq[6];
int seqlen;

int isaseq()
{
	if ((int)strlen(seq) < seqlen)
	{
		return 0;
	}
	for (int i = 0; i < seqlen; i++)
	{
		if (!isalpha(seq[i]))
		{
			return 0;
		}
	}
	return 1;
}
void addchar(char c)
{
	int n = strlen(seq);
	if (n < seqlen)
	{
		seq[n] = c;
		seq[n + 1] = '\0';
		return;
	}
	for (int i = 0; i < n - 1; i++)
	{
		seq[i] = seq[i + 1];
	}
	seq[n - 1] = c;
}
void addseq(char *seq)
{
	if (lst == NULL || strcmp(seq, lst->seq) < 0)
	{
		node *n = new node;
		strcpy(n->seq, seq);
		n->freq = 1;
		n->nxt = lst;
		lst = n;
		return;
	}
	if (strcmp(seq, lst->seq) == 0)
	{
		lst->freq += 1;
		return;
	}
	node *p = lst;
	while (p->nxt != NULL && strcmp(seq, p->nxt->seq) >= 0)
	{
		p = p->nxt;
	}
	if (strcmp(seq, p->seq) == 0)
	{
		p->freq += 1;
		return;
	}
	node *n = new node;
	strcpy(n->seq, seq);
	n->freq = 1;
	n->nxt = p->nxt;
	p->nxt = n;
}
void freelst()
{
	while (lst != NULL)
	{
		node *d = lst;
		lst = lst->nxt;
		delete d;
	}
}
void printdelmax_()
{
	int max_ = 0;
	node *p = lst;
	while (p != NULL)
	{
		if (p->freq > max_)
		{
			max_ = p->freq;
		}
		p = p->nxt;
	}
	if (max_ == 0)
	{
		return;
	}
	printf("Frequency = %d, Sequence(s) = (", max_);
	int gotone = 0;
	node *q = NULL;
	p = lst;
	while (p != NULL)
	{
		if (p->freq == max_)
		{
			if (gotone)
			{
				cout << ',';
			}
			cout << p->seq;
			gotone = 1;
			node *d = p;
			if (q == NULL)
			{
				lst = p->nxt;
			}
			else
			{
				q->nxt = p->nxt;
			}
			p = p->nxt;
			delete d;
		}
		else
		{
			q = p;
			p = p->nxt;
		}
	}
	printf(")\n");
}
void report()
{
	printf("Analysis for Letter Sequences of Length %d\n", seqlen);
	printf("-----------------------------------------\n");
	for (int i = 0; i < 5; i++)
	{
		printdelmax_();
	}
	if (seqlen < 5)
	{
		printf("\n");
	}
}

char c, text[10240];
int text_index = 0;

void cnt(int n)
{
	seq[0] = '\0';
	seqlen = n;
	if (n == 1)
	{
		while (scanf("%c", &c) == 1)
		{
			addchar(toupper(char(c)));
			if (isaseq())
			{
				addseq(seq);
			}
			text[text_index++] = c;
		}
	}
	else
	{
		for (int i = 0; i < text_index; ++i)
		{
			addchar(toupper(char(text[i])));
			if (isaseq())
			{
				addseq(seq);
			}
		}
	}
	report();
	freelst();
}

int main()
{
	for (int i = 1; i <= 5; i++)
	{
		cnt(i);
	}
	return 0;
}
