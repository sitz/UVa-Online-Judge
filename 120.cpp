#include <bits/stdc++.h>

using namespace std;

#define MAXN 32
int St[MAXN], Or[MAXN];
int N;
char str[10000];

int com(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int Search(int end, int key)
{
	int i;
	for (i = 0; i <= end; i++)
	{
		if (St[i] == key)
		{
			break;
		}
	}
	return N - i;
}

int Com[200];

void Rev(int ind)
{
	int temp[30], i, j = 0;
	for (i = ind; i >= 0; i--)
	{
		temp[j++] = St[i];
	}
	for (i = 0; i <= ind; i++)
	{
		St[i] = temp[i];
	}
}

void SolvedCase()
{
	int i, p, c = 0, f = 0;
	qsort(Or, N, sizeof(int), com);
	for (i = N - 1; i >= 0; i--)
	{
		if (St[i] == Or[i])
		{
			continue;
		}
		p = Search(i, Or[i]);
		if (p != N)
		{
			Com[c++] = p;
			Rev(N - p);
		}
		Com[c++] = N - i;
		Rev(i);
		f = 1;
	}
	if (!f)
	{
		printf("0\n");
		return;
	}
	printf("%d", Com[0]);
	for (i = 1; i < c; i++)
	{
		printf(" %d", Com[i]);
	}
	printf(" 0\n");
}
void Sep()
{
	char *p;
	N = 0;
	p = strtok(str, " ");
	St[N] = Or[N] = atoi(p);
	N++;
	while (p)
	{
		p = strtok(NULL, " ");
		if (p)
		{
			St[N] = Or[N] = atoi(p);
			N++;
		}
	}
}

int main()
{
	while (gets(str))
	{
		Sep();
		printf("%d", Or[0]);
		for (int i = 1; i < N; i++)
		{
			printf(" %d", Or[i]);
		}
		putchar('\n');
		SolvedCase();
	}
	return 0;
}
