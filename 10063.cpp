#include <bits/stdc++.h>

using namespace std;

char str[15], dummy[15];
void Insert(char c, char ss[], int p)
{
	int i, l = strlen(ss);
	strcpy(dummy, ss);
	if (p == l)
	{
		dummy[l] = c;
		dummy[l + 1] = NULL;
		return;
	}
	for (i = l; i > p; i--)
	{
		dummy[i] = dummy[i - 1];
	}
	dummy[p] = c;
	dummy[l + 1] = NULL;
}
void recur(int level, char ss[])
{
	char temp[100];
	strcpy(temp, ss);
	if (level == strlen(str))
	{
		puts(ss);
		return;
	}
	for (int i = 0; i <= level; i++)
	{
		Insert(str[level], temp, i);
		recur(level + 1, dummy);
		strcpy(dummy, temp);
	}
}

int main()
{
	int f = 0;
	char temp[15];
	while (scanf("%s", str) != EOF)
	{
		if (f++)
		{
			putchar('\n');
		}
		temp[0] = str[0];
		temp[1] = NULL;
		recur(1, temp);
	}
	return 0;
}
