#include <bits/stdc++.h>

using namespace std;

/****
10508
****/
#define MAXN 2000
char Word[MAXN][MAXN];
char Temp[MAXN];
int N, M;
int main()
{
	int diff, i, j;
	while (scanf("%d%d", &N, &M) == 2)
	{
		scanf("%s", Word[0]);
		for (i = 1; i < N; i++)
		{
			scanf("%s", Temp);
			diff = 0;
			for (j = 0; j < M; j++)
				if (Word[0][j] != Temp[j])
				{
					diff++;
				}
			strcpy(Word[diff], Temp);
		}
		for (i = 0; i < N; i++)
		{
			printf("%s\n", Word[i]);
		}
	}
	return 0;
}
