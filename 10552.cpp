#include <bits/stdc++.h>

using namespace std;

typedef char str[101];

struct pp
{
	str name, p1, p2, b, d;
} p[1000];
int np, first;

str buf, cmd, name, p1, p2, b, d;

void fix(char *s)
{
	while (s[strlen(s) - 1] == ' ')
	{
		s[strlen(s) - 1] = 0;
	}
}
void ancestors(str n, int ind)
{
	int i, j;
	for (i = 0; i < np && strcmp(n, p[i].name); i++)
	{
	}
	if (ind)
	{
		for (j = 0; j < ind; j++)
		{
			printf(" ");
		}
		printf("%s", n);
		if (i < np)
		{
			printf(" %s -", p[i].b);
			if (*p[i].d)
			{
				printf(" %s", p[i].d);
			}
		}
		printf("\n");
	}
	if (i < np)
	{
		ancestors(p[i].p1, ind + 2);
		ancestors(p[i].p2, ind + 2);
	}
}
void descendants(str n, int ind)
{
	int i, j;
	for (i = 0; i < np; i++)
	{
		if (!strcmp(n, p[i].p1) || !strcmp(n, p[i].p2))
		{
			for (j = 0; j < ind; j++)
			{
				printf(" ");
			}
			printf("%s %s -", p[i].name, p[i].b);
			if (*p[i].d)
			{
				printf(" %s", p[i].d);
			}
			printf("\n");
			descendants(p[i].name, ind + 2);
		}
	}
}
int cmp(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}
int main()
{
	int i;
	while (gets(buf))
	{
		*cmd = *name = *d = *p1 = *p2 = 0;
		sscanf(buf, "%s %[^:] : %[^:] : %[^:] : %[^:]", cmd, name, d, p1, p2);
		fix(name);
		fix(p1);
		fix(p2);
		fix(d);
		if (!strcmp(cmd, "BIRTH"))
		{
			strcpy(p[np].name, name);
			strcpy(p[np].b, d);
			if (strcmp(p1, p2) < 0)
			{
				strcpy(p[np].p1, p1);
				strcpy(p[np].p2, p2);
			}
			else
			{
				strcpy(p[np].p1, p2);
				strcpy(p[np].p2, p1);
			}
			np++;
			qsort(p, np, sizeof(struct pp), cmp);
		}
		else if (!strcmp(cmd, "DEATH"))
		{
			for (i = 0; i < np && strcmp(name, p[i].name); i++)
				;
			strcpy(p[i].d, d);
		}
		else if (!strcmp(cmd, "ANCESTORS"))
		{
			if (first++)
			{
				printf("\n");
			}
			printf("ANCESTORS of %s\n", name);
			ancestors(name, 0);
		}
		else if (!strcmp(cmd, "DESCENDANTS"))
		{
			if (first++)
			{
				printf("\n");
			}
			printf("DESCENDANTS of %s\n", name);
			descendants(name, 2);
		}
		else if (!strcmp(cmd, "QUIT"))
		{
			exit(0);
		}
		else
		{
			printf("invalid command %s\n", cmd);
		}
	}
	printf("missing QUIT command \n");
}
