#include <bits/stdc++.h>

using namespace std;

#define maxn 10000

char the_index[maxn][22], text[100000], sep[maxn][22];
int total, ts;
vector<int> V[maxn];

int com(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}
int Empty(char ss[])
{
	int i;
	for (i = 0; ss[i]; i++)
	{
		if (ss[i] == '\n')
		{
			ss[i] = NULL;
			break;
		}
	}
	if (strlen(ss) == 0)
		return 1;
	return 0;
}
void Sep()
{
	int i, j, k;
	ts = 0;
	char temp[112];
	for (i = 0; text[i];)
	{
		if (!isalpha(text[i]) && !isdigit(text[i]))
		{
			i++;
			continue;
		}
		k = 0;
		for (j = i; text[j] && (isalpha(text[j]) || isdigit(text[j])); j++)
			temp[k++] = toupper(text[j]);
		temp[k] = NULL;
		strcpy(sep[ts++], temp);
		i = j;
	}
}
void Cal(int line)
{
	int i, *j;
	Sep();
	qsort(sep, ts, sizeof(sep[0]), com);
	for (i = 0; i < total; i++)
	{
		j = (int *)bsearch(&the_index[i], sep, ts, sizeof(the_index[0]), com);
		if (j)
			V[i].push_back(line);
	}
}
void Print()
{
	int i, j, k, pre, f;
	for (i = 0; i < total; i++)
	{
		f = 1;
		if (V[i].size() == 0)
			continue;
		for (j = 0; the_index[i][j]; j++)
		{
			if (!isdigit(the_index[i][j]) && !isalpha(the_index[i][j]))
			{
				f = 0;
				break;
			}
		}
		printf("%s", the_index[i]);
		if (V[i].size() == 0)
		{
			printf("\n");
			continue;
		}
		pre = V[i][0];
		printf(" %d", V[i][0]);
		for (j = 1; j < V[i].size(); j++)
		{
			if (V[i][j] != pre + 1)
			{
				printf(", %d", V[i][j]);
				pre = V[i][j];
			}
			else
			{
				printf("-");
				while (j < V[i].size() && V[i][j] == pre + 1)
				{
					pre = V[i][j];
					j++;
				}
				j--;
				printf("%d", pre);
			}
		}
		printf("\n");
	}
}
void Free()
{
	int i;
	for (i = 0; i < total; i++)
		V[i].clear();
}

int main()
{
	int line, i, ks = 1;
	total = 0;
	while (gets(the_index[total++]))
	{
		if (Empty(the_index[total - 1]))
			break;
		for (i = 0; the_index[total - 1][i]; i++)
			the_index[total - 1][i] = toupper(the_index[total - 1][i]);
		while (gets(the_index[total]))
		{
			if (Empty(the_index[total]))
				break;
			for (i = 0; the_index[total][i]; i++)
				the_index[total][i] = toupper(the_index[total][i]);
			total++;
		}
		qsort(the_index, total, sizeof(the_index[0]), com);
		line = 1;
		while (1)
		{
			gets(text);
			if (Empty(text))
				break;
			Cal(line);
			line++;
		}
		printf("Case %d\n", ks++);
		Print();
		Free();
		total = 0;
		printf("\n");
	}
	return 0;
}
