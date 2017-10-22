#include <bits/stdc++.h>

using namespace std;

#define MAXN 10005

char dic[MAXN][16];
int st[1000];
int wd, ind;

int in_del(char bb[], char ss[])
{
	int i, j, p = 0, d = 0, f;
	for (i = 0; ss[i]; i++)
	{
		f = 1;
		for (j = p; bb[j]; j++)
		{
			if (ss[i] == bb[j])
			{
				f = 0;
				p = j + 1;
				break;
			}
		}
		if (f)
			return 0;
	}
	return 1;
}
int Rep(char bb[], char ss[])
{
	int i, d;
	d = 0;
	for (i = 0; bb[i]; i++)
	{
		if (bb[i] != ss[i])
			d++;
		if (d > 1)
			return 0;
	}
	return 1;
}
void Cal(char ss[])
{
	int i;
	int l1, l2;
	l1 = strlen(ss);
	ind = 0;
	for (i = 0; i < wd; i++)
	{
		l2 = strlen(dic[i]);
		if (abs(l1 - l2) > 1)
			continue;
		if (!strcmp(ss, dic[i]))
		{
			printf("%s is correct\n", ss);
			return;
		}
		if ((l1 == l2) && Rep(ss, dic[i]))
			st[ind++] = i;
		if ((l1 > l2) && in_del(ss, dic[i]))
			st[ind++] = i;
		if ((l1 < l2) && in_del(dic[i], ss))
			st[ind++] = i;
	}
	printf("%s:", ss);
	for (i = 0; i < ind; i++)
		printf(" %s", dic[st[i]]);
	printf("\n");
}

int main()
{
	int kase;
	char temp[20];
	scanf("%d", &kase);
	while (kase--)
	{
		wd = 0;
		while (1)
		{
			scanf("%s", dic[wd]);
			if (!strcmp(dic[wd], "#"))
				break;
			wd++;
		}
		while (1)
		{
			scanf("%s", temp);
			if (!strcmp(temp, "#"))
				break;
			Cal(temp);
		}
		if (kase)
		{
			putchar('\n');
		}
	}
	return 0;
}
