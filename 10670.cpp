#include <bits/stdc++.h>

using namespace std;

int st, ter, ag, AB[102][2];

struct ss
{
	char nam[20];
	int cost;
} Ag[102];

int cmp(const void *a, const void *b)
{
	ss *x = (ss *)a;
	ss *y = (ss *)b;
	if (x->cost != y->cost)
	{
		return x->cost - y->cost;
	}
	return strcmp(x->nam, y->nam);
}
int Count(int a, int b)
{
	int cost = 0, in, h, d;
	in = st;
	while (in > ter)
	{
		h = in / 2;
		if (h >= ter)
		{
			d = in - h;
			if (d * a > b)
			{
				cost += b;
			}
			else
			{
				cost += d * a;
			}
			in = h;
		}
		else
		{
			cost += (in - ter) * a;
			break;
		}
	}
	return cost;
}
void Cal()
{
	int i;
	for (i = 0; i < ag; i++)
	{
		Ag[i].cost = Count(AB[i][0], AB[i][1]);
	}
	qsort(Ag, ag, sizeof(ss), cmp);
	for (i = 0; i < ag; i++)
	{
		printf("%s %d\n", Ag[i].nam, Ag[i].cost);
	}
}
void Sep(char xx[], int n)
{
	int i, j = 0;
	char temp[19];
	for (i = 0; xx[i] != ':'; i++)
	{
		temp[i] = xx[i];
	}
	temp[i] = '\0';
	strcpy(Ag[n].nam, temp);
	for (++i; xx[i] != ','; i++)
	{
		temp[j++] = xx[i];
	}
	temp[j] = '\0';
	AB[n][0] = atoi(temp);
	j = 0;
	for (++i; xx[i]; i++)
	{
		temp[j++] = xx[i];
	}
	temp[j] = '\0';
	AB[n][1] = atoi(temp);
}

int main()
{
	int k, c = 1;
	char temp[100];
	scanf("%d", &k);
	while (k--)
	{
		scanf("%d%d%d", &st, &ter, &ag);
		for (int i = 0; i < ag; i++)
		{
			scanf("%s", temp);
			Sep(temp, i);
		}
		printf("Case %d\n", c++);
		Cal();
	}
	return 0;
}
