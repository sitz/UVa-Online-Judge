#include <bits/stdc++.h>

using namespace std;

#define MAXN 22

int N, M, C[MAXN];
struct ss
{
	char candidate[82];
	char party[82];
	int cand_number;
} V[MAXN], Temp;
int com(const void *a, const void *b)
{
	ss *x = (ss *)a;
	ss *y = (ss *)b;
	return strcmp(x->candidate, y->candidate);
}
int Cal()
{
	int i, j, max = 0, c = 0;
	ss *p;
	qsort(V, N, sizeof(V[0]), com);
	for (j = 0; j < N; j++)
	{
		V[j].cand_number = j;
		C[j] = 0;
	}
	for (i = 0; i < M; i++)
	{
		gets(Temp.candidate);
		p = (ss *)bsearch(&Temp, V, N, sizeof(V[0]), com);
		if (p)
		{
			C[p->cand_number]++;
			if (C[p->cand_number] > max)
			{
				max = C[p->cand_number];
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		if (C[i] == max)
		{
			j = i;
			c++;
			if (c > 1)
			{
				printf("tie\n");
				return 0;
			}
		}
	}
	printf("%s\n", V[j].party);
	return 0;
}

int main()
{
	char input[100];
	int kase, i;
	gets(input);
	sscanf(input, "%d", &kase);
	gets(input);
	while (kase--)
	{
		gets(input);
		sscanf(input, "%d", &N);
		for (i = 0; i < N; i++)
		{
			gets(V[i].candidate);
			gets(V[i].party);
		}
		gets(input);
		sscanf(input, "%d", &M);
		Cal();
		if (kase)
		{
			printf("\n");
			gets(input);
		}
	}
	return 0;
}
