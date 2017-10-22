#include <bits/stdc++.h>

using namespace std;

#define MAX 85
#define MIN(a, b) (a >= b ? b : a)

const char ss[3][3] = {"C", "I", "D"};
char st[MAX], ter[MAX];
int l1, l2, ind, cnt;

struct dyn {int r, c, com, val;} M[MAX][MAX];

void IniC()
{
	int i;
	M[0][0].val = 0;
	for (i = 1; st[i]; i++)
	{
		M[0][i].val = i;
		M[0][i].r = 0;
		M[0][i].c = i - 1;
		M[0][i].com = 2;
	}
}
void IniR()
{
	int i;
	for (i = 1; ter[i]; i++)
	{
		M[i][0].val = i;
		M[i][0].r = i - 1;
		M[i][0].c = 0;
		M[i][0].com = 1;
	}
}
void Select(int r, int c, int rp, int Ins, int Delt)
{
	int nr, nc, cm, temp, val;
	temp = MIN(rp, Ins);
	if (rp <= Ins)
	{
		nr = r - 1;
		nc = c - 1;
		cm = 0;
		val = rp;
	}
	else
	{
		nr = r - 1;
		nc = c;
		cm = 1;
		val = Ins;
	}
	if (temp > Delt)
	{
		nr = r;
		nc = c - 1;
		cm = 2;
		val = Delt;
	}
	M[r][c].val = val;
	M[r][c].r = nr;
	M[r][c].c = nc;
	M[r][c].com = cm;
	if (ter[r] == st[c])
	{
		M[r][c].com = 4;
	}
}
void Dynamic()
{
	int i, j, k, val, p, q;
	l1 = strlen(&ter[1]);
	l2 = strlen(&st[1]);
	for (i = 1; ter[i]; i++)
	{
		for (j = 1; st[j]; j++)
		{
			val = (ter[i] == st[j]) ? 0 : 1;
			k = M[i - 1][j - 1].val + val;
			p = M[i - 1][j].val + 1;
			q = M[i][j - 1].val + 1;
			Select(i, j, k, p, q);
		}
	}
}
void Path(int r, int c)
{
	if (r == 0 && c == 0)
	{
		return;
	}
	Path(M[r][c].r, M[r][c].c);
	if (M[r][c].com == 2)
	{
		printf("%d Delete %d\n", cnt++, ind);
	}
	else if (M[r][c].com == 1)
	{
		printf("%d Insert %d,%c\n", cnt++, ind, ter[r]);
	}
	else if (M[r][c].com == 0)
	{
		printf("%d Replace %d,%c\n", cnt++, ind, ter[r]);
	}
	if (M[r][c].com != 2)
	{
		ind++;
	}
}

int main()
{
	int f = 0;
	while (gets(&st[1]))
	{
		gets(&ter[1]);
		if (f++)
		{
			printf("\n");
		}
		IniR();
		IniC();
		Dynamic();
		ind = cnt = 1;
		printf("%d\n", M[l1][l2].val);
		Path(l1, l2);
	}
	return 0;
}
