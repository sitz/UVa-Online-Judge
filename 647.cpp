#include <bits/stdc++.h>

using namespace std;

#define MAXN 102

struct ss
{
	int chutes, ladders;
	int loss, win;
} B[MAXN];
struct xx
{
	int loss;
	int poss;
} pp[15];
int T[1005], tt, P;

void Cal()
{
	int i, rhead = 0, n, pos;
	while (1)
	{
		for (i = 0; i < P; i++)
		{
			if (pp[i].loss)
			{
				pp[i].loss = 0;
				continue;
			}
			n = T[rhead++];
			pos = n + pp[i].poss;
			if (pos == 100)
			{
				printf("%d\n", i + 1);
				return;
			}
			else if (pos > 100)
			{
				continue;
			}
			else if (B[pos].chutes)
			{
				pp[i].poss = B[pos].chutes;
				if (B[pp[i].poss].win)
				{
					i--;
				}
				if (B[pp[i].poss].loss)
				{
					pp[i].loss = 1;
				}
			}
			else if (B[pos].ladders)
			{
				pp[i].poss = B[pos].ladders;
				if (B[pp[i].poss].win)
				{
					i--;
				}
				if (B[pp[i].poss].loss)
				{
					pp[i].loss = 1;
				}
			}
			else if (B[pos].loss)
			{
				pp[i].loss = 1;
				pp[i].poss = pos;
			}
			else if (B[pos].win)
			{
				pp[i].poss = pos;
				i--;
			}
			else
			{
				pp[i].poss = pos;
			}
		}
	}
}

int main()
{
	int n, m;
	tt = 0;
	while (scanf("%d", &n) && n)
	{
		T[tt++] = n;
	}
	while (scanf("%d", &P) && P)
	{
		while (scanf("%d%d", &n, &m))
		{
			if (!n && !m)
			{
				break;
			}
			if (n < m)
			{
				B[n].ladders = m;
			}
			else
			{
				B[n].chutes = m;
			}
		}
		while (scanf("%d", &n) && n)
		{
			if (n < 0)
			{
				n = -n;
				B[n].loss = 1;
			}
			else
			{
				B[n].win = 1;
			}
		}
		Cal();
		memset(B, 0, sizeof(int) * MAXN);
		memset(pp, 0, sizeof(int) * 15);
	}
	return 0;
}
