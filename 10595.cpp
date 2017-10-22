#include <bits/stdc++.h>

using namespace std;

/*
Knight on the Bee Board
10595
*/
#define MAX(a, b) (a > b ? a : b)
int L, B, Obs, limiT;
char F[217][217];
int P[217][217];
int A[185], Qh, Qt;
int X[] = {2, 1, -1, -2, -3, -3, -2, 3, 3, 2, 1, -1};
int Y[] = {1, 2, 3, 3, 2, 1, -1, -1, -2, -3, -3, -2};
struct ss
{
	int x, y;
} pp;
struct tt
{
	int x, y;
	int Cost;
} Q[10009];
struct cor
{
	int x, y;
} co[10001];
void Ini()
{
	int i, j = 0, sum = 1;
	for (i = 1; sum < 10010; i++)
	{
		sum += j;
		A[i] = sum;
		j += 6;
	}
	L = i - 1;
}
ss Side_1(int stp, int x, int y, int T)
{
	int m = stp - T;
	pp.x = x;
	pp.y = -m;
	return pp;
}
ss Side_2(int stp, int x, int y, int T)
{
	int m = stp - T;
	pp.x = x - m;
	pp.y = y;
	return pp;
}
ss Side_3(int stp, int x, int y, int T)
{
	int m = stp - T;
	pp.x = x - m;
	pp.y = y + m;
	return pp;
}
ss Side_4(int stp, int x, int y, int T)
{
	int m = stp - T;
	pp.x = x;
	pp.y = m + y;
	return pp;
}
ss Side_5(int stp, int x, int y, int T)
{
	int m = stp - T;
	pp.x = x + m;
	pp.y = y;
	return pp;
}
ss Side_6(int stp, int x, int y, int T)
{
	int m = stp - T;
	pp.x = x + m;
	pp.y = y - m;
	return pp;
}
int Find(int T)
{
	int i;
	for (i = 2; i <= L; i++)
	{
		if (T <= A[i])
		{
			return i;
		}
	}
	return 0;
}
ss Cordinate(int T)
{
	int j, k, N, K;
	N = Find(T);
	K = A[N];
	j = K;
	k = j - N + 1;
	if (T <= j && k <= T)
	{
		return Side_1(j, N - 1, 0, T);
	}
	j = k;
	k = j - N + 1;
	if (T <= j && k <= T)
	{
		return Side_2(j, N - 1, -(N - 1), T);
	}
	j = k;
	k = j - N + 1;
	if (T <= j && k <= T)
	{
		return Side_3(j, 0, -(N - 1), T);
	}
	j = k;
	k = j - N + 1;
	if (T <= j && k <= T)
	{
		return Side_4(j, -(N - 1), 0, T);
	}
	j = k;
	k = j - N + 1;
	if (T <= j && k <= T)
	{
		return Side_5(j, -(N - 1), N - 1, T);
	}
	j = k;
	k = j - N + 1;
	return Side_6(j, 0, N - 1, T);
}
void Push(int x, int y, int Co)
{
	Q[Qh].x = x;
	Q[Qh].Cost = Co;
	Q[Qh++].y = y;
	Qh %= 10009;
}
tt Pop()
{
	tt temp;
	temp = Q[Qt++];
	Qt %= 10009;
	return temp;
}
int IsEmpty()
{
	return Qh == Qt;
}
int Bfs(int st, int teR)
{
	int i, d, c;
	tt temp;
	for (i = 0; i <= B; i++)
	{
		Q[i].Cost = 0;
	}
	Qh = Qt = 0;
	F[co[st].x + 100][co[st].y + 100] = 1;
	Push(co[st].x, co[st].y, 0);
	while (!IsEmpty())
	{
		temp = Pop();
		for (i = 0; i < 12; i++)
		{
			c = temp.x + X[i];
			d = temp.y + Y[i];
			if (P[c + 100][d + 100] > B)
			{
				continue;
			}
			if (P[c + 100][d + 100] == teR)
			{
				return temp.Cost + 1;
			}
			if (F[c + 100][d + 100] == 0)
			{
				F[c + 100][d + 100] = 1;
				Push(c, d, temp.Cost + 1);
			}
		}
	}
	return -1;
}
void Set()
{
	ss p;
	int i, x, y;
	for (i = 2; i <= 10000; i++)
	{
		p = Cordinate(i);
		x = p.x + 100;
		y = p.y + 100;
		P[x][y] = i;
		co[i].x = p.x;
		co[i].y = p.y;
	}
}
void Cal()
{
	int i, st, des, m;
	for (i = 0; i < Obs; i++)
	{
		scanf("%d", &m);
		F[co[m].x + 100][co[m].y + 100] = 1;
	}
	scanf("%d%d", &st, &des);
	if (st == des)
	{
		printf("0\n");
		return;
	}
	if (F[co[des].x + 100][co[des].y + 100] == 1)
	{
		printf("Impossible.\n");
		return;
	}
	m = Bfs(st, des);
	if (m < 0)
	{
		printf("Impossible.\n");
	}
	else
	{
		printf("%d\n", m);
	}
}
int main()
{
	int i, j;
	Ini();
	Set();
	while (scanf("%d%d", &B, &Obs) == 2)
	{
		Cal();
		for (i = 0; i <= 215; i++)
			for (j = 0; j <= 215; j++)
			{
				F[i][j] = 0;
			}
	}
	return 0;
}
