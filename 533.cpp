#include <bits/stdc++.h>

using namespace std;

char buf[1005];
int lx, ly, rx, ry, *px, *py, nxt[1005], stk[1005];

void deal(char *s)
{
	int i, j, k;
	for (i = 0, j = 0, k = 0; s[i]; i++)
	{
		if (s[i] != ' ')
		{
			if (s[i] == '(')
			{
				stk[k++] = j;
			}
			else
			{
				if (s[i] == ')')
				{
					nxt[stk[--k]] = j + 1;
				}
				nxt[j] = j + 1;
			}
			s[j++] = s[i];
		}
	}
	s[j] = 0;
}

void recursion(char *s, int left, int right)
{
	int i, x, y;
	if (s[left] == '(' && nxt[left] > right)
	{
		recursion(s, left + 1, right - 1);
		return;
	}
	for (i = left; i <= right; i = nxt[i])
	{
		if (s[i] == '+' || s[i] == '-')
		{
			recursion(s, left, i - 1);
			x = *px;
			y = *py;
			recursion(s, i + 1, right);
			if (s[i] == '+')
			{
				x += *px;
				y += *py;
			}
			else
			{
				x -= *px;
				y -= *py;
			}
			*px = x;
			*py = y;
			return;
		}
	}
	for (i = left; i <= right; i = nxt[i])
	{
		if (s[i] == '*')
		{
			recursion(s, left, i - 1);
			x = *px;
			y = *py;
			recursion(s, i + 1, right);
			x = *px * y + *py * x;
			y *= *py;
			*px = x;
			*py = y;
			return;
		}
	}
	if (s[left] == 'x')
	{
		*px = 1;
		*py = 0;
	}
	else
	{
		*px = 0;
		sscanf(s + left, "%d", py);
	}
}

int main()
{
	int cas;
	char *lptr, *rptr;
	cas = 0;
	while (gets(buf))
	{
		px = &lx;
		py = &ly;
		lptr = strtok(buf, "=");
		deal(lptr);
		recursion(lptr, 0, strlen(lptr) - 1);
		px = &rx;
		py = &ry;
		rptr = strtok(NULL, "=");
		deal(rptr);
		recursion(rptr, 0, strlen(rptr) - 1);
		lx -= rx;
		ry -= ly;
		if (cas)
		{
			printf("\n");
		}
		printf("Equation #%d\n", ++cas);
		if (lx)
		{
			printf("x = %.6lf\n", (double)ry / lx);
		}
		else
		{
			if (!ry)
			{
				printf("Infinitely many solutions.\n");
			}
			else
			{
				printf("No solution.\n");
			}
		}
	}
	return 0;
}
