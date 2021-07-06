#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int(i) = int(a); (i) < int(b); (i)++)
#define FOREQ(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)

#define MAXN 27
#define MAX 100

static char city1[100000], city2[100000], FL[MAXN][MAXN];
static int QH, QT, Q[MAX];

struct Vertex {int pr; char cl;} V[MAXN];

inline void push(int n)
{
	Q[QH++] = n;
	QH %= MAX;
}
inline int pop()
{
	int n = Q[QT++];
	QT %= MAX;
	return n;
}
inline bool is_empty_()
{
	return QH == QT;
}

void BFS(int st, int ter)
{
	int u;
	FOR(i, 0, MAXN)
	V[i].cl = 'W';
	V[st].cl = 'G';
	QH = QT = 0;
	push(st);
	while (!is_empty_())
	{
		u = pop();
		FOR(i, 0, MAXN)
		{
			if (FL[u][i] && V[i].cl == 'W')
			{
				V[i].pr = u;
				V[i].cl = 'G';
				if (ter == i)
				{
					return;
				}
				push(i);
			}
		}
	}
}

void print_path(int s, int t)
{
	if (s == t)
	{
		printf("%c", s + 'A');
		return;
	}
	else
	{
		print_path(s, V[t].pr);
	}
	printf("%c", t + 'A');
}

static int T, nt, q, a, b;

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &nt, &q);
		FOR(i, 0, nt)
		{
			scanf("%s%s", city1, city2);
			a = city1[0] - 'A';
			b = city2[0] - 'A';
			FL[b][a] = FL[a][b] = 1;
		}
		while (q--)
		{
			scanf("%s%s", city1, city2);
			a = city1[0] - 'A';
			b = city2[0] - 'A';
			if (a == b)
			{
				continue;
			}
			BFS(a, b);
			print_path(a, b);
			printf("\n");
		}
		if (T)
		{
			printf("\n");
		}
		FOR(i, 0, MAXN)
		{
			FOR(j, 0, MAXN)
			{
				FL[i][j] = 0;
			}
		}
	}
	return 0;
}
