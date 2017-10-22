#include <bits/stdc++.h>

using namespace std;

/*
732
Anagram By Stack
*/
#define MAXN 1000
struct ss
{
	int fre1, fre2;
} L[300];
char Str[MAXN], Ter[MAXN];
int Len;
int NotMatch()
{
	int i, j, k;
	Len = strlen(Str);
	k = strlen(Ter);
	if (Len != k)
	{
		return 1;
	}
	for (i = 0; Str[i]; i++)
	{
		j = Str[i];
		L[j].fre1++;
		k = Ter[i];
		L[k].fre2++;
	}
	for (i = 0; i < 300; i++)
		if (L[i].fre1 != L[i].fre2)
		{
			return 1;
		}
	return 0;
}
void Recur(char ch, int level, int hd, int ph, int pp, char C[], char S[], char Res[])
{
	int i;
	char tS[MAXN];
	C[level] = ch;
	for (i = 0; i < ph; i++)
	{
		tS[i] = S[i];
	}
	if (ch == 'i')
	{
		if (hd >= Len)
		{
			return;
		}
		tS[ph++] = Str[hd++];
		tS[ph] = NULL;
	}
	if (ch == 'o')
	{
		if (ch == 0)
		{
			return;
		}
		if (S[ph - 1] != Ter[pp])
		{
			return;
		}
		Res[pp++] = S[ph - 1];
		ph--;
	}
	if (level == 2 * Len - 1)
	{
		Res[pp] = NULL;
		printf("%c", C[0]);
		if (!strcmp(Res, Ter))
		{
			for (i = 1; i < 2 * Len; i++)
			{
				printf(" %c", C[i]);
			}
		}
		printf("\n");
		return;
	}
	Recur('i', level + 1, hd, ph, pp, C, tS, Res);
	Recur('o', level + 1, hd, ph, pp, C, tS, Res);
}
int main()
{
	char S[MAXN], Res[MAXN];
	char C[MAXN];
	while (scanf("%s", Str) != EOF)
	{
		scanf("%s", Ter);
		if (NotMatch())
		{
			printf("[\n");
			printf("]\n");
			continue;
		}
		printf("[\n");
		Recur('i', 0, 0, 0, 0, Res, S, C);
		printf("]\n");
		memset(L, 0, sizeof(int) * 300);
	}
	return 0;
}
