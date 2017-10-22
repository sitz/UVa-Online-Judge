#include <bits/stdc++.h>

using namespace std;

#define maxn 35

typedef unsigned long long ss;

ss Com[maxn][maxn], Val[maxn][maxn], G[maxn], total, N, K;
char CFg[maxn][maxn], Fg[maxn], A[maxn][maxn], BB[maxn][maxn];
set<string> S;

int com(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}
ss Combination(ss n, ss r)
{
	ss d;
	if (n == r)
		return 1;
	if (r == 1)
		return n;
	if (r == 0)
		return 1;
	if (CFg[n][r] == 1)
		return Com[n][r];
	CFg[n][r] = 1;
	d = Combination(n - 1, r) + Combination(n - 1, r - 1);
	Com[n][r] = d;
	return d;
}
void Gen()
{
	ss i, j, k, n, r, p;
	for (i = 2; i <= 15; i++)
	{
		Val[i][1] = 1;
		n = 2 * i - 1;
		r = i - 1;
		p = 2;
		for (j = 2 * i; j <= 30; j += i)
		{
			k = Combination(n, r);
			Val[i][p] = Val[i][p - 1] * k;
			p++;
			n += i;
		}
	}
	for (i = 16; i <= 30; i++)
		Val[i][1] = 1;
}
int Rem(int n, int lim)
{
	int i, c = 0;
	for (i = n; i < lim; i++)
		if (Fg[i] == 0)
			c++;
	return c;
}
int Rem1(int n, int tg)
{
	int i, c = 0;
	for (i = n; i < tg; i++)
		c += G[i];
	return c;
}
void Process(int tg)
{
	int i, j;
	string st = "";
	for (i = 0; i < tg; i++)
		strcpy(BB[i], A[i]);
	qsort(BB, tg, sizeof(BB[0]), com);
	st += BB[0];
	for (i = 1; i < tg; i++)
	{
		st += " ";
		st += BB[i];
	}
	S.insert(st);
}
void Recur(int n, int g, int tg, int level, string st, int lim, int ck)
{
	int i, j, ng = g, k;
	char ch = 'A';
	if (G[g] == level)
	{
		strcpy(A[g], st.c_str());
		st = "";
		ng = g + 1;
		level = 0;
	}
	if (ng + 1 > tg)
	{
		if (ck)
		{
			printf("%s", A[0]);
			for (k = 1; k < tg; k++)
				printf(" %s", A[k]);
			cout << endl;
		}
		else
			Process(tg);
		return;
	}
	for (i = 0; i < lim; i++)
	{
		if (Fg[i] == 0)
		{
			if (level > 0)
			{
				if (i <= n)
					continue;
				else
				{
					k = Rem(i, lim) + level;
					j = G[ng];
					if (j > k)
						return;
					ch = i + 'A';
					Fg[i] = 1;
					Recur(i, ng, tg, level + 1, st + ch, lim, ck);
					Fg[i] = 0;
				}
			}
			else
			{
				k = Rem(i, lim);
				j = Rem1(ng, tg);
				if (j > k)
					return;
				ch = 'A' + i;
				Fg[i] = 1;
				Recur(i, ng, tg, level + 1, st + ch, lim, ck);
				Fg[i] = 0;
			}
		}
	}
}
void Recur2(int n, int level, int ter, string st, int tg, int r)
{
	int i;
	char ch;
	Fg[n] = 1;
	if (level == ter)
	{
		strcpy(A[0], st.c_str());
		Recur(0, 1, tg, 0, "", N, 0);
		Fg[n] = 0;
		return;
	}
	for (i = n + 1; i < N; i++)
	{
		ch = 'A' + i;
		Recur2(i, level + 1, ter, st + ch, tg, r);
	}
	Fg[n] = 0;
}
void Count()
{
	ss d, k;
	if (N == K || K > N || K == 1)
	{
		printf("1\n");
		return;
	}
	d = N / K;
	if (N % K == 0)
	{
		total = Val[K][d];
		printf("%llu\n", Val[K][d]);
		return;
	}
	k = Combination(N, N % K);
	total = Val[K][d] * k;
	printf("%llu\n", Val[K][d] * k);
}
void Print()
{
	ss d, r, tg, i;
	string st;
	char ch = 'A';
	set<string>::iterator p;
	d = N / K;
	r = N % K;
	if (r == 0)
	{
		for (tg = 0; tg < d; tg++)
			G[tg] = K;
		Recur(0, 0, d, 0, "", N, 1);
		return;
	}
	tg = d + 1;
	G[0] = r;
	for (i = 1; i < tg; i++)
		G[i] = K;
	for (i = 0; i + r - 1 < N; i++, ch++)
	{
		st = ch;
		Recur2(i, 1, r, st, tg, r);
	}
	for (p = S.begin(); p != S.end(); p++)
	{
		st = *p;
		printf("%s\n", st.c_str());
	}
	S.clear();
}
void Cal(string Cmd)
{
	ss d;
	char ch;
	Count();
	if (Cmd == "COUNT")
		return;
	if (K >= N)
	{
		for (ch = 'A', d = 0; d < N; ch++, d++)
			printf("%c", ch);
		printf("\n");
		return;
	}
	if (K == 1)
	{
		printf("A");
		for (ch = 'B', d = 1; d < N; d++, ch++)
			printf(" %c", ch);
		printf("\n");
		return;
	}
	Print();
}

int main()
{
	char Cmd[15];
	Gen();
	while (scanf("%s", Cmd))
	{
		if (!strcmp(Cmd, "END"))
		{
			break;
		}
		scanf("%llu%llu", &N, &K);
		total = 0;
		Cal(Cmd);
	}
	return 0;
}
