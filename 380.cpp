#include <bits/stdc++.h>

using namespace std;

#define MAXN 10002

struct xx
{
	int st, end, des;
};
struct ss
{
	xx list[111];
	int ind;
} Call[MAXN];
int M[10003], Num[MAXN], tn;
char Fg[MAXN];

void ReadCase()
{
	int a, b, c, d, u, v;
	tn = 1;
	while (1)
	{
		scanf("%d", &a);
		if (!a)
			break;
		u = M[a];
		if (!u)
		{
			u = tn++;
			Num[tn - 1] = a;
			M[a] = tn - 1;
		}
		scanf("%d%d%d", &b, &c, &d);
		v = M[d];
		if (!v)
		{
			v = tn++;
			Num[tn - 1] = d;
			M[d] = tn - 1;
		}
		Call[u].list[Call[u].ind].des = v;
		Call[u].list[Call[u].ind].st = b;
		Call[u].list[Call[u].ind++].end = c + b;
	}
}
int Recur(int u, int time)
{
	int i;
	if (Fg[u])
		return 10000;
	Fg[u] = 1;
	for (i = 0; i < Call[u].ind; i++)
		if (time >= Call[u].list[i].st && time <= Call[u].list[i].end)
			return Recur(Call[u].list[i].des, time);
	return u;
}
void Cal()
{
	int n, u, t, d, v;
	while (1)
	{
		scanf("%d", &t);
		if (t == 9000)
			break;
		scanf("%d", &n);
		u = M[n];
		if (u)
		{
			d = Recur(u, t);
			v = Num[d];
		}
		else
			v = n;

		if (d == 10000)
			printf("AT %.4d CALL TO %.4d RINGS 9999\n", t, n);
		else
			printf("AT %.4d CALL TO %.4d RINGS %.4d\n", t, n, v);

		for (t = 1; t <= tn; t++)
			Fg[t] = 0;
	}
}
void Free()
{
	int i;
	for (i = 0; i < 10000; i++)
		M[i] = 0;
	for (i = 0; i <= tn; i++)
		Call[i].ind = 0;
}

int main()
{
	int ks, sys = 1;
	printf("CALL FORWARDING OUTPUT\n");
	scanf("%d", &ks);
	while (ks--)
	{
		ReadCase();
		printf("SYSTEM %d\n", sys++);
		Cal();
		Free();
	}
	printf("END OF OUTPUT\n");
	return 0;
}
