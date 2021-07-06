#include <bits/stdc++.h>

using namespace std;

#define maxn 15000000

char F[maxn + 4], B[7][7], C[7][7];
struct ss
{
	int d1, d2, d3, d4;
	int m1, m2, m3, m4;
};
struct xyz
{
	int r, c;
};
int BlankR()
{
	int i, j;
	for (i = 1; i <= 5; i++)
		for (j = 1; j <= 5; j++)
			if (B[i][j] == 1)
				return i - 1;
	return i - 1;
}
int BlankC()
{
	int i, j;
	for (i = 1; i <= 5; i++)
		for (j = 1; j <= 5; j++)
			if (B[j][i] == 1)
				return i - 1;
	return i - 1;
}
void Move(int r, int c)
{
	int i, j;
	for (i = 1; i <= 5; i++)
		for (j = 1; j <= 5; j++)
		{
			C[i][j] = 0;
			if (B[i][j])
				C[i - r][j - c] = 1;
		}
}
ss Dec()
{
	int i, j, sum = 0, p = 1, k, l, r, c;
	int sum2, sum3, sum4, m1, m2, m3, m4;
	sum2 = sum3 = sum4 = 0;
	m1 = m2 = m3 = m4 = 0;
	ss temp;
	r = BlankR();
	if (r == 5)
	{
		temp.d1 = 0;
		return temp;
	}
	c = BlankC();
	Move(r, c);
	for (i = 1, k = 5; i <= 5; i++, k--)
	{
		for (j = 1, l = 5; j <= 5; j++, l--)
		{
			sum += C[i][j] * p;
			sum2 += C[j][k] * p;
			sum3 += C[k][l] * p;
			sum4 += C[l][i] * p;
			m1 += C[i][l] * p;
			m2 += C[l][k] * p;
			m3 += C[k][j] * p;
			m4 += C[j][i] * p;
			p *= 2;
		}
	}
	temp.d1 = sum;
	temp.d2 = sum2;
	temp.d3 = sum3;
	temp.d4 = sum4;
	temp.m1 = m1;
	temp.m2 = m2;
	temp.m3 = m3;
	temp.m4 = m4;
	return temp;
}
void Fill(int r, int c, int des, int dir)
{
	int i;
	if (dir == 1)
		for (i = c; i <= des; i++)
			B[r][i] = 0;
	else
		for (i = r; i <= des; i++)
			B[i][c] = 0;
}
void UnFill(int r, int c, int des, int dir)
{
	int i;
	if (dir == 1)
		for (i = c; i <= des; i++)
			B[r][i] = 1;
	else
		for (i = r; i <= des; i++)
			B[i][c] = 1;
}
int Recur(int r, int c, int des, int dir)
{
	int i, j, k, d, fg = 0, lim = 0, res = 0;
	ss dc;
	Fill(r, c, des, dir);
	dc = Dec();
	if (!dc.d1)
	{
		UnFill(r, c, des, dir);
		return 2;
	}
	if (dc.d1 <= maxn)
	{
		if (F[dc.d1] > 0)
		{
			UnFill(r, c, des, dir);
			return F[dc.d1];
		}
	}
	if (dc.d2 <= maxn)
	{
		if (F[dc.d2] > 0)
		{
			UnFill(r, c, des, dir);
			return F[dc.d2];
		}
	}
	if (dc.d3 <= maxn)
	{
		lim = 1;
		if (F[dc.d3] > 0)
		{
			UnFill(r, c, des, dir);
			return F[dc.d3];
		}
	}
	if (dc.d4 <= maxn)
	{
		lim = 1;
		if (F[dc.d4] > 0)
		{
			UnFill(r, c, des, dir);
			return F[dc.d4];
		}
	}
	if (dc.m1 <= maxn)
	{
		if (F[dc.m1] > 0)
		{
			UnFill(r, c, des, dir);
			return F[dc.m1];
		}
	}
	if (dc.m2 <= maxn)
	{
		if (F[dc.m2] > 0)
		{
			UnFill(r, c, des, dir);
			return F[dc.m2];
		}
	}
	if (dc.m3 <= maxn)
	{
		lim = 1;
		if (F[dc.m3] > 0)
		{
			UnFill(r, c, des, dir);
			return F[dc.m3];
		}
	}
	if (dc.m4 <= maxn)
	{
		if (F[dc.m4] > 0)
		{
			UnFill(r, c, des, dir);
			return F[dc.m4];
		}
	}
	for (i = 1; i <= 5; i++)
	{
		for (j = 1; j <= 5; j++)
		{
			if (B[i][j] == 1)
			{
				for (k = j; k <= 5 && B[i][k]; k++)
				{
					d = Recur(i, j, k, 1);
					if (d == 1)
					{
						fg = 1;
						break;
					}
				}
				if (fg)
					break;
				for (k = i + 1; k <= 5 && B[k][j]; k++)
				{
					d = Recur(i, j, k, 2);
					if (d == 1)
					{
						fg = 1;
						break;
					}
				}
			}
		}
		if (fg)
			break;
	}
	if (fg)
	{
		if (dc.d1 <= maxn)
			F[dc.d1] = 2;
		if (dc.d2 <= maxn)
			F[dc.d2] = 2;
		if (dc.d3 <= maxn)
			F[dc.d3] = 2;
		if (dc.d4 <= maxn)
			F[dc.d4] = 2;
		if (dc.m1 <= maxn)
			F[dc.m1] = 2;
		if (dc.m2 <= maxn)
			F[dc.m2] = 2;
		if (dc.m3 <= maxn)
			F[dc.m3] = 2;
		if (dc.m4 <= maxn)
			F[dc.m4] = 2;
	}
	else
	{
		if (dc.d1 <= maxn)
			F[dc.d1] = 1;
		if (dc.d2 <= maxn)
			F[dc.d2] = 1;
		if (dc.d3 <= maxn)
			F[dc.d3] = 1;
		if (dc.d4 <= maxn)
			F[dc.d4] = 1;
		if (dc.m1 <= maxn)
			F[dc.m1] = 1;
		if (dc.m2 <= maxn)
			F[dc.m2] = 1;
		if (dc.m3 <= maxn)
			F[dc.m3] = 1;
		if (dc.m4 <= maxn)
			F[dc.m4] = 1;
	}
	UnFill(r, c, des, dir);
	if (fg)
		return 2;
	return 1;
}
bool Res(ss l)
{
	int r;
	if (l.d1 <= maxn)
		if (F[l.d1])
			r = F[l.d1];
		else if (l.d2 <= maxn)
			if (F[l.d2])
				r = F[l.d2];
			else if (l.d3 <= maxn)
				if (F[l.d3])
					r = F[l.d3];
				else if (l.d4 <= maxn)
					if (F[l.d4])
						r = F[l.d4];
					else if (l.m1 <= maxn)
						if (F[l.m1])
							r = F[l.m1];
						else if (l.m2 <= maxn)
							if (F[l.m2])
								r = F[l.m2];
							else if (l.m3 <= maxn)
								if (F[l.m3])
									r = F[l.m3];
								else if (l.m4 <= maxn)
									if (F[l.m4])
										r = F[l.m4];
	if (r == 2)
		printf("winning\n");
	if (r == 1)
		printf("losing\n");
	if (r == 1 || r == 2)
		return true;
	return false;
}
void Shift(int r, int c)
{
	int i, j;
	if (!r && !c)
		return;
	for (i = 1; i <= 5; i++)
		for (j = 1; j <= 5; j++)
			if (B[i][j] == 1)
			{
				B[i - r][j - c] = B[i][j];
				B[i][j] = 0;
			}
}
void Cal()
{
	int i, j, d, fg = 0, k, r, c;
	ss l;
	l = Dec();
	if (l.d1 == 33554431 || l.d1 == 0)
	{
		printf("winning\n");
		return;
	}
	if (Res(l))
		return;
	r = BlankR();
	c = BlankC();
	Shift(r, c);
	for (i = 1; i <= 5; i++)
	{
		for (j = 1; j <= 5; j++)
		{
			if (B[i][j] == 1)
			{
				for (k = j; k <= 5 && B[i][k]; k++)
				{
					d = Recur(i, j, k, 1);
					if (d == 1)
					{
						fg = 1;
						break;
					}
				}
				if (fg)
					break;
				for (k = i + 1; k <= 5 && B[k][j]; k++)
				{
					d = Recur(i, j, k, 2);
					if (d == 1)
					{
						fg = 1;
						break;
					}
				}
			}
		}
		if (fg)
			break;
	}
	printf(fg ? "winning\n" : "losing\n");
}

int main()
{
	int ks, i, j, l = 1;
	scanf("%d", &ks);
	while (ks--)
	{
		for (i = 1; i <= 5; i++)
		{
			for (j = 1; j <= 5; j++)
			{
				scanf("%d", &B[i][j]);
			}
		}
		Cal();
	}
	return 0;
}
