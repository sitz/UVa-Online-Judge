#include <bits/stdc++.h>

using namespace std;

typedef long long ss;

ss B[17][17], P[100], R[17][17][17], F[17][17], k;
char com[100];
char pos[] = "123456789ABCDEF";

void Ini()
{
	int i;
	for (i = 0; pos[i]; i++)
		P[pos[i]] = i + 1;
}

ss recur(ss r, ss c, ss level, ss limit)
{
	ss i, fg = 1;
	if (F[r][c] == 1)
		return B[r][c];
	if (level == limit)
		return 1;
	F[r][c] = 1;
	if (com[r] == '?')
	{
		for (i = 1; i <= limit; i++)
		{
			if (i == c - 1 || i == c || i == c + 1)
				continue;
			B[r][c] += recur(r + 1, i, level + 1, limit);
		}
	}
	else
	{
		if (c == P[com[r]] - 1 || c == P[com[r]] || c == P[com[r]] + 1)
			return 0;
		else
			B[r][c] = recur(r + 1, P[com[r]], level + 1, limit);
	}
	return B[r][c];
}
void Free()
{
	int i, j;
	for (i = 1; i <= 15; i++)
		for (j = 1; j <= 15; j++)
			B[i][j] = F[i][j] = 0;
}
void Cal()
{
	ss i, j;
	k = 0;
	j = strlen(com);
	if (com[0] == '?')
		for (i = 1; i <= j; i++)
			k += recur(1, i, 1, j);
	else
		k = recur(1, P[com[0]], 1, j);
	printf("%lld\n", k);
}

int main()
{
	Ini();
	while (scanf("%s", com) != EOF)
	{
		Cal();
		Free();
	}
	return 0;
}
