#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
#define MAX 5000

char C_1[MAXN][4], C_2[MAXN][4], St[MAXN + MAXN][4], Link[MAX][MAX];
char B[5], E[5];
int N, K, I, Q[MAXN], QH, QT;
struct Vertex
{
	int pr;
	char cl;
} V[MAX];

int com(const void *a, const void *b)
{
	return strcmp((char *)b, (char *)a);
}

// binary search
int B_search(char a[])
{
	int lo = 0, up = I - 1;
	int mid = (lo + up) / 2;
	while (lo <= up && strcmp(St[mid], a))
	{
		if (strcmp(a, St[mid]) < 0)
		{
			lo = mid + 1;
		}
		else if (strcmp(a, St[mid]) > 0)
		{
			up = mid - 1;
		}
		mid = (lo + up) / 2;
	}
	if (strcmp(a, St[mid]))
	{
		return -1;
	}
	return mid;
}
int isEmpty()
{
	return QH == QT;
}
int pop()
{
	int x = Q[QH++];
	QH %= MAXN;
	return x;
}
void push(int x)
{
	Q[QT++] = x;
	QT %= MAXN;
}
int BFS(int s, int t)
{
	int i;
	for (i = 0; i < I; i++)
	{
		V[i].cl = 'W';
	}
	V[s].cl = 'G';
	QH = QT = 0;
	push(s);
	while (!isEmpty())
	{
		int u = pop();
		for (int v = 0; v < I; v++)
		{
			if (V[v].cl == 'W' && Link[u][v] == 1)
			{
				V[v].cl = 'G';
				V[v].pr = u;
				if (v == t)
				{
					return 1;
				}
				push(v);
			}
		}
	}
	return 0;
}
void Set()
{
	int i, q, p;
	I = 0;
	qsort(St, K, sizeof(St[0]), com);
	for (i = 1; i < K; i++)
		if (!strcmp(St[i - 1], St[i]))
		{
			strcpy(St[i - 1], "99");
		}
	qsort(St, K, sizeof(St[0]), com);
	for (i = 0; i < K; i++)
	{
		if (strcmp(St[i], "99"))
		{
			I++;
		}
		else
		{
			break;
		}
	}
	for (i = 0; i < N; i++)
	{
		p = B_search(C_1[i]);
		q = B_search(C_2[i]);
		if (p < 0 || q < 0)
		{
			printf("Erro\n");
			exit(0);
		}
		Link[p][q] = Link[q][p] = 1;
	}
}
void PrintPath(int s, int m, int t)
{
	if (s == t)
	{
		printf("%s %s\n", St[t], St[m]);
		return;
	}
	PrintPath(s, t, V[t].pr);
	if (s != m)
	{
		printf("%s %s\n", St[t], St[m]);
	}
}
void CaL()
{
	int i, j, p, q;
	p = B_search(B);
	q = B_search(E);
	if (p == -1 || q == -1)
	{
		printf("No route\n");
		return;
	}
	j = BFS(p, q);
	if (j == 0)
	{
		printf("No route\n");
		return;
	}
	else
	{
		PrintPath(p, p, q);
	}
}

int main()
{
	int i, j = 0;
	while (scanf("%d", &N) == 1)
	{
		K = 0;
		if (j)
		{
			putchar('\n');
		}
		for (i = 0; i < N; i++)
		{
			scanf("%s%s", C_1[i], C_2[i]);
			strcpy(St[K++], C_1[i]);
			strcpy(St[K++], C_2[i]);
		}
		scanf("%s%s", B, E);
		Set();
		CaL();
		j++;
		for (i = 0; i < MAX; i++)
		{
			memset(Link[i], 0, sizeof(char) * MAX);
		}
	}
	return 0;
}
