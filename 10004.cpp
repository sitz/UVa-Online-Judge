#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int(i) = int(a); (i) < int(b); (i)++)
#define FOREQ(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)

#define MAXN 202

struct SS {char color;} V[MAXN];

static char Link[MAXN][MAXN];
static int a, b, s, N, E, Q[MAXN], QH, QT;

inline void push(int n)
{
	Q[QH++] = n;
	QH %= MAXN;
}
inline int pop()
{
	int n = Q[QT++];
	QT %= MAXN;
	return n;
}
inline bool is_empty_()
{
	return QH == QT;
}

inline int BFS(int s)
{
	int u;
	char co;
	V[s].color = 'w';
	QH = QT = 0;
	push(s);
	while (!is_empty_())
	{
		u = pop();
		co = 'w';
		if (V[u].color == 'w')
		{
			co = 'b';
		}
		FOR(i, 0, N)
		{
			if (Link[i][u] == 1)
			{
				if (V[i].color == 'g')
				{
					V[i].color = co;
					Link[i][u] = Link[u][i] = 0;
					push(i);
				}
				else if (V[i].color == V[u].color)
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
	while (scanf("%d", &N) && N)
	{
		scanf("%d", &E);
		FOR(i, 0, E)
		{
			scanf("%d%d", &a, &b);
			Link[a][b] = Link[b][a] = 1;
			s = a;
		}
		FOREQ(i, 0, N)
		V[i].color = 'g';
		if (BFS(s))
		{
			printf("BICOLORABLE.\n");
		}
		else
		{
			printf("NOT BICOLORABLE.\n");
		}
		FOR(i, 0, MAXN)
		memset(Link[i], 0, 201 * sizeof(char));
	}
	return 0;
}
