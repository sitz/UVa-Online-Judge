#include <bits/stdc++.h>

using namespace std;

#define MAXN 10001

struct Tree
{
	char name[31];
	int cnt = 0;
} species[MAXN], a_tree;
Tree *the_tree;

char input[100];
int total, N;

int cmp(const void *a, const void *b)
{
	Tree *t1 = (Tree *)a;
	Tree *t2 = (Tree *)b;
	return strcmp(t1->name, t2->name);
}
int cmp_t(const Tree &t1, const Tree &t2)
{
	return strcmp(t1.name, t2.name) < 0;
}

int main()
{
	int T;
	scanf("%d", &T);
	gets(input);
	gets(input);
	while (T--)
	{
		total = 0;
		N = 0;
		while (gets(a_tree.name))
		{
			for (int i = 0; a_tree.name[i]; i++)
			{
				if (a_tree.name[i] == '\n')
				{
					a_tree.name[i] = '\0';
				}
			}
			if (strlen(a_tree.name) < 1)
			{
				break;
			}

			N++;

			the_tree = (Tree *)bsearch(&a_tree, species, total, sizeof(species[0]), cmp);
			if (the_tree != NULL)
			{
				the_tree->cnt++;
			}
			else
			{
				strcpy(species[total].name, a_tree.name);
				species[total].cnt++;
				total++;
				sort(species, species + total, cmp_t);
			}
		}

		for (int i = 0; i < total; i++)
		{
			printf("%s %.4lf\n", species[i].name, (species[i].cnt * 100.0f) / (double)N);
		}

		if (T)
		{
			printf("\n");
			for (int i = 0; i < MAXN; i++)
			{
				species[i].cnt = 0;
			}
		}
	}
	return 0;
}
