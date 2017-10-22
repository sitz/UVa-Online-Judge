#include <bits/stdc++.h>

using namespace std;

char ss[100], temp[100], fg[100];
int R, len;

int com(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}

void recur(int n, int lvl)
{
	temp[lvl] = ss[n];
	fg[n] = 1;
	if (lvl == R - 1)
	{
		temp[lvl + 1] = '\0';
		puts(temp);
		fg[n] = 0;
		return;
	}
	if (lvl == len - 1)
	{
		fg[n] = 0;
		return;
	}
	for (int i = n + 1; i < len; i++)
	{
		if (fg[i - 1] == 0 && ss[i] == ss[i - 1])
		{
			continue;
		}
		recur(i, lvl + 1);
	}
	fg[n] = 0;
}

void cal()
{
	int i;
	len = strlen(ss);
	qsort(ss, len, sizeof(char), com);
	for (i = 0; i <= len - R; i++)
	{
		if (i && ss[i] == ss[i - 1])
		{
			continue;
		}
		recur(i, 0);
	}
}

int main()
{
	char input[100];
	while (gets(input))
	{
		sscanf(input, "%s%d", ss, &R);
		cal();
	}
	return 0;
}
