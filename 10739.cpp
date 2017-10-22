#include <bits/stdc++.h>

using namespace std;

#define MAXN 1002

int Cost[MAXN][MAXN], len;
char Str[MAXN];

int recur(int r, int c)
{
	int x;
	if (r >= c)
		return 0;
	if (Cost[r][c])
		return Cost[r][c];
	if (Str[r] == Str[c])
		Cost[r][c] = recur(r + 1, c - 1);
	else
	{
		Cost[r][c] = recur(r, c - 1) + 1;
		x = recur(r + 1, c) + 1;
		if (x < Cost[r][c])
			Cost[r][c] = x;
		x = recur(r + 1, c - 1) + 1;
		if (x < Cost[r][c])
			Cost[r][c] = x;
	}
	return Cost[r][c];
}

void Cal()
{
	len = strlen(Str) - 1;
	printf("%d\n", recur(0, len));
}

void Free()
{
	int i, j;
	for (i = 0; i <= len; i++)
		for (j = 0; j <= len; j++)
			Cost[i][j] = 0;
}

int main()
{
	int k, c = 1;
	char input[100];
	gets(input);
	sscanf(input, "%d", &k);
	while (k--)
	{
		gets(Str);
		printf("Case %d: ", c++);
		Cal();
		if (k)
			Free();
	}
	return 0;
}
