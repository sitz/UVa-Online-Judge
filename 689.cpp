#include <bits/stdc++.h>

using namespace std;

typedef struct
{
	int len;
	char *str;
} WORD;
WORD *word;
int n_word, max_word;
int isPali(char *s, int len)
{
	int l = 0, r = len - 1;
	while (l < r)
	{
		if (s[l] != s[r])
		{
			return 0;
		}
		l++, r--;
	}
	return 1;
}

int isExisted(char *s, int len)
{
	int flag = len % 2;
	int i;
	for (i = 0; i < n_word; i++)
	{
		if (word[i].len % 2 != flag)
		{
			continue;
		}
		int j = (word[i].len - len) / 2;
		if (memcmp(word[i].str + j, s, len) == 0)
		{
			return 1;
		}
	}
	return 0;
}

char *StrDup(char *s, int len)
{
	char *r = (char *)malloc(len + 1);
	memcpy(r, s, len);
	r[len] = 0;
	return r;
}

int Compare(void const *p1, void const *p2)
{
	return strcmp(((WORD *)p1)->str, ((WORD *)p2)->str);
}

char line[8192], test[8192];

int main()
{
	while (gets(line))
	{
		int i, j;
		for (i = j = 0; line[i]; i++)
			if ('a' <= line[i] && line[i] <= 'z')
			{
				test[j++] = line[i] + 'A' - 'a';
			}
			else if ('A' <= line[i] && line[i] <= 'Z')
			{
				test[j++] = line[i];
			}
		test[j] = 0;
		n_word = 0, max_word = 32;
		word = (WORD *)malloc(32 * sizeof(WORD));
		int len = strlen(test);
		for (i = len; i >= 3; i--)
			for (j = 0; j + i <= len; j++)
			{
				if (!isPali(test + j, i))
				{
					continue;
				}
				if (isExisted(test + j, i))
				{
					continue;
				}
				if (n_word == max_word)
					max_word += 32,
							word = (WORD *)realloc(word, max_word * sizeof(WORD));
				word[n_word].len = i;
				word[n_word].str = StrDup(test + j, i);
				n_word++;
			}
		qsort(word, n_word, sizeof(WORD), Compare);
		for (i = 0; i < n_word; i++)
		{
			if (i)
			{
				putchar(' ');
			}
			printf(word[i].str);
			free(word[i].str);
		}
		putchar('\n');
		free(word);
	}
}
