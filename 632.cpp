#include <bits/stdc++.h>

using namespace std;

/*
632
Compression (II)
*/
struct ss
{
	int st;
} w[1999];
char str[1999];
int N;
int com(const void *a, const void *b)
{
	int p, q, i, l1, l2;
	ss *x = (ss *)a;
	ss *y = (ss *)b;
	p = x->st;
	q = y->st;
	for (i = 0; i < N; i++)
	{
		l1 = (p + i) % N;
		l2 = (q + i) % N;
		if (str[l1] > str[l2])
		{
			return 1;
		}
		if (str[l1] < str[l2])
		{
			return -1;
		}
	}
	return 0;
}
void ReadCase()
{
	char temp[60];
	int d = 0;
	gets(temp);
	N = atoi(temp);
	str[0] = NULL;
	while (1)
	{
		gets(temp);
		strcat(str, temp);
		d += strlen(temp);
		if (d >= N)
		{
			break;
		}
	}
}
void Cal()
{
	int i, p;
	for (i = 0; i < N; i++)
	{
		w[i].st = i;
	}
	qsort(w, N, sizeof(w[0]), com);
	for (i = 0; i < N; i++)
		if (w[i].st == 1)
		{
			break;
		}
	printf("%d\n", i);
	for (i = 0; i < N; i++)
	{
		if (i && i % 50 == 0)
		{
			putchar('\n');
		}
		p = w[i].st + N - 1;
		p %= N;
		printf("%c", str[p]);
	}
	printf("\n");
}
int main()
{
	int kase;
	char input[100];
	gets(input);
	kase = atoi(input);
	gets(input);
	while (kase--)
	{
		ReadCase();
		Cal();
		if (kase)
		{
			gets(input);
			printf("\n");
		}
	}
	return 0;
}
