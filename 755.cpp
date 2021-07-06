#include <bits/stdc++.h>

using namespace std;

/***************
Title : 787-3279
   No : 755
***************/
#define max 100009
char a[400];
char digit[max][10];
char tele_num[max][50];
int N;
int sort_function(const void *a, const void *b)
{
	return (strcmp((char *)a, (char *)b));
}
int value()
{
	int p;
	char i, m = '2';
	char j = 2, k = 0;
	for (i = 'A'; i < 'Z'; i++)
	{
		if (i == 'Q')
		{
			continue;
		}
		k++;
		if (k % 4 == 0)
		{
			m++;
			k = 1;
		}
		p = i;
		a[p] = m;
	}
	return 0;
}
int convert()
{
	int i, j, k, m;
	for (i = 0; i < N; i++)
	{
		k = 0;
		for (j = 0; tele_num[i][j]; j++)
		{
			if (isdigit(tele_num[i][j]))
			{
				digit[i][k] = tele_num[i][j];
			}
			else if (isalpha(tele_num[i][j]))
			{
				m = tele_num[i][j];
				digit[i][k] = a[m];
			}
			else
			{
				continue;
			}
			k++;
		}
		digit[i][k] = NULL;
	}
	return 0;
}
int calculate()
{
	char temp[10];
	int i, j, c, k;
	k = 0;
	for (i = 0; i < N;)
	{
		strcpy(temp, digit[i]);
		c = 1;
		for (++i; !strcmp(temp, digit[i]) && i < N; i++)
		{
			c++;
		}
		if (c >= 2)
		{
			k = 1;
			for (j = 0; temp[j]; j++)
			{
				printf("%c", temp[j]);
				if (j == 2)
				{
					printf("-");
				}
			}
			printf(" %d\n", c);
			c = 1;
		}
	}
	if (!k)
	{
		printf("No duplicates.\n");
	}
	return 0;
}
int main()
{
	int i, pp;
	char f[120], qq[120];
	value();
	gets(qq);
	sscanf(qq, "%d", &pp);
	gets(qq);
	while (pp--)
	{
		gets(f);
		sscanf(f, "%d", &N);
		for (i = 0; i < N; i++)
		{
			gets(tele_num[i]);
		}
		convert();
		qsort((void *)digit, N, sizeof(digit[0]), sort_function);
		calculate();
		if (pp)
		{
			printf("\n");
			gets(f);
		}
	}
	return 0;
}
