#include <bits/stdc++.h>

double A[205][205], B[205], x[205], y[205];
int pi[205], n;

int LUP_Decomp()
{
	int i, j, k, k1;
	double p, absol;
	for (i = 0; i < n; i++)
	{
		pi[i] = i;
	}
	for (k = 0; k < n; k++)
	{
		p = 0;
		for (i = k, k1 = i; i < n; i++)
		{
			absol = A[i][k];
			if (absol < 0)
			{
				absol = -absol;
			}
			if (absol > p)
			{
				p = absol, k1 = i;
			}
		}
		if (fabs(p) < 1e-6)
		{
			return 0;
		}
		if (k != k1)
		{
			pi[k] ^= pi[k1] ^= pi[k] ^= pi[k1];
		}
		for (i = 0; i < n; i++)
		{
			p = A[k][i];
			A[k][i] = A[k1][i];
			A[k1][i] = p;
		}
		for (i = k + 1; i < n; i++)
		{
			A[i][k] = A[i][k] / A[k][k];
			for (j = k + 1; j < n; j++)
			{
				A[i][j] = A[i][j] - A[i][k] * A[k][j];
			}
		}
	}
	return 1;
}

void LUP_Solve()
{
	int i, j;
	char one[50], two[50];
	if (LUP_Decomp() == 0)
	{
		puts("No solution");
		return;
	}
	for (i = 0; i < n; i++)
	{
		y[i] = 0;
		for (j = 0; j < i; j++)
		{
			y[i] = y[i] + A[i][j] * y[j];
		}
		y[i] = B[pi[i]] - y[i];
	}
	for (i = n - 1; i + 1; i--)
	{
		x[i] = 0;
		for (j = i + 1; j < n; j++)
		{
			x[i] = x[i] + A[i][j] * x[j];
		}
		x[i] = (y[i] - x[i]) / A[i][i];
	}
	for (i = 0; i < n; i += 2)
	{
		sprintf(one, "%.1lf", x[i]);
		sprintf(two, "%.1lf", x[i + 1]);
		if (strcmp(one, "-0.0") == 0)
		{
			strcpy(one, "0.0");
		}
		if (strcmp(two, "-0.0") == 0)
		{
			strcpy(two, "0.0");
		}
		printf("(%s,%s)\n", one, two);
	}
}

int main()
{
	char inp[100000], *ptr, *ptr1;
	double temp[205];
	int i, j, k, kase = 0;
	n = 0;
	while (gets(inp))
	{
		for (ptr = inp, j = 0; *ptr; ptr++)
		{
			if (*ptr == ' ' || *ptr == '(' || *ptr == ')' || *ptr == ',')
			{
				continue;
			}
			else
			{
				for (ptr1 = ptr; *ptr1 != ' ' && *ptr1 != '(' && *ptr1 != ')' && *ptr1 != ','; ptr1++)
					;
				*ptr1 = 0;
				temp[j++] = atof(ptr);
				ptr = ptr1;
			}
		}
		for (i = 0; i + 2 < j; i += 2)
		{
			A[n + 1][i + 1] = A[n][i] = temp[i];
			A[n + 1][i] = temp[i + 1], A[n][i + 1] = -temp[i + 1];
		}
		B[n] = temp[i], B[n + 1] = temp[i + 1];
		n += 2;
		for (k = 2; k + 2 < j; k += 2)
		{
			gets(inp);
			for (ptr = inp, j = 0; *ptr; ptr++)
			{
				if (*ptr == ' ' || *ptr == '(' || *ptr == ')' || *ptr == ',')
				{
					continue;
				}
				else
				{
					for (ptr1 = ptr; *ptr1 != ' ' && *ptr1 != '(' && *ptr1 != ')' && *ptr1 != ','; ptr1++)
						;
					*ptr1 = 0;
					temp[j++] = atof(ptr);
					ptr = ptr1;
				}
			}
			for (i = 0; i + 2 < j; i += 2)
			{
				A[n + 1][i + 1] = A[n][i] = temp[i];
				A[n + 1][i] = temp[i + 1], A[n][i + 1] = -temp[i + 1];
			}
			B[n] = temp[i], B[n + 1] = temp[i + 1];
			n += 2;
		}
		if (kase)
		{
			puts("");
		}
		if (n != i)
		{
			puts("No solution");
		}
		else
		{
			LUP_Solve();
		}
		n = 0;
		kase++;
		if (getchar() == EOF)
		{
			break;
		}
	}
	return 0;
}
/*
(1,0) (2,0) (3,0) (14,0)
(2,0) (3,0) (4,0) (20,0)
(3,0) (4,0) (4,0) (23,0)

(1,0) (2,0) (3,0) (4,0)
(2,0) (4,0) (6,0) (8,0)
(3,0) (4,0) (5,0) (26,0)

(1,0) (2,0) (3,0) (14, 0)
(1,0) (1,0) (1,0) (06,0)
(1,0) (1,0) (-1, 0) (0,0)

(1,  9) (6, -3) (-9, 4)
(-11, -1) ( 7, 5) (16, -36)
*/
