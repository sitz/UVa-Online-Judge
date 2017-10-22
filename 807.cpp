#include <bits/stdc++.h>

using namespace std;

#define BUFFER 80
char mat[10][5000], final[10][BUFFER + 4], printmode = 0;
long end_[10], max_;

long mat_write(int row, unsigned long long n, long long b)
{
	long i, k = 0, poww = 0, x = 0;
	unsigned long long stack[800], indx[800];
	if (max_ < row)
	{
		max_ = row;
	}
	if (row)
	{
		for (; end_[row] < end_[row - 1]; end_[row]++)
		{
			mat[row][end_[row]] = ' ';
		}
	}
	while (n)
	{
		if (n % b)
		{
			stack[k] = n % b, indx[k] = poww;
			k++;
		}
		poww++;
		n /= b;
	}
	if (printmode)
	{
		putchar('(');
	}
	for (i = k - 1; i >= 0; i--)
	{
		if (stack[i])
		{
			if (stack[i] > 1 && indx[i])
			{
				if (printmode)
				{
					printf("%llu*", stack[i]);
				}
				end_[row] += sprintf(mat[row] + end_[row], "%llu*", stack[i]);
			}
			if (indx[i])
			{
				if (printmode)
				{
					printf("%llu", b);
				}
				end_[row] += sprintf(mat[row] + end_[row], "%llu", b);
			}
			else
			{
				if (printmode)
				{
					printf("%llu", stack[i]);
				}
				end_[row] += sprintf(mat[row] + end_[row], "%llu", stack[i]);
			}
			if (indx[i] > 1)
			{
				if (printmode)
				{
					putchar('^');
				}
				x = mat_write(row + 1, indx[i], b);
				while (end_[row] < x)
				{
					mat[row][end_[row]++] = ' ';
				}
			}
			if (i)
			{
				end_[row] += sprintf(mat[row] + end_[row], "+");
				if (printmode)
				{
					putchar('+');
				}
			}
		}
	}
	if (printmode)
	{
		putchar(')');
	}
	mat[row][end_[row]] = 0;
	if (row == 0 && printmode)
	{
		puts("");
	}
	return end_[row];
}

void print_mat(unsigned long long n, int limit)
{
	int i, j = 0, x, t, part, prevj = 0, newj = 0, flag = 1;
	if (printmode)
	{
		for (i = max_; i + 1; i--)
		{
			puts(mat[i]);
		}
		puts("");
	}
	for (part = 1; flag; part++)
	{
		j = prevj;
		for (x = 0; mat[0][j] && x < limit; j++, x++)
		{
			if (mat[0][j] == '+')
			{
				newj = j;
			}
		}
		if (mat[0][j] == 0 || mat[0][j] == '+')
		{
			newj = j;
		}
		if (mat[0][j] == 0)
		{
			flag = 0;
		}
		for (i = max_; i + 1; i--)
		{
			if (part == 1 && i == 0)
			{
				sprintf(final[0], "%llu = ", n);
			}
			else
				for (t = 0; t + limit < BUFFER; t++)
				{
					sprintf(& final[i][t], " ");
				}
			for (j = prevj, x = BUFFER - limit; j < newj && end_[i] > j; j++, x++)
			{
				sprintf(& final[i][x], "%c", mat[i][j]);
			}
			final[i][x] = 0;
			for (x = strlen(final[i]) - 1; final[i][x] == ' '; x--)
			{
				final[i][x] = 0;
			}
			puts(final[i]);
		}
		prevj = newj;
		if (flag)
		{
			puts("");
		}
	}
}

int main()
{
	unsigned long long n, b;
	int i, test = 0;
	while (scanf("%llu%llu", &n, &b) != EOF && (n || b))
	{
		if (test)
		{
			puts("--------------------------------------------------------------------------------");
		}
		for (i = 0; i < 10; i++)
		{
			mat[i][0] = end_[i] = 0;
		}
		max_ = 0;
		printf("%llu in complete base %llu:\n", n, b);
		i = sprintf(mat[0], "%llu = ", n);
		mat_write(0, n, b);
		printf("\n");
		print_mat(n, BUFFER - i);
		test++;
	}
	return 0;
}
