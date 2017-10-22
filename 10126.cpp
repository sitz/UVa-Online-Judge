#include <bits/stdc++.h>

using namespace std;

#define MAXN 20002

char word[MAXN][40], str[100000];
int tw, fre;

int com(const void *a, const void *b)
{
	return (strcmp((char *)a, (char *)b));
}

void Sep()
{
	int i, j, k;
	char temp[25];
	for (i = 0; str[i];)
	{
		if (!isalpha(str[i]))
		{
			i++;
			continue;
		}
		k = 0;
		for (j = i; str[j] && isalpha(str[j]); j++)
		{
			temp[k++] = tolower(str[j]);
		}
		i = j;
		temp[k] = NULL;
		strcpy(word[tw++], temp);
	}
}

void Cal()
{
	int i, j, k, f = 1;
	qsort((void *)word, tw, sizeof(word[0]), com);
	for (i = 0; i < tw;)
	{
		k = 1;
		for (j = i + 1; j < tw && !strcmp(word[i], word[j]); j++)
		{
			k++;
		}
		i = j;
		if (k == fre)
		{
			f = 0;
			printf("%s\n", word[i - 1]);
		}
	}
	if (f)
	{
		printf("There is no such word.\n");
	}
}

int main()
{
	int k = 0, m = 0;
	while (scanf("%s", str) != EOF)
	{
		fre = atoi(str);
		tw = 0;
		while (1)
		{
			scanf("%s", str);
			if (!strcmp(str, "EndOfText"))
				break;
			Sep();
			m++;
		}
		if (k++)
			printf("\n");
		Cal();
	}
	return 0;
}
