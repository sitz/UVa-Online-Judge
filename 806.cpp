#include <bits/stdc++.h>

using namespace std;

#define MAXN 67

char Map[MAXN][MAXN], Fg[MAXN][MAXN];
int Seq[MAXN * MAXN];
int N, tn, the_index;

int ReadCase()
{
	int i, j;
	tn = 0;
	scanf("%d", &N);
	if (!N)
		return 0;
	if (N > 0)
		for (i = 0; i < N; i++)
			scanf("%s", Map[i]);
	else
		while (scanf("%d", &j) && j != -1)
			Seq[tn++] = j;
	return 1;
}
int AllOne(int x, int y, int p, int q)
{
	int i, j, c = 0;
	for (i = x; i <= p; i++)
		for (j = y; j <= q; j++)
			if (Map[i][j] == '1')
				c++;
	return c;
}
int A[10];
void Get(int level)
{
	int i, j = 1, k = 0;
	for (i = 1; i <= level; i++)
	{
		k += A[i] * j;
		j *= 5;
	}
	Seq[tn++] = k;
}
void Recur(int x, int y, int p, int q, int sizE, int v, int level)
{
	int j = sizE / 2, o;
	A[level] = v;
	o = AllOne(x, y, p, q);
	if (o == sizE * sizE)
	{
		Get(level);
		return;
	}
	if (o == 0)
		return;
	Recur(x, y, x + j - 1, y + j - 1, j, 1, level + 1);
	Recur(x, y + j, x + j - 1, q, j, 2, level + 1);
	Recur(x + j, y, p, y + j - 1, j, 3, level + 1);
	Recur(x + j, y + j, p, q, j, 4, level + 1);
}
int com(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
void Print()
{
	int i, k = 0, c = 1;
	while (k < tn)
	{
		printf("%d", Seq[k]);
		c = 1;
		for (i = k + 1; i < tn && c < 12; i++, c++)
			printf(" %d", Seq[i]);
		k = i;
		printf("\n");
	}
}
void Cal1()
{
	int z, k = N * N;
	z = AllOne(0, 0, N - 1, N - 1);
	tn = 0;
	if (z == 0)
	{
		printf("Total number of black nodes = 0\n");
		return;
	}
	if (z == k)
	{
		printf("0\n");
		printf("Total number of black nodes = 1\n");
		return;
	}
	Recur(0, 0, N - 1, N - 1, N, 0, 0);
	qsort(Seq, tn, sizeof(int), com);
	Print();
	printf("Total number of black nodes = %d\n", tn);
}
void Fill(int x, int y, int p, int q, int sizE, int level)
{
	int i, j = sizE / 2, k, n;
	if (level == the_index)
	{
		for (i = x; i <= p; i++)
			for (k = y; k <= q; k++)
				Fg[i][k] = 1;
		return;
	}
	n = A[level];
	switch (n)
	{
	case 1:
		Fill(x, y, x + j - 1, y + j - 1, j, level + 1);
		break;
	case 2:
		Fill(x, y + j, x + j - 1, q, j, level + 1);
		break;
	case 3:
		Fill(x + j, y, p, y + j - 1, j, level + 1);
		break;
	case 4:
		Fill(x + j, y + j, p, q, j, level + 1);
		break;
	}
}
void Base5(int n)
{
	the_index = 0;
	while (n)
	{
		A[the_index++] = n % 5;
		n /= 5;
	}
	Fill(0, 0, N - 1, N - 1, N, 0);
}
void Cal2()
{
	int i;
	N *= -1;
	memset(Fg, 0, MAXN * MAXN);
	for (i = 0; i < tn; i++)
		Base5(Seq[i]);
	for (i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			if (Fg[i][j])
				printf("*");
			else
				printf(".");
		printf("\n");
	}
}

int main()
{
	int img = 1;
	while (ReadCase())
	{
		if (img > 1)
			printf("\n");
		printf("Image %d\n", img++);
		if (N > 0)
			Cal1();
		else
			Cal2();
	}
	return 0;
}
