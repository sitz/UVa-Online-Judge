#include <bits/stdc++.h>

using namespace std;

#define MAX 10000

int M[MAX][5], N, dis;
char input[100];

struct ss
{
	char l, r;
} B[MAX];

int IsEmpty()
{
	int i;
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '\n')
		{
			input[i] = NULL;
			break;
		}
	}
	if (strlen(input) == 0)
		return 1;
	return 0;
}
int recur(int n)
{
	int i, l, r;
	if (dis)
		return -1;
	B[n].l = 1;
	l = M[n][0];
	r = M[n][2];
	if (l == 0)
	{
		for (i = n + 1; i < N; i++)
			if (B[i].l == 0)
				break;
		l = recur(i);
		M[n][0] = l;
	}
	if (dis)
		return -1;
	if (r == 0)
	{
		for (i = n + 1; i < N; i++)
			if (B[i].l == 0)
				break;
		r = recur(i);
		M[n][2] = r;
	}
	if (dis)
		return -1;
	if (M[n][1] * l != r * M[n][3])
	{
		dis = 1;
		return -1;
	}
	return r + l;
}
void Cal()
{
	int i, d;
	dis = 0;
	d = recur(0);
	if (d < 0)
		printf("NO\n");
	else
		printf("YES\n");
	for (i = 0; i < N; i++)
		B[i].l = 0;
}

int main()
{
	int kases;
	gets(input);
	sscanf(input, "%d", &kases);
	gets(input);
	while (kases--)
	{
		N = 0;
		while (gets(input))
		{
			if (IsEmpty())
				break;
			sscanf(input, "%d%d%d%d", &M[N][0], &M[N][1], &M[N][2], &M[N][3]);
			N++;
		}
		Cal();
		if (kases)
			printf("\n");
	}
	return 0;
}
