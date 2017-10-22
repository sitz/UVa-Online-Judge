#include <bits/stdc++.h>

using namespace std;

char str[2008], buf[2008];
int n, l, target, lst[15];

int digit(char c)
{
	return c >= '0' && c <= '9';
}

int recursion(int left, int right)
{
	int i, p;
	for (i = right, p = 0; i >= left; i--)
	{
		if (str[i] == '(')
		{
			p++;
		}
		else if (str[i] == ')')
		{
			p--;
		}
		else if (p == 0 && digit(str[i]) == 0)
		{
			break;
		}
	}
	if (i < left)
	{
		if (str[left] == '(')
		{
			return recursion(left + 1, right - 1);
		}
		sscanf(str + left, "%d", &i);
		return i;
	}
	else
	{
		/*printf("range %d to %d ii %d, left %d, right %d.\n", left, right, i, recursion(left, i-1), recursion(i+1, right));*/
		if (str[i] == '+')
		{
			return recursion(left, i - 1) + recursion(i + 1, right);
		}
		else if (str[i] == '-')
		{
			return recursion(left, i - 1) - recursion(i + 1, right);
		}
		return recursion(left, i - 1) * recursion(i + 1, right);
	}
}

int dfs(int depth)
{
	if (depth == n)
	{
		return recursion(0, l - 1) == target;
	}
	str[lst[depth]] = '*';
	if (dfs(depth + 1))
	{
		return 1;
	}
	str[lst[depth]] = '+';
	if (dfs(depth + 1))
	{
		return 1;
	}
	str[lst[depth]] = '-';
	if (dfs(depth + 1))
	{
		return 1;
	}
	return 0;
}

int main()
{
	int cas;
	char *p, *q;
	cas = 0;
	while (gets(buf))
	{
		if (strcmp(buf, "0") == 0)
		{
			break;
		}
		sscanf(buf, "%d", &target);
		strtok(buf, "=");
		for (p = strtok(NULL, "="), q = str; *p; p++)
		{
			if (*p == ' ')
			{
				if (q > str && (digit(*(q - 1)) || *(q - 1) == ')'))
				{
					*(q++) = ' ';
				}
			}
			else if (*p == '(')
			{
				if (q > str && (digit(*(q - 1)) || *(q - 1) == ')'))
				{
					*(q++) = ' ';
				}
				*(q++) = *p;
			}
			else if (*p == ')')
			{
				if (q > str && *(q - 1) == ' ')
				{
					q--;
				}
				*(q++) = *p;
			}
			else
			{
				if (q > str && *(q - 1) == ')')
				{
					*(q++) = ' ';
				}
				*(q++) = *p;
			}
		}
		*q = 0;
		l = q - str;
		for (n = 0, p = str; *p; p++)
		{
			if (*p == ' ')
			{
				lst[n++] = p - str;
				*p = '*';
			}
		}
		/*printf("**%s**\n", str);*/
		printf("Equation #%d:\n", ++cas);
		if (dfs(0))
		{
			printf("%d=%s\n\n", target, str);
		}
		else
		{
			printf("Impossible.\n\n");
		}
	}
	return 0;
}
