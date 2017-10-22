#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) (a > b ? a : b)

struct ss
{
	int ok;
	int heavy;
	int light;
} coin[15];

struct xx
{
	char aa[10];
	char bb[10];
	char cc[10];
} waight[4];

void MarkHeavy(char str[])
{
	int i, j;
	for (i = 0; str[i]; i++)
	{
		j = str[i] - 'A';
		coin[j].heavy++;
	}
}

void MarkLight(char str[])
{
	int i, j;
	for (i = 0; str[i]; i++)
	{
		j = str[i] - 'A';
		coin[j].light++;
	}
}

void MarkEqual(char str[])
{
	int i, j;
	for (i = 0; str[i]; i++)
	{
		j = str[i] - 'A';
		coin[j].ok = 1;
	}
}

void RemainEqual(char str1[], char str2[])
{
	int a[15] = {0};
	int i, j, k;
	for (i = 0; str2[i]; i++)
	{
		j = str1[i] - 'A';
		k = str2[i] - 'A';
		a[j] = a[k] = 1;
	}
	for (i = 0; i < 12; i++)
		if (a[i] == 0)
			coin[i].ok = 1;
}

void Cal()
{
	int i, rec, count = 0, rec2, max = 0, j;
	for (i = 0; i < 12; i++)
	{
		if (coin[i].light && coin[i].heavy)
			coin[i].ok = 1;
		if (coin[i].ok == 0)
		{
			count++;
			rec = i;
			j = MAX(coin[i].heavy, coin[i].light);
			if (j > max)
			{
				rec2 = i;
				max = j;
			}
		}
	}
	if (count == 1)
	{
		if (coin[rec].light)
			printf("%c is the counterfeit coin and it is light.\n", rec + 'A');
		else
			printf("%c is the counterfeit coin and it is heavy.\n", rec + 'A');
		return;
	}
	if (coin[rec2].light)
		printf("%c is the counterfeit coin and it is light.\n", rec2 + 'A');
	else
		printf("%c is the counterfeit coin and it is heavy.\n", rec2 + 'A');
}

void Free()
{
	int i;
	for (i = 0; i < 12; i++)
		coin[i].heavy = coin[i].light = coin[i].ok = 0;
}

int main()
{
	int kases, i;
	char aa[7], bb[7], cc[7];
	scanf("%d", &kases);
	while (kases--)
	{
		for (i = 0; i < 3; i++)
		{
			scanf("%s%s%s", aa, bb, cc);
			strcpy(waight[i].aa, aa);
			strcpy(waight[i].bb, bb);
			strcpy(waight[i].cc, cc);
			if (!strcmp(cc, "even"))
			{
				MarkEqual(aa);
				MarkEqual(bb);
			}
			else if (!strcmp(cc, "up"))
			{
				MarkHeavy(aa);
				MarkLight(bb);
				RemainEqual(aa, bb);
			}
			else
			{
				MarkLight(aa);
				MarkHeavy(bb);
				RemainEqual(aa, bb);
			}
		}
		Cal();
		Free();
	}
	return 0;
}
