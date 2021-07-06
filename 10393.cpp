#include <bits/stdc++.h>

using namespace std;

char FINGER[10][10] = {"aqz", "wsx", "edc", "rfvtgb", " ", " ", "yhnujm", "ik,", "ol.", "p;/"};
char WORD[1002][52];
char STORE[1002][52];
char FLAG[300];
int N, F, MAX;
int CR[15], LEN;

int sort_function(const void *a, const void *s)
{
	char *c = (char *)a;
	char *d = (char *)s;
	if (strlen(c) == strlen(d))
	{
		return strcmp((char *)c, (char *)d);
	}
	return strlen(d) - strlen(c);
}
void MAKEZERO()
{
	int i, j, k, m;
	for (i = 0; i < 300; i++)
	{
		FLAG[i] = 0;
	}
	for (i = 0; i < F; i++)
	{
		k = CR[i] - 1;
		for (j = 0; FINGER[k][j]; j++)
		{
			m = FINGER[k][j];
			FLAG[m] = 1;
		}
	}
}
int TYPEABLE(int i)
{
	int j, k;
	for (j = 0; WORD[i][j]; j++)
	{
		k = WORD[i][j];
		if (FLAG[k])
		{
			return 0;
		}
	}
	return 1;
}
void PRINT()
{
	int i;
	printf("%d\n", MAX);
	for (i = 0; i < MAX; i++)
	{
		if (strlen(STORE[i]) == LEN)
		{
			printf("%s\n", STORE[i]);
		}
	}
}

int main()
{
	int i;
	char buf[60];
	int x;
	while (scanf("%d%d", &F, &N) == 2)
	{
		for (i = 0; i < F; i++)
		{
			scanf("%d", &CR[i]);
		}
		MAKEZERO();
		for (i = 0; i < N; i++)
		{
			scanf("%s", WORD[i]);
		}
		qsort((void *)WORD, N, sizeof(WORD[0]), sort_function);
		MAX = 0;
		LEN = 0;
		strcpy(buf, "$$$");
		for (i = 0; i < N; i++)
		{
			x = strlen(WORD[i]);
			if (!strcmp(buf, WORD[i]))
			{
				continue;
			}
			if (x < LEN)
			{
				break;
			}
			if (TYPEABLE(i))
			{
				if (x >= LEN)
				{
					LEN = x;
					strcpy(STORE[MAX++], WORD[i]);
					strcpy(buf, WORD[i]);
				}
			}
		}
		PRINT();
	}
	return 0;
}
