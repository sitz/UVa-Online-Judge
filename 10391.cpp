#include <bits/stdc++.h>

using namespace std;

#define MAXW 120000
#define MAXC 200

char WORD[MAXW][MAXC];
char M[MAXC], F[MAXW];
int K;

int qs(const void *a, const void *b)
{
	return (strcmp((char *)a, (char *)b));
}
void SOLVEDCASE()
{
	int i, j, p, q;
	int *c;
	//qsort(WORD,K,sizeof(WORD[0]),qs);
	for (i = 0; i < K - 1; i++)
	{
		for (j = i + 1; j < K; j++)
		{
			if (strncmp(WORD[j], WORD[i], strlen(WORD[i])) == 0)
			{
				q = 0;
				for (p = strlen(WORD[i]); p < strlen(WORD[j]); p++)
				{
					M[q++] = WORD[j][p];
				}
				M[q] = NULL;
				c = (int *)bsearch(M, WORD, K, sizeof(WORD[0]), qs);
				if (c)
				{
					F[j] = 1;
				}
			}
			else
			{
				break;
			}
		}
	}
	for (i = 0; i < K; i++)
		if (F[i])
		{
			puts(WORD[i]);
		}
}

int main()
{
	K = 0;
	while (scanf("%s", WORD[K]) != EOF)
	{
		K++;
	}
	SOLVEDCASE();
	return 0;
}
