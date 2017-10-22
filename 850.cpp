#include <bits/stdc++.h>

using namespace std;

/**
850
**/
#define MAXN 102
char STR[MAXN][82];
char key[] = "the quick brown fox jumps over the lazy dog";
int W, l;
struct ss
{
	int replace;
	char c;
} V[30];
int MATCH(char temp[])
{
	char dummy[100];
	int i, j, k, m = 0;
	strcpy(dummy, temp);
	for (i = 0; i < 30; i++)
	{
		V[i].c = V[i].replace = 0;
	}
	for (i = 0; dummy[i]; i++)
	{
		if (isalpha(dummy[i]))
		{
			k = dummy[i] - 'a';
			if (key[m] == ' ')
			{
				m++;
			}
			j = key[m] - 'a';
			if (V[k].c == 0)
			{
				V[k].c = 1;
				V[k].replace = j;
				dummy[i] = key[m];
			}
			else
			{
				j = V[k].replace + 'a';
				dummy[i] = j;
			}
			m++;
			if (m > l)
			{
				return 0;
			}
		}
	}
	if (m < l)
	{
		return 0;
	}
	if (strcmp(dummy, key) == 0)
	{
		return 1;
	}
	return 0;
}
void Cal()
{
	int i, j, m;
	for (i = 0; i < W; i++)
	{
		for (j = 0; STR[i][j]; j++)
		{
			if (STR[i][j] == ' ')
			{
				printf(" ");
				continue;
			}
			m = STR[i][j] - 'a';
			printf("%c", V[m].replace + 'a');
		}
		putchar('\n');
	}
}
int main()
{
	char input[100];
	int kase, i, f = 0;
	l = strlen(key);
	gets(input);
	sscanf(input, "%d", &kase);
	gets(input);
	while (kase--)
	{
		W = 0;
		f = 0;
		while (1)
		{
			gets(STR[W]);
			for (i = 0; STR[W][i]; i++)
				if (STR[W][i] == '\n')
				{
					STR[W][i] = NULL;
				}
			if (strlen(STR[W]) <= 0)
			{
				break;
			}
			if (f)
			{
				W++;
				continue;
			}
			if ((strlen(STR[W]) == l) && MATCH(STR[W]) == 1)
			{
				f = 1;
			}
			W++;
		}
		if (!f)
		{
			printf("No solution.\n");
		}
		else
		{
			Cal();
		}
		if (kase)
		{
			putchar('\n');
		}
	}
	return 0;
}
