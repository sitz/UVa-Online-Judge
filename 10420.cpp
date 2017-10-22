#include <bits/stdc++.h>

using namespace std;

char name[2009][80];
int n;

int sort_function(const void *a, const void *s)
{
	return (strcmp((char *)a, (char *)s));
}

int count()
{
	int i, c;
	char inter[80];
	qsort((void *)name, n, sizeof(name[0]), sort_function);
	for (i = 0; i < n;)
	{
		c = 1;
		strcpy(inter, name[i]);
		for (i++; !strcmp(inter, name[i]) && i < n; i++)
		{
			c++;
		}
		printf("%s %d\n", inter, c);
	}
	return 0;
}

int main()
{
	char mid[100];
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", name[i]);
		gets(mid);
	}
	count();
	return 0;
}
