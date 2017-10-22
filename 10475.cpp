#include <bits/stdc++.h>

using namespace std;

static char name[15][16], temp[16], graph[15][15];
static int ans[5], t, p, s;

int compare(const void *a, const void *b)
{
	const char *c, *d;
	int la, lb;
	c = (const char *)a;
	d = (const char *)b;
	la = strlen(c);
	lb = strlen(d);
	if (la > lb)
	{
		return -1;
	}
	else if (la < lb)
	{
		return 1;
	}
	else
	{
		return strcmp(c, d);
	}
}
int find(char *s)
{
	for (int i = 0; i < t; i++)
		if (strcmp(name[i], s) == 0)
		{
			return i;
		}
	return -1;
}
void DFS(int depth, int choose)
{
	ans[depth] = choose;
	int i, j;
	if (depth == s - 1)
	{
		for (i = 0; i <= depth; i++)
		{
			if (i)
			{
				printf(" ");
			}
			printf("%s", name[ans[i]]);
		}
		printf("\n");
		return;
	}
	for (i = choose + 1; i < t; i++)
	{
		for (j = 0; j <= depth; j++)
			if (!graph[ans[j]][i])
			{
				break;
			}
		if (j == depth + 1)
		{
			DFS(depth + 1, i);
		}
	}
}
int main()
{
	int times, i, j, caseno, a, b;
	scanf("%d", &times);
	for (caseno = 1; caseno <= times; caseno++)
	{
		printf("Set %d:\n", caseno);
		scanf("%d %d %d", &t, &p, &s);
		for (i = 0; i < t; i++)
		{
			scanf("%s", name + i);
			for (j = 0; name[i][j]; j++)
				if (isalpha(name[i][j]))
				{
					name[i][j] = toupper(name[i][j]);
				}
		}
		qsort(name, t, 16, compare);
		memset(graph, true, sizeof(graph));
		for (i = 0; i < p; i++)
		{
			scanf("%s", temp);
			for (j = 0; temp[j]; j++)
				if (isalpha(temp[j]))
				{
					temp[j] = toupper(temp[j]);
				}
			a = find(temp);
			scanf("%s", temp);
			for (j = 0; temp[j]; j++)
				if (isalpha(temp[j]))
				{
					temp[j] = toupper(temp[j]);
				}
			b = find(temp);
			if (a < b)
			{
				graph[a][b] = false;
			}
			else
			{
				graph[b][a] = false;
			}
		}
		for (i = 0; i < t; i++)
		{
			DFS(0, i);
		}
		puts("");
	}
	return 0;
}
