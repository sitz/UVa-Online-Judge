#include <bits/stdc++.h>

using namespace std;

#define MAXN 1090

char fg[MAXN][MAXN];

void Mark(char aa[], char bb[])
{
	int i, st, end, m, h;
	aa[2] = ' ';
	sscanf(aa, "%d%d", &h, &m);
	st = h * 60 + m;
	bb[2] = ' ';
	sscanf(bb, "%d%d", &h, &m);
	end = h * 60 + m;
	for (i = st; i < end; i++)
	{
		fg[i][i + 1] = 1;
	}
}

void Sep(char ss[])
{
	char *p, aa[20], bb[20];
	p = strtok(ss, " ");
	strcpy(aa, p);
	p = strtok(NULL, " ");
	strcpy(bb, p);
	Mark(aa, bb);
}

void Cal()
{
	int i, max = 0, st, end, j;
	for (i = 600; i < 1080;)
	{
		if (fg[i][i + 1] == 1)
		{
			i++;
			continue;
		}
		else
		{
			j = 0;
			end = i;
			while (fg[i][i + 1] == 0 && i < 1080)
			{
				j++;
				i++;
			}
			if (j > max)
			{
				st = end;
				max = j;
			}
		}
	}
	printf("the longest nap starts at %d:%02d and will last for ", st / 60, st % 60);
	if (max < 60)
		printf("%d minutes.\n", max);
	else
		printf("%d hours and %d minutes.\n", max / 60, max % 60);
}

void Free()
{
	int i;
	for (i = 600; i <= 1080; i++)
	{
		fg[i][i + 1] = 0;
	}
}

int main()
{
	char input[500];
	int k, f = 1;
	while (gets(input))
	{
		sscanf(input, "%d", &k);
		while (k--)
		{
			gets(input);
			Sep(input);
		}
		printf("Day #%d: ", f++);
		Cal();
		Free();
	}
	return 0;
}
