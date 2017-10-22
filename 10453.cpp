#include <bits/stdc++.h>

using namespace std;

/*
10739
String to Palindrome
*/
#define MAXN 1002
struct ss
{
	int cost, cmd;
	int pi, pj;
} Cost[MAXN][MAXN];
int len, ft, re;
char Str[MAXN];
char F[MAXN], R[MAXN];
int recur(int r, int c)
{
	int x;
	if (r >= c)
	{
		return 0;
	}
	if (Cost[r][c].cost)
	{
		return Cost[r][c].cost;
	}
	if (Str[r] == Str[c])
	{
		Cost[r][c].cost = recur(r + 1, c - 1);
		Cost[r][c].cmd = 3;
		Cost[r][c].pi = r + 1;
		Cost[r][c].pj = c - 1;
	}
	else
	{
		Cost[r][c].cost = recur(r, c - 1) + 1;
		Cost[r][c].cmd = 1;
		Cost[r][c].pi = r;
		Cost[r][c].pj = c - 1;
		x = recur(r + 1, c) + 1;
		if (x < Cost[r][c].cost)
		{
			Cost[r][c].cost = x;
			Cost[r][c].cmd = 2;
			Cost[r][c].pi = r + 1;
			Cost[r][c].pj = c;
		}
	}
	return Cost[r][c].cost;
}
int Gen(int r, int c)
{
	if (r == c)
	{
		F[ft++] = Str[r];
		return 1;
	}
	if (Cost[r][c].cmd == 1)
	{
		F[ft++] = Str[c];
		R[re++] = Str[c];
	}
	else if (Cost[r][c].cmd == 2)
	{
		F[ft++] = Str[r];
		R[re++] = Str[r];
	}
	else if (Cost[r][c].cmd == 3)
	{
		F[ft++] = Str[r];
		R[re++] = Str[r];
		if (c == r + 1)
		{
			return 1;
		}
	}
	if (Gen(Cost[r][c].pi, Cost[r][c].pj))
	{
		return 1;
	}
	return 0;
}
void Cal()
{
	int i;
	len = strlen(Str) - 1;
	printf("%d ", recur(0, len));
	ft = re = 0;
	Gen(0, len);
	for (i = 0; i < ft; i++)
	{
		printf("%c", F[i]);
	}
	for (i = re - 1; i >= 0; i--)
	{
		printf("%c", R[i]);
	}
	printf("\n");
}
void Free()
{
	int i, j;
	for (i = 0; i <= len; i++)
		for (j = 0; j <= len; j++)
		{
			Cost[i][j].cost = 0;
		}
}
int main()
{
	while (gets(Str))
	{
		Cal();
		Free();
	}
	return 0;
}
