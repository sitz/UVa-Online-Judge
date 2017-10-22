#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000

const char *acgt = "ACGT";

char s[MAXN], res[MAXN];
int M[300], to[MAXN][4], cnt[MAXN], n, id, resLen, resCnt;

void clear(int i)
{
	cnt[i] = 0;
	for (int j = 0; j < 4; j++)
	{
		to[i][j] = -1;
	}
}

void add(int i, char *x)
{
	cnt[i]++;
	if (!*x)
	{
		return;
	}
	int &ni = to[i][M[*x]];
	if (ni == -1)
	{
		clear(ni = id++);
	}
	add(ni, x + 1);
}

void rec(int i, int depth = 0)
{
	s[depth] = 0;
	if (depth > resLen && cnt[i] > 1)
	{
		resLen = depth;
		resCnt = cnt[i];
		strcpy(res, s);
	}
	for (int j = 0; j < 4; j++)
	{
		if (to[i][j] != -1)
		{
			s[depth] = acgt[j];
			rec(to[i][j], depth + 1);
		}
	}
}

int main()
{
	M['A'] = 0;
	M['C'] = 1;
	M['G'] = 2;
	M['T'] = 3;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", s);
		clear(0);
		id = 1;
		for (int i = 0; i < strlen(s); i++)
		{
			add(0, s + i);
		}
		resLen = resCnt = 0;
		rec(0);
		if (resLen > 0)
		{
			printf("%s %d\n", res, resCnt);
		}
		else
		{
			puts("No repetitions found!");
		}
	}
}
