#include <bits/stdc++.h>

using namespace std;

/*
395
Board Silly
*/
char R[] = "ABCDEFGH";
char C[] = "12345678";
char B[10][10], pie, opo;
char M[100][10];
int rp, cp, dgp1, dgp2, in;
int com(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}
void ReadCase()
{
	int i;
	char temp[2];
	for (i = 1; i < 8; i++)
	{
		scanf("%s", B[i]);
	}
	scanf("%s", temp);
	pie = temp[0];
	opo = 'O';
	if (pie == 'O')
	{
		opo = 'X';
	}
}
void Count(int r, int c)
{
	int i, j;
	rp = cp = dgp1 = dgp2 = 1;
	for (i = r - 1; i >= 0; i--)
		if (B[i][c] != '.')
		{
			rp++;
		}
	for (i = r + 1; i < 8; i++)
		if (B[i][c] != '.')
		{
			rp++;
		}
	for (i = c + 1; i < 8; i++)
		if (B[r][i] != '.')
		{
			cp++;
		}
	for (i = c - 1; i >= 0; i--)
		if (B[r][i] != '.')
		{
			cp++;
		}
	i = r - 1;
	j = c - 1;
	while (i >= 0 && j >= 0)
	{
		if (B[i][j] != '.')
		{
			dgp2++;
		}
		i--;
		j--;
	}
	i = r + 1;
	j = c + 1;
	while (i < 8 && j < 8)
	{
		if (B[i][j] != '.')
		{
			dgp2++;
		}
		i++;
		j++;
	}
	i = r - 1;
	j = c + 1;
	while (i >= 0 && j < 8)
	{
		if (B[i][j] != '.')
		{
			dgp1++;
		}
		i--;
		j++;
	}
	i = r + 1;
	j = c - 1;
	while (i < 8 && j >= 0)
	{
		if (B[i][j] != '.')
		{
			dgp1++;
		}
		i++;
		j--;
	}
}
void u_l_dg(int r, int c)
{
	int tr, tc, i, p, q;
	tr = r - dgp2;
	tc = c - dgp2;
	if (tr < 0 || tc < 0)
	{
		return;
	}
	if (B[tr][tc] == pie)
	{
		return;
	}
	p = r - 1;
	q = c - 1;
	for (i = 0; i < dgp2 - 1; i++)
	{
		if (B[p][q] == opo)
		{
			return;
		}
		p--;
		q--;
	}
	M[in][0] = R[r];
	M[in][1] = C[c];
	M[in][2] = '-';
	M[in][3] = R[tr];
	M[in][4] = C[tc];
	M[in++][5] = NULL;
}
void l_r_dg(int r, int c)
{
	int tr, tc, i, p, q;
	tr = r + dgp2;
	tc = c + dgp2;
	if (tr >= 8 || tc >= 8)
	{
		return;
	}
	if (B[tr][tc] == pie)
	{
		return;
	}
	p = r + 1;
	q = c + 1;
	for (i = 0; i < dgp2 - 1; i++)
	{
		if (B[p][q] == opo)
		{
			return;
		}
		p++;
		q++;
	}
	M[in][0] = R[r];
	M[in][1] = C[c];
	M[in][2] = '-';
	M[in][3] = R[tr];
	M[in][4] = C[tc];
	M[in++][5] = NULL;
}
void u_r(int r, int c)
{
	int tr, i, p, q;
	tr = r - rp;
	if (tr < 0)
	{
		return;
	}
	if (B[tr][c] == pie)
	{
		return;
	}
	p = r - 1;
	q = c;
	for (i = 0; i < rp - 1; i++)
	{
		if (B[p][q] == opo)
		{
			return;
		}
		p--;
	}
	M[in][0] = R[r];
	M[in][1] = C[c];
	M[in][2] = '-';
	M[in][3] = R[tr];
	M[in][4] = C[c];
	M[in++][5] = NULL;
}
void l_r(int r, int c)
{
	int tr, i, p, q;
	tr = r + rp;
	if (tr >= 8)
	{
		return;
	}
	if (B[tr][c] == pie)
	{
		return;
	}
	p = r + 1;
	q = c;
	for (i = 0; i < rp - 1; i++)
	{
		if (B[p][q] == opo)
		{
			return;
		}
		p++;
	}
	M[in][0] = R[r];
	M[in][1] = C[c];
	M[in][2] = '-';
	M[in][3] = R[tr];
	M[in][4] = C[c];
	M[in++][5] = NULL;
}
void r_c(int r, int c)
{
	int tc, i, p;
	tc = c + cp;
	if (tc >= 8)
	{
		return;
	}
	if (B[r][tc] == pie)
	{
		return;
	}
	p = c + 1;
	for (i = 0; i < cp - 1; i++)
	{
		if (B[r][p] == opo)
		{
			return;
		}
		p++;
	}
	M[in][0] = R[r];
	M[in][1] = C[c];
	M[in][2] = '-';
	M[in][3] = R[r];
	M[in][4] = C[tc];
	M[in++][5] = NULL;
}
void l_c(int r, int c)
{
	int tc, i, p;
	tc = c - cp;
	if (tc < 0)
	{
		return;
	}
	if (B[r][tc] == pie)
	{
		return;
	}
	p = c - 1;
	for (i = 0; i < cp - 1; i++)
	{
		if (B[r][p] == opo)
		{
			return;
		}
		p--;
	}
	M[in][0] = R[r];
	M[in][1] = C[c];
	M[in][2] = '-';
	M[in][3] = R[r];
	M[in][4] = C[tc];
	M[in++][5] = NULL;
}
void u_r_dg(int r, int c)
{
	int tr, tc, i, p, q;
	tr = r - dgp1;
	tc = c + dgp1;
	if (tr < 0 || tc >= 8)
	{
		return;
	}
	if (B[tr][tc] == pie)
	{
		return;
	}
	p = r - 1;
	q = c + 1;
	for (i = 0; i < dgp1 - 1; i++)
	{
		if (B[p][q] == opo)
		{
			return;
		}
		p--;
		q++;
	}
	M[in][0] = R[r];
	M[in][1] = C[c];
	M[in][2] = '-';
	M[in][3] = R[tr];
	M[in][4] = C[tc];
	M[in++][5] = NULL;
}
void l_l_dg(int r, int c)
{
	int tr, tc, i, p, q;
	tr = r + dgp1;
	tc = c - dgp1;
	if (tr >= 8 || tc < 0)
	{
		return;
	}
	if (B[tr][tc] == pie)
	{
		return;
	}
	p = r + 1;
	q = c - 1;
	for (i = 0; i < dgp1 - 1; i++)
	{
		if (B[p][q] == opo)
		{
			return;
		}
		p++;
		q--;
	}
	M[in][0] = R[r];
	M[in][1] = C[c];
	M[in][2] = '-';
	M[in][3] = R[tr];
	M[in][4] = C[tc];
	M[in++][5] = NULL;
}
void Print()
{
	int i;
	if (!in)
	{
		printf("No moves are possible\n");
		return;
	}
	qsort(M, in, sizeof(M[0]), com);
	for (i = 0; i < in; i++)
	{
		printf("%s\n", M[i]);
	}
}
void Cal()
{
	int i, j;
	in = 0;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (B[i][j] == pie)
			{
				Count(i, j);
				u_l_dg(i, j);
				u_r(i, j);
				u_r_dg(i, j);
				r_c(i, j);
				l_r_dg(i, j);
				l_r(i, j);
				l_l_dg(i, j);
				l_c(i, j);
			}
		}
	}
	Print();
}
int main()
{
	int f = 0;
	while (scanf("%s", B[0]) != EOF)
	{
		if (f++)
		{
			putchar('\n');
		}
		ReadCase();
		Cal();
	}
	return 0;
}
