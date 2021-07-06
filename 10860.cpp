#include <bits/stdc++.h>

using namespace std;

char SS[10002], HavS[128], HavX[128], Temp[102], Fg[10002];
int N, R[10002], Len, MinLen, ff;

struct ss {char str[102]; int len;};
ss XX[102];

int com(const void *a, const void *b)
{
	ss *x = (ss *)a;
	ss *y = (ss *)b;
	return y->len - x->len;
}

int Imp()
{
	int i;
	for (i = 33; i <= 127; i++)
	{
		if (HavS[i] > HavX[i])
		{
			return 1;
		}
	}
	return 0;
}

int Match(int ind, int st)
{
	int i, k;
	k = Len - st + 1;
	if (XX[ind].len > k)
	{
		return 0;
	}
	for (i = 0; i < XX[ind].len; i++)
	{
		if (XX[ind].str[i] != SS[st + i])
		{
			return 0;
		}
	}
	return 1;
}

void Recur(int n, int lvl)
{
	int i;
	if (Fg[n] && R[n] <= lvl)
	{
		return;
	}
	Fg[n] = 1;
	R[n] = lvl;
	if (n == Len - 1)
	{
		MinLen = lvl;
		ff = 1;
		return;
	}
	for (i = 0; i < N + N; i++)
	{
		if (Match(i, n + 1))
		{
			Recur(n + XX[i].len, lvl + 1);
		}
	}
}

void Cal()
{
	int i;
	ff = 0;
	if (Imp())
	{
		printf("Not possible.\n");
		return;
	}
	Len = strlen(SS);
	qsort(XX, N + N, sizeof(XX[0]), com);
	for (i = 0; i < N + N; i++)
	{
		if (Match(i, 0))
		{
			Recur(XX[i].len - 1, 1);
		}
	}

	if (ff)
	{
		printf("%d.\n", MinLen);
	}
	else
	{
		printf("Not possible.\n");
	}
}

void Free()
{
	int i;
	for (i = 33; i <= 127; i++)
	{
		HavX[i] = HavS[i] = 0;
	}
	for (i = 0; i < Len; i++)
	{
		Fg[i] = 0;
	}
}

void Rev(char xx[], int len)
{
	int i, k = 0;
	for (i = len - 1; i >= 0; i--)
	{
		Temp[k++] = xx[i];
	}
	Temp[k] = '\0';
}

int main()
{
	int ks, st = 1, i, j, k;
	scanf("%d", &ks);
	while (ks--)
	{
		scanf("%s", SS);
		for (i = 0; SS[i]; i++)
		{
			k = SS[i];
			HavS[k] = 1;
		}
		scanf("%d", &N);
		for (i = 0; i < N; i++)
		{
			scanf("%s", XX[i].str);
			XX[i].len = strlen(XX[i].str);
			Rev(XX[i].str, XX[i].len);
			strcpy(XX[i + N].str, Temp);
			XX[i + N].len = XX[i].len;
			for (j = 0; j < XX[i].len; j++)
			{
				k = XX[i].str[j];
				HavX[k] = 1;
			}
		}
		printf("Set %d: ", st++);
		Cal();
		Free();
	}
	return 0;
}
