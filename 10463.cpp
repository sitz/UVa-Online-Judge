#include <bits/stdc++.h>

using namespace std;

/****
10463
****/
#define MAXN 400
#define MAX(a, b) (a > b ? a : b)
struct nn
{
	char colour;
	int move;
} B[MAXN];
char F[150][250];
char P[115];
int X[] = {-3, -3, 3, 3, -1, 1, -1, 1};
int Y[] = {-1, 1, -1, 1, 3, 3, -3, -3};
int Q[MAXN], H, T, pp[31];
int R, C, I;
int Sr, Sc, Tr, Tc;
void Prime_table()
{
	int i, j;
	for (i = 2; i * i <= 113;)
	{
		for (j = i + i; j <= 113; j += i)
		{
			P[j] = 1;
		}
		for (i++; P[i]; i++)
			;
	}
	I = 1;
	pp[0] = 2;
	for (i = 3; i <= 113; i += 2)
		if (P[i] == 0)
		{
			pp[I++] = i;
		}
}
void Push(int n)
{
	Q[H++] = n;
	H %= MAXN;
}
int Pop()
{
	int n = Q[T++];
	T %= MAXN;
	return n;
}
int IsEmpty()
{
	return H == T;
}
int BFS(int s, int t)
{
	int i, j, k, r, c = 0;
	int nr, nc, ss;
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
		{
			B[c].move = 0;
			B[c].colour = 0;
			c++;
		}
	H = T = 0;
	B[s].move = 0;
	Push(s);
	B[s].colour = 1;
	while (!IsEmpty())
	{
		k = Pop();
		r = k / C;
		c = k % C;
		j = B[k].move;
		for (i = 0; i < 8; i++)
		{
			nr = r + X[i];
			nc = c + Y[i];
			if (nr >= R || nr < 0 || nc >= C || nc < 0)
			{
				continue;
			}
			ss = nr * C + nc;
			if (ss == t)
			{
				return j + 1;
			}
			if (B[ss].colour != 1)
			{
				B[ss].move = j + 1;
				B[ss].colour = 1;
				Push(ss);
			}
		}
	}
	return 0;
}
int IDS(int move, int t, int cu, int limit)
{
	int i, ss, r, c, nr, nc;
	r = move / C;
	c = move % C;
	if (move == t && limit == cu)
	{
		return 1;
	}
	if (limit == cu)
	{
		return 0;
	}
	if (F[limit][move] == 1)
	{
		return 0;
	}
	if (B[move].colour == 1)
	{
		return 0;
	}
	B[move].colour = 1;
	F[limit][move] = 1;
	for (i = 0; i < 8; i++)
	{
		nr = r + X[i];
		nc = c + Y[i];
		if (nr >= R || nr < 0 || nc >= C || nc < 0)
		{
			continue;
		}
		ss = nr * C + nc;
		if (IDS(ss, t, cu + 1, limit))
		{
			return 1;
		}
	}
	B[move].colour = 0;
	return 0;
}
void Cal()
{
	int i, s;
	int j, k, m;
	P[1] = P[0] = 1;
	s = BFS(Sr * C + Sc, Tr * C + Tc);
	if (!P[s] && s)
	{
		printf("The knight takes %d prime moves.\n", s);
		return;
	}
	if (s == 0)
	{
		printf("Destination is not reachable.\n");
		return;
	}
	for (i = 0; i < I; i++)
	{
		if (pp[i] > (R * C) / 2)
		{
			break;
		}
		m = 0;
		for (j = 0; j < R; j++)
		{
			for (k = 0; k < C; k++)
			{
				B[m++].colour = 0;
			}
		}
		for (j = 0; j <= pp[i]; j++)
			for (k = 0; k <= R * C; k++)
			{
				F[j][k] = 0;
			}
		m = IDS(Sr * C + Sc, Tr * C + Tc, 0, pp[i]);
		if (m)
		{
			printf("The knight takes %d prime moves.\n", pp[i]);
			return;
		}
	}
	printf("The knight takes %d composite move(s).\n", s);
	;
}
int main()
{
	int kase = 1;
	Prime_table();
	while (scanf("%d%d%d%d%d%d", &R, &C, &Sr, &Sc, &Tr, &Tc) == 6)
	{
		printf("CASE# %d: ", kase++);
		if (Sr == Tr && Sc == Tc)
		{
			printf("The knight takes 0 composite move(s).\n");
			continue;
		}
		Cal();
	}
	return 0;
}
