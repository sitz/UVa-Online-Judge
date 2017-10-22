#include <bits/stdc++.h>

using namespace std;

#define MAX 20
#define MIN 10
int printout(int, long, int);
int adderr(char[][12], char *, int);
long valid(char *);
int main()
{
	long zip[500], zip2[500], num, comp;
	int letters, bundles, prev, count;
	int flag, i, j, k, n, savi, nzip, nerr;
	char s[12], err[20][12];
	letters = bundles = 0;
	i = n = 0;
	printf("ZIP         LETTERS     BUNDLES\n\n");
	while (scanf("%s", s) == 1)
	{
		//s[strlen(s)-1] = '\0';
		if ((num = valid(s)) > 0)
		{
			zip[i++] = num;
		}
		else
		{
			n = adderr(err, s, n);
		}
	}
	nzip = i;
	nerr = n;
	for (i = 0; i < nzip - 1; ++i) /* sort the zips */
		for (j = 0; j < nzip - 1; ++j)
			if (zip[j] > zip[j + 1])
			{
				comp = zip[j];
				zip[j] = zip[j + 1];
				zip[j + 1] = comp;
			}
	i = prev = k = 0;
	flag = 0; /* first pass for 5-digit codes */
	while (i < nzip)
	{
		count = 0;
		comp = zip[i];
		savi = i;
		while (zip[i] == comp && i < nzip)
		{
			i++;
		}
		count = i - savi;
		if (count >= MIN)
		{
			letters += count;
			bundles += printout(count, comp, flag);
			for (j = prev; j < savi; ++j) /* copy nonbundled to zip2 */
			{
				zip2[k++] = zip[j];
			}
			prev = i;
		}
	} /* end while i < nzip  */
	for (j = prev; j < nzip; ++j)
	{
		zip2[k++] = zip[j]; /* end first pass */
	}
	putchar('\n');
	i = 0;
	nzip = k;
	flag = 1; /* 2nd pass for 3-digit codes */
	while (i < nzip)
	{
		savi = i;
		comp = zip2[i++] / 100;
		while (zip2[i] / 100 == comp && i < nzip)
		{
			i++;
		}
		count = i - savi;
		if (count >= MIN)
		{
			letters += count;
			bundles += printout(count, comp, flag);
			for (j = savi; j < i; ++j) /* zero out bundled positions */
			{
				zip2[j] = 0;
			}
		}
	} /* end while i < nzip and end of 2nd pass */
	putchar('\n');
	i = 0;
	while (i < nzip) /* last pass for first class zips */
	{
		while (zip2[i] == 0 && i < nzip)
		{
			i++;
		}
		comp = zip2[i++];
		count = 1;
		while (zip2[i] == comp && i < nzip)
		{
			count++;
			i++;
		}
		printf("%ld        %3d           0\n", comp, count);
		letters += count;
	} /* end while i < nzip and end last pass  */
	printf("\nTOTALS       %3d          %2d\n\n", letters, bundles);
	printf("INVALID ZIP CODES\n");
	for (n = 0; n < nerr; ++n)
	{
		printf("%s\n", err[n]);
	}
}
long valid(char *s)
{
	int i;
	if (strlen(s) != 5)
	{
		return -1;
	}
	for (i = 0; isdigit(s[i]); ++i)
		;
	if (i != 5) /* if < 5 it's nonnumeric */
	{
		return -1;
	}
	return atol(s); /* convert to numeric */
}
int printout(int count, long comp, int flag)
{
	int k, rem; /* k is no. bundles */
	k = count / MAX;
	rem = count % MAX;
	if (rem > 0)
	{
		k++;
	}
	if (flag == 1)
	{
		printf("%3ldxx", comp);
	}
	else
	{
		printf("%5ld", comp);
	}
	printf("        %3d          %2d\n", count, k);
	return k;
}
int adderr(char err[][12], char *s, int n)
{
	int i;
	for (i = 0; i < n; ++i)
		if (strcmp(err[i], s) == 0)
		{
			return n;
		}
	strcpy(err[n], s);
	/*  printf("%s   %s\n", err[n], s);   */
	return ++n;
}
