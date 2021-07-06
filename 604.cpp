#include <bits/stdc++.h>

using namespace std;

#define MAXN 6

char V[] = "AEIOUY";
char vf[30], B1[6][6], B2[6][6], com1[30], com2[30], Str[100], A[6], Fg[MAXN][MAXN], Word[100000][5];
int ind, Max;
map<string, bool> M1, M2;

int com(const void *a, const void *b)
{
	char *x = (char *)a;
	char *y = (char *)b;
	return strcmp(x, y);
}
void Ini()
{
	int i, u;
	for (i = 0; V[i]; i++)
	{
		u = V[i] - 'A';
		vf[u] = 1;
	}
}
void Sep(int n)
{
	int i, j = 0, u;
	for (i = 0; Str[i]; i++)
	{
		if (isalpha(Str[i]))
		{
			B1[n][j++] = Str[i];
			u = Str[i] - 'A';
			com1[u] = 1;
		}
		if (j == 4)
			break;
	}
	j = 0;
	for (++i; Str[i]; i++)
	{
		if (isalpha(Str[i]))
		{
			B2[n][j++] = Str[i];
			u = Str[i] - 'A';
			com2[u] = 1;
		}
		if (j == 4)
			return;
	}
}
void recur1(int r, int c, int v, int level)
{
	int i, j, nr, nc, x;
	A[level] = B1[r][c];
	if (v > 2)
		return;
	if (level >= 2 && v == 0)
		return;
	if (level == 3 && v == 2)
	{
		A[level + 1] = NULL;
		if (M1[A] == true)
			return;
		M1[A] = true;
		Max++;
		return;
	}
	if (level >= 3)
		return;
	Fg[r][c] = 1;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0)
				continue;
			nr = r + i;
			nc = c + j;
			if (nr < 0 || nr >= 4 || nc < 0 || nc > 4)
				continue;
			if (Fg[nr][nc])
				continue;
			x = B1[nr][nc] - 'A';
			if (!com1[x] || !com2[x])
				continue;
			x = vf[x];
			recur1(nr, nc, v + x, level + 1);
		}
	}
	Fg[r][c] = 0;
}
void recur2(int r, int c, int v, int level)
{
	int i, j, nr, nc, x;
	A[level] = B2[r][c];
	if (v > 2)
		return;
	if (level >= 2 && v == 0)
		return;
	if (level == 3 && v == 2)
	{
		A[level + 1] = NULL;
		if (M1[A] == false)
			return;
		if (M2[A] == true)
			return;
		M2[A] = true;
		strcpy(Word[ind++], A);
		return;
	}
	if (level >= 3)
		return;
	Fg[r][c] = 1;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0)
				continue;
			nr = r + i;
			nc = c + j;
			if (nr < 0 || nr >= 4 || nc < 0 || nc > 4)
				continue;
			if (Fg[nr][nc])
				continue;
			x = B2[nr][nc] - 'A';
			if (!com1[x] || !com2[x])
				continue;
			x = vf[x];
			recur2(nr, nc, v + x, level + 1);
		}
	}
	Fg[r][c] = 0;
}
void Cal()
{
	int i, j, u;
	ind = Max = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			u = B1[i][j] - 'A';
			if (com1[u] && com2[u])
				recur1(i, j, vf[u], 0);
		}
	}
	if (Max == 0)
	{
		printf("There are no common words for this pair of boggle boards.\n");
		return;
	}
	ind = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			u = B2[i][j] - 'A';
			if (com1[u] && com2[u])
				recur2(i, j, vf[u], 0);
		}
	}
	if (ind == 0)
	{
		printf("There are no common words for this pair of boggle boards.\n");
		return;
	}
	qsort(Word, ind, sizeof(Word[0]), com);
	for (i = 0; i < ind; i++)
		printf("%s\n", Word[i]);
}
void Free()
{
	int i;
	for (i = 0; i < 26; i++)
		com1[i] = com2[i] = 0;
	M1.clear();
	M2.clear();
}

int main()
{
	int i, f = 0;
	char temp[100];
	Ini();
	while (gets(Str))
	{
		if (!strcmp(Str, "#"))
			break;
		Sep(0);
		for (i = 0; i < 3; i++)
		{
			gets(Str);
			Sep(i + 1);
		}
		gets(temp);
		if (f++)
			printf("\n");
		Cal();
		Free();
	}
	return 0;
}
