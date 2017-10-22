#include <bits/stdc++.h>

using namespace std;

#define MAX 1003

char strf[MAX][21], strs[MAX][21], str[MAX];
int LIS[MAX][MAX], fg, fl, sl;

void Sep(char ss[][21], int &n)
{
	char *p;
	p = strtok(str, " ");
	while (p)
	{
		strcpy(ss[n++], p);
		p = strtok(NULL, " ");
	}
}
int Dp()
{
	int i, j;
	if (sl == 1 || fl == 1)
	{
		return 0;
	}
	for (i = 1; i < fl; i++)
	{
		for (j = 1; j < sl; j++)
		{
			if (!strcmp(strf[i], strs[j]))
			{
				LIS[i][j] = LIS[i - 1][j - 1] + 1;
			}
			else
			{
				LIS[i][j] = max(LIS[i][j - 1], LIS[i - 1][j]);
			}
		}
	}
	return LIS[fl - 1][sl - 1];
}
int Ini()
{
	int i;
	for (i = 0; str[i]; i++)
	{
		if (str[i] == '\n')
		{
			str[i] = NULL;
			break;
		}
		if (!isalpha(str[i]) && !isdigit(str[i]))
		{
			str[i] = ' ';
		}
	}
	if (strlen(str) == 0)
	{
		return 1;
	}
	return 0;
}
void Cal()
{
	int k;
	k = Dp();
	printf("Length of longest match: %d\n", k);
}

int main()
{
	int i, k = 1;
	while (gets(str))
	{
		printf("%2d. ", k++);
		i = Ini();
		fl = sl = 1;
		if (i)
		{
			gets(str);
			printf("Blank!\n");
			continue;
		}
		Sep(strf, fl);
		gets(str);
		i = Ini();
		if (i)
		{
			printf("Blank!\n");
			continue;
		}
		Sep(strs, sl);
		Cal();
	}
	return 0;
}
