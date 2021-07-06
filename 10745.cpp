#include <bits/stdc++.h>

using namespace std;

/*
10745
Dominant String
*/
#define MAXN 15002
struct ss
{
	int len;
	int fre[27];
	char dominant;
} word[MAXN];
char W[MAXN][12];
char Rec[MAXN][12];
int total, rec;
int com(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}
int Dominant(int p, int q)
{
	int i, j;
	for (i = 0; i < W[q][i]; i++)
	{
		j = W[q][i] - 'a';
		if (word[p].fre[j] < word[q].fre[j])
		{
			return 0;
		}
	}
	return 1;
}
void Cal()
{
	int i, j, k, x = 0;
	qsort(W, total, sizeof(W[0]), com);
	for (i = 0; i < total; i++)
	{
		word[i].len = strlen(W[i]);
		for (j = 0; W[i][j]; j++)
		{
			k = W[i][j] - 'a';
			word[i].fre[k]++;
		}
	}
	for (i = 0; i + 1 < total; i++)
	{
		if (word[i].dominant == 1)
		{
			continue;
		}
		for (j = i + 1; j < total; j++)
		{
			if (word[j].dominant == 1)
			{
				continue;
			}
			if (word[i].len > word[j].len)
			{
				if (Dominant(i, j))
				{
					word[j].dominant = 1;
				}
			}
			else if (word[i].len < word[j].len)
			{
				if (Dominant(j, i))
				{
					word[i].dominant = 1;
					if (word[i].len == word[j].len)
					{
						word[j].dominant = 1;
					}
				}
			}
		}
	}
	for (i = 0; i < total; i++)
		if (word[i].dominant == 0)
		{
			printf("%s\n", W[i]);
		}
}
int main()
{
	total = 0;
	while (gets(W[total]))
	{
		total++;
	}
	Cal();
	return 0;
}
