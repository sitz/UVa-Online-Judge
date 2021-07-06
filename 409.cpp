#include <bits/stdc++.h>

using namespace std;

char sen[22][72], w[72][70], word[22][22];
int c, wo, s;

void word_cnt(char a[])
{
	int i, j, k, len;
	c = 0;
	len = strlen(a);
	for (i = 0; a[i];)
	{
		if (isalpha(a[i]))
		{
			k = 0;
			for (j = i; isalpha(a[j]) && a[j]; j++)
			{
				w[c][k++] = tolower(a[j]);
			}
			w[c][k] = '\0';
			c++;
			if (j >= len)
			{
				break;
			}
			i = j;
			for (i++; !isalpha(a[i]) && a[i]; i++)
				;
		}
		else
		{
			i++;
		}
	}
}

int com()
{
	int i, cnt, j;
	cnt = 0;
	for (i = 0; i < c; i++)
	{
		for (j = 0; j < wo; j++)
		{
			if (!strcmp(w[i], word[j]))
			{
				cnt++;
			}
		}
	}
	return cnt;
}

int calc()
{
	int i, j, k, f[30], p[30], m;
	int max = 0;
	k = 0;
	for (i = 1; i <= s; i++)
	{
		word_cnt(sen[i]);
		m = com();
		if (m > max)
		{
			k = 0;
			f[k] = m;
			p[k] = i;
			max = m;
			k++;
		}
		else if (m >= max)
		{
			f[k] = m;
			p[k++] = i;
		}
	}
	for (i = 0; i < k; i++)
	{
		printf("%s\n", sen[p[i]]);
	}
	printf("\n");
	return 0;
}

int main()
{
	int i, t = 1;
	while (scanf("%d%d", &wo, &s) == 2)
	{
		for (i = 0; i < wo; i++)
		{
			scanf("%s", word[i]);
		}
		for (i = 0; i <= s; i++)
		{
			gets(sen[i]);
		}
		printf("Excuse Set #%d\n", t++);
		calc();
	}
	return 0;
}
