#include <bits/stdc++.h>

using namespace std;

/*
584
Bowling
*/
struct ss
{
	int r1, r2;
	int Type;
} fra[15];
char str[100];
char temp[30];
void Set()
{
	int i, r = 0, x, d = 0;
	for (i = 0; str[i] && str[i] != '\n'; i += 2)
	{
		temp[d++] = str[i];
	}
	temp[d] = NULL;
	for (i = 0; i < d;)
	{
		if (temp[i] == 'X')
		{
			fra[r].Type = 2;
			fra[r].r1 = 10;
			i++;
			r++;
		}
		else
		{
			fra[r].r1 = temp[i] - '0';
			x = 10 - fra[r].r1;
			fra[r].r2 = temp[i + 1] - '0';
			if (temp[i + 1] == '/')
			{
				fra[r].Type = 1;
				fra[r].r2 = x;
			}
			i += 2;
			r++;
		}
	}
}
int Count(int n)
{
	int c = 0;
	if (fra[n].Type == 0)
	{
		return fra[n].r1 + fra[n].r2;
	}
	if (fra[n].Type == 1)
	{
		c = 10 + fra[n + 1].r1;
	}
	else
	{
		c = 10 + fra[n + 1].r1;
		if (fra[n + 1].Type == 2)
		{
			c += fra[n + 2].r1;
		}
		else
		{
			c += fra[n + 1].r2;
		}
	}
	return c;
}
void Cal()
{
	int i, j = 0;
	for (i = 0; i < 10; i++)
	{
		j += Count(i);
	}
	printf("%d\n", j);
}
void Ini()
{
	int i;
	for (i = 0; i < 15; i++)
	{
		fra[i].r1 = fra[i].r2 = fra[i].Type = 0;
	}
}
int main()
{
	while (gets(str))
	{
		if (!strcmp(str, "Game Over"))
		{
			break;
		}
		Ini();
		Set();
		Cal();
	}
	return 0;
}
