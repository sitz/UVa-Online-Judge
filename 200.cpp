#include <bits/stdc++.h>

using namespace std;

#define MAXN 30
#define MAX 100000

char STR[MAX][MAXN];
char LIST[MAX][MAXN];
int TIME;
struct vertex
{
	char color;
	int Ftime;
} VERTEX[MAXN];
struct node
{
	int ft;
	node *next;
};
node *lst;

void ADD(int m, int n)
{
	int i, j, k, en;
	j = STR[m][0] - 65;
	k = STR[n][0] - 65;
	LIST[j][k] = 1;
	VERTEX[j].color = 'w';
	VERTEX[k].color = 'w';
	k = strlen(STR[m]);
	j = strlen(STR[n]);
	if (k > j)
	{
		en = j;
	}
	else
	{
		en = k;
	}
	for (i = 1; i < en; i++)
	{
		if (STR[m][i - 1] == STR[n][i - 1])
		{
			j = STR[m][i] - 65;
			k = STR[n][i] - 65;
			LIST[j][k] = 1;
			VERTEX[j].color = 'w';
			VERTEX[k].color = 'w';
			k = strlen(STR[m]);
			j = strlen(STR[n]);
		}
		else
		{
			break;
		}
	}
}

void DoDFS(int n)
{
	VERTEX[n].color = 'g';
	TIME++;
	for (int j = 0; j < 27; j++)
	{
		if (LIST[n][j])
		{
			if (VERTEX[j].color == 'w')
			{
				DoDFS(j);
			}
		}
	}
	node *p = (node *)malloc(sizeof(node));
	p->ft = n;
	p->next = lst;
	lst = p;
	VERTEX[n].color = 'b';
}

void PRINT()
{
	int j;
	node *x = lst;
	while (x != NULL)
	{
		j = x->ft + 65;
		printf("%c", j);
		x = x->next;
	}
}

void DFS()
{
	int i;
	for (i = 0; i < 28; i++)
	{
		VERTEX[i].Ftime = 0;
	}
	TIME = 0;
	for (i = 0; i < 28; i++)
	{
		if (VERTEX[i].color == 'w')
		{
			DoDFS(i);
		}
	}
}

int main()
{
	int k = 0, i;
	while (1)
	{
		scanf("%s", STR[k]);
		if (!strcmp(STR[k], "#"))
		{
			break;
		}
		k++;
	}
	for (i = 0; i < k - 1; i++)
	{
		ADD(i, i + 1);
	}
	DFS();
	PRINT();
	putchar('\n');
	return 0;
}
