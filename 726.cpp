#include <bits/stdc++.h>

using namespace std;

typedef struct
{
	char w;
	int v;
} word;
word W1[128], W2[128];
int cmp(const void *a, const void *b)
{
	if (((word *)a)->v != ((word *)b)->v)
	{
		return ((word *)b)->v - ((word *)a)->v;
	}
	return ((word *)a)->w - ((word *)b)->w;
}
char in[50000], *O[50000], T[128];
int main()
{
	int i, j, n, len;
	for (i = 0; i < 128; i++)
	{
		W1[i].w = W2[i].w = T[i] = i;
		W1[i].v = W2[i].v = 0;
	}
	while (gets(in))
	{
		if (in[0] == '\0')
		{
			break;
		}
		for (i = 0; in[i]; i++)
		{
			W1[in[i] | 32].v++;
		}
	}
	qsort(W1 + 'a', 26, sizeof(word), cmp);
	for (n = 0; gets(in); n++)
	{
		for (i = 0; in[i]; i++)
		{
			W2[in[i] | 32].v++;
		}
		len = strlen(in);
		O[n] = (char *)malloc((len + 1) * sizeof(char));
		strcpy(O[n], in);
	}
	qsort(W2 + 'a', 26, sizeof(word), cmp);
	for (i = 'a'; i <= 'z'; i++)
	{
		T[(int)W2[i].w] = W1[(int)i].w;
		T[(int)W2[i].w ^ 32] = W1[(int)i].w ^ 32;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; O[i][j]; j++)
		{
			printf("%c", T[(int)O[i][j]]);
		}
		printf("\n");
	}
	return 0;
}
